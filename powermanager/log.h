#ifndef LOG_H
#define LOG_H

#include <Arduino.h> // for Serial
#include "config.h"

#ifdef DEBUG
  #define logInit() Serial.begin(9600)
  #define log(arg) Serial.print(arg)
  #define logLn(arg) Serial.println(arg)
#else
  #define logInit()
  #define log(arg)
  #define logLn(arg)
#endif

#endif // LOG_H