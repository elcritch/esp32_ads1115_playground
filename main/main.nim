import nesper
import nesper/timers
import nesper/net_utils
import nesper/nvs_utils
import nesper/events
import nesper/wifi
import nesper/tasks
import os

import esp32_ads1115_playground/server

when defined(ESP32_ETHERNET):
  import setup_eth
else:
  import setup_wifi

# const CONFIG_EXAMPLE_WIFI_SSID = getEnv("WIFI_SSID")
# const CONFIG_EXAMPLE_WIFI_PASSWORD = getEnv("WIFI_PASSWORD")

const
  TAG*: cstring = "main"
  APP_DONE* = EventBits_t(BIT(1))


var app_events: EventGroupHandle_t

app_main():

  networkingStart() 

  # Other startup code
  # ...
  app_events = xEventGroupCreate()


  # Connect networking
  # check:
    # networkingConnect()

  # Connect networking
  # onNetworking():
    # logi(TAG, "Connected to %s", networkConnectionName)
    # logi(TAG, "IPv4 address: %s", $networkIpAddr)
    # logi(TAG, "network setup!\n")

  run_server()

  # turn off networking 
  # check:
    # networkingDisconnect()

  discard app_events.xEventGroupWaitBits(APP_DONE, 1, 1, portMAX_DELAY)

  while true:
    logi(TAG, "network ok\n")
    delay(1000.Millis)

  assert false, "shouldn't reach here!"
