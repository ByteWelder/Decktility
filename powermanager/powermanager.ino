#include "log.h"
#include "batterystate.h"
#include "chargestate.h"
#include "powerswitch.h"
#include "ltc294x.h"
#include "battery.h"

void setup() {
  logInit();
  log("Init ... ");

  setBattery(murata3120Vtc6);

  ltc294xInit();
  batteryStateInit();
  chargeStateInit();
  powerSwitchInit();

  logLn("done");
  
  batteryStateLog();
}


void loop() {
  batteryStateUpdate();
  chargeStateUpdate();
  powerSwitchUpdate();

  delay(1000);
}
