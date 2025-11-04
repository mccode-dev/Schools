import mcstasscript as ms

from itertools import permutations

from .quiz import Quiz, make_red, make_green, make_orange
from .helpers import name_of_component_type, is_instrument_object

class UnionQuiz(Quiz):
    def __init__(self):
        super().__init__()


    def question_1(self, answer=None):
        """
        What is not a reason to use Union components:
        A: Want to describe complex geometry
        B: Combination of physical processes in one geometry
        C: Multiple scattering between geometries / processes
        D: Model detector systems
        E: Logging of scattering
        F: Logging of absorption
        G: Gravity support
        H: Tracking of features in data
        """

        feedback = {"A": "The Union components can be used to simulate highly complex geometries!",
                    "B": "Union materials can contain an unlimited number of scattering processes.",
                    "C": "All multiple scattering will be handled, even between geometries.",
                    "D": "With the absorption loggers the absorption in detectors can be modelled.",
                    "E": "The Union components have powerful logger components that log scattering.",
                    "F": "The Union components have powerful abs_logger components that log absorption.",
                    "G": "The Union components ignores gravity, so the Union components may not be the right option if gravity effects are important in the described area.",
                    "H": "The Union components have several features for tracking interesting features in data.",
                    }

        self.multiple_choice(answer=answer, correct_answer="G", feedback=feedback)

    def question_2(self, answer=None):
        """
        Important limitation to remember when using Union components

        No perfectly overlapping edges
        Maximum 10 geometries
        Maximum 5 processes in a material
        One Union system per instrument
        """

        feedback = {"A": "Two geometries should overlap or be separate, not share a face.",
                    "B": "There are no limits to the number of geometries simulated.",
                    "C": "There are no limits to the number of processes in a material.",
                    "D": "It is allowed to have several distinct Union systems in an instrument."
                    }

        self.multiple_choice(answer=answer, correct_answer="A", feedback=feedback)

    def question_3(self, answer=None):
        """
        What does a process component do?

        Describes a number of scattering mechanisms
        Describes a physical process
        Describes absorption
        """

        feedback = {"A": "A process component describes just one kind of scattering.",
                    "B": "Yes! It describes a single scattering mechanism.",
                    "C": "No, absorption is handled elsewhere.",
                    }

        self.multiple_choice(answer=answer, correct_answer="B", feedback=feedback)

    def question_4(self, answer=None):
        """
        What is meant by a material in Union? (created by Union_make_material)

        Connects any single process to a absorption description
        Collects a number of processes and absorption description
        Materials are not user defined
        The position and rotation of material components are important
        """

        feedback = {"A": "No, each process does not get individual absorption, its handled differently.",
                    "B": "Yes, a material collects an arbitrary number of processes and one description of absorption.",
                    "C": "The Union_make_material component is used to create user defined materials.",
                    "D": "No, they are completely ignored as a material has no placement in space."
                    }

        self.multiple_choice(answer=answer, correct_answer="B", feedback=feedback)

    def question_5(self, answer=None):
        """
        Which statement about geometry components below is true?

        Geometry components can take multiple material definitions
        Geometry components are optional for running a Union simulation
        The position and rotation of geometry components are important
        The geometry component performs the simulation
        """

        feedback = {"A": "No, a geometry component take at most a single material definition.",
                    "B": "No, without geometry components there will be nothing simulated.",
                    "C": "Yes, the geometry component describes something physical which is placed in space.",
                    "D": "No, the geometry components themselves do not contain any simulation code."
                    }

        self.multiple_choice(answer=answer, correct_answer="C", feedback=feedback)

    def question_6(self, answer=None):
        """
        What is the responsibility of a logger component?

        A logger records absorbed intensity
        A logger records scattering intensity
        A logger records the final state of the ray
        A logger always records positions
        """

        feedback = {"A": "No, that would be an abs_logger component!",
                    "B": "Yes, it records scattered intensity along some axis defined by the individual logger component.",
                    "C": "No, the important aspect of loggers is that they can access scattering step of the simulation.",
                    "D": "No, the scattered intensity could be recorded as function of something different, for example energy or momentum transfer."
                    }

        self.multiple_choice(answer=answer, correct_answer="B", feedback=feedback)

    def question_7(self, answer=None):
        """
        What is the responsibility of an abs_logger component?

        An abs_logger records the final weight of each ray
        An abs_logger needs to be connected to a specific geometry
        An abs_logger records scattering intensity
        An abs_logger records absorbed intensity
        """

        feedback = {"A": "No, the abs_loggers records absorption along the entire path of the ray.",
                    "B": "No, it doesn't need to, but it can be if only absorption in that geometry is desired.",
                    "C": "No, the regular logger components perform that role.",
                    "D": "Yes, it records absorbed intensity along the path of the ray.",
                    }

        self.multiple_choice(answer=answer, correct_answer="D", feedback=feedback)

    def question_8(self, answer=None):
        """
        What is the purpose of a conditional component?

        A conditional component decides when a geometry is simulated
        A conditional component can affect exactly one other component
        A conditional component imposes a condition on logger or abs_logger components
        A conditional component is required to perform a simulation with Union components
        """

        feedback = {"A": "No, that is done using the number_of_activation parameter on a geometry.",
                    "B": "No, a conditional component can affect multiple loggers / abs_loggers.",
                    "C": "Yes, it defines a condition on the final ray and imposes that on loggers / abs_loggers.",
                    "D": "No, conditional components are a specialized tool not frequently used."
                    }

        self.multiple_choice(answer=answer, correct_answer="C", feedback=feedback)

    def question_9(self, answer=None):
        """
        Select the true statement about the Union_master component.

        There can only be one master component in an instrument
        A Union_master component is required to perform a simulation with Union components
        All Union components in an instrument file are simulated in a master component
        The Union_master needs to be placed on a Union geometry
        """

        feedback = {"A": "No, there is no limitation on the number of master components in an instrument.",
                    "B": "Yes, without a master the rays in McStas are not affected by anything Union.",
                    "C": "No, a master component only simulates geometries defined earlier than itself.",
                    "D": "No, the location of the Union_master component doesn't really matter, all the location data is stored in the geometries."
                    }

        self.multiple_choice(answer=answer, correct_answer="B", feedback=feedback)

    def question_10(self, answer=None):
        """
        The geometry with highest priority decides what material to be simulated
        The geometry with lowest priority decides what material to be simulated
        The priority of a geometry decides how likely it is a ray scatters from it
        """

        feedback = {"A": "Yes, when multiple geometries cover a point, the one with highest priority decides the material.",
                    "B": "No, the Union components defines a higher priority to be more important.",
                    "C": "No, there is a parameter called p_interact on geometries for that purpose.",
                    }

        self.multiple_choice(answer=answer, correct_answer="A", feedback=feedback)

    def question_11(self, answer=None):
        if not is_instrument_object(answer):
            return

        required_pars = {"sigma": [4*0.0082, "4*0.0082"], "unit_cell_volume": 66.4}

        msg = "The incoherent process component was found with the right parameters"

        required_component = "Incoherent_process"
        comp_name = name_of_component_type(answer, required_component=required_component)
        if comp_name is None:
            return

        self.last_component_in_instr_check(answer, comp_type_str=required_component,
                                           required_pars=required_pars, success_msg=msg)

    def question_12(self, answer=None):
        if not is_instrument_object(answer):
            return

        required_pars = {"reflections": '"Al.laz"'}

        msg = "The powder process component was found with the right parameters"

        required_component = "Powder_process"
        comp_name = name_of_component_type(answer, required_component=required_component)
        if comp_name is None:
            return

        self.last_component_in_instr_check(answer, comp_type_str=required_component,
                                           required_pars=required_pars, success_msg=msg)

    def question_13(self, answer=None):
        if not is_instrument_object(answer):
            return

        inc_name = name_of_component_type(answer, required_component="Incoherent_process")
        if inc_name is None:
            return

        pow_name = name_of_component_type(answer, required_component="Powder_process")
        if pow_name is None:
            return

        # Could improve code to understand each permutation
        expected_process_string = [f'"{inc_name},{pow_name}"', f'"{pow_name},{inc_name}"']

        required_pars = {"my_absorption": [100*4*0.231/66.4, "100*4*0.231/66.4"],
                         "process_string": expected_process_string}

        msg = "The material component was found with the right parameters"

        required_component = "Union_make_material"
        comp_name = name_of_component_type(answer, required_component=required_component)
        if comp_name is None:
            return

        self.last_component_in_instr_check(answer, comp_type_str=required_component,
                                           required_pars=required_pars, success_msg=msg)

    def question_14(self, answer=None):
        # Check there are two single_crystal_process components

        if not is_instrument_object(answer):
            return

        #type_name_dict = {x.component_name: x.name for x in answer.component_list}
        types = [x.component_name for x in answer.component_list]
        xtal_process_count = types.count("Single_crystal_process")

        if xtal_process_count == 1:
            print(make_red("Only see one Single_crystal_process in the provided instrument"))
            return

        if xtal_process_count > 2:
            print(make_red("See more than two single crystal processes in the instrument!"))
            return

        # Finds last single crystal, the one that should be modified
        single_crystal = name_of_component_type(answer, required_component="Single_crystal_process")
        if single_crystal is None:
            return

        required_pars = {"reflections": '"YBaCuO.lau"', "mosaic":15, "packing_factor":0.5,
                         "ax":3.8186, "by":3.886, "cz":11.6777}
        required_component = "Single_crystal_process"
        msg = "Twinned single crystal process found with correct parameters!"
        correct = self.last_component_in_instr_check(answer, comp_name=single_crystal, comp_type_str=required_component,
                                                     required_pars=required_pars, success_msg=msg,
                                                     required_ROTATED_relative="ABSOLUTE",
                                                     required_ROTATED_data=["twin_x", "twin_y", "twin_z"])

        if not correct:
            print(make_orange("Will proceed to check the material when the twinned "
                              "single crystal process is added correctly"))
            return

        required_component = "Union_make_material"
        comp_name = name_of_component_type(answer, required_component=required_component)
        if comp_name is None:
            return

        # All permutations of process names
        index_al_material = types.index("Union_make_material")
        components_after_Al = answer.component_list[index_al_material+1:]

        process_components = []
        for comp in components_after_Al:
            if comp.component_name in ["Incoherent_process", "Single_crystal_process"]:
                process_components.append(comp)

        process_names = [x.name for x in process_components]

        if len(process_names) < 3:
            print(make_red("A total of three processes are needed to make this material,"
                           + " but after the Al definitions only these were found: \n"
                           + str(process_names)))
            return

        if len(process_names) > 3:
            print(make_red("A total of three processes are needed to make this material,"
                           + " but after the Al definitions more than 3 were found found: \n"
                           + str(process_names)))
            return

        possible_orders = list(permutations(process_names))
        possible_strings = []
        for possible_order in possible_orders:
            possible_strings.append('"' + ",".join(possible_order) + '"')

        required_pars = {"my_absorption": [100*14.82/173.28, "100*14.82/173.28"],
                         "process_string": possible_strings}

        msg = "The material component was found with all required processes!"

        self.last_component_in_instr_check(answer, comp_type_str=required_component,
                                           required_pars=required_pars, success_msg=msg)


    def question_15(self, answer=None):
        if not is_instrument_object(answer):
            return

        required_pars = dict(xwidth=0.01, yheight=0.035,
                             focus_xw=7.0E-3, focus_yh=1E-2, dist=1,
                             lambda0=4.5, dlambda=4.0, flux=1E13)

        msg = "The source was found with the right parameters"

        required_component = "Source_simple"

        self.last_component_in_instr_check(answer, comp_type_str=required_component,
                                           required_pars=required_pars, success_msg=msg)

    def question_16(self, answer=None):
        if not is_instrument_object(answer):
            return

        source = name_of_component_type(answer, required_component="Source_simple")
        if source is None:
            print(make_red("Did not find the source"))
            return

        cylinder = name_of_component_type(answer, required_component="Union_cylinder")
        if cylinder is None:
            print(make_red("Did not find a Union_cylinder component."))
            return

        sample_material = name_of_component_type(answer, required_component="Union_make_material")
        if sample_material is None:
            print(make_red("Did not find the Union material for the sample."))
            return

        required_pars = dict(radius=3E-3, yheight=1E-2, material_string='"' + sample_material + '"')
        required_component = "Union_cylinder"
        msg = "The sample cylinder is set up correctly!"
        correct = self.last_component_in_instr_check(answer, comp_name=cylinder, comp_type_str=required_component,
                                                     required_pars=required_pars, success_msg=msg,
                                                     required_AT_relative=source,
                                                     required_AT_data = [0, 0, 1])

        if not correct:
            print(make_orange("Will proceed to check Al box when sample cylinder is set up correctly."))

        box = name_of_component_type(answer, required_component="Union_box")
        if box is None:
            print(make_red("Did not find the Union_box component for the sample holder."))
            return

        types = [x.component_name for x in answer.component_list]
        index_al_material = types.index("Union_make_material")
        Al_material = answer.component_list[index_al_material]
        Al_material_name = Al_material.name

        required_pars = dict(material_string='"' + Al_material_name + '"')
        required_component = "Union_box"
        msg = "The sample holder is set up correctly!"
        self.last_component_in_instr_check(answer, comp_name=box, comp_type_str=required_component,
                                           required_pars=required_pars, success_msg=msg)

        # Check cylinder has higher priority than box
        box_comp = answer.get_component(box)
        cylinder_comp = answer.get_component(cylinder)

        if box_comp.priority >= cylinder_comp.priority:
            print(make_red("Check the priorities on the sample and sample holder, "
                           "the sample should be the one that decides the material in the overlap."))

    def question_17(self, answer=None):
        if not is_instrument_object(answer):
            return

        cylinder = name_of_component_type(answer, required_component="Union_cylinder")
        if cylinder is None:
            print(make_red("Did not find the sample component."))
            return

        loggers = []
        for comp in answer.component_list:
            if comp.component_name == "Union_logger_2D_space":
                loggers.append(comp)

        filenames = []
        dimension_combinations = []
        for logger in loggers:
            required_component = "Union_logger_2D_space"
            msg = "Found a logger with the correct position!"
            self.last_component_in_instr_check(answer, success_msg=msg,
                                               comp_name=logger.name, comp_type_str=required_component,
                                               required_AT_relative=cylinder, required_AT_data=[0,0,0])

            filenames.append(logger.filename)
            dimension_combinations.append(logger.D_direction_1.strip('"') + logger.D_direction_2.strip('"'))

        if "zx" not in dimension_combinations:
            print(make_red("Did not find a logger that detects in the zx plane."))

        if "zy" not in dimension_combinations:
            print(make_red("Did not find a logger that detects in the zy plane."))

        if "xy" not in dimension_combinations:
            print(make_red("Did not find a logger that detects in the xy plane."))

        if len(filenames) != len(set(filenames)):
            print(make_red("Found duplicated filenames in loggers, these should be unique."))

    def question_18(self, answer=None):
        if not is_instrument_object(answer):
            return

        required_component = "Union_master"
        msg = "The Union_master component was correctly added!"
        self.last_component_in_instr_check(answer, comp_type_str=required_component, success_msg=msg)

    def question_19(self, answer=None):

        below = "I don't see a clear difference with twinning this low, you must have good eyes."
        above = ("At this value there is clearly a difference, but I also see one at lower twinning values.\n"
                 + "Try to use higher ncount, log plotting and the "
                 + "orders of magnitude option to increase readability of the plot.")
        correct = "Yes, at about this amount of twinning the peaks start to split into two."
        self.insert_value(answer, correct_answer=0.9, tollerance_interval=0.601,
                          feedback_below=below,
                          feedback_above=above,
                          feedback_correct=correct)

    def question_20(self, answer=None):
        """
        Which twin axis impact the L_monitor the least?

        twin_x
        twin_y
        twin_z
        """

        feedback = {
            "A": "No, it is assumed they all are quite close to 0, try around there.",
            "B": "No, it is assumed they all are quite close to 0, try around there.",
            "C": "Exactly, it doesn't impact it at all (when the others are 0).",
            }

        self.multiple_choice(answer=answer, correct_answer="C", feedback=feedback)

    def question_21(self, wavelength=None, n_Al_peaks=None):

        if wavelength is None or n_Al_peaks is None:
            print("Insert investigated wavelength and number of Al_peaks found as:\n"
                  + " question_21(wavelength=1.2, n_Al_peaks=8)")
            return

        if not 0.5 <= wavelength <= 8.5:
            print("Only look in the wavelenth interval of 0.5 to 8.5 Å.")
            return

        allowed_values = [2.55, 3.55, 3.86, 7.84]
        tollerance = 0.1

        found_answer = None
        for allowed_value in allowed_values:
            if allowed_value - tollerance <= wavelength <= allowed_value + tollerance:
                found_answer = allowed_value

        if found_answer is None:
            print(make_red("That wavelength was not close to a reflection, you have to be a bit more accurate."))
            return

        print(make_green("The given wavelength correspond to a reflection!"))

        correct_n_Al_peaks = None
        if wavelength > 4.67:
            correct_n_Al_peaks = 0
        elif 4.05 < wavelength < 4.67:
            correct_n_Al_peaks = 1
        elif 2.86 < wavelength < 4.05:
            correct_n_Al_peaks = 2
        elif 2.44 < wavelength < 2.86:
            correct_n_Al_peaks = 3

        below = "There should be more at this wavelength, use the PSD_sphere monitor with log scale to count."
        above = "There should not be that many at this wavelength, use the PSD_sphere monitor with log scale to count."

        if correct_n_Al_peaks > 0:
            success = "Yes, you identified the Bragg peaks from the aluminium sample holder correctly."
        else:
            success = "Yes, at this wavelength there are no aluminium bragg peaks from the sample holder!"

        self.insert_value(n_Al_peaks, correct_answer=correct_n_Al_peaks,
                          feedback_below=below,
                          feedback_above=above,
                          feedback_correct=success)
