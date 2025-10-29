# Solutions for thermal time of flight diffractometer

### Exercise part 1
Since the source emits a broad wavelength range and the speed of a neutron depend on its wavelength, neutrons of different wavelengths will arrive at different times. They spread out in time over distance.

### Exercise part 2
There is indeed overlap between the two pulses at 160 m from the source.

### Exercise part 3
The largest possible wavelength band without overlap is,
$$\Delta \lambda = \frac{T}{\alpha L} = \frac{1}{\alpha L f} = \frac{1}{252.7 \mu \text{s} / \text{m} / Å \cdot 160 \text{m} \cdot 14 \text{Hz}} = 1.77 Å. $$

Regardless of where the wavelength band starts, overlap is avoided since the neutron speed is inversely proportional to the wavelength.

### Exercise part 4
The signal in the time of flight cylinder monitor can be explained by the constant q scattering of the sample, meaning the scattering angle will depend on wavelength.

Note that some wavelength overlap is seen, as now the detector is effectively 161 m from the source (when the neutrons scatter in a point like sample), the wavelength band can be adjusted accordingly.

With the small TOF detector at $2\theta = 90$ my simulations resulted in a peak at $t=7.42\cdot 10^4 \mu s$ with a width of $dt=8.27\cdot 10^2 \mu s$.

Since the long pulse starts at $t=0$, it is reasonable to subtract half the pulse length from the measured time, 1.43 ms.

To calculate the measured q we combine the equations from the theory chapter. 

$$t=\alpha \lambda L$$
$$q = 2k_i \text{sin}(\theta) = \frac{4\pi}{\lambda}\text{sin}(\theta)$$

$$q=\frac{4\pi\alpha L}{t}\text{sin}(\theta) = \frac{4\pi\alpha\cdot 161 \text{m}}{7.42\cdot 10^4 \mu \text{s} - 1.43 \text{ms}}\text{sin}(45^\circ) = 4.96 Å^{-1}$$

To calculate the $q$ uncertainty, $dq$, we use propagation of uncertainty on the above formula. Here the time corrected for the pulse width is considered the variable t to simplify the calculation.

$$ dq = \sqrt{ \left(\frac{\partial q}{\partial t}\right)^2 dt^2} = \sqrt{ \left(- \frac{4\pi\alpha L}{t^2} \text{sin}(\theta)\right)^2 dt^2} = 0.056 Å ^{-1}$$

Thus resulting in a $dq/q\approx 1.1$%, which is too large for powder experiments.

### Exercise part 5
The measured time and resulting resolution is shown for the different instrument configurations.


| Instrument                      | Measured t             | Peak dt                | $q$           | $dq$            | $dq/q$  |
| ------------------------------- | ---------------------- | ---------------------- | ------------- | --------------- | ------- |
| No chopper                      | $7.42\cdot 10^4 \mu s$ | $8.27\cdot 10^2 \mu s$ | 4.97 Å$^{-1}$ | 0.056 Å$^{-1}$  | 1.1 %   |
| Chopper 14 Hz                   | $7.35\cdot 10^4 \mu s$ | $3.57\cdot 10^2 \mu s$ | 5.02 Å$^{-1}$ | 0.0248 Å$^{-1}$ | 0.5 %   |
| Chopper 28 Hz                   | $7.34\cdot 10^4 \mu s$ | $1.96\cdot 10^2 \mu s$ | 5.02 Å$^{-1}$ | 0.013 Å$^{-1}$  | 0.27 %  |
| Counter rotating choppers 28 Hz | $7.34\cdot 10^4 \mu s$ | $1.06\cdot 10^2 \mu s$ | 5.02 Å$^{-1}$ | 0.0074 Å$^{-1}$ | 0.14 %  |

The measured q value is close to what was simulated, but affected by statistical noise. Introducing the chopper, increasing the speed and introducing a counter rotating chopper all improves the resolution of the instrument.



