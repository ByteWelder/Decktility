# Decktility

A custom-built cyberdeck, inspired by various handheld PCs and palmtops, but especially by [Yarh.io Micro 2](https://yarh.io/).

Project status: alpha

![Decktility device mockup](decktility.png)

![Decktility device mockup](decktility-back.png)

![Decktility device mockup](decktility-internals.png)

# Features

- Compact design: `124.4 mm` width, `144.0 mm` height, `16.1 mm` depth
- Powered by a Raspberry Pi CM4 and a BTT Pad 5 (`800x480` resolution with capacitive touch)
- Replaceable batteries
- About `20 h` of battery life (\*)
- USB-C charging
- Power management (reports to the Pi and refuses to turn on when battery is critically low)

(\*) Using US18650VTC6 cells. Power draw was tested with an idle Discord tab in Chrome.

# Software

## Raspberry Pi

The Pi can be given the OS of your chosing. Consider [Raspberry Pi OS](https://www.raspberrypi.com/software/) or [Kali](https://www.kali.org/docs/arm/raspberry-pi-4/).

Check the to the [Pad 5 Manual](https://github.com/bigtreetech/Raspberry-Pad/tree/master/Pad5) for installing the OS and setting up some of the hardware.

The [Power Manager Client](./powermanager-client) is used to communicate charging status and battery status to the Arduino Nano. This info can be used to show warnings or even auto-shutdown the Pi.

## Arduino Nano / Power Manager

The [Power Manager](./powermanager) controls the power connection to the Pi and the keyboard. Power is enabled/disabled depending on the battery voltage.

The power manager measures battery and charging status, and can send it over I2C to the Pi.

The project can be opened and built with Arduino IDE v2 from [Arduino.cc](https://www.arduino.cc/).

# Case

The case is available as open hardware via [OnShape](https://cad.onshape.com/documents/bcf3b5212bb2ba6496cfe6cf/w/d70be68a60b4c80f684ba746/e/f2fb47dfa2dbdc91d7666ed1).

# Bill of materials

The links are mainly to search results, as links to specific items tend to fail as shops update their stock.
Make sure to double-check that you're ordering the correct item.

- BigTreeTech Pad 5
- Raspberry Pi CM4
- Arduino Nano V3.0 with USB-C connector
- Electronic Switch Control Board (e.g. FLR784 mosfet module on [AliExpress](https://www.aliexpress.com/w/wholesale-LR784-mosfet-module.html?catId=0&SearchText=LR784+mosfet+module))
- `5 V` `3 A` step down converter, adjustable ([AliExpress](https://www.aliexpress.com/w/wholesale-5v-3a-step-down-12%2525252d20v.html?catId=0&SearchText=5v+3a+step+down+12-20v))
- USB-C 2S battery charger/BMS ([AliExpress](https://www.aliexpress.com/w/wholesale-Type%2525252dC-USB-2%252F3S-BMS-15W.html?catId=0&origin=y&SearchText=Type-C+USB+2%2F3S+BMS+15W+))
- BlueTooth mini keyboard with 49 keys ([AliExpress](https://www.aliexpress.com/w/wholesale-bluetooth-mini-keyboard-49-keys.html?catId=0&SearchText=bluetooth+mini+keyboard+49+keys))
- 2x 18650 battery (`1.5 A` charge current, e.g. `US18650VTC6`)
- 4x Spring steel 18650 leaf spring battery contact
- 11x M2 insert nut (`3 mm` high, `3.5 mm` wide)
- 10x M1.4 3mm button head screw
- ?x M2 screws of various sizes (TBD)
- ?x M3 screws of various sizes (TBD)
- Double-sided tape (about `1 mm` thick) to secure the BEC PCB. (e.g. 3M VHB tape)
- 2006 5V fan (`20 x 6 mm`)
- Other things like wire, soldering gear, 3D printer.

# License

All hardware, software and other content in this project are licensed under `Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)`.

See [LICENSE.md](LICENSE.md) for details. For a short overview and translations go to the [Creative Commons website](https://creativecommons.org/licenses/by-sa/4.0/legalcode).

