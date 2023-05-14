# Assembling Decktility

## Power Manager / Arduino Nano

You can build the project with `Arduino IDE V2`. Change `config.h` to your liking.

The default pins are as follows:
- `Vbat` is measured at pin `A0`.
- Charge state is measured at pin `D2`. It connects to the LED connector on the USB-C BMS board. This is marked as `LED` on the back or `D` on the front of the PCB.
- The power enable pin for the mosfet is wired to `D3`.
- `Vin` and `Gnd` are wired to the common ground and to the switch that connects to the `5 V` of the step down converter.

## Keyboard mod

The keyboard comes with a Lithium battery installed, but I needed it to work with `5 V`.
I copied the idea from [Yarh.io](https://yarh.io/yarh-io-m2.html), but I'll elaborate on it here.

- Desolder the lipo.
- Desolder the USB connector. I ended up cutting it off entirely, including the PCB part under it that sticks out.
- Connect the `5 V` pad from the USB connector to the `+` connector where the lipo was. You can use the pad of the USB connector, but I found it easier to solder directly to the top of `R20`.
- Desolder and remove `U6`. The 2 pads on the bottom right should be soldered together.

![keyboard PCB modded](pics/keyboard-mod.jpg)

## Mosfet module mod

If you are not trying the (untested) alternative [mosfet module](mosfet-alternative.jpg) then you must double up on the `100 R` and `4.7 kR` resistors.
I soldered them on top of the existing ones as encircled in blue:

![mosfet module resistor locations](pics/mosfet-modded.jpg)

Note: This mosfet setup (N fet)  makes it impossible to also connect the I2C pins from the Arduino to the Pi. Do **not** connect these in this scenario.

## Heat inserts

Insert heat inserts:

- In the case
- To the sides of the keyboard top panel
- On the top of the battery container 
