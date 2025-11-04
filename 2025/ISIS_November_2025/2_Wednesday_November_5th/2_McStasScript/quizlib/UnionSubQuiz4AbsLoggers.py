import mcstasscript as ms

from itertools import permutations

from .quiz import Quiz, make_red, make_green, make_orange, print_box
from .helpers import name_of_component_type, is_instrument_object

class UnionSubQuiz4AbsLoggers(Quiz):
    def __init__(self):
        super().__init__()

    def question_1(self, answer=None):

        if not is_instrument_object(answer):
            return

        required_pars = {"target_geometry": '"He3_gas"', "yheight": 0.5-0.02,
                         "n": 300, "filename": '"detector_signal.dat"'}

        msg = "The abs_logger component was added correctly!"

        abs_logger_name = name_of_component_type(answer, required_component="Union_abs_logger_1D_space")
        if abs_logger_name is None:
            return

        if abs_logger_name != "signal":
            print_box("The added component was not called 'signal' as requested!", False)

        filenames = []
        for comp in answer.make_component_subset():
            if hasattr(comp, "filename"):
                if comp.filename in filenames:
                    print_box("All the filenames need to be unique! Two of " + str(comp.filename) + " found.", False)
                    return
                else:
                    filenames.append(comp.filename)

        self.last_component_in_instr_check(answer, comp_type_str="Union_abs_logger_1D_space",
                                           required_pars=required_pars,
                                           success_msg=msg,
                                           required_AT_relative="He3_gas",
                                           required_AT_data=[0, 0, 0])

    def question_2(self, answer=None):

        if not is_instrument_object(answer):
            return

        required_pars = {"target_geometry": '"He3_gas"', "yheight": 0.5-0.02,
                         "n": 200, "time_bins": 300, "time_min": "t_min",
                         "time_max": "t_max", "filename": '"detector_signal_tof.dat"'}

        msg = "The abs_logger component was added correctly!"

        abs_logger_name = name_of_component_type(answer, required_component="Union_abs_logger_1D_space_tof")
        if abs_logger_name is None:
            return

        if abs_logger_name != "signal_tof":
            print_box("The added component was not called 'signal_tof' as requested!", False)

        filenames = []
        for comp in answer.make_component_subset():
            if hasattr(comp, "filename"):
                if comp.filename in filenames:
                    print_box("All the filenames need to be unique! Two of " + str(comp.filename) + " found.", False)
                    return
                else:
                    filenames.append(comp.filename)

        self.last_component_in_instr_check(answer, comp_type_str="Union_abs_logger_1D_space_tof",
                                           required_pars=required_pars,
                                           success_msg=msg,
                                           required_AT_relative="He3_gas",
                                           required_AT_data=[0, 0, 0])

    def question_3(self, answer=None):

        if not is_instrument_object(answer):
            return

        required_pars = {"D_direction_1": '"z"', "D_direction_2": '"y"',
                         "D1_min": -0.04, "D1_max": 0.04, "D2_min": -0.26, "D2_max": 0.26,
                         "n1": 300, "n2":300}

        msg = "The abs_logger component was added correctly!"

        abs_logger_name = name_of_component_type(answer, required_component="Union_abs_logger_2D_space")
        if abs_logger_name is None:
            return

        filenames = []
        for comp in answer.make_component_subset():
            if hasattr(comp, "filename"):
                if comp.filename in filenames:
                    print_box("All the filenames need to be unique! Two of " + str(comp.filename) + " found.", False)
                    return
                else:
                    filenames.append(comp.filename)

        self.last_component_in_instr_check(answer, comp_type_str="Union_abs_logger_2D_space",
                                           required_pars=required_pars,
                                           success_msg=msg,
                                           required_AT_relative="He3_gas",
                                           required_AT_data=[0, 0, 0])


    def question_4(self, answer=None):
        """
        Run a simulation without the SANS sample and without the beamstop.
        On the detectors, what is the y value of the direct beam?
        """

        below = "The detector does not have y values that low!"
        above = "I don't see any signal on the reference monitor with that large y value"
        correct = "Yes, the direct beam is at the bottom of the detector!"
        self.insert_value(answer, correct_answer=-0.245, tollerance_interval=2*0.0051,
                          feedback_below=below, feedback_above=above,
                          feedback_correct=correct)


    def question_5(self, answer=None):
        """
        Run the simulation with the SANS sample and without a beamstop.
        Where is the largest discrepancy between the reference and the Union signal?

        - A: The bottom of the detector (low y)
        - B: The center of the detector (0 y)
        - C: The top of the detector (high y)
        """

        feedback = {"A": "Yes, without a beamstop the direct beam hits the detector.",
                    "B": "No, the center of the detector seems to fit quite well.",
                    "C": "No, the top of the detector seems to fit quite well.",
                    }

        self.multiple_choice(answer=answer, correct_answer="A", feedback=feedback)

    def question_6(self, answer=None):
        """
        Why do we see this discrepancy?

        - A: The Union detector is more efficient than the reference
        - B: The direct beam hits the detector and scatters into it
        - C: Scattering of the SANS signal within the detector
        """

        feedback = {"A": "No, the Union detector has real efficiency, always lower than the ideal monitors.",
                    "B": "Yes, the beam hits the aluminium casing and scatters into the gas.",
                    "C": "To some extent yes, but there is a larger contribution.",
                    }

        self.multiple_choice(answer=answer, correct_answer="B", feedback=feedback)

    def question_7(self, answer=None):
        """
        Run the simulation with both the SANS sample and beamstop enabled at high wavelengths (lowest wavelength at 3 or higher).
        How would you describe the relationship between the reference and Union signal?

        - A: They agree
        - B: There is a scaling difference
        - C: There are large unexpected difference
        """

        feedback = {"A": "Yes, they are remarkably similar given the extra detail in the Union version.",
                    "B": "No, the detector efficiency of the simulated system is very high.",
                    "C": "No, maybe the simulation settings are off?",
                    }

        self.multiple_choice(answer=answer, correct_answer="A", feedback=feedback)

    def question_8(self, answer=None):
        """
        Run the simulation with both the SANS sample and beamstop enabled at high wavelengths
        (highest wavelength at 2 or lower).
        How is the agreement between the reference and Union signal?

        - A: They agree
        - B: There is a scaling difference
        - C: There are large unexpected difference
        """

        feedback = {"A": "No, at these low wavelengths there are some differences.",
                    "B": "Yes, at lower wavelengths the He3 absorption cross section is not great enough to have perfect efficiency.",
                    "C": "No, maybe the simulation settings are off?",
                    }

        self.multiple_choice(answer=answer, correct_answer="B", feedback=feedback)

    def question_9(self, answer=None):
        """
        Run the simulation with a very narrow wavelength spread around 6 AA,
        less than 1E-4 and compare the two tof diagrams.

        - A: The reference line is broader
        - B: The union line is broader
        - C: They are similar
        - D: The reference data has a lot of background
        - E: The Union data has a lot of background
        - F: The Union data has an unexpected feature
        """

        feedback = {"A": "No, try a narrower wavelength band to make it more visible.",
                    "B": "Yes, since the Union detector is the entire gas volume neutrons can be absorbed at different depths giving broadening of the detection time.",
                    "C": "No, the 1D plots may be similar, but there are differences in the 2D y, tof plots.",
                    "D": "No, there is no extra background in the reference data.",
                    "E": "Yes, the Union system simulates several kinds of background that all show up in some form.",
                    "F": "Well, yes, there are some small details, but nothing major.",
                    }

        if not isinstance(answer, list):
            print('Hint: this question has more than one right answer, you can give a list ["A", "B"].')

        if not isinstance(answer, list):
            answer = [answer]

        for single_answer in answer:
            self.multiple_choice(answer=single_answer, correct_answer=["B", "E"], feedback=feedback)

    def question_10(self, answer=None):
        """
        Run the simulation with a very narrow wavelength spread around 6 AA,
        less than 1E-4 and compare the two tof diagrams.

        - A: The reference line is broader
        - B: The union line is broader
        - C: They are similar
        - D: The reference data has a lot of background
        - E: The Union data has a lot of background
        - F: The Union data has an unexpected feature
        """

        feedback = {"A": "No, try a narrower wavelength band to make it more visible.",
                    "B": "Yes, since the Union detector is the entire gas volume neutrons can be absorbed at different depths giving broadening of the detection time.",
                    "C": "No, the 1D plots may be similar, but there are differences in the 2D y, tof plots.",
                    "D": "No, there is no extra background in the reference data.",
                    "E": "Yes, the Union system simulates several kinds of background that all show up in some form.",
                    "F": "Yes, there are some some significant effects from the regions with high intensity.",
                    }

        if not isinstance(answer, list):
            print('Hint: this question has more than one right answer, you can give a list ["A", "B"].')

        if not isinstance(answer, list):
            answer = [answer]

        for single_answer in answer:
            self.multiple_choice(answer=single_answer, correct_answer=["B", "E", "F"], feedback=feedback)


