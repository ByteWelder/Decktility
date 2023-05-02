#include <Wire.h>
#include "log.h"
#include "batterystate.h"
#include "chargestate.h"
#include "powerswitch.h"

enum RequestType {
  NONE = 0,
  VBAT = 1,
  CHARGE_STATE = 2
};

enum RequestType requestType = NONE;

void setup() {
  logInit();
  log("Init ... ");

  Wire.begin(I2C_ADDRESS);
  Wire.onRequest(onRequestEvent);
  Wire.onReceive(onReceiveEvent);

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

void onRequestEvent() {
  RequestType type = requestType; // copy for thread-safety
  switch (type) {
    case VBAT: {
      float vbat = batteryStateGetVoltageAverage();
      Wire.write((byte*)&vbat, sizeof(float));
      logLn("responded to vbat request");
      break;
    }
    
    case CHARGE_STATE: {
      uint8_t charging = chargeState() ? 1 : 0;
      Wire.write(charging);
      logLn("responded to charging request");
      break;
    }
    
    default: {
      log("unkown request: ");
      logLn(requestType);
    }
  }
}

void onReceiveEvent(size_t size) {
  static uint8_t buffer[32];
  Wire.readBytes(buffer, size);

  size_t expected = 4; // request is 2 bytes of protocol info
  uint8_t header = 42; // 3rd byte is a header with constant value
  if (size == expected && buffer[2] == header) {
    log("received request type ");
    logLn(buffer[3]); // 4th byte is request type
    requestType = (RequestType)buffer[3];
  }
}
