#ifndef CONFIG_H
#define CONFIG_H

#define I2C_ADDRESS 0x64

#define VBAT_ADC_PIN A0
// Tweak with PSU. See when analog input becomes 1023.
#define VBAT_ADC_MAX_READABLE_PIN_VOLTAGE 4.1f
// Measured between 2 resistors when input voltage is at max (e.g. 8.4V)
#define VBAT_ADC_MAX_BATTERY_PIN_VOLTAGE 3.05f // 0.03
#define VBAT_ADC_MAX_BATTERY_REAL_VOLTAGE 8.4f
#define VBAT_CELL_COUNT 2

#define CHARGE_STATE_PIN 2

#define POWER_ENABLE_PIN 3

#define DEBUG
// #define BATTERY_STATE_LOG
#define CHARGE_STATE_LOG
#define POWER_SWITCH_LOG
// #define I2C_LOG

#endif