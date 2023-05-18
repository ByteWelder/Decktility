#include "log.h"
#include "batterystate.h"
#include "chargestate.h"
#include "powerswitch.h"
#include "ltc294x.h"


void setup() {
  logInit();
  log("Init ... ");

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
