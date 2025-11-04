import mcstasscript as ms

from itertools import permutations

from .quiz import Quiz, make_red, make_green, make_orange, print_box
from .helpers import name_of_component_type, is_instrument_object

class UnionSubQuiz5Loggers(Quiz):
    def __init__(self):
        super().__init__()

    def question_1(self, answer=None):

        if not is_instrument_object(answer):
            return

        required_pars = {"D_direction_1": '"z"', "D_direction_2": '"x"',
                         "D1_min": -0.07, "D1_max": 0.07, "D2_min": -0.07, "D2_max": 0.07,
                         "n1": 200, "n2":200}

        msg = "The logger component was added correctly!"

        required_component = "Union_logger_2D_space"

        logger_name = name_of_component_type(answer, required_component=required_component)
        if logger_name is None:
            return

        this_comp = answer.get_component(logger_name)
        if this_comp.filename is None:
            print_box("Remember to provide a filename!", False)

        filenames = []
        for comp in answer.make_component_subset():
            if hasattr(comp, "filename"):
                if comp.filename in filenames:
                    print_box("All the filenames need to be unique! Two of " + str(comp.filename) + " found.", False)
                    return
                else:
                    filenames.append(comp.filename)

        self.last_component_in_instr_check(answer, comp_type_str=required_component,
                                           required_pars=required_pars, comp_name=logger_name,
                                           success_msg=msg,
                                           required_AT_relative="cryostat_center",
                                           required_AT_data=[0, 0, 0])

    def question_2(self, answer=None):

        if not is_instrument_object(answer):
            return

        required_pars = {"D_direction_1": '"z"', "D_direction_2": '"y"',
                         "D1_min": -0.07, "D1_max": 0.07, "D2_min": -0.1, "D2_max": 0.2,
                         "n1": 200, "n2":200}

        msg = "The logger component was added correctly!"

        required_component = "Union_logger_2D_space"

        logger_name = name_of_component_type(answer, required_component=required_component)
        if logger_name is None:
            return

        this_comp = answer.get_component(logger_name)
        if this_comp.filename is None:
            print_box("Remember to provide a filename!", False)

        filenames = []
        for comp in answer.make_component_subset():
            if hasattr(comp, "filename"):
                if comp.filename in filenames:
                    print_box("All the filenames need to be unique! Two of " + str(comp.filename) + " found.", False)
                    return
                else:
                    filenames.append(comp.filename)

        self.last_component_in_instr_check(answer, comp_type_str=required_component,
                                           required_pars=required_pars, comp_name=logger_name,
                                           success_msg=msg,
                                           required_AT_relative="cryostat_center",
                                           required_AT_data=[0, 0, 0])

    def question_3(self, answer=None):

        if not is_instrument_object(answer):
            return

        required_pars = {"Q_direction_1": '"z"', "Q_direction_2": '"x"',
                         "Q1_min": -3.3, "Q1_max": 3.3, "Q2_min": -3.3, "Q2_max": 3.3,
                         "n1": 200, "n2":200}

        msg = "The logger component was added correctly!"

        required_component = "Union_logger_2DQ"

        logger_name = name_of_component_type(answer, required_component=required_component)
        if logger_name is None:
            return

        this_comp = answer.get_component(logger_name)
        if this_comp.filename is None:
            print_box("Remember to provide a filename!", False)

        filenames = []
        for comp in answer.make_component_subset():
            if hasattr(comp, "filename"):
                if comp.filename in filenames:
                    print_box("All the filenames need to be unique! Two of " + str(comp.filename) + " found.", False)
                    return
                else:
                    filenames.append(comp.filename)

        self.last_component_in_instr_check(answer, comp_type_str=required_component,
                                           required_pars=required_pars, comp_name=logger_name,
                                           success_msg=msg)

    def question_4(self, answer=None):
        """
        Run a simulation with 1E7 rays at Bragg condition for the 010 reflection at a wavelength of 4 Å  and 5 Å.
        Look at the background visible on banana_tof_detector / banana_detector for both. Which of these have the most background?

        - A: The simulation at $\\lambda=4$Å
        - B: The simulation at $\\lambda=5$Å
        """

        feedback = {"A": "Yes, there are all sorts of spurions!",
                    "B": "No, even though there are more signal than purely the Bragg peak, the other setting has more.",
                    }

        self.multiple_choice(answer=answer, correct_answer="A", feedback=feedback)

    def question_5(self, answer=None):
        """
        Look at the logger results at the two wavelengths, what clue do they give of the big difference between the
        background at the two energies?

        - A: Additional scattering from the Sample in the form of incoherent scattering
        - B: Additional scattering from the Sample in the form of single crystal scattering
        - C: Additional scattering from the Cryostat in the form of incoherent scattering
        - D: Additional scattering from the Cryostat in the form of powder scattering
        """

        feedback = {"A": "That doesn't change that much with wavelength, but it is hard to see. We really need better information!",
                    "B": "We have different angles, but the sample scattering should be similar. This is hard to see, we need more data!",
                    "C": "That doesn't change that much with wavelength, but it is hard to see. We really need better information!",
                    "D": "Yes, that is what is going on, but we can get more clear data on this!"}

        self.multiple_choice(answer=answer, correct_answer="D", feedback=feedback)

    def question_6(self, answer=None):

        if not is_instrument_object(answer):
            return

        if not "order_total" in answer.parameters.parameters:
            print_box("The parameter was not found in the instrument parameters, did you change the name from order_total?", False, False)
            return
        else:
            par = answer.parameters["order_total"]

        for comp in answer.make_component_subset():
            if "logger" in comp.component_name:
                if comp.order_total != "order_total" and comp.order_total is not par:
                    print_box("Found logger named '" + comp.name + "' which didn't have order_total assigned to the new parameter.", False)
                    return

        print_box("Great, all loggers now have the order_total parameter!", True)

    def question_7(self, answer=None):

        if not is_instrument_object(answer):
            return

        if not "order_total" in answer.parameters.parameters:
            print_box("The parameter was not found in the instrument parameters, did you change the name from order_total?", False, False)
            return
        else:
            par = answer.parameters["order_total"]

        for comp in answer.make_component_subset():
            if "logger" in comp.component_name:
                if comp.order_total != "order_total" and comp.order_total is not par:
                    print_box("Found logger named '" + comp.name + "' which didn't have order_total assigned to the new parameter.", False)
                    return

        required_pars = {"Q_direction_1": '"z"', "Q_direction_2": '"x"',
                         "Q1_min": -3.3, "Q1_max": 3.3, "Q2_min": -3.3, "Q2_max": 3.3,
                         "n1": 200, "n2": 200, "target_geometry": '"sample"'}

        msg = "The logger component was added correctly!"

        required_component = "Union_logger_2DQ"

        logger_name = name_of_component_type(answer, required_component=required_component)
        if logger_name is None:
            return

        this_comp = answer.get_component(logger_name)
        if this_comp.filename is None:
            print_box("Remember to provide a filename!", False)

        filenames = []
        for comp in answer.make_component_subset():
            if hasattr(comp, "filename"):
                if comp.filename in filenames:
                    print_box("All the filenames need to be unique! Two of " + str(comp.filename) + " found.", False)
                    return
                else:
                    filenames.append(comp.filename)

        self.last_component_in_instr_check(answer, comp_type_str=required_component,
                                           required_pars=required_pars, comp_name=logger_name,
                                           success_msg=msg)

    def question_8(self, answer=None):

        if not is_instrument_object(answer):
            return


        if not "order_total" in answer.parameters.parameters:
            print_box("The parameter was not found in the instrument parameters, did you change the name from order_total?", False, False)
            return
        else:
            par = answer.parameters["order_total"]

        for comp in answer.make_component_subset():
            if "logger" in comp.component_name:
                if comp.order_total != "order_total" and comp.order_total is not par:
                    print_box("Found logger named '" + comp.name + "' which didn't have order_total assigned to the new parameter.", False)
                    return

        required_pars = {"Q_direction_1": '"z"', "Q_direction_2": '"x"',
                         "Q1_min": -3.3, "Q1_max": 3.3, "Q2_min": -3.3, "Q2_max": 3.3,
                         "n1": 200, "n2": 200, "target_geometry": '"orange_layer_0_layer,orange_layer_1_layer"'}

        msg = "The logger component was added correctly!"

        required_component = "Union_logger_2DQ"

        logger_name = name_of_component_type(answer, required_component=required_component)
        if logger_name is None:
            return

        this_comp = answer.get_component(logger_name)
        if this_comp.filename is None:
            print_box("Remember to provide a filename!", False)

        filenames = []
        for comp in answer.make_component_subset():
            if hasattr(comp, "filename"):
                if comp.filename in filenames:
                    print_box("All the filenames need to be unique! Two of " + str(comp.filename) + " found.", False)
                    return
                else:
                    filenames.append(comp.filename)

        self.last_component_in_instr_check(answer, comp_type_str=required_component,
                                           required_pars=required_pars, comp_name=logger_name,
                                           success_msg=msg)

    def question_9(self, answer=None):
        """
        Run the simulation with a wavelength of 4 Å and order_total=1. Look at the logger showing scattering in the cryostat.
        What are the two vertical lines?

        - A: First order incoherent scattering in cryostat
        - B: First order powder scattering in cryostat
        - C: First order single crystal scattering in the sample
        - D: Second order incoherent scattering in cryostat
        - E: Second order powder scattering in cryostat
        - F: Second order single crystal scattering in the sample
        """

        feedback = {"A": "No, but it is first order and in the cryostat.",
                    "B": "Yes, these are powder lines!",
                    "C": "No, the feature is not visible in the logger 2DQ targeting the sample",
                    "D": "No, order_total ensures we only see first order scattering",
                    "E": "No, order_total ensures we only see first order scattering",
                    "F": "No, order_total ensures we only see first order scattering",}

        self.multiple_choice(answer=answer, correct_answer="B", feedback=feedback)

    def question_10(self, answer=None):
        """
        Run the simulation in the Bragg condition with a wavelength of 4 Å and the order_total parameter of 1
        to see the first order of scattering. Find the Bragg peak on the 2D scattering vector logger (only a single pixel).
        Where is it located?

        - A: $Q_z$=  0.49 Å$^{-1}$, $Q_x$ =  0.00 Å$^{-1}$
        - B: $Q_z$= -0.24 Å$^{-1}$, $Q_x$ = -1.02 Å$^{-1}$
        - C: $Q_z$=  0.88 Å$^{-1}$, $Q_x$ = -1.40 Å$^{-1}$
        - D: $Q_z$=  1.21 Å$^{-1}$, $Q_x$ =  0.48 Å$^{-1}$
        """

        feedback = {"A": "No, find the single pixel and get the coordinates using the mouse!",
                    "B": "No, find the single pixel and get the coordinates using the mouse!",
                    "C": "Yes, that matches our Bragg condition.",
                    "D": "No, find the single pixel and get the coordinates using the mouse!"
                    }

        self.multiple_choice(answer=answer, correct_answer="C", feedback=feedback)

    def question_11(self, answer=None):
        """
        Run the simulation in the Bragg condition with a wavelength of 4 Å and the order_total parameter of 0
        to see all  orders of scattering. On the 2D Q logger we 4 lines, two at constant $Q_z$ and two at an angle.
        We wish to understand the two at an angle. Use the parameters available and the loggers looking at only sample / cryostat
        o find the origin of the two lines by running additional simulations.

        - A: First order scattering in sample
        - B: First order scattering in cryostat
        - C: Second order scattering in sample (2 scattering events in sample)
        - D: Second order scattering in cryostat (2 scattering events in cryostat)
        - E: Second order scattering in sample (first cryostat, then sample)
        - F: Second order scattering in cryostat (first sample, then cryostat)
        """

        feedback = {"A": "No, they are not visible with order_total=1 so that can't be the origin.",
                    "B": "No, they are not visible with order_total=1 so that can't be the origin.",
                    "C": "No, they are not visible on the logger 2DQ which targets the sample.",
                    "D": "No, if we run out of the Bragg condition the signal isn't visible so the sample is included.",
                    "E": "No, they are not visible on the logger 2DQ which targets the sample with order_total=2.",
                    "F": "Yes, since we see them with order_total=2 in the cryostat and not when sample is rotated out of the Bragg condition!",
                    }

        self.multiple_choice(answer=answer, correct_answer="F", feedback=feedback)

    def question_12(self, answer=None):
        """
        In the logger 2D Q recording scattering at all orders we see some broad lines across the narrow lines.
        Look at these at different values of order_total. What are these?

        - A: Powder scattering from a ray that scattered from the sample at previous scattering
        - B: Incoherent scattering from a ray that scattered from the sample at previous scattering
        - C: Powder scattering from a ray that scattered from the cryostat at previous scattering
        - D: Incoherent scattering from a ray that scattered from the cryostat at previous scattering
        """

        feedback = {"A": "No, they appear even when the sample is out of the Bragg condition.",
                    "B": "No, they appear even when the sample is out of the Bragg condition.",
                    "C": "Yes, they are always opposite to the narrow lines in the previous order!",
                    "D": "No, they are too sharp for that even though."}

        self.multiple_choice(answer=answer, correct_answer="C", feedback=feedback)