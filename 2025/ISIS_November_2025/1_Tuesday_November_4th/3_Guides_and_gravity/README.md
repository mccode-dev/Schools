## Guides
This folder contains two example instruments,
- 1: Exercise_guides.instr
- 2: Guide_BT_template.instr

Both are a starting point to explore simulations of guides using McStas. The first one is the simpler of the two, with just a source, a straight guide and a few monitors. The second has more monitors, and two sets for use with normalization of the data to brilliance transfer. New users of McStas should start exploring the first, while more advanced users can skip that and look at the brilliance transfer template. The jupyter notebook called plot_brill can be used to perform the brilliance transfer normalization of the Guide_BT_template data.

### TASK
Explore the impact of guide parameters and geometry. Start by adjusting the guide length and compare the generated data from different guide lengths.

### HINTS
* Use Guide or Guide_gravity component
* ```mcdoc guide```
* Add parameter in DEFINE INSTRUMENT line between parenthesis
* m value important

### INTERPRETATION
Guides can transport some limited divergence, strongly depending on wavelength

### EXTRA
Perform a scan over guide length

