import mcstasscript as ms
from libpyvinyl.Parameters.Parameter import Parameter

from .quiz import Quiz
from .quiz import make_red, make_green, make_orange, print_box
from .helpers import name_of_component_type, is_instrument_object


class McStasScriptQuiz(Quiz):
    def __init__(self):
        super().__init__()

    def question_1(self, answer=None):
        """
        Question: How many components are inserted
        """

        self.insert_value(answer=answer, correct_answer=3, feedback_correct="",
                          feedback_below="There are more than that, look for use of add_component.",
                          feedback_above="There are not quite that many, look for use of add_component.")

    def question_2(self, answer=None):
        """
        Question: Distance between source and monitor
        """

        self.insert_value(answer=answer, correct_answer=7.5, feedback_correct="",
                          feedback_below="The distance is greater than that, there must be a distance that wasn't added.",
                          feedback_above="The distance is not that long.")

    def question_3(self, answer=None):
        feedback = {"A": "No, the component objects do not need to know about the instrument they are part of.",
                    "B": "Yes, the instrument contains all the defined components.",
                    "C": "No, the instrument object used to create the component objects register them at creation.",
                    }
        self.multiple_choice(answer=answer, correct_answer="B", feedback=feedback)

    def question_4(self, answer=None):
        feedback = {"A": "No, that would be help(instrument.add_parameter).",
                    "B": "No, that sounds like the show_parameters method on a component object.",
                    "C": "No, try to use the method on the instrument object from the exercise.",
                    "D": "",
                    }
        self.multiple_choice(answer=answer, correct_answer="D", feedback=feedback)

    def question_5(self, answer=None):
        feedback = {"A": "That would work if the parameter of interest has been specified.",
                    "B": "This is the best option, it shows all available parameters and their units.",
                    "C": "No, that would just return the component object, but you could use that on your quest to get the unit.",
                    "D": "This would work and be the preferred option if you don't have a component object of that type.",
                    }

        if not isinstance(answer, list):
            answer = [answer]

        for single_answer in answer:
            self.multiple_choice(answer=single_answer, correct_answer=["A", "B", "D"], feedback=feedback)

    def question_6(self, answer=None):

        required_attr = {"name": "my_instrument"}
        wrong_attr_msg = {"name": "The instrument name was not set to 'my_instrument'."}
        missing_attr_msg = {"name": "How did you even do this?"}

        self.type_and_attributes(answer, ms.interface.instr.McStas_instr,
                                 required_attributes=required_attr,
                                 wrong_attr_msg=wrong_attr_msg,
                                 missing_attr_msg=missing_attr_msg)

    def question_7(self, answer=None):

        if not is_instrument_object(answer):
            return

        required_pars = {"focus_aw": 1.0, "focus_ah": 1.0, "lambda0": 1.2, "dlambda": 0.1,
                         "xwidth": 0.035, "yheight": 0.035}

        msg = "The Source_div source was found with the right parameters."

        self.last_component_in_instr_check(answer, comp_type_str="Source_div",
                                           required_pars=required_pars,
                                           success_msg=msg)

    def question_8(self, answer=None):

        if not is_instrument_object(answer):
            return

        required_pars = {"radius": 0.0075, "yheight": 0.03, "reflections": '"Y2O3.laz"'}

        msg = "The powderN component was found with the right parameters and position."

        source_name = name_of_component_type(answer, required_component="Source_div")
        if source_name is None:
            return

        self.last_component_in_instr_check(answer, comp_type_str="PowderN",
                                           required_pars=required_pars,
                                           success_msg=msg,
                                           required_AT_relative=source_name,
                                           required_AT_data=[0, 0, 1])

    def question_9(self, answer=None):

        if not is_instrument_object(answer):
            return

        required_pars = {"xwidth": 0.5, "yheight": 0.5, "filename": '"psd.dat"', "restore_neutron": 1}

        msg = "The PSD_monitor component was found with the right parameters and position."

        sample_name = name_of_component_type(answer, required_component="PowderN")
        if sample_name is None:
            return

        self.last_component_in_instr_check(answer, comp_type_str="PSD_monitor",
                                           required_pars=required_pars,
                                           success_msg=msg,
                                           required_AT_relative=sample_name,
                                           required_AT_data=[0, 0, 0.4])

    def question_10(self, answer=None):
        if not is_instrument_object(answer):
            return

        source_name = name_of_component_type(answer, required_component="Source_div")
        source = answer.get_component(source_name)

        expected_parameters = {"lambda0": "wavelength", "dlambda": "wavelength_half_spread"}
        actual_parameters =  [x.name for x in answer.parameters.parameters.values()]

        for component_par_name in expected_parameters:
            instr_parameter_name = expected_parameters[component_par_name]

            if instr_parameter_name not in actual_parameters:
                msg = ("The instrument did not contain a parameter with the name '"
                       + instr_parameter_name + "'.")
                print_box(msg, False)
                return

            if not hasattr(source, component_par_name):
                print(make_orange("Bug in expected values for this component."
                                  + str(component_par_name)))
                return

            found_value = getattr(source, component_par_name)
            if isinstance(found_value, Parameter):
                if found_value.name != instr_parameter_name:
                    print(make_green("A parameter object was assigned to the correct parameter"))
                    msg = ("The " + component_par_name + " was expected to have a parameter called '"
                           + str(instr_parameter_name) + "' but it was '" + str(found_value.name) + "'.")
                    print_box(msg, False)
                    return

            elif isinstance(found_value, str):
                if found_value != instr_parameter_name:
                    print(make_green("A parameter was assigned to the correct parameter"))
                    msg = ("The " + component_par_name + " was expected to have a parameter called '"
                           + str(instr_parameter_name) + "' but it was '" + str(found_value) + "'.")
                    print_box(msg, False)
                    return
            elif isinstance(found_value, (float, int)):
                msg = ("The " + component_par_name + " was expected to have a parameter called '"
                       + str(instr_parameter_name) + "' but it was set to the value " + str(found_value) + ".")
                print_box(msg, False)
                return

            else:
                print(make_orange("Did not recognize the parameter assigned to "
                                  + str(component_par_name)))
                return

        print_box("All parameters were correctly defined and assigned!", True)
