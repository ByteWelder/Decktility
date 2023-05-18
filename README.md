# Decktility

Decktility is a handheld PC, inspired by [Yarh.io Micro 2](https://yarh.io/) and [uConsole](https://www.clockworkpi.com/uconsole).

It is built with a Raspbery Pi CM4 and BigTreeTech Pad 5, and has about 6 hours of battery life.

![Decktility device mockup](docs/pics/decktility.jpg)

![Decktility device mockup](docs/pics/decktility-internals.png)

# Project status

This project is in **beta**. Upcoming changes:

- M2 heat insert nuts are being replaced (`3.5 x 3 mm` to `3.2 x 2 mm`)
- Electronics plateau lowered from `3 mm` to `2 mm` to create more space for wiring.
- Electronics plateau improvements for new FET setup
- Battery status kernel driver support

# Features

- Compact design: `124.4 x 144.0 x 16.3 mm` (w x h x d). The battery lid portrudes by `10.2 mm`.
- Weighs approximately `375 g`. (depends on filament weight)
- Powered by a Raspberry Pi CM4 and a BTT Pad 5 (`800x480` resolution with capacitive touch)
- Replaceable batteries, for when `6 h` of battery life isn't enough. (\*)
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

The power manager measures battery and charging status, and can send it over I2C to the Pi. (note: there is an issue with the latest power fet changes, so I2C support is WIP)

The project can be opened and built with Arduino IDE v2 from [Arduino.cc](https://www.arduino.cc/).

# Case

The case is available as open hardware via [OnShape]
- [Beta v0.6](https://cad.onshape.com/documents/bcf3b5212bb2ba6496cfe6cf/v/9458e81329733e3846e63f3d/e/4a5e1b73d1adb9b17f2035b1)
- [Main/WIP](https://cad.onshape.com/documents/bcf3b5212bb2ba6496cfe6cf/w/d70be68a60b4c80f684ba746/e/f2fb47dfa2dbdc91d7666ed1)

**Warning**: Don't print from the Main branch, because it will possibly have unfinished and/or untested changes.

STL and STEP files will be posted on GitHub when I've worked out the last few issues. Meanwhile, you can export them directly from OnShape by right-clicking on the parts and chosing "Export".

# Building

Considering the project is in beta status, I advise you to wait a bit until it is in a more stable state. Some components and designs are expected to change.
I store the major changes of the project in OnShape as different versions, so you should have a reference when major changes occur.

This project comes with no warranty. I take no responsibility whatsoever. Build this project at your own risk.

- [Bill of materials](docs/bom.md)
- [Printing guide](docs/printing.md)
- [Assembling](docs/assembling.md)

# License

All hardware, software and other content in this project are licensed under `Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)`.

See [LICENSE.md](LICENSE.md) for details. For a short overview and translations go to the [Creative Commons website](https://creativecommons.org/licenses/by-sa/4.0/legalcode).

