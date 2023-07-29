#include "ESP32TimerBinding.h"
#include <Arduino.h>
#include <TinyUI.h>

int64_t ESP32TimerBinding::getTime() {
  return esp_timer_get_time();
}