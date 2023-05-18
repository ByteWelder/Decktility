#include <Arduino.h>
#include <Wire.h>
#include "config.h"
#include "log.h"
#include "ltc294x.h"
#include "ltc294x_internal.h"
#include "batterystate.h"
#include "chargestate.h"
#include "battery.h"

enum Ltc294xRegister {
  STATUS                      = 0x00, // R
  CONTROL                     = 0x01, // R/W
  ACCUMULATED_CHARGE          = 0x02, // R/W
  CHARGE_THRESHOLD_HIGH       = 0x04, // R/W
  CHARGE_THRESHOLD_LOW        = 0x06, // R/W
  VOLTAGE                     = 0x08, // R, LTC2942 only
  VOLTAGE_THRESHOLD_HIGH      = 0x0A, // R/W, LTC2942 only
  VOLTAGE_THRESHOLD_LOW       = 0x0B, // R/W, LTC2942 only
  TEMPERATURE                 = 0x0C, // R, LTC2942 only
  TEMPERATURE_THRESHOLD_HIGH  = 0x0E, // R/W, LTC2942 only
  TEMPERATURE_THRESHOLD_LOW   = 0x0F, // R/W, LTC2942 only
  INVALID                     = 0xFF
};

#define I2C_ADDRESS 0x64

volatile enum Ltc294xRegister requestedRegister = Ltc294xRegister::INVALID;
volatile bool ltc294xIsCharging = false;

extern void ltc294xRequestEvent();
extern void ltc294xReceiveEvent(size_t);

void ltc294xInit() {
  Wire.begin(I2C_ADDRESS);
  Wire.onRequest(ltc294xRequestEvent);
  Wire.onReceive(ltc294xReceiveEvent);
}

/**
 * See https://github.com/torvalds/linux/blob/master/drivers/power/supply/ltc2941-battery-gauge.c
 * at ltc294x_get_voltage()
 */
uint16_t scaleVoltage(uint32_t inMilliVolts) {
    inMilliVolts /= 100;
    inMilliVolts *= 0xFFFF;
    inMilliVolts /= 60000;
    return inMilliVolts;
}

#define LTC294X_MID_SUPPLY  0x7FFF
#define LTC294X_MAX_VALUE 0xFFFF
#define R_SENSE 50
#define QLSB ((85 * 50000) / R_SENSE)

static inline uint32_t getBinFromUah(uint32_t uAh) {
	int Q = (uAh * 100) / (QLSB / 10);
	return (Q < LTC294X_MAX_VALUE) ? Q : LTC294X_MAX_VALUE;
}

void ltc294xRequestEvent() {
  #ifdef I2C_LOG
    logLn("onRequestEvent");
  #endif
  switch (requestedRegister) {
    case Ltc294xRegister::STATUS: {
      uint8_t result = 0;
      Wire.write((byte*)&result, 1);
    }
    case Ltc294xRegister::CONTROL: {
      uint8_t result = 0x3C;
      Wire.write((byte*)&result, 1);
    }
    case Ltc294xRegister::ACCUMULATED_CHARGE: {
      float cellVoltage = batteryStateGetVoltageAverage() / (float)VBAT_CELL_COUNT;
      uint16_t capacity = getBinFromUah(getEstimatedBatteryCapacity(cellVoltage) * 1000.f);
      uint8_t result[] = { capacity >> 8, capacity & 0x00ff };
      Wire.write((byte*)&result, 2);
    }
    case Ltc294xRegister::CHARGE_THRESHOLD_HIGH:	{
      uint16_t capacity = getBinFromUah(getBattery().capacity * 1000.f);
      uint8_t result[] = { capacity >> 8, capacity & 0x00ff };
      Wire.write((byte*)&result, 2);
    }
    case Ltc294xRegister::CHARGE_THRESHOLD_LOW:	{
      float voltage = getBattery().vCritical;
      uint16_t criticalCapacity = getBinFromUah(getEstimatedBatteryCapacity(voltage) * 1000.f);
      uint8_t result[] = { criticalCapacity >> 8, criticalCapacity & 0x00ff };
      Wire.write((byte*)&result, 2);
    }
    case Ltc294xRegister::VOLTAGE:	{
      uint16_t value = scaleVoltage(batteryStateGetVoltageAverage() * 1000.f);
      uint8_t result[] = { value >> 8, value & 0x00ff };
      Wire.write((byte*)&result, 2);
    }
    case Ltc294xRegister::TEMPERATURE:	{
      // Mock implementation
      uint16_t value = 1;
      uint8_t result[] = { value >> 8, value & 0x00ff };
      Wire.write((byte*)&result, 2);
    }
    case Ltc294xRegister::TEMPERATURE_THRESHOLD_HIGH: {
      // Mock implementation
      uint8_t result = 128;
      Wire.write((byte*)&result, 1);
    }
    case Ltc294xRegister::TEMPERATURE_THRESHOLD_LOW:	{
      // Mock implementation
      uint8_t result = 0;
      Wire.write((byte*)&result, 1);
    }
  }
}

void ltc294xReceiveEvent(size_t size) {
  if (size == 0) {
    #ifdef I2C_LOG
      logLn("onReceiveEvent: bus poll");
    #endif
  } else if (size == 1) {
    static uint8_t buffer = 0;
    Wire.readBytes(&buffer, 1);
    requestedRegister = buffer;
    #ifdef I2C_LOG
      log("onReceiveEvent: register ");
      logLn(requestedRegister);
    #endif
  } else {
    // Mock implementation
    static uint8_t buffer[32];
    Wire.readBytes(buffer, size);
    #ifdef I2C_LOG
      log("onReceiveEvent(");
      log(size);
      log(") ");
      for (int i=0; i<size; ++i) {
        log(buffer[i]);
        log(" ");
      }
      logLn();
      #endif
  }
}

