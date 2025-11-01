#!/usr/bin/env python3
# Automatically generated file. 
# Format:    Python script code
# McStas <http://www.mcstas.org>
# Instrument: templateSANS_Mantid.instr (templateSANS_Mantid)
# Date:       Sat Nov  1 09:25:28 2025
# File:       templateSANS_Mantid_generated.py

import mcstasscript as ms

# Python McStas instrument description
def make():
    instr = ms.McStas_instr("templateSANS_Mantid_generated", author = "McCode Py-Generator", origin = "ESS DMSC")
    
# Add collected DEPENDENCY strings
    instr.set_dependency('  @NEXUSFLAGS@ ')

    # *****************************************************************************
    # * Start of instrument 'templateSANS_Mantid' generated code
    # *****************************************************************************
    # MCSTAS system dir is "/Users/peterwillendrup/micromamba/share/mcstas/resources/"


    # *****************************************************************************
    # * instrument 'templateSANS_Mantid' and components DECLARE
    # *****************************************************************************

    # Instrument parameters:

    Lambda = instr.add_parameter('double', 'lambda', value=6, comment='Parameter type (double) added by McCode py-generator')
    dlambda = instr.add_parameter('double', 'dlambda', value=0.05, comment='Parameter type (double) added by McCode py-generator')
    r = instr.add_parameter('double', 'r', value=150, comment='Parameter type (double) added by McCode py-generator')
    PHI = instr.add_parameter('double', 'PHI', value=1e-3, comment='Parameter type (double) added by McCode py-generator')
    Delta_Rho = instr.add_parameter('double', 'Delta_Rho', value=0.6, comment='Parameter type (double) added by McCode py-generator')
    sigma_abs = instr.add_parameter('double', 'sigma_abs', value=0.0, comment='Parameter type (double) added by McCode py-generator')

    component_definition_metadata = {
    }
    instr.append_declare(r'''
    ''')


    instr.append_initialize(r'''
    ''')


    # *****************************************************************************
    # * instrument 'templateSANS_Mantid' TRACE
    # *****************************************************************************
    
    # Comp instance a1, placement and parameters
    a1 = instr.add_component('a1','Progress_bar')
    
    a1.profile = '"NULL"'
    a1.percent = '10'
    a1.flag_save = '0'
    a1.minutes = '0'
    
    # Comp instance arm, placement and parameters
    arm = instr.add_component('arm','Arm')
    
    
    # Comp instance sourceMantid, placement and parameters
    sourceMantid = instr.add_component('sourceMantid','Source_simple', AT=['0', '0', '0'], AT_RELATIVE='arm', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='arm')
    
    sourceMantid.radius = '0.02'
    sourceMantid.yheight = '0'
    sourceMantid.xwidth = '0'
    sourceMantid.dist = '3'
    sourceMantid.focus_xw = '0.01'
    sourceMantid.focus_yh = '0.01'
    sourceMantid.E0 = '0'
    sourceMantid.dE = '0'
    sourceMantid.lambda0 = 'lambda'
    sourceMantid.dlambda = 'dlambda'
    sourceMantid.flux = '1e16'
    sourceMantid.gauss = '0'
    sourceMantid.target_index = '+ 1'
    
    # Comp instance coll1, placement and parameters
    coll1 = instr.add_component('coll1','Slit', AT=['0', '0', '3'], AT_RELATIVE='arm', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='arm')
    
    coll1.xmin = 'UNSET'
    coll1.xmax = 'UNSET'
    coll1.ymin = 'UNSET'
    coll1.ymax = 'UNSET'
    coll1.radius = '0.005'
    coll1.xwidth = 'UNSET'
    coll1.yheight = 'UNSET'
    
    # Comp instance coll2, placement and parameters
    coll2 = instr.add_component('coll2','Slit', AT=['0', '0', '6'], AT_RELATIVE='arm', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='arm')
    
    coll2.xmin = 'UNSET'
    coll2.xmax = 'UNSET'
    coll2.ymin = 'UNSET'
    coll2.ymax = 'UNSET'
    coll2.radius = '0.005'
    coll2.xwidth = 'UNSET'
    coll2.yheight = 'UNSET'
    
    # Comp instance LdetectorPRE, placement and parameters
    LdetectorPRE = instr.add_component('LdetectorPRE','L_monitor', AT=['0', '0', '0.05'], AT_RELATIVE='coll2', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='coll2')
    
    LdetectorPRE.nL = '1000'
    LdetectorPRE.filename = '"Edet0.dat"'
    LdetectorPRE.nowritefile = '0'
    LdetectorPRE.xmin = '-0.3'
    LdetectorPRE.xmax = '0.3'
    LdetectorPRE.ymin = '-0.3'
    LdetectorPRE.ymax = '0.3'
    LdetectorPRE.xwidth = '0'
    LdetectorPRE.yheight = '0'
    LdetectorPRE.Lmin = '5.5'
    LdetectorPRE.Lmax = '6.5'
    LdetectorPRE.restore_neutron = '0'
    
    # Comp instance sampleMantid, placement and parameters
    sampleMantid = instr.add_component('sampleMantid','Sans_spheres', AT=['0', '0', '0.2'], AT_RELATIVE='coll2', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='coll2')
    # SPLIT 10 times at sampleMantid
    sampleMantid.set_SPLIT('10')
    # EXTEND at sampleMantid
    sampleMantid.append_EXTEND(r'''
        if (!SCATTERED) ABSORB;
    ''')


    
    sampleMantid.R = 'r'
    sampleMantid.Phi = 'PHI'
    sampleMantid.Delta_rho = 'Delta_Rho'
    sampleMantid.sigma_abs = 'sigma_abs'
    sampleMantid.xwidth = '0.01'
    sampleMantid.yheight = '0.01'
    sampleMantid.zdepth = '0.005'
    sampleMantid.radius = '0'
    sampleMantid.target_x = '0'
    sampleMantid.target_y = '0'
    sampleMantid.target_z = '6'
    sampleMantid.target_index = '0'
    sampleMantid.focus_xw = '0'
    sampleMantid.focus_yh = '0'
    sampleMantid.focus_aw = '0'
    sampleMantid.focus_ah = '0'
    sampleMantid.focus_r = '0'
    
    # Comp instance detector, placement and parameters
    detector = instr.add_component('detector','PSD_monitor', AT=['0', '0', '3'], AT_RELATIVE='sampleMantid', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='sampleMantid')
    
    detector.nx = '128'
    detector.ny = '128'
    detector.filename = '"PSD.dat"'
    detector.xmin = '-0.3'
    detector.xmax = '0.3'
    detector.ymin = '-0.3'
    detector.ymax = '0.3'
    detector.xwidth = '0'
    detector.yheight = '0'
    detector.restore_neutron = '0'
    detector.nowritefile = '0'
    
    # Comp instance Ldetector, placement and parameters
    Ldetector = instr.add_component('Ldetector','L_monitor', AT=['0', '0', '3.01'], AT_RELATIVE='sampleMantid', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='sampleMantid')
    
    Ldetector.nL = '1000'
    Ldetector.filename = '"Edet.dat"'
    Ldetector.nowritefile = '0'
    Ldetector.xmin = '-0.3'
    Ldetector.xmax = '0.3'
    Ldetector.ymin = '-0.3'
    Ldetector.ymax = '0.3'
    Ldetector.xwidth = '0'
    Ldetector.yheight = '0'
    Ldetector.Lmin = '5.5'
    Ldetector.Lmax = '6.5'
    Ldetector.restore_neutron = '0'
    
    # Comp instance PSDrad, placement and parameters
    PSDrad = instr.add_component('PSDrad','PSD_monitor_rad', AT=['0', '0', '3.02'], AT_RELATIVE='sampleMantid', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='sampleMantid')
    
    PSDrad.nr = '100'
    PSDrad.filename = '"psd2.dat"'
    PSDrad.filename_av = '"psd2_av.dat"'
    PSDrad.rmax = '0.3'
    
    # Comp instance nD_Mantid_1, placement and parameters
    nD_Mantid_1 = instr.add_component('nD_Mantid_1','Monitor_nD', AT=['0', '0', '3.2'], AT_RELATIVE='sampleMantid', ROTATED=['0.0', '0.0', '0.0'], ROTATED_RELATIVE='sampleMantid')
    
    nD_Mantid_1.user1 = '""'
    nD_Mantid_1.user2 = '""'
    nD_Mantid_1.user3 = '""'
    nD_Mantid_1.xwidth = '0'
    nD_Mantid_1.yheight = '0'
    nD_Mantid_1.zdepth = '0'
    nD_Mantid_1.xmin = '-0.3'
    nD_Mantid_1.xmax = '0.3'
    nD_Mantid_1.ymin = '-0.3'
    nD_Mantid_1.ymax = '0.3'
    nD_Mantid_1.zmin = '0'
    nD_Mantid_1.zmax = '0'
    nD_Mantid_1.bins = '0'
    nD_Mantid_1.min = '-1e40'
    nD_Mantid_1.max = '1e40'
    nD_Mantid_1.restore_neutron = '1'
    nD_Mantid_1.radius = '0'
    nD_Mantid_1.options = '"mantid square x limits=[-0.3 0.3] bins=128 y limits=[-0.3 0.3] bins=128, neutron pixel min=0 t, list all neutrons"'
    nD_Mantid_1.filename = '"bank01_events.dat"'
    nD_Mantid_1.geometry = '"NULL"'
    nD_Mantid_1.nowritefile = '0'
    nD_Mantid_1.username1 = '"NULL"'
    nD_Mantid_1.username2 = '"NULL"'
    nD_Mantid_1.username3 = '"NULL"'
    
    # Instruct McStasscript not to 'check everythng'
    instr.settings(checks=False)
    return instr


