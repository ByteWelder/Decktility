# Bill of materials for Decktility

I ordered many of the components from AliExpress.
Make sure to double-check that you're ordering the correct item.

- BigTreeTech Pad 5
- Raspberry Pi CM4
- Arduino Nano V3.0
- `5 V` `3 A` step down converter like [this](pics/step-down-top.jpg)
- USB-C 2S battery charger/BMS like [this](pics/usb-c-bms.jpg)
- BlueTooth mini keyboard like [this](pics/bluetooth-keyboard.jpg) (needs modding, see build guide)
- 2x 18650 battery. **Must** be capable of `1.5 A` charge current. For example: `US18650VTC6`
- 4x Spring steel 18650 leaf spring battery contact like this [this](pics/battery-contacts.jpg)
- 50x M2 heat insert nut (`2 mm` high, `3.2 mm` wide) (you don't need 50, but you might need more than a single set in case of a failed print)
- 10x M1.4 2mm self-tapping screw (it's best to get a set with various sizes, because printing tolerances vary)
- A set of watch maker screws of various sizes (M1.0, M1.2, M1.4, etc.)
- 4x M2.5 4mm (button or flat head) for Pad 5 mounting (there are cheap sets with M2-M2.5-M3 screws out there)
- 2006 5V fan (`20 x 6 mm`)
- Electrical wire: 24 AWG for power and 28 AWG for silicon. (silicon, not plastic)
- SS12F15 mini slide switch
- Electronic switch control board (see below)
- Experiment PCB
- (optional) Elastic jewelry wire, 1mm, transparent ('optical fiber' to wire USB charger LEDs to case)
- (optional) JST-SH male and female plugs (for easy detaching I2C wires during development)
- Other things like soldering gear, 3D printer.

## Electronic switch control board

I used a [module](pics/fet-module.jpg) that you can find on AliExpress/Amazon. The module itself is too large, 
so it needed to be transplanted onto an experiment board.
You could either buy such a module and transplant the components, or you can buy the components individually.

Check the assembly guide for the schematics.

