#ifndef LTC294X_INTERNAL_H
#define LTC294X_INTERNAL_H

enum Ltc294xRegister {
  STATUS                      = 0x00, // R
  CONTROL                     = 0x01, // R/W
  ACCUMULATED_CHARGE          = 0x02, // R/W
  CHARGE_THRESHOLD_HIGH       = 0x04, // R/W
  CHARGE_THRESHOLD_LOW        = 0x06, // R/W
  VOLTAGE                     = 0x08, // R, LTC2942 only
  VOLTAGE_THRESHOLD_HIGH      = 0x0A, // R/W, LTC2942 only
  VOLTAGE_THRESHOLD_LOW       = 0x0B, // R/W, LTC2942 only
  TEMPERATURE                 = 0x0C, // R, LTC2942 only
  TEMPERATURE_THRESHOLD_HIGH  = 0x0E, // R/W, LTC2942 only
  TEMPERATURE_THRESHOLD_LOW   = 0x0F, // R/W, LTC2942 only
  INVALID                     = 0xFF
};

// These must match driver settings in /boot/config.txt
#define RSENSE 50
#define QLSB ((85 * 50000) / RSENSE)

static inline int convert_bin_to_uAh(int Q) {
	return ((Q * (QLSB / 10))) / 100;
}

static inline int convert_uAh_to_bin(int x) {
  return (x * 100) / (QLSB / 10);
}

#endif // LTC294X_INTERNAL_H