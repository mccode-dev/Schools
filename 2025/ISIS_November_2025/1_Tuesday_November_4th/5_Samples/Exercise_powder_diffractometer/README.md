# Time of flight powder diffractometer
This is a longer exercise where we construct a time of flight powder diffractometer. It is based on an exercise for NIDS 2011 by Kim Lefmann and Linda Udby.

## Theory
In a diffractometer it is assumed that all scattering is elastic, meaning the speed of the neutron is constant before and after scattering in the sample. A neutron count in a detector at a given position and time must then be traced back to another known time and position, for example the pulse of a source or a chopper opening. The path length L, the neutron wavelength and time of flight is related with:

$$t=\alpha \lambda L$$

Where $~\alpha $ is a constant,    $\alpha = m_n/h \approx 252.7 \mu \textrm{~s/m/Å.} $
The scattering vector can then be calculated using:

$$q = 2k_i \text{sin}(\theta) = \frac{4\pi}{\lambda}\text{sin}(\theta)$$

## POWTOF instrument
We will simulate a simple time of flight instrument at the ESS source.

### Explore time of flight
We begin with a simplified instrument without guide in order to understand the time of flight aspect of the instrument. For this reason we will use a simple flat source with a flat spectrum as a starting point, and only later use the more realistic source. 

The ESS source have a frequency of $f=14$ Hz and a pulse duration of $d=2.86$ ms. The time structure is not included in the basic McStas sources, but an instrument file called ```POWTOF.instr``` is provided here that includes the time structure, use this instrument as a starting point for this exercise.

**Exercises part 1**
- Place time of flight monitor TOF_monitor.comp at 3 positions in the instrument:
    - Just after the moderator surface
    - 6.5 m from the moderator 
    - 160 m from the moderator
- Adjust the focusing of the source to the monitor furthest from the source.
- Adjust the time range of the tof monitors such that the entire pulse is visible
- Place wavelength sensitive time of flight monitors at the same three positions, note these aren't available in reality.
- Run the simulate with one pulse. Explain the monitor output, especially think about the results in terms of resolution.

### Wavelength band
In the theory section it was assumed a given count in the detector could be traced back to a specific pulse. This assumption is obviously correct in the above scenario, as only a single pulse was simulated.

**Exercises part 2**
- Rerun the simulation with lambda range from 0.5 to 5 Å and two pulses
- Adjust the time range on the time of flight monitors so both pulses are visible
- Explain the output of the simulation

It should be clear that the slower neutrons from the first pulse and the fast neutrons from the second pulse can reach the detector at the same time, and thus introduce an ambiguity in our analysis of the data. We must enforce that the used wavelength band    $\Delta \lambda $ is narrow enough to produce a smaller time difference in earliest and last arrival $~\Delta t $ than the time between pulses $~T = 1/f $.

$$ T \geq \Delta t = \alpha \Delta \lambda L \Rightarrow \Delta \lambda \leq \frac{T}{\alpha L} $$

In practice choppers are used to limit the wavelength range to desired wavelength band. At the present stage of our simulation, we can adjust the simulated wavelength range to match the wavelength band.

**Exercises part 3**
- Calculate the largest possible wavelength band for our instrument
- Perform a simulation with this wavelength band, both starting at 0.5 Å and 3.0 Å
- Explain the results

### Instrument backend
With our understanding of the frontend of the instrument, we are now ready to add a simple sample and backend in the form of a detector.

**Exercises part 4**
- Add a Powder1.comp sample with $~q = \textrm{5 Å}^{-1}$ with diameter 6 mm at the sample position
- Add a TOF_cylPSD_monitor.comp with a diameter of 2 m and height of 20 cm
- Perform the simulation (You may want to add a beamstop component after the sample to avoid the direct beam in the detector)
- Explain the output
- Introduce an instrument parameter called theta to the simulation
- Place a single 10 mm wide TOF detector at an angle $~2 \theta = 90^\circ$  1 m from the sample
- Run the simulation and calculate the scattering vector $q$ and the resolution, $dq$, considering the full neutron path

Typically powder diffraction experiments are performed with $~dq/q \approx 10^{-3}$ at the 90 degree scattering angle. In order to improve and control the resolution we introduce a chopper. It is beneficial to place a chopper as close to the source as possible, at the ESS that is approximately 6.5 m after the source due to shielding.

**Exercises part 5**
- Place a chopper at 6.5 m with a radius of 0.35 m and an angular opening of 4 degrees that spin with the same frequency as the source
- Set the delay of the chopper (a time the chopper is fully open)
- Repeat the simulation and calculate $dq/q$
- [optional] Add a counter rotating chopper just after the first one (negative frequency)

### Simple model to realistic instrument
The current instrument is a crude model that captures the important concepts of a powder diffractometer at ESS, but we can easily improve the fidelity of the simulation. This will be at expense of longer computing times.

**Exercises part 6**
- Exchange the source with a ESS_Butterfly moderator
- Introduce an elliptic guide with focus on source and sample, change focus to start of the guide
- Add a more realistic powder sample using the powderN component and a laz data file from the McStas installation


