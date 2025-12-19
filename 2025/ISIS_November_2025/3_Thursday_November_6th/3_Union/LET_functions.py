import numpy as np
import scipp as sc

import mcstasscript as ms

from mcstasscript.tools.ncrystal_union import add_ncrystal_union_material
import NCrystal as NC

import numpy as np
import copy

def add_cfg_refractive_material(name, cfg, instrument):
    add_ncrystal_union_material(instrument, name, cfg)
    info = NC.createInfo(cfg)
    instrument.get_component(name).set_parameters(refraction_SLD=info.getSLD()*1E-6)

def add_materials(instrument):    
    add_cfg_refractive_material("Al", "Al_sg225.ncmat;temp=10C", instrument)
    add_cfg_refractive_material("Air", "gasmix::air/25C/1.0atm/0.30relhumidity", instrument)
    add_cfg_refractive_material("He3", "gasmix::He/5bar/He_is_He3", instrument)
    add_cfg_refractive_material("Fe", "Fe_sg225_Iron-gamma.ncmat;temp=25C", instrument)
    add_cfg_refractive_material("B4C", "B4C_sg166_BoronCarbide.ncmat;temp=25C", instrument)
    
    add_cfg_refractive_material("TiO2", 
                                "TiO2_sg136_Rutile.ncmat;temp=10C;mos=20.0arcmin;dir1=@crys_hkl:2,0,0@lab:0,1,0;dir2=@crys_hkl:0,2,0@lab:1,0,0", 
                                instrument)
    add_cfg_refractive_material("Bi", 
                                "Bi_sg166.ncmat;temp=10C;mos=20.0arcmin;dir1=@crys_hkl:2,-1,0@lab:0,0,1;dir2=@crys_hkl:0,0,1@lab:1,0,0", 
                                instrument)
    

    cd_inc = instrument.add_component("Cd_inc", "Incoherent_process")
    cd_inc.set_parameters(sigma=2.0*3.46, unit_cell_volume=43.11)

    cd_pow = instrument.add_component("Cd_pow", "Powder_process")
    cd_pow.reflections = '"Cd.laz"'

    Cd = instrument.add_component("Cd", "Union_make_material")
    Cd.set_parameters(my_absorption=2*2520*100/43.11, process_string='"Cd_inc,Cd_pow"',
                      refraction_sigma_coh=3.04, refraction_density=8.65, refraction_weight=8.65)

def detector_module(instrument, prefix, ref, dist,
                    priority_min, priority_max,
                    sample_position, order):

    priority_span = priority_max - priority_min

    box = instrument.add_component(prefix + "_box", "Union_box")
    box.set_parameters(xwidth=0.60, yheight=4.1, zdepth=0.3,
                       priority=priority_min, p_interact=0.2,
                       material_string='"Cd"')
    box.set_AT(dist - box.zdepth/2, RELATIVE=ref)

    box_vacuum = instrument.add_component(prefix + "_box_vacuum", "Union_box")
    box_vacuum.set_parameters(xwidth=box.xwidth-0.006,
                              yheight=box.yheight-0.01,
                              zdepth=box.zdepth,
                              priority=priority_min + 0.1*priority_span,
                              material_string='"Vacuum"')
    box_vacuum.set_AT(-0.01, RELATIVE=box)


    tube_radius = 0.025/2
    tube_positions = np.linspace(-box_vacuum.xwidth/2 + tube_radius + 5E-4,
                                 box_vacuum.xwidth/2 - tube_radius - 5E-4,
                                 14)

    tube_names = []
    for index, position in enumerate(tube_positions):
        tube_name = prefix + "_tube_" + str(index)

        tube_priority = box_vacuum.priority + 0.1*priority_span*((index+1)/len(tube_positions))

        tube_shell = instrument.add_component(tube_name + "_shell", "Union_cylinder")
        tube_shell.set_parameters(radius=tube_radius, yheight=4.0 + 1E-3,
                                  priority=tube_priority, material_string='"Fe"')
        tube_shell.set_AT([position, 0, box_vacuum.zdepth/2 - tube_radius - 0.01], RELATIVE=box_vacuum)

        tube_priority += 0.001

        He_name = tube_name + "_He3"
        tube_names.append(He_name)
        tube_He = instrument.add_component(tube_name + "_He3", "Union_cylinder")
        tube_He.set_parameters(radius=tube_radius - 0.5E-3, yheight=4.0, p_interact=0.2,
                               priority=tube_priority, material_string='"He3"')
        tube_He.set_AT(0, tube_shell)

    
    abs_logger = instrument.add_component(prefix + "_abs_logger", "Union_abs_logger_nD")
    abs_logger.set_parameters(
                              target_geometry='"' + ",".join(tube_names) + '"',
                              filename='"' + tube_name + '.dat"')
    abs_logger.options = f'"previous, x y z t, list all neutrons"'
    abs_logger.set_AT(0, sample_position)  

    if order is not None:
        abs_logger.order_total = order

