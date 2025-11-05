# Demo notes

Rough notes for what might be demonstrated during the presentation (very very approximate, likely to change).

Any reference to jupyter notebooks below concerns notebooks found at https://github.com/mctools/ncrystal-notebooks

## After slide 10 (cfgstrings)

Show https://github.com/mctools/ncrystal/wiki/CfgRefDoc and perhaps the cfg-string examples on https://github.com/mctools/ncrystal/wiki/Using-NCrystal

## After slide 13 (after Py+CLI APIs shown)

Play around a bit on the command-line with nctool:
```
nctool -h
nctool "Al_sg225.ncmat"
nctool -a "Al_sg225.ncmat"
nctool -d "Al_sg225.ncmat"
nctool -b
nctool gasmix::0.7xCO2+0.3xAr/1.5atm/250K
nctool -b | grep -i Be
nctool "Be_sg194.ncmat"
nctool "Be_sg194.ncmat;temp=200K"  "Be_sg194.ncmat;temp=20C"  "Be_sg194.ncmat;temp=80K"
nctool -d "Be_sg194.ncmat"
nctool --extract Si_sg227.ncmat
```
Show basic notebook, with material load + plot: `ncrystal1_basic_01_Introduction_and_Python_API.ipynb`.

## After slide 16 (first "NCrystal in mcstas" slide)

Open mcgui and show some simulations with an NCrystal_sample. Specifically the `simplencrystal.instr` from the demo_materials folder.

Show both the 3D view of the setup and a histogram. Play a bit with wavelengths and cfg-string, and also use `nctool` during this process.

## After slide 18 ("landmap of data and CLI converters")

Show how we can convert from CIF or to (or use) lau/laz files.

We use https://www.crystallography.net/cod/3000000.html as an example (just because codid::3000000 is an easy to remember database ID).

First show how we can use CIF files:
```
ncrystal_cif2ncmat codid::3000000 # (see warnings)
ncrystal_cif2ncmat codid::3000000 --showcif
ncrystal_cif2ncmat codid::3000000 --uisotemp=293
nctool -d autogen_CCaO3_sg40_cod3000000.ncmat
nctool -a autogen_CCaO3_sg40_cod3000000.ncmat
```
Then show how we can convert to other formats:
```
ncrystal_ncmat2hkl  "autogen_CCaO3_sg40_cod3000000.ncmat;temp=300K" --format=laz -o cod3000000_300K.laz
ncrystal_ncmat2hkl  "autogen_CCaO3_sg40_cod3000000.ncmat;temp=300K" --format=lau -o cod3000000_300K.lau
ls -lh cod3000000_300K.laz cod3000000_300K.lau
ncrystal_ncmat2hkl  "autogen_CCaO3_sg40_cod3000000.ncmat;temp=300K;dcutoff=0.5" --format=lau -o cod3000000_300K_trunc.lau
ll -h cod3000000_300K_trunc.lau
```

We can compare with cif2hkl if we want:
```
ncrystal_cif2ncmat codid::3000000 --showcif > cod3000000.cif
cif2hkl --xtal --mode NUC -o cod3000000_via_cif2hkl.lau cod3000000.cif
cif2hkl --powder --mode NUC -o via_cif2hkl.laz cod3000000.cif
nctool 'autogen_CCaO3_sg40_cod3000000.ncmat;temp=293' via_cif2hkl.laz -c comp=bragg
```

## After slide 22 (mini-mc)

```
nctool --mc --help
nctool --mc "2Aa" "2cm" "Al_sg225.ncmat;temp=250K" #several reflections
nctool --mc "4.3Aa" "2cm" "Al_sg225.ncmat;temp=250K" #single reflection, multiscat effect clear.
nctool --mc "0.5Aa" "2cm" "Al_sg225.ncmat;temp=250K"
nctool --mc "1.0Aa" "2cm" "V_sg229.ncmat"  #Note very isotropic, but elastic+inelastic balance
nctool --mc "4.0Aa" "2cm" "V_sg229.ncmat"  #Note bragg peak and tendency for backwards scattering.
```

We might also demo the relevant jupyter notebook: `ncrystal1_basic_03_Scatter_patterns_with_the_builtin_MiniMC_framework.ipynb`

## After slide 27 (NCMATComposer)

Show notebook with NCMATComposer: `ncrystal2_advanced_01_Creating_materials_and_the_NCMATComposer.ipynb`

## After all slides

Mention place to ask for help, report issues, and follow project is at https://github.com/mctools/ncrystal

Spend some more time on notebooks.
