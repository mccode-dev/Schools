## TASK 1 - DiskChopper
The instrument file [Exercise_chopper.instr](Exercise_chopper.instr)
contains your starting point, an instrument with:
* A `Source_simple` 
* A `Guide_gravity`
* A set of monitors:
  - a `PSD_monitor`, a `Divergence_monitor` and an `L_monitor`

Your task is to
1) add a 120 Hz DiskChopper at 4.5 m from the source with parameters:
* Single-slit chopper, slit opening 2 degrees
* `radius=0.45` m
* `yheight=0.08`
* `isfirst=1` (we are using a "steady state source")

2) Calculate the correct chopper delay (phase) for centering the
DiskChopper slit on the wavelength `L_target

## HINTS
* Split the guide into two segments, accommodating a chopper housing
  of 10 cm.
* Use the variables in DECLARE  and INITIALIZE to calculate appropriate phase / delay of
  the chopper.
* McStas has a constant called K2V that converts from wavevector to velocity

You _may_ cheat by looking at the solution file
