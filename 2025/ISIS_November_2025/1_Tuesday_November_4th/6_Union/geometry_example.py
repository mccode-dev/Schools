
import mcstasscript as ms
import mcstasscript.jb_interface as ms_widget

def make_instrument():
    instrument = ms.McStas_instr("Union_demo")

    incoherent = instrument.add_component("incoherent", "Incoherent_process")
    incoherent.sigma = 2.5
    incoherent.unit_cell_volume = 13.8

    inc_material = instrument.add_component("inc_material", "Union_make_material")
    inc_material.my_absorption = 1.2
    inc_material.process_string = '"incoherent"'

    src = instrument.add_component("source", "Source_div")

    wavelength = 5.0
    src.set_parameters(xwidth=0.15, yheight=0.15, focus_aw=0.01, focus_ah=0.01,
                       lambda0=wavelength, dlambda=0.01*wavelength)



    box_x = instrument.add_parameter("box_x", value=-0.03, comment="[m] coordinate")
    box_priority = instrument.add_parameter("box_priority", value=10, comment="[1]")

    box = instrument.add_component("box", "Union_box")
    box.set_parameters(xwidth=0.06, yheight=0.06, zdepth=0.04,
                       material_string = '"inc_material"', priority=box_priority)
    box.set_AT([box_x, 0, 1])

    cyl_x = instrument.add_parameter("cylinder_x", value=0.03, comment="[m] coordinate")
    cyl_z = instrument.add_parameter("cylinder_z", value=0.00, comment="[m] coordinate")
    cyl_priority = instrument.add_parameter("cylinder_priority", value=8, comment="[1]")
    cyl_material = instrument.add_parameter("string", "cylinder_material", value='"inc_material"',
                                            options=['"inc_material"', '"Vacuum"'],
                                            comment="Material choice for the cylinder")


    cyl = instrument.add_component("cylinder", "Union_cylinder")
    cyl.set_parameters(radius=0.025, yheight=0.0401, material_string = cyl_material, priority=cyl_priority)
    cyl.set_AT([cyl_x, 0, "1 + cylinder_z"])
    cyl.set_ROTATED([90, 0, 0])


    logger = instrument.add_component("logger_space", "Union_logger_2D_space")
    logger.D_direction_1 = '"x"'
    logger.D1_min = -0.08
    logger.D1_max = 0.08
    logger.n1 = 250
    logger.D_direction_2 = '"y"'
    logger.D2_min = -0.08
    logger.D2_max = 0.08
    logger.n2 = 250
    logger.filename = '"logger.dat"'

    master = instrument.add_component("master", "Union_master")

    return instrument
    
def show():
    instrument = make_instrument()
    return ms_widget.show(instrument)
