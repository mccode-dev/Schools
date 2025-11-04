import mcstasscript as ms

from itertools import permutations

from .quiz import Quiz, make_red, make_green, make_orange, print_box
from .helpers import name_of_component_type, is_instrument_object

class UnionSubQuiz2Geometry(Quiz):
    def __init__(self):
        super().__init__()

    def question_1(self, answer=None):
        """
        Which statement about geometry components below is true?

        - A: Geometry components can take multiple material definitions
        - B: Geometry components are optional for running a Union simulation
        - C: The position and rotation of geometry components are important
        - D: The geometry component performs the simulation
        """

        feedback = {"A": "No, a geometry component take at most a single material definition.",
                    "B": "No, without geometry components there will be nothing simulated.",
                    "C": "Yes, the geometry component describes something physical which is placed in space.",
                    "D": "No, the geometry components themselves do not contain any simulation code."
                    }

        self.multiple_choice(answer=answer, correct_answer="C", feedback=feedback)

    def question_2(self, answer=None):
        """
        Does the placement of the geometry components in the instrument file matter?

        - A: Not at all, they can be wherever in the instrument
        - B: Slightly, they have to be after their material and before their master
        - C: Yes, the rays will interact with them in the given order
        """

        feedback = {"A": "No, a geometry component can't be before its material or after the desired master",
                    "B": "Yes, but their order does not matter, they will all be simulated. ",
                    "C": "No, all the rays can interact with the geometries in any order.",
                    }

        self.multiple_choice(answer=answer, correct_answer="B", feedback=feedback)

    def question_3(self, answer=None):
        """
        What is the purpose of the priority parameter?

        - A: To select which of two overlapping geometries to simulate in overlapping region
        - B: To select how important a geometry is and assign statistics accordingly
        - C: To hide a geometry component when drawing the instrument
        - D: To disable or enable a geometry
        """

        feedback = {"A": "Yes, the one with highest priority is simulated in the overlapping region",
                    "B": "No, for that one could use the p_interact parameter",
                    "C": "No, for that one could use the visualize parameter",
                    "D": "No, for that one could use the number_of_activations parameter",
                    }

        self.multiple_choice(answer=answer, correct_answer="A", feedback=feedback)

    def question_4(self, answer=None):
        if not is_instrument_object(answer):
            return

        required_pars = {"xwidth": 0.16, "yheight": 0.09, "zdepth": 0.07, "material_string": '"Al"'}

        msg = "The Union_box component was found with the right properties"

        required_component = "Union_box"
        comp_name = name_of_component_type(answer, required_component=required_component)
        if comp_name is None:
            return

        comp = answer.get_component(comp_name)
        if comp.priority is None:
            print_box("Remember to assign a priority to all Union geometries!", False)
            return

        self.last_component_in_instr_check(answer, comp_type_str=required_component,
                                           required_pars=required_pars, success_msg=msg,
                                           required_AT_data=[0,0,0], comp_name=comp_name,
                                           required_AT_relative="sample_position")

        component_names = [x.name for x in answer.make_component_subset()]

        detector_index = component_names.index("detector")
        box_index = component_names.index(comp_name)
        if box_index != detector_index - 1:
            print_box("The box was made correctly, but was not placed correctly in the component sequence", False)
            return

    def question_5(self, answer=None):
        if not is_instrument_object(answer):
            return

        msg = "The Union_master component was found with the right properties"

        required_component = "Union_master"
        comp_name = name_of_component_type(answer, required_component=required_component)
        if comp_name is None:
            return

        self.last_component_in_instr_check(answer, comp_type_str=required_component,
                                           success_msg=msg, comp_name=comp_name)

        component_names = [x.name for x in answer.make_component_subset()]

        detector_index = component_names.index("detector")
        master_index = component_names.index(comp_name)
        if master_index != detector_index - 1:
            print_box("The Union_master component was added, but was not placed correctly in the component sequence", False)
            return

    def question_6(self, answer=None):
        if not is_instrument_object(answer):
            return

        msg = "The Union_stop component was found with the right properties"

        required_component = "Union_stop"
        comp_name = name_of_component_type(answer, required_component=required_component)
        if comp_name is None:
            return

        self.last_component_in_instr_check(answer, comp_type_str=required_component,
                                           success_msg=msg, comp_name=comp_name)

        master_name = name_of_component_type(answer, required_component="Union_master")
        if master_name is None:
            return

        component_names = [x.name for x in answer.make_component_subset()]

        master_index = component_names.index(master_name)
        stop_index = component_names.index(comp_name)
        if master_index > stop_index:
            print_box("The stop component needs to be after the Union master!", False)
            return

    def question_7(self, answer=None):
        if not is_instrument_object(answer):
            return

        msg = "The Union_box component was found with the right properties"

        required_component = "Union_box"
        comp_name = "box_vacuum"

        component_names = [x.name for x in answer.make_component_subset()]
        component_types = [x.component_name for x in answer.make_component_subset()]
        if comp_name not in component_names:
            print_box("Did not find a component name 'box_vacuum'!", False)
            return

        required_pars = {"xwidth": 0.14, "yheight": 0.09, "zdepth": 0.05,
                         "material_string": '"Vacuum"'}

        check = self.last_component_in_instr_check(answer, comp_type_str=required_component,
                                                   required_pars=required_pars, success_msg=msg,
                                                   required_AT_data=[0, 0.01, 0], comp_name=comp_name,
                                                   required_AT_relative="box")
        if not check:
            return

        vacuum_priority = None
        outer_priority = None
        # find both boxes
        for index, comp_type in enumerate(component_types):
            if comp_type == "Union_box":
                name = component_names[index]
                comp = answer.get_component(name)
                if name == "box_vacuum":
                    vacuum_priority = comp.priority
                else:
                    outer_priority = comp.priority

        if vacuum_priority is None or outer_priority is None:
            print_box("Didn't manage to find both boxes?", False, False)
            return

        if vacuum_priority <= outer_priority:
            print_box("The two boxes does not have the right relationship between their priorities, which should be higher?", False)
            return

        master_name = name_of_component_type(answer, required_component="Union_master")
        if master_name is None:
            return

        master_index = component_names.index(master_name)
        vacuum_index = component_names.index(comp_name)
        if master_index < vacuum_index:
            print_box("The box_vacuum component needs to be before the Union master!", False)
            return

        print_box("The box_vacuum was added correctly and hollows out the box!", True)

    def question_8(self, answer=None):
        if not is_instrument_object(answer):
            return

        component_names = [x.name for x in answer.make_component_subset()]
        component_types = [x.component_name for x in answer.make_component_subset()]

        vacuum_priority = None
        master_index = None
        # find both boxes
        for index, comp_type in enumerate(component_types):
            if comp_type == "Union_box":
                name = component_names[index]
                comp = answer.get_component(name)
                if name == "box_vacuum":
                    vacuum_priority = comp.priority
                    vacuump_comp = comp

            if comp_type == "Union_master":
                master_index = index

        if vacuum_priority is None:
            print_box("Didn't find the box_vacuum component in the instrument?", False, False)

        if master_index is None:
            print_box("Didn't find the Union_master component in the instrument?", False, False)


        n_spheres = 0
        sphere_priorities = []
        for index, component_type in enumerate(component_types):

            if component_type != "Union_sphere":
                continue
            else:
                n_spheres += 1

            required_pars = {"material_string": '"SiO2"'}
            required_component = "Union_sphere"
            comp_name = component_names[index]
            comp = answer.get_component(comp_name)

            check = self.last_component_in_instr_check(answer, comp_type_str=required_component,
                                                       required_pars=required_pars, comp_name=comp_name,
                                                       required_AT_relative="box_vacuum", print_output=False)

            if not check:
                return

            if comp.priority < vacuum_priority:
                print_box(f"This marble '{comp_name}' does not have the right priority relative to the box_vacuum.", False)
                return

            if comp.priority in sphere_priorities:
                print_box("Two of the marbles have the same priority, all priorities need to be unique.", False)
                return

            sphere_priorities.append(comp.priority)

            if index > master_index:
                print_box(f"This marble '{comp_name}' was placed after the Union_master in the instrument.", False)
                return

            if comp.radius is None:
                print_box(f"This marble '{comp_name}' needs a reasonable radius!", False)
                return
            else:
                radius = comp.radius

            if (abs(comp.AT_data[0]) > vacuump_comp.xwidth - radius or abs(comp.AT_data[1]) > vacuump_comp.yheight - radius
                    or abs(comp.AT_data[2]) > vacuump_comp.zdepth - radius):
                print_box(f"This marble '{comp_name}' is not fully inside the box! You have lost a marble!", False)
                return

        if n_spheres == 1:
            print_box(f"Found {n_spheres} marble with appropriate properties, add a few more!", True, True)
        else:
            print_box(f"Found {n_spheres} marbles with appropriate properties, great! You still have all your marbles!", True, True)

    def question_9(self, answer=None):
        """
        Does the simulation allow a ray to scatter in all the marbles?

        - A: Yes, and the box too
        - B: No, the ray can only scatter in one of the geometries
        """

        feedback = {"A": "Yes, multiple scattering between all geometries is always simulated with Union components",
                    "B": "No, multiple scattering between all geometries is always simulated with Union components",
                    }

        self.multiple_choice(answer=answer, correct_answer="A", feedback=feedback)










