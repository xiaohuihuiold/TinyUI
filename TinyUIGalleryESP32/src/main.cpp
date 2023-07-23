#include <Arduino.h>
#include <TinyUI.h>

#include "ESP32RenderBinding.h"
#include "ESP32TimerBinding.h"

using namespace tiny;

void setup() {
  Serial.begin(115200);

  TinyUI::begin(std::make_shared<ESP32TimerBinding>(),
                std::make_shared<ESP32RenderBinding>());
}

void loop() {
  TinyUI::get()->beginFrame();
  auto canvas = TinyUI::get()->beginCanvas();
  canvas->drawLine({0, 0}, {128, 64}, {});
  TinyUI::get()->endFrame();
}
