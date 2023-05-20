# Printing Guidelines for Decktility

The settings below are based on what I used in SuperSlicer (~PrusaSlicer).
They might (not) translate to other slicer software.

If you don't own a 3D printer yourself, you can use an [online service](https://duckduckgo.com/?t=ffab&q=online+3d+printing+service&ia=web).

The parts can be found in the [printables folder](../printables).

## Filament

If your 3D printer does not have an enclosure, use PETG or PCTG.
I prefer using ASA (with ABS/ABS+ as alternative).

Avoid using PLA or other similar low-temperature filaments:
The BMS can get hot (`45 C`, measured outside the case).
There is active cooling, but if the fan is defect, it might heat up the plastic and warp it.

## Printing

Some parts are exported from CAD upside-down and need to be flipped `180 degrees`.

You can print with layer height of `0.2 mm` or finer and a `0.4 mm` nozzle.

### PCB Bracket

Print in normal orientation with build plate supports.

### Battery Cover

Rotate it 90 degrees over the Y axis so it stands up on its side.
You need supports along the edge on this inside.
I painted them on manually, because they get attached to the inner wall.
Alternatively, you can use `Supports: Everywhere`.

Make sure you clean up the inside thoroughly, so it fits on the case.

### Main Case

Note that the walls are relatively thin and weaken the case near connector holes.
This means that your wall adhesion has to be good. Ensure you're running your filament at a high enough
temperature for the speed you're printing at. If you calibrated your filament to work at a minimum
tempearture, you might have to raise it to create sufficient strength.

Consider changing the the top layer fill patern to `Concentric`. This will give you smoother top surface quality,
both for mounting components and for the top edge of the case.

When printing the main case with ASA, I slice with manually added supports only. I place these supports at:
- The counterbores on the back (the ones for mounting the display)
- The ethernet bridging part
- The Pi's IO connector on the back

When printing with ASA, disable bridging fan speed to avoid adhesion problems near the connector openings.
Otherwise, layers might split off when placing the display into the case.

