
import nesper
import nesper/timers
import nesper/i2cs
import nesper/gpios
import nesper/tasks
import nesper/esp/driver/dac

import nesper/esp-idf-lib/i2cdev
import nesper/esp-idf-lib/ads111x

const
  TAG = "ADS"

let
  I2C_PORT = i2c_port_t(0)
  SDA_GPIO = GpioPin(23)
  SCL_GPIO = GpioPin(22)
  GAIN = ADS111X_GAIN_4V096 # // +-4.096V

var gain_val: float32

var
  devaddr = ADS111X_ADDR_GND
  device: i2c_dev_t

proc measure(dev: i2c_dev_ptr): (float32, int) =
    #// wait for conversion end
    var busy: bool
    while busy:
      check: ads111x_is_busy(dev, addr busy)

    #// Read result
    var raw: int16 = 0
    if (ads111x_get_value(dev, addr raw) == ESP_OK):
      var voltage: float32 = gain_val / ADS111X_MAX_VALUE * float(raw)
      return (voltage, raw.int)
    else:
      TAG.logi("[%x] Cannot read ADC value\n")
      return (NaN.float32, 0.int)

type
  Ads111xConfig* = object
    mode: ads111x_mode_t
    data_rate: ads111x_data_rate_t
    mux: ads111x_mux_t
    gain: ads111x_gain_t

proc ads111x_read_single*(dev: i2c_dev_ptr, cfg: Ads111xConfig): (float32, int) =
  TAG.logi("set cfg: %s", repr cfg)
  # check: ads111x_set_mode(dev, cfg.mode) #    // Continuous conversion mode
  check: ads111x_set_data_rate(dev, cfg.data_rate) #; // 32 samples per second
  check: ads111x_set_input_mux(dev, cfg.mux) #;    // positive = AIN0, negative = GND
  check: ads111x_set_gain(dev, cfg.gain)

  # check: ads111x_set_comp_latch(dev, ADS111X_COMP_LATCH_DISABLED) #;    // positive = AIN0, negative = GND
  # check: ads111x_set_comp_mode(dev, ADS111X_COMP_MODE_NORMAL) #;    // positive = AIN0, negative = GND
  # check: ads111x_set_comp_queue(dev, ADS111X_COMP_QUEUE_DISABLED) #;    // positive = AIN0, negative = GND

  # var dch: ads111x_mux_t
  # check: ads111x_get_input_mux(dev, addr dch)
  # TAG.logi("mux: %s", $dch)

  # if cfg.mode == ADS111X_MODE_SINGLE_SHOT:
  check: ads111x_start_conversion(dev)

  # discard dev.measure()
  return dev.measure()


# // Main task
proc ads111x_test(args: pointer) {.cdecl.} = 

    TAG.logi("Initializing devices\n")
    gain_val = ads111x_gain_values[GAIN]
    var dev = addr device

    # // Setup ICs
    TAG.logi("Initialize device \n")
    # initialize device
    check: ads111x_init_desc(dev, devaddr, I2C_PORT, SDA_GPIO, SCL_GPIO)

    let t0 = newBasicTimer()

    let
      cfg_ch0 = Ads111xConfig(mode: ADS111X_MODE_SINGLE_SHOT,
                              mux: ADS111X_MUX_0_GND,
                              data_rate: ADS111X_DATA_RATE_8,
                              gain: ADS111X_GAIN_4V096)
      cfg_ch1 = Ads111xConfig(mode: ADS111X_MODE_SINGLE_SHOT,
                              mux: ADS111X_MUX_1_GND,
                              data_rate: ADS111X_DATA_RATE_8,
                              gain: ADS111X_GAIN_4V096)


    TAG.logi("set cfg ch0: %s", repr cfg_ch0)
    TAG.logi("set cfg ch1: %s", repr cfg_ch1)
    
    check: ads111x_set_mode(dev, ADS111X_MODE_SINGLE_SHOT) #    // Continuous conversion mode

    while true:
      let
        adj = (t0.elapsed().uint64 div 1_000_000).uint8 mod 20'u8
        d1 = 60'u8 + adj
      check: dac_output_voltage(DAC_CHANNEL_2, d1)
      TAG.logi("set dac output: %f", float(d1)/256.0 * 3.3)
      delay(207.Millis)

      # measure(i)
      let (voltage_ch0, raw_ch0) = dev.ads111x_read_single(cfg_ch0)
      TAG.logi("Raw ADC ch0:: value: %d, voltage: %.04f volts", raw_ch0, voltage_ch0)

      delay(100.Millis)

      let (voltage_ch1, raw_ch1) = dev.ads111x_read_single(cfg_ch1)
      TAG.logi("Raw ADC ch1:: value: %d, voltage: %.04f volts", raw_ch1, voltage_ch1)

      echo "\n"
      delay(500.Millis)


proc run_server*() {.exportc.} =
  # setup dac's
  check: dac_output_enable(DAC_CHANNEL_1)
  check: dac_output_voltage(DAC_CHANNEL_1, 60)
  check: dac_output_enable(DAC_CHANNEL_2)
  check: dac_output_voltage(DAC_CHANNEL_2, 20)

  # initialize 
  TAG.logi("run server\n", )
  check: i2cdev_init()

  var tsk_handle: TaskHandle_t
  discard xTaskCreate(pvTaskCode=ads111x_test,
                  pcName="ads111x_test",
                  usStackDepth=8*1024,
                  pvParameters=nil,
                  uxPriority=2,
                  pvCreatedTask=addr tsk_handle)
                  

# a0 => 27
# a1 => 13

# gpio 25 & gpio 26

when isMainModule:
  echo "running server"
  run_server()

