#include <Arduino.h>
#include <TinyUI.h>
#include <U8g2lib.h>

#include "ESP32TimerBinding.h"

using namespace tiny;

void setup() {
  Serial.begin(115200);
  TinyUI::begin(new ESP32TimerBinding());
}

void loop() {}
