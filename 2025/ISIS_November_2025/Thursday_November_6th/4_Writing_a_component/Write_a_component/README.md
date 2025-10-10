# Recipe for writing a perfect mirror

* Copy ```Arm.comp``` from ```$MCSTAS/optics``` to the local workdir, rename to ```Mirror_simple.comp```
* Edit the file changing all instances of Arm to Mirror_simple
* Add ```SETTING PARAMETERS``` for geometry, e.g. ```yheight``` and ```zlength```
* In ```INITIALIZE``` check that the new parameters are > 0
* In ```TRACE```, do a ```PROP_X0``` to move the neutron to the mirror plane
* if-statement checking that the neutron is inside the z-y ranges, otherwise ```RESTORE_NEUTRON```
* Flip the sign of vx and ```SCATTER```
* Add a rectangle on the y-z plane in the ```DISPLAY``` section to show the mirror 
* Try using the mirror in an instrument
* Add a scalar reflectivity ```r0``` as a  ```SETTING PARAMETERS```
* Do a MC choice with ```rand01``` in the ```TRACE``` section to see if we are below ```r0```, otherwise transmit
* Build a test instrument with:
   1. a source
   1. a mirror (your compoenent)
   1. two detectors - one catching the reflected beam, one catching the trasnmitted
* Try out your mirror to confirm the it works.
* Add another  ```SETTING PARAMETERS```: fraction. We will use this to govern Monte Carlo statistics in the reflected and transmitted branches.
