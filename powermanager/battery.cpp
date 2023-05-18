#include "battery.h"

const Battery murata3120Vtc6 = {
  .capacity = 3120,
  .vMax = 4.2f,
  .vCritical = 3.2f,
  .vRecovery = 3.35f,
  // Estimated discharge graph
  // based on https://www.murata.com/-/media/webrenewal/products/batteries/cylindrical/datasheet/us18650vtc6-product-datasheet.ashx?la=en-us&cvid=20220207015421000000
  .graph = {
    { .fromC = 0,     .fromV = 4.20f,   .toC = 0,     .toV = 4.15f  },
    { .fromC = 0,     .fromV = 4.15f,   .toC = 620,   .toV = 4.00f  },
    { .fromC = 620,   .fromV = 4.00f,   .toC = 940,   .toV = 3.90f  },
    { .fromC = 940,   .fromV = 3.90f,   .toC = 2400,  .toV = 3.42f  },
    { .fromC = 2400,  .fromV = 3.42f,   .toC = 2730,  .toV = 3.20f  },
    { .fromC = 2730,  .fromV = 3.20f,   .toC = 3120,  .toV = 2.50f  }
  }
};

const Battery& battery = murata3120Vtc6;

void setBattery(const Battery& newBattery) {
  battery = newBattery;
}
const Battery& getBattery() {
  return battery;
}

uint16_t getEstimatedBatteryCapacity(float cellVoltage) {
  for (int i=0; i < BATTERY_GRAPH_SEGMENTS; ++i) {
    const BatteryGraphSegment& segment = battery.graph[i];
    if (cellVoltage >= segment.fromV && i == 0) {
      return battery.capacity;
    } else if (cellVoltage <= segment.fromV && cellVoltage >= segment.toV) {
      float voltageFactor = 1.f - (segment.toV - cellVoltage) /
        (segment.toV - segment.fromV);
      float capacityUsed = (float)segment.fromC +
        (voltageFactor * (float)(segment.toC - segment.fromC));
      return battery.capacity - (uint16_t)capacityUsed;
    }
  }

  return 0;
}
