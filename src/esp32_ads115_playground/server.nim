
import nesper
import nesper/timers
import nesper/i2cs
import nesper/gpios
import nesper/tasks

import nesper/esp-idf-lib/i2cdev
import nesper/esp-idf-lib/ads111x

const
  DEV_COUNT = 2  #// 2 ICs
  TAG = "ADS"

let
  I2C_PORT = i2c_port_t(0)
  SDA_GPIO = GpioPin(16)
  SCL_GPIO = GpioPin(17)
  GAIN = ADS111X_GAIN_4V096 # // +-4.096V

var gain_val: float32

var
  devaddrs = [ADS111X_ADDR_GND, ADS111X_ADDR_VCC]
  devices: array[DEV_COUNT, i2c_dev_t]

proc measure(n: int) =
    #// wait for conversion end
    var busy: bool
    while busy:
      check: ads111x_is_busy(addr devices[n], addr busy)

    #// Read result
    var raw: int16 = 0
    if (ads111x_get_value(addr devices[n], addr raw) == ESP_OK):
      var voltage: float32 = gain_val / ADS111X_MAX_VALUE * float(raw)
      TAG.logd("[%u] Raw ADC value: %d, voltage: %.04f volts\n", n, raw, voltage)
    else:
      TAG.logd("[%u] Cannot read ADC value\n", n)


# // Main task
proc ads111x_test(args: pointer) {.cdecl.} = 
    gain_val = ads111x_gain_values[GAIN]

    # // Setup ICs
    for i in 0..<DEV_COUNT:
      # initialize device
      check: ads111x_init_desc(addr devices[i], devaddrs[i], I2C_PORT, SDA_GPIO, SCL_GPIO)

      check: ads111x_set_mode(addr devices[i], ADS111X_MODE_CONTINUOUS) #    // Continuous conversion mode
      check: ads111x_set_data_rate(addr devices[i], ADS111X_DATA_RATE_32) #; // 32 samples per second
      check: ads111x_set_input_mux(addr devices[i], ADS111X_MUX_0_GND) #;    // positive = AIN0, negative = GND
      check: ads111x_set_gain(addr devices[i], GAIN)

    while true:
      for i in 0 ..< DEV_COUNT:
        measure(i)
        delay(500.Millis)

proc run_server*() {.exportc.} =
  # initialize 
  check: i2cdev_init()
  var tsk_handle: TaskHandle_t
  discard xTaskCreate(pvTaskCode=ads111x_test,
                  pcName="ads111x_test",
                  usStackDepth=8*1024,
                  pvParameters=nil,
                  uxPriority=2,
                  pvCreatedTask=addr tsk_handle)
                  


when isMainModule:
  echo "running server"
  run_server()

