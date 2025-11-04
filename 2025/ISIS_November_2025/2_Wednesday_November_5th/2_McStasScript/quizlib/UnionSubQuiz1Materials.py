import mcstasscript as ms

from itertools import permutations

from .quiz import Quiz, make_red, make_green, make_orange, print_box
from .helpers import name_of_component_type, is_instrument_object

class UnionSubQuiz1Materials(Quiz):
    def __init__(self):
        super().__init__()

    def question_1(self, answer=None):
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

    def question_2(self, answer=None):
        """
        What is meant by a material in Union? (created by Union_make_material)

        Connects any single process to a absorption description
        Materials are not user defined
        Collects a number of processes and absorption description
        The position and rotation of material components are important
        """

        feedback = {"A": "No, each process does not get individual absorption, its handled differently.",
                    "B": "The Union_make_material component is used to create user defined materials.",
                    "C": "Yes, a material collects an arbitrary number of processes and one description of absorption.",
                    "D": "No, they are completely ignored as a material has no placement in space."
                    }

        self.multiple_choice(answer=answer, correct_answer="C", feedback=feedback)

    def question_3(self, answer=None):
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

    def question_4(self, answer=None):
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

    def question_5(self, answer=None):
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

    def question_6(self, answer=None):
        if not is_instrument_object(answer):
            return

        msg = "The incoherent process component was found with the right parameters"

        required_component = "Incoherent_process"
        comp_name = "Au_inc"
        required_pars = {"sigma": 4*0.43, "unit_cell_volume": 67.86, "packing_factor" : "Au_fraction"}

        self.last_component_in_instr_check(answer, comp_type_str=required_component,
                                           required_pars=required_pars, success_msg=msg,
                                           comp_name=comp_name)

        msg = "The powder process component was found with the right parameters"

        required_component = "Powder_process"
        comp_name = "Au_pow"
        required_pars = {"reflections": '"Au.laz"', "packing_factor" : "Au_fraction"}

        self.last_component_in_instr_check(answer, comp_type_str=required_component,
                                           required_pars=required_pars, success_msg=msg,
                                           comp_name=comp_name)

    def question_7(self, answer=None):
        if not is_instrument_object(answer):
            return

        msg = "The incoherent process component was found with the right parameters"

        required_component = "Incoherent_process"
        comp_name = "Cu_inc"
        required_pars = {"sigma": 4*0.55, "unit_cell_volume": 47.24, "packing_factor": "Cu_fraction"}

        self.last_component_in_instr_check(answer, comp_type_str=required_component,
                                           required_pars=required_pars, success_msg=msg,
                                           comp_name=comp_name)

        msg = "The powder process component was found with the right parameters"

        required_component = "Powder_process"
        comp_name = "Cu_pow"
        required_pars = {"reflections": '"Cu.laz"', "packing_factor": "Cu_fraction"}

        self.last_component_in_instr_check(answer, comp_type_str=required_component,
                                           required_pars=required_pars, success_msg=msg,
                                           comp_name=comp_name)

    def question_8(self, answer=None):
        if not is_instrument_object(answer):
            return

        mix = answer.get_component("gold_and_copper_mix")

        if mix.process_string is None:
            print_box("No process string given to the gold_and_copper_mix material!", False)

        string = mix.process_string

        if not '"' == string[0] and '"' == string[-1]:
            print_box("The process string lacks the quotation marks, it needs both single and double quotes.", False)
            return

        string = string.strip('"')
        parts = string.split(",")

        if "Au_inc" not in parts:
            print_box("Au_inc is missing!", False)
            return

        if "Au_pow" not in parts:
            print_box("Au_pow is missing!", False)
            return

        if "Cu_inc" not in parts:
            print_box("Cu_inc is missing!", False)
            return

        if "Cu_pow" not in parts:
            print_box("Cu_pow is missing!", False)
            return

        if len(parts) > 4:
            print_box("There seem to be to many processes included?", False)
            return

        print_box("The process string looks correct!", True)