# Introduction exercise to Sources and Monitors

The purpose of this exercise is simply to get familiar with the concepts of Source and Monitors in McStas.
We will insert a source and two monitors and then modify these to examine some internal properties.

## Exercise 1: First source and monitors.
1. Start a new instrument simulation and insert a circular source ( Source_simple with radius != 0 ) in the trace section, to emit neutrons with wavelengths in the interval lamdba=[1 8] AA. Focus the sampling at a rectangle downstream.
2. Insert a PSD_monitor and a L_monitor at the same position as the focusing rectangle. Make sure they capture the full radiation of the source. Do you see what you expected? It should look something like this:
![First Results mcplot](images/2_sources_and_monitors_1st.png?raw=true "")

## Variations on the starting point
3. Move the PSD_monitor up close to the source. What happens to the spatial distribution?
4. Add the parmeter "gauss=1" to the source and see what happens.
5. Now change the source to be of the type Source_div. This also implies replacing the "focus_xw", "focus_yh", and "dist" parameter with the angular focusing parameters: "focus_ah" and "focus_aw".
6. Try to switch "gauss" off, to see what happens.

## Exercise 2: More Monitors

1. Start a new ionstrument file, named ‘sources_monitors_ex.instr’.
   HINT: you can use the ‘template.instr’ file that exists in today’s class folder and you can open it with the editor of your liking, or open it from the McStas gui by clicking: File —> New (python)
1. Add a source using the Source\_Maxwell\_3.comp component, with:  
    - source dimensions: (w)0.132m X (h)0.164m  
    - distance to target : 1.5 m  
    - focus area: (w)0.03m X (h)0.12m  
    - wavelength range: 0.1Å to 9.9Å  
    - T1=27.63[K], I1=2.4E12 [n/s/cm2/st/AA], T2=130.76[K],  
    - I2=4.03E12[n/s/cm2/st/AA] ,T3=309.33[K], I3=1.24E13[n/s/cm2/st/AA]  
1. Add the following monitors at two different distances from the source, at 1.5m and 4.5m:
    - PSD monitor (PSD_monitor)  
    - A linear PSD monitor for the y-direction (PSDlin_monitor)  
    - Wavelength monitor (L_monitor)  
    - 2D Divergence monitor (Divergence_monitor)  
    - Divergence-position monitor for the x-direction (DivPos_monitor)  
1. Try to replace the monitors by Monitor_nD-instances. You will need to use `mcdoc Monitor_nD` for this.
2. Try to change your source into a pulsed source, for instance by adding an EXTEND block to your source where you set the neutron clock to something known. Then add two (or more) TOF_monitors and check the behaviour of you neutron beam - does it work as you expected?
