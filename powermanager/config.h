#ifndef CONFIG_H
#define CONFIG_H

#define I2C_ADDRESS 0x64

#define VBAT_ADC_PIN A0
// Tweak with PSU. See when analog input becomes 1023.
#define VBAT_ADC_MAX_READABLE_PIN_VOLTAGE 4.1f
// Measured between 2 resistors when input voltage is at max (e.g. 8.4V)
#define VBAT_ADC_MAX_BATTERY_PIN_VOLTAGE 3.05f // 0.03
#define VBAT_ADC_MAX_BATTERY_REAL_VOLTAGE 8.4f

#define VBAT_TURN_OFF 6.6f // min 3.3V per cell when disabling power
#define VBAT_TURN_ON 6.9f // min 3.45V per cell before enabling power

#define CHARGE_STATE_PIN 2

#define POWER_ENABLE_PIN 3

#define DEBUG
#define BATTERY_STATE_LOG
#define CHARGE_STATE_LOG
#define POWER_SWITCH_LOG

#endif