# NeXus, Mantid exercises

The purpose of these exercises is simply to get familiar with the NeXus-oriented tools and workflows included in McStas.

## Exercise A: Compare and work with output data in McStas and NeXus format
1. Pick one or two of the provided [Mantid-oriented instruments](Mantid_example_instruments)
2. Generate output data in standard McStas format
3. Generate output in NeXus format
4. Use the 'plot' button with a NeXus output and inspect it using Nexpy
5. Try opening the file in Mantid (use `module load mantid` and `mantid` to get workbench running)
6. Does it make a difference if `--format=NeXus` or `--format=NeXus --IDF` is used? Does the first one load?

## Exercise B: Use the information from the lecture to add Mantid backend to templateSANS from the McStas examples
1. Add required component naming
2. Add a Monitor_nD with list mode and required naming
3. Generate output in NeXus format
4. Open the  the 'plot' button with a NeXus output and inspect it using Nexpy
5. Try opening the file in Mantid (use `module load mantid` and `mantid` to get workbench running)

## Exercise C: Use your required skilles to add Mantid type NeXus output to another instrument of choice
1. Like B but you decide the starting point

## Exercise D: Play with the McStasToX notebook
1. Work your way through the cells of the [McStasToX example notebook](../McStasToX) provided

