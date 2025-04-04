## TASK 1 simulating a neutron Velocity_selector:

Instrumentfile: [Ex_selector.instr](Ex_selector.instr)

![Look around](pics/Vsel_1.png)

![Simulation tasks](pics/Vsel_2.png)


## TASK 2 improve the instrument file:
### Given that:

![Analytical consideration](pics/Vsel_3.png)

### RESULT: Please form an expression of selector frequency as function of desired wavelength $f(\lambda)$ - may be used in Bonus task 3 below.
<hr>

## BONUS TASK 3 (or DEMO): Implement result from TASK 2 for futher work
* Exchange the instrument input-parameter `f` for a `lambda` (add a default of e.g. 6Å)
* In the `DECLARE` section, uncomment the `// double f;` -> `double f;`
* Add your equation in c-code under `INITIALIZE`

**RESULT: Save this instrument file for further work on Tuesday**
<hr>

## BONUS TASK 4 (or DEMO): Data analysis in NeXpy
* On the run dialogue in mcgui, select `Output format: NeXus -c` (-c means recompile to ensure format is supported) and run a simulation
* Plot and NeXpy should appear:
![NeXpy](pics/nexpy.png)
* Expand the tree structure `mccode->data->LmonVel_dat`
* Double-click `data` inside and select `Axis 0` to be Wavelength in Å, a plot should appear:
![NeXpy-plot](pics/nexpy-plot.png)
* Clicking the `y` tab will give access to the `Fit` button, and pressing will bring up a new small window:
![NeXpy-fit](pics/nexpy-fit.png)
* Add a Gaussian Model, `Fit`, `Plot Model` and `Show Fit Report`
![NeXpy-fit-data](pics/nexpy-fit-data.png)
![NeXpy-fit-plot](pics/nexpy-fit-plot.png)
![NeXpy-fit-report](pics/nexpy-fit-report.png)
(For those thinking a Gaussian is not a correct model in this case, this is correct. The v-selector transmission is in fact triangular ;-))

**Hint:** If you `save` your fits or parameters, these will become available in the left pane of NeXpy and can be saved by using a right-click menu point