if __name__ == '__main__':
    instr=make()
    # Use instr.settings() to add e.g. seed=1000, ncount=1e7, mpi=8, openacc=True, force_compile=False etc.)
    

# Show diagram
    instr.show_diagram()
    

# Visualise with default parameters (defaults to 'webgl-legacy' visualisation)
    instr.show_instrument()
    

# Generate a dataset with default parameters.
    data = instr.backengine()
    
# Overview plot:
    ms.make_sub_plot(data)
    

# Other useful commands follow...
    
# One plot pr. window
    #ms.make_plot(data)
    
# Load another dataset
    #data2 = ms.load_data('some_other_folder')
    
# Adjusting a specific plot
    #ms.name_plot_options("PSD_4PI", data, log=1, colormap="hot", orders_of_mag=5)
    

# Bring up the 'interface' - only relevant in Jupyter
    #%matplotlib widget
    #import mcstasscript.jb_interface as ms_widget
    #ms_widget.show(data)
    

# Bring up the simulation 'interface' - only relevant in Jupyter
    #%matplotlib widget
    #import mcstasscript.jb_interface as ms_widget
    #sim_widget = ms_widget.SimInterface(instr)
    #sim_widget.show_interface()
    

# Acessing data from the interface
    #data = sim_widget.get_data()


# end of generated Python code templateSANS_Mantid_generated.py 
