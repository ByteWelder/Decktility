# Decktility

Decktility is a handheld PC, inspired by [Yarh.io Micro 2](https://yarh.io/) and [uConsole](https://www.clockworkpi.com/uconsole).

It is built with a Raspbery Pi CM4 and BigTreeTech Pad 5, and has about 6 hours of battery life.

![Decktility device mockup](docs/pics/decktility.jpg)

![Decktility device mockup](docs/pics/decktility-internals.png)

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

The power manager measures battery and charging status, and can send it over I2C to the Pi. This enables battery status on the Pi desktop.

The project can be opened and built with Arduino IDE v2 from [Arduino.cc](https://www.arduino.cc/).

# Case

The case is available as open hardware via [OnShape]
- [v1.0](https://cad.onshape.com/documents/bcf3b5212bb2ba6496cfe6cf/v/bb9262cb0caf4859bc4bdf05/e/c5b400bc9f33c73249dce75b)
- [Main/WIP](https://cad.onshape.com/documents/bcf3b5212bb2ba6496cfe6cf/w/d70be68a60b4c80f684ba746/e/f2fb47dfa2dbdc91d7666ed1)

**Warning**: Don't print from the Main branch, because it will possibly have unfinished and/or untested changes.

STL and STEP files will be posted on GitHub when I've worked out the last few issues. Meanwhile, you can export them directly from OnShape by right-clicking on the parts and chosing "Export".

# Building

This project comes with no warranty. I take no responsibility whatsoever. Build this project at your own risk.
A detailed wiring schematic will be published soon, and the assembly guide is expected to improve still.

- [Bill of materials](docs/bom.md)
- [Printing guide](docs/printing.md)
- [Assembling](docs/assembling.md)

# License

All hardware, software and other content in this project are licensed under `Attribution-ShareAlike 4.0 International (CC BY-SA 4.0)`.

See [LICENSE.md](LICENSE.md) for details. For a short overview and translations go to the [Creative Commons website](https://creativecommons.org/licenses/by-sa/4.0/legalcode).

