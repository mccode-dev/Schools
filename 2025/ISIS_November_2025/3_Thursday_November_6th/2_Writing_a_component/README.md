# Recipe for writing a perfect mirror

### Initial component naming update
* Copy the enclosed [```Arm.comp```](Arm.comp) to the local workdir, rename to ```Mirror_simple.comp```
* Edit the file changing all instances of Arm to Mirror_simple
### Add input parameters for geometry
* Add ```SETTING PARAMETERS``` for geometry, e.g. ```yheight``` and ```zlength```
* In ```INITIALIZE``` check that the new parameters are > 0
### Add propagation and checks
* In ```TRACE```, do a ```PROP_X0``` to move the neutron to the mirror plane
* if-statement checking that the neutron is inside the z-y ranges, otherwise ```RESTORE_NEUTRON```
### Mirror the neutron
* Neutrons inside mirror bounds receive a flip the sign of vx and ```SCATTER```
### Draw the compnent in mcdisplay
* Add a rectangle() on the y-z plane in the ```DISPLAY``` section to
  show the mirror (for inspiration look in `Pol_mirror`
### Add the mirror in an minimal instr and do a 1st run
* Try using the mirror in an instrument
### Add physics!
* Add a scalar reflectivity ```r0``` as a  ```SETTING PARAMETERS```
* Do a MC choice with ```rand01``` in the ```TRACE``` section to see
  if we are below ```r0```, otherwise transmit
### Integrate in test instrument:
* Build a test instrument with:
   1. a source
   1. a mirror (your compoenent)
   1. two detectors - one catching the reflected beam, one catching the trasnmitted
* Try out your mirror to confirm the it works.
### Add biasing for reflection/transmission
* Add another  ```SETTING PARAMETERS```: fraction. We will use this to govern Monte Carlo statistics in the reflected and transmitted branches.
1
