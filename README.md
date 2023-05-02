# Decktility

A custom-built cyberdeck, inspired by various handheld PCs and palmtops, but especially by [Yarh.io Micro 2](https://yarh.io/).

# Software

## Raspberry Pi

The Pi can be given the OS of your chosing. Consider [Raspberry Pi OS](https://www.raspberrypi.com/software/) or [Kali](https://www.kali.org/docs/arm/raspberry-pi-4/).

The [Power Manager Client](./powermanager-client) is used to communicate charging status and battery status to the Arduino Nano. This info can be used to show warnings or even auto-shutdown the Pi.

## Arduino Nano / Power Manager

The [Power Manager](./powermanager) controls the power connection to the Pi and the keyboard. Power is enabled/disabled depending on the battery voltage.

The power manager measures battery and charging status, and can send it over I2C to the Pi.

# Bill of materials

The links are mainly to search results, as links to specific items tend to fail as shops update their stock.
Make sure to double-check that you're ordering the correct item.

- BigTreeTech Pad 5
- Raspberry Pi CM4 (the model of your choice)
- Arduino Nano (or clone)
- Electronic Switch Control Board (e.g. F5305S PMOS Trigger Module on [AliExpress](https://www.aliexpress.com/w/wholesale-F5305S-PMOS-Trigger-Module.html?catId=0&SearchText=F5305S+PMOS+Trigger+Module))
- 5V 3A step down converter ([AliExpress](https://www.aliexpress.com/w/wholesale-3A-Mini-Step-Down-Converter-Board.html?catId=0&SearchText=3A+Mini+Step+Down+Converter+Board))
- USB C 2S battery charger/BMS ([AliExpress](https://www.aliexpress.com/w/wholesale-Type%2525252dC-USB-2%252F3S-BMS-15W.html?catId=0&origin=y&SearchText=Type-C+USB+2%2F3S+BMS+15W+))
- BlueTooth mini keyboard with 49 keys ([AliExpress](https://www.aliexpress.com/w/wholesale-bluetooth-mini-keyboard-49-keys.html?catId=0&SearchText=bluetooth+mini+keyboard+49+keys))
- 2x 18650 battery (`1.5 A` charge current, e.g. `US18650VTC6`)
- 18650 2S battery holder ([AliExpress](https://www.aliexpress.com/w/wholesale-Type%2525252dC-USB-2%252F3S-BMS-15W.html?catId=0&origin=y&SearchText=Type-C+USB+2%2F3S+BMS+15W+))
