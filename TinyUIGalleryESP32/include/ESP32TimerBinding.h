#ifndef GALLERY_ESP32TIMERBINDING_H
#define GALLERY_ESP32TIMERBINDING_H

#include <Arduino.h>
#include <TinyUI.h>

class ESP32TimerBinding : public tiny::binding::TimerBinding {
 public:
  int64_t getTime();
};

#endif