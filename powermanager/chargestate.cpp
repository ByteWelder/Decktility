#include <Arduino.h>
#include <stdbool.h>
#include "log.h"
#include "config.h"

bool isCharging = 0;

void chargeStateInit() {
  isCharging = false;
  pinMode(CHARGE_STATE_PIN, INPUT);
}

void chargeStateUpdate() {
  bool newState = digitalRead(CHARGE_STATE_PIN) == HIGH;

  if (newState != isCharging) {
    isCharging = newState;
    #ifdef CHARGE_STATE_LOG
      if (isCharging) {
        logLn("charging: yes");
      } else {
        logLn("charging: no");
      }
    #endif
  }
}

bool chargeState() {
  return isCharging;
}
