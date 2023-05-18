#include <Arduino.h>
#include "powerswitch.h"
#include "config.h"
#include "batterystate.h"
#include "log.h"
#include "battery.h"

int lastState = LOW;

void powerSwitchInit() {
  pinMode(POWER_ENABLE_PIN, OUTPUT);
  digitalWrite(POWER_ENABLE_PIN, LOW);
}

void powerSwitchUpdate() {
  float vBatCell = batteryStateGetVoltageAverage() / VBAT_CELL_COUNT;
  const Battery& battery = getBattery();
  int newState;
  if (vBatCell > battery.vRecovery) {
    newState = HIGH;
  } else if (vBatCell < battery.vCritical) {
    newState = LOW;
  } else {
    newState = lastState;
  }

  if (newState != lastState) {
    digitalWrite(POWER_ENABLE_PIN, newState);
    lastState = newState;
    #ifdef POWER_SWITCH_LOG
      batteryStateLog();
      if (newState == HIGH) {
        logLn("power turned on");
      } else {
        logLn("power turned off");
      }
    #endif
  }
}
