#include <Arduino.h>
#include <Wire.h>
#include "config.h"
#include "log.h"
#include "ltc294x_internal.h"
#include "batterystate.h"
#include "chargestate.h"

  

volatile enum Ltc294xRegister requestedRegister = Ltc294xRegister::INVALID;

extern void ltc294xRequestEvent();
extern void ltc294xReceiveEvent(size_t);

void ltc294xInit() {
  Wire.begin(I2C_ADDRESS);
  Wire.onRequest(ltc294xRequestEvent);
  Wire.onReceive(ltc294xReceiveEvent);
}

void ltc294xRequestEvent() {
  logLn("onRequestEvent");
  switch (requestedRegister) {
    case Ltc294xRegister::STATUS: {
      uint8_t result = 1;
      Wire.write((byte*)&result, 1);
    }
    case Ltc294xRegister::CONTROL: {
      uint8_t result = 0;
      Wire.write((byte*)&result, 1);
    }
    case Ltc294xRegister::ACCUMULATED_CHARGE: {
      uint16_t value = (uint16_t) (batteryStateGetVoltageAverage() * 100.f);
      uint8_t result[] = { value >> 8, value & 0x00ff }; // msb, lsb
      Wire.write((byte*)&result, 2);
    }
    case Ltc294xRegister::CHARGE_THRESHOLD_HIGH:	{
      uint16_t value = (uint16_t) (VBAT_ADC_MAX_BATTERY_REAL_VOLTAGE * 100.f);
      uint8_t result[] = { value >> 8, value & 0x00ff }; // msb, lsb
      Wire.write((byte*)&result, 2);
    }
    case Ltc294xRegister::CHARGE_THRESHOLD_LOW:	{
      uint16_t value = (uint16_t) (VBAT_TURN_OFF * 100.f);
      uint8_t result[] = { value >> 8, value & 0x00ff }; // msb, lsb
      Wire.write((byte*)&result, 2);
    }
    case Ltc294xRegister::VOLTAGE:	{
      uint16_t value = 6 * (batteryStateGetVoltageAverage() / 65535.f);
      uint8_t result[] = { value >> 8, value & 0x00ff }; // msb, lsb
      Wire.write((byte*)&result, 2);
    }
    case Ltc294xRegister::VOLTAGE_THRESHOLD_HIGH: {
      uint8_t value = (uint8_t) (VBAT_ADC_MAX_BATTERY_REAL_VOLTAGE / 0.0234375);
      Wire.write((byte*)&value, 1);
    }
    case Ltc294xRegister::VOLTAGE_THRESHOLD_LOW:	{
      uint8_t value = (uint8_t) (VBAT_TURN_OFF / 0.0234375);
      Wire.write((byte*)&value, 1);
    }
    case Ltc294xRegister::TEMPERATURE:	{
      uint16_t value = 1;
      uint8_t result[] = { value >> 8, value & 0x00ff }; // msb, lsb
      Wire.write((byte*)&result, 2);
    }
    case Ltc294xRegister::TEMPERATURE_THRESHOLD_HIGH: {
      uint8_t result = 128;
      Wire.write((byte*)&result, 1);
    }
    case Ltc294xRegister::TEMPERATURE_THRESHOLD_LOW:	{
      uint8_t result = 0;
      Wire.write((byte*)&result, 1);
    }
  }
}

void ltc294xReceiveEvent(size_t size) {
  if (size == 0) {
    logLn("onReceiveEvent: bus poll");
  } else if (size == 1) {
    static uint8_t buffer = 0;
    Wire.readBytes(&buffer, 1);
    requestedRegister = buffer;
    log("onReceiveEvent: register ");
    logLn(requestedRegister);
  } else {
    log("onReceiveEvent(");
    log(size);
    log(") ");
    static uint8_t buffer[32];
    Wire.readBytes(buffer, size);
    for (int i=0; i<size; ++i) {
      log(buffer[i]);
      log(" ");
    }
    logLn();
  }
}
