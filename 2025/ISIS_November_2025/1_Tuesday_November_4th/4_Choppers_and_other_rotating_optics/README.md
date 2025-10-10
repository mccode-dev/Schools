## TASK 1 - DiskChopper
Let's try to limit the wavelength band coming through the optics.
If you got that far you may use information from the last
part of the sources and monitor exercise.

## HINTS
* The guide has to be split into two segments to accommodate the chopper
* Use DiskChopper, but set is_first to 0
* Ensure the distance between source and chopper is known
* Use declare and initialize to calculate appropriate delay
* McStas has a constant called K2V that converts from wavevector to velocity

You _may_ cheat by looking at the solution file

### TASK2 - Velocity_selector
Replace the higher order suppressing chopper with a velocity selector which only
allows the deisred wavelength through.

### HINTS
* ```mcdoc V_selector```
* You may (mostly) use the default values coming from D11@ILL
* You will have to make more room for the velocity selector than for he chopper
* Declare extra variable(s) to be able to dynamically set the wavelength