def add_loggers(instrument, ref, xwidth=7, yheight=3, zdepth=7):

    logger = instrument.add_component("logger_zx", "Union_logger_2D_space")
    logger.set_parameters(D_direction_1='"z"', D1_min=-zdepth/2, D1_max=zdepth/2, n1=600,
                          D_direction_2='"x"', D2_min=-xwidth/2, D2_max=xwidth/2, n2=600)
    logger.set_AT(0, ref)
    
    

def make_instrument(union_detector=True, order=None, air=False):

    instrument = ms.McStas_instr("LET")

    init = instrument.add_component("init", "Union_init")

    instrument.add_parameter("Cd_depth", value=0.3)

    add_materials(instrument)

    source = instrument.add_component("source", "Source_simple")
    source.set_parameters(xwidth=0.1, yheight=0.1, flux=1E10,
                          dist=10, focus_xw=0.02, focus_yh=0.02,
                          E0=instrument.add_parameter("E0", value=5),
                          dE=instrument.add_parameter("dE", value=0.1)
                         )

    sample_position = instrument.add_component("sample_position", "Arm")
    sample_position.set_AT(source.dist, RELATIVE=source)

    if air:
        air_geometry = instrument.add_component("air_volume", "Union_cylinder")
        air_geometry.set_parameters(radius=3.5, yheight=4.5, priority=1,
                                    material_string='"Air"', p_interact=0.1)
        air_geometry.set_AT(0, sample_position)

    if union_detector:
        detector_module_angles = np.linspace(-40, 135, 12)
        for index, angle in enumerate(detector_module_angles):
            name = "module_" + str(index)
            ref = instrument.add_component(name + "_direction", "Arm")
            ref.set_AT(0, RELATIVE=sample_position)
            ref.set_ROTATED([0,angle,0], RELATIVE=sample_position)
    
            pixel_min = detector_module(instrument=instrument,ref=ref,
                                        prefix=name, dist=3.5,
                                        priority_min=100 + 2*index,
                                        priority_max=100 + 2*index + 1,
                                        sample_position=sample_position,
                                        order=order)
    

    add_loggers(instrument, sample_position)

    instrument.add_user_var("int", "n_scattering")
    master = instrument.add_component("master", "Union_master")
    master.append_EXTEND("""
    n_scattering = number_of_scattering_events;
    """)
    

    if not union_detector:
        mon = instrument.add_component("detector", "Monitor_nD")
        mon.set_parameters(xwidth=7.1, yheight=4, filename='"detector"', restore_neutron=1)
        mon.options = '"banana, th limits=[-50 160] x y z t neutron, list all"'
        mon.set_AT(0, sample_position)

        if order is not None:
            order_as_string = str(int(order))
            mon.set_WHEN(f"n_scattering == {order_as_string}")

    instrument.add_component("stop", "Union_stop")


    return instrument


def to_scipp(p_array, t_array, x_array, y_array, z_array, position_array, source_dist):
    da = sc.DataArray(
    data=sc.array(dims=["events"], values=p_array, unit=sc.units.counts),
    coords={
      "t": sc.array(dims=["events"], values=t_array, unit="s"),
      "x": sc.array(dims=["events"], values=x_array, unit="m"),    
      "y": sc.array(dims=["events"], values=y_array, unit="m"),
      "z": sc.array(dims=["events"], values=z_array, unit="m"),    
      'source_position': sc.vector([0, 0, source_dist], unit='m'),
      'sample_position': sc.vector([0,0,0], unit='m'),
      'position': sc.vectors(dims=['events'], values=position_array, unit='m'),
      },
    )
    
    # Add two theta
    th = np.atan2(da.coords["x"].values, da.coords["z"].values)*180/3.14159
    da.coords["th"] = sc.array(dims=["events"], values=th, unit="deg")

    return da

def extract(data, union_detector, source_dist):
    if union_detector:
        # Union detector workflow
        first_abs_logger = ms.name_search("module_0_abs_logger", data)
        
        tubes = []
        for mon in data[0:]:
            if "abs_logger" in mon.name:
                if hasattr(mon, "Events"):
                    tubes.append(mon.Events)
            
        total = np.concatenate(tuple(tubes))
    
        p_array = total[:, first_abs_logger.find_variable_index("p")]
        t_array = total[:, first_abs_logger.find_variable_index("t")]
        
        x_array = total[:, first_abs_logger.find_variable_index("x")]
        y_array = total[:, first_abs_logger.find_variable_index("y")]
        z_array = total[:, first_abs_logger.find_variable_index("z")]
        position_array = total[:, first_abs_logger.find_variable_index("x"):first_abs_logger.find_variable_index("z")+1]
    
    else: 
        # Monitor_nD workflow
        detector = ms.name_search("detector", data)
        print(detector)
    
        p_array = detector.get_data_column("p")
        t_array = detector.get_data_column("t")
        x_array = detector.get_data_column("x")
        y_array = detector.get_data_column("y")
        z_array = detector.get_data_column("z")
    
        position_array = np.stack((x_array.T, y_array.T, z_array.T)).T
    
    return to_scipp(p_array, t_array, x_array, y_array, z_array, position_array, source_dist)
