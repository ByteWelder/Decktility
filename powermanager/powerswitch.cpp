#include <Arduino.h>
#include "powerswitch.h"
#include "config.h"
#include "batterystate.h"
#include "log.h"

int lastState = LOW;

void powerSwitchInit() {
  pinMode(POWER_ENABLE_PIN, OUTPUT);
  digitalWrite(POWER_ENABLE_PIN, LOW);
}

void powerSwitchUpdate() {
  float vbat = batteryStateGetVoltageAverage();
  int newState;
  if (vbat > VBAT_TURN_ON) {
    newState = HIGH;
  } else if (vbat < VBAT_TURN_OFF) {
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
