#include <Arduino.h>
#include "log.h"
#include "config.h"
#include "batterystate.h"

#define ADC_RESOLUTION 1023.f

// Entry count should be low enough to get updates often (1 entry per second),
// but high enough so that the voltage readings don't fluctuate too much.
// Too many items might result in slow response to low battery. This would only
// be problematic with high current draw.
#define VOLTAGE_HISTORY_ENTRIES 7
float voltageHistory[VOLTAGE_HISTORY_ENTRIES];
uint8_t voltageHistoryIndex = 0;

void storeCurrentVoltageInHistory() {
  voltageHistoryIndex++;
  if (voltageHistoryIndex > (VOLTAGE_HISTORY_ENTRIES - 1)) {
    voltageHistoryIndex = 0;
  }
  voltageHistory[voltageHistoryIndex] = batteryStateGetVoltageNow();
}

void batteryStateInit() {
  batteryStateGetVoltageNow(); // discard first result because it is inaccurate
  // Fill the buffer with readings
  for (int i=0; i<VOLTAGE_HISTORY_ENTRIES; ++i) {
    storeCurrentVoltageInHistory();
  }
}

void batteryStateUpdate() {
  storeCurrentVoltageInHistory();

  #ifdef BATTERY_STATE_LOG
    batteryStateLog();
  #endif
}

void batteryStateLog() {
    log("battery: ");
    log(batteryStateGetVoltageAverage());
    logLn(" V");
}

float batteryStateGetVoltageAverage() {
  float sum = 0.0f;
  for (int i=0; i<VOLTAGE_HISTORY_ENTRIES; ++i) { 
    sum += voltageHistory[i];
  } 
  return sum / (float)VOLTAGE_HISTORY_ENTRIES;
}

float batteryStateGetVoltageNow() {
    // read the value from the sensor:
  int adcValue = analogRead(VBAT_ADC_PIN);
  float adcValueScaled = (float)adcValue / ADC_RESOLUTION;
  float voltageReadOnPin = adcValueScaled * VBAT_ADC_MAX_READABLE_PIN_VOLTAGE;
  float voltage = voltageReadOnPin / VBAT_ADC_MAX_BATTERY_PIN_VOLTAGE * VBAT_ADC_MAX_BATTERY_REAL_VOLTAGE;
  return voltage;
}
