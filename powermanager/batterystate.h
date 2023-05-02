#ifndef BATTERYSTATE_H
#define BATTERYSTATE_H

extern void batteryStateInit();
extern void batteryStateUpdate();
extern float batteryStateGetVoltageAverage();
extern float batteryStateGetVoltageNow();
extern void batteryStateLog();

#endif // BATTERYSTATE_H