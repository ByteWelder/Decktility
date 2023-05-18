#ifndef BATTERY_H
#define BATTERY_H

#include <Arduino.h>

#define BATTERY_GRAPH_SEGMENTS 6

struct BatteryGraphSegment {
  uint16_t fromC; // capacity
  float fromV; // voltage
  uint16_t toC; // capacity
  float toV; // voltage
};

struct Battery {
  uint16_t capacity; // mAh
  float vMax; // maximum cell voltage (typically 4.2)
  float vCritical; // critical cell voltage: turn off device below this value
  float vRecovery; // minimal safe cell voltage to start using after power off
  BatteryGraphSegment graph[BATTERY_GRAPH_SEGMENTS];
};

extern const Battery murata3120Vtc6;

extern void setBattery(const Battery& battery);
extern const Battery& getBattery();

extern uint16_t getEstimatedBatteryCapacity(float cellVoltage);

#endif // BATTERY_H
