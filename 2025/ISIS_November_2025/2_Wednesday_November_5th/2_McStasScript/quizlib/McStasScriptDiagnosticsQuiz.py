import mcstasscript as ms
from libpyvinyl.Parameters.Parameter import Parameter

from .quiz import Quiz
from .quiz import make_red, make_green, make_orange, print_box
from .helpers import name_of_component_type, is_instrument_object


"""
This exercise is about the user getting an instrument object and working with it

There will be three mystery instrument objects and the same questions for each:
    What kind of instrument is it?
    What sample is used?
    Any interesting parts?
    Any bugs?
    
The three mystery instruments are:
    Triple axis
    SANS
    Chopper diffractometer
    
Possible instruments:
    Triple axis
    Diffractometer Powder
    Diffractometer Single crystal
    Laue
    SANS
    Chopper direct spectrometer
    Chopper indirect spectrometer
    Chopper diffractometer
"""

class DiagnosticsQuiz(Quiz):
    def __init__(self):
        super().__init__()


    def instrument_1_question_1(self, answer=None):
        """
        What kind of instrument is described by the given instrument object?

        A: Laue Camera
        B: Triple Axis Spectrometer
        C: Diffractometer on continuous source
        D: Small Angle Neutron Scattering instrument
        E: Time of Flight Diffractometer
        F: Time of Flight Spectrometer
        """

        feedback = {"A": "No, try to use the diagram to identify the instrument type.",
                    "B": "Yes, this is a triple axis spectrometer.",
                    "C": "No, try to use the diagram to identify the instrument type.",
                    "D": "No, try to use the diagram to identify the instrument type.",
                    "E": "No, try to use the diagram to identify the instrument type.",
                    "F": "No, try to use the diagram to identify the instrument type."
                    }

        self.multiple_choice(answer=answer, correct_answer="B", feedback=feedback)

    def instrument_1_question_2(self, answer=None):
        """
        What sample component is used?

        A: Powder1
        B: PowderN
        C: SANS_spheres2
        D: Phonon_simple
        E: Single_crystal
        F: Incoherent
        G: Tunneling_sample
        """

        feedback = {"A": "No, use get_component to inspect the sample component.",
                    "B": "No, use get_component to inspect the sample component.",
                    "C": "No, use get_component to inspect the sample component.",
                    "D": "Yes! Very appropriate for a triple axis spectrometer.",
                    "E": "No, use get_component to inspect the sample component.",
                    "F": "No, use get_component to inspect the sample component.",
                    "G": "No, use get_component to inspect the sample component.",
                    }

        self.multiple_choice(answer=answer, correct_answer="D", feedback=feedback)

    def instrument_1_question_3(self, answer=None):
        """
        Does this instrument use any interesting McStas features?

        A: GROUP
        B: EXTEND
        C: WHEN
        D: JUMP
        E: SPLIT
        F: target_index
        """

        feedback = {"A": "No, the GROUP keyword was not used in this instrument.",
                    "B": "No, the EXTEND keyword was not used in this instrument.",
                    "C": "No, the WHEN keyword was not used in this instrument.",
                    "D": "No, the JUMP keyword was not used in this instrument.",
                    "E": "No, the SPLIT keyword was not used in this instrument.",
                    "F": "Yes, a target_index parameter was used on the sample.",
                    }

        self.multiple_choice(answer=answer, correct_answer="F", feedback=feedback)

    def instrument_1_question_4(self, answer=None):
        """
        With the standard settings of the instrument, the sample emits neutrons
        with energies around two peaks, one of which is measured. What is the
        energy of the peak that is not measured?
        """


        below = "I don't see any peak with this energy that is not already measured. Try to use the diagnostics tools."
        above = "I don't see any peak with this energy that is not already measured. Try to use the diagnostics tools."
        correct = "Yes, the there is an energy gain branch as well that adds ~6 meV to the initial 10 meV at this scattering vector."
        self.insert_value(answer, correct_answer=16.1, tollerance_interval=1.0,
                          feedback_below=below, feedback_above=above,
                          feedback_correct=correct)




    def instrument_2_question_1(self, answer=None):
        """
        What kind of instrument is described by the given instrument object?

        A: Laue Camera
        B: Triple Axis Spectrometer
        C: Diffractometer on continuous source
        D: Small Angle Neutron Scattering instrument
        E: Time of Flight Diffractometer
        F: Time of Flight Spectrometer
        """

        feedback = {"A": "No, try to use the diagram to identify the instrument type.",
                    "B": "No, try to use the diagram to identify the instrument type.",
                    "C": "No, try to use the diagram to identify the instrument type.",
                    "D": "No, try to use the diagram to identify the instrument type.",
                    "E": "Yes, this is a time of flight diffractometer.",
                    "F": "No, try to use the diagram to identify the instrument type."
                    }

        self.multiple_choice(answer=answer, correct_answer="E", feedback=feedback)

    def instrument_2_question_2(self, answer=None):
        """
        What sample component is used?

        A: Powder1
        B: PowderN
        C: SANS_spheres2
        D: Phonon_simple
        E: Single_crystal
        F: Incoherent
        G: Tunneling_sample
        """

        feedback = {"A": "Yes! The sample simulates one powder line.",
                    "B": "No, use get_component to inspect the sample component.",
                    "C": "No, use get_component to inspect the sample component.",
                    "D": "No, use get_component to inspect the sample component.",
                    "E": "No, use get_component to inspect the sample component.",
                    "F": "No, use get_component to inspect the sample component.",
                    "G": "No, use get_component to inspect the sample component.",
                    }

        self.multiple_choice(answer=answer, correct_answer="A", feedback=feedback)

    def instrument_2_question_3(self, answer=None):
        """
        Does this instrument use any interesting McStas features?

        A: GROUP
        B: EXTEND
        C: WHEN
        D: JUMP
        E: SPLIT
        F: target_index
        """

        feedback = {"A": "No, the GROUP keyword was not used in this instrument.",
                    "B": "Yes, the EXTEND keyword was used in this instrument.",
                    "C": "Yes, the WHEN keyword was used in this instrument.",
                    "D": "No, the JUMP keyword was not used in this instrument.",
                    "E": "No, the SPLIT keyword was not used in this instrument.",
                    "F": "No, a target_index parameter was not used in this instrument.",
                    }

        if not isinstance(answer, list):
            print('Hint: this question has more than one right answer, you can give a list ["A", "B"].')

        if not isinstance(answer, list):
            answer = [answer]

        for single_answer in answer:
            self.multiple_choice(answer=single_answer, correct_answer=["B", "C"], feedback=feedback)

    def instrument_2_question_4(self, answer=None):
        """
        What is the time width FWHM before the first chopper
        """

        below = "That is quite low, are you using the standard settings of the instrument?"
        above = "That's higher than expected, are you using the standard settings of the instrument?"
        correct = "Yes, that matches the time width before the first chopper!"
        self.insert_value(answer, correct_answer=0.003, tollerance_factor=0.15,
                          feedback_below=below, feedback_above=above,
                          feedback_correct=correct)

    def instrument_2_question_5(self, answer=None):
        """
        What is the time width FWHM bewteen the choppers
        """

        below = "That is quite low, are you using the standard settings of the instrument?"
        above = "That's higher than expected, are you using the standard settings of the instrument?"
        correct = "Yes, that matches the time width between the choppers!"
        self.insert_value(answer, correct_answer=0.00089, tollerance_factor=0.15,
                          feedback_below=below, feedback_above=above,
                          feedback_correct=correct)

    def instrument_2_question_6(self, answer=None):
        """
        What is the time width FWHM after both choppers
        """

        below = "That is quite low, are you using the standard settings of the instrument?"
        above = "That's higher than expected, are you using the standard settings of the instrument?"
        correct = "Yes, that matches the time width after the last chopper!"
        self.insert_value(answer, correct_answer=0.00038, tollerance_factor=0.15,
                          feedback_below=below, feedback_above=above,
                          feedback_correct=correct)

    def instrument_2_question_7(self, answer=None):
        """
        Add a view to the diagnostics object that show the correlation between time and x position.
        What shape does the correlation have after both choppers?
        - A: A circle
        - B: A line
        - C: A square aligned with the coordinate system
        - D: A square rotated 45 deg
        - E: An oval
        """

        feedback = {"A": "No, use the point after the counter_chopper and add_view('t', 'x').",
                    "B": "No, use the point after the counter_chopper and add_view('t', 'x').",
                    "C": "No, use the point after the counter_chopper and add_view('t', 'x').",
                    "D": "Yes, this is due to the choppers being counter rotating!",
                    "E": "No, use the point after the counter_chopper and add_view('t', 'x').",
                    }

        self.multiple_choice(answer=answer, correct_answer="D", feedback=feedback)

    def instrument_2_question_8(self, answer=None):
        """
        On the TOFdet monitor the single peak of the sample can be seen, giving an indication
        of the resolution of the instrument at 90 deg. Which of these configurations provide the highest resolution?

        - A: Both choppers enabled and frequency_multiplier of 1
        - B: One chopper enabled and frequency_multiplier of 1
        - C: One chopper enabled and frequency_multiplier of 2
        """

        feedback = {"A": "Yes, this combination provides the best resolution.",
                    "B": "No, both adding a second chopper and increasing the frequency_multiplier would improve the resolution.",
                    "C": "No, I measured a narrower peak at a different configuration, but not by much.",
                    }

        self.multiple_choice(answer=answer, correct_answer="A", feedback=feedback)

    def instrument_2_question_9(self, answer=None):
        """
        Replace the sample with a PowderN that use Na2Ca3Al2F14.laz as the reflection data
        but have the same physical shape and position as the current sample.
        Answer with instrument object. Set d_phi to 12.
        """

        sample_name = name_of_component_type(answer, required_component="PowderN")
        if sample_name is None:
            return

        sample = answer.get_component(sample_name)

        component_list = answer.make_component_subset()

        component_names = [x.name for x in component_list]
        component_types = [x.component_name for x in component_list]

        if "Powder1" in component_types:
            print(make_red("The old sample is still in the instrument, it should be removed"))
            return

        new_sample_index = component_types.index("PowderN")
        guide_index = component_names.index("guide2")

        if new_sample_index != guide_index + 1:
            print(make_red("The new sample should be after the 'guide2' component in the component sequence"))
            return

        required_pars = {"radius": 0.003, "yheight": 0.02, "reflections": '"Na2Ca3Al2F14.laz"', "d_phi": 12}
        success_msg = "The sample was exchanged successfully! Try to run the instrument."

        if sample.EXTEND != "if (!SCATTERED) ABSORB;\n":
            print(sample.EXTEND)
            print(make_red("The new sample should have the extend section 'if (!SCATTERED) ABSORB;'"))
            return

        self.last_component_in_instr_check(answer, "PowderN", comp_name=sample.name, required_pars=required_pars,
                                           required_AT_data=[0,0,"sample_position"], required_AT_relative="Source",
                                           success_msg=success_msg)

    def instrument_3_question_1(self, answer=None):
        """
        What kind of instrument is described by the given instrument object?

        A: Laue Camera
        B: Triple Axis Spectrometer
        C: Diffractometer on continuous source
        D: Small Angle Neutron Scattering instrument
        E: Time of Flight Diffractometer
        F: Time of Flight Spectrometer
        """

        feedback = {"A": "No, try to use the diagram to identify the instrument type.",
                    "B": "No, try to use the diagram to identify the instrument type.",
                    "C": "No, try to use the diagram to identify the instrument type.",
                    "D": "Yes, this is a SANS instrument.",
                    "E": "No, try to use the diagram to identify the instrument type.",
                    "F": "No, try to use the diagram to identify the instrument type."
                    }

        self.multiple_choice(answer=answer, correct_answer="D", feedback=feedback)

    def instrument_3_question_2(self, answer=None):
        """
        What sample component is used?

        A: Powder1
        B: PowderN
        C: SANS_spheres2
        D: Phonon_simple
        E: Single_crystal
        F: Incoherent
        G: Tunneling_sample
        """

        feedback = {"A": "No, use get_component to inspect the sample component.",
                    "B": "No, use get_component to inspect the sample component.",
                    "C": "Yes, this instrument uses the newest version of SANS_spheres.",
                    "D": "No, use get_component to inspect the sample component.",
                    "E": "No, use get_component to inspect the sample component.",
                    "F": "No, use get_component to inspect the sample component.",
                    "G": "No, use get_component to inspect the sample component.",
                    }

        self.multiple_choice(answer=answer, correct_answer="C", feedback=feedback)

    def instrument_3_question_3(self, answer=None):
        """
        Does this instrument use any interesting McStas features?

        A: GROUP
        B: EXTEND
        C: WHEN
        D: JUMP
        E: SPLIT
        F: target_index
        """

        feedback = {"A": "No, the GROUP keyword was not used in this instrument.",
                    "B": "Yes, the EXTEND keyword was used in this instrument.",
                    "C": "Yes, the WHEN keyword was used in this instrument.",
                    "D": "No, the JUMP keyword was not used in this instrument.",
                    "E": "Yes, the SPLIT keyword was used in this instrument.",
                    "F": "No, the target_index parameter was used in this instrument.",
                    }

        if not isinstance(answer, list):
            print('Hint: this question has more than one right answer, you can give a list ["A", "B"].')

        if not isinstance(answer, list):
            answer = [answer]

        for single_answer in answer:
            self.multiple_choice(answer=single_answer, correct_answer=["B", "C", "E"], feedback=feedback)


    def instrument_3_question_4(self, answer=None):
        """
        This instrument does not have a guide, add a curved guide between the source and the
        collimator section with 10 segments of Guide_gravity components and a rotation of 0.3 deg between each.
        """

        if answer is None:
            print("Insert your answer in the question above.")
            return

        correct_type = isinstance(answer, ms.interface.instr.McStas_instr)
        if not correct_type:
            print(make_red("The answer should be an instrument object."))
            return

        component_names = [x.name for x in answer.make_component_subset()]
        component_types = [x.component_name for x in answer.make_component_subset()]
        last_guide = None

        n_guide_gravities = 0
        for index, name in enumerate(component_names):
            if name == "source":
                if n_guide_gravities > 0:
                    print(make_red("Guide elements should be added after the source"))
                    return

            if name == "coll1":
                if n_guide_gravities == 0:
                    print(make_red("Guide elements should be added before the collimation section"))
                    return

            if component_types[index] == "Guide_gravity":
                n_guide_gravities += 1

                required_pars = {"w1": 0.03, "h1": 0.03, "m": 2, "l": 1.5}
                success_msg = "Guide element '" + name + "' added correctly"

                if last_guide is None:
                    required_AT_data = [0, 0, 2]
                    required_AT_relative = "source"
                else:
                    required_AT_data = [0, 0, last_guide.l + 0.01]
                    required_AT_relative = last_guide.name

                guide_check = self.last_component_in_instr_check(answer, "Guide_gravity", comp_name=name,
                                                                 required_ROTATED_data=[0, 0.3, 0],
                                                                 required_AT_data=required_AT_data,
                                                                 required_AT_relative=required_AT_relative,
                                                                 required_pars=required_pars,
                                                                 success_msg=success_msg)

                last_guide = answer.get_component(name)

                if not guide_check:
                    return

                guide_name = name

                if not guide_check:
                    print_box("Found a problem in a guide component", False)
                    return

        if n_guide_gravities != 10:
            print_box("Didn't find 10 Guide_gravity components", False)
            return

        source_name = name_of_component_type(answer, required_component="Source_simple")
        if source_name is None:
            return

        required_pars = {"focus_xw": 0.03, "focus_yh": 0.03, "dist": 2.0}
        success_msg = "Source updated correctly"

        check = self.last_component_in_instr_check(answer, "Source_simple", comp_name=source_name,
                                                   required_pars=required_pars, success_msg=success_msg)

        if not check:
            print("The source needs to be updated with new focusing parameters!")
            return

        success_msg = "First pinhole updated correctly"
        check = self.last_component_in_instr_check(answer, "Slit", comp_name="coll1",
                                                   required_AT_relative=guide_name,
                                                   success_msg=success_msg)

        if not check:
            print("The collimation section needs to be relative to the new guide!")
            return

        success_msg = "Last pinhole updated correctly, everything checks out!"
        check = self.last_component_in_instr_check(answer, "Slit", comp_name="coll2",
                                                   required_AT_data=[0,0,3],
                                                   required_AT_relative="coll1",
                                                   success_msg=success_msg)

        if not check:
            print("The last pinhole should have its position relative to the first pinhole!")
            return

    def instrument_3_question_5(self, answer=None):
        """
        The curved guide will introduce a wavelength cut off as neutrons with the lowest wavelengths
        can't be transported. Use the diagnostics features to find the wavelength where the
        transmission is half of the maximum.
        """

        below = "I don't see the cutoff that low, are you viewing the wavelength distribution before coll1?"
        above = "I don't see the cutoff that high, are you viewing the wavelength distribution before coll1?"
        correct = "Yes, the wavelength cut-off is in that region!"
        self.insert_value(answer, correct_answer=3.9, tollerance_interval=0.3,
                          feedback_below=below, feedback_above=above,
                          feedback_correct=correct)

    def instrument_3_question_6(self, answer=None):
        """
        Set run_to to sample_position
        """

        if not is_instrument_object(answer):
            return

        if answer.run_to_ref == "sample_position":
            message = "Yes, the instrument is set up for running to sample_position!"
            correct = True
            valid = True
        elif answer.run_to_ref is not None:
            message = "No, the instrument is set up to run to " + answer.run_to_ref + " instead of sample_position"
            correct = False
            valid = True
        else:
            message = "No, the instrument is set up to run to the end. Use the run_to method!"
            correct = False
            valid = True

        print_box(message, correct, valid=valid)


    def instrument_3_question_7(self, answer=None):
        """
        Check dump exists at sample_position
        """

        if not is_instrument_object(answer):
            return

        dump = answer.dump_database.get_dump("sample_position")

        if dump is None:
            message = "Didn't find a beam dump at the sample_position, did you run the instrument?"
            correct = False
            valid = True
        else:
            message = "A beam dump was found at the sample_position, great!"
            correct = True
            valid = True

        print_box(message, correct, valid=valid)

    def instrument_3_question_8(self, answer=None):
        """
        Set run_to to None and run_from to sample_position
        """

        if not is_instrument_object(answer):
            return

        if answer.run_from_ref == "sample_position":
            message_from = "Yes, the instrument is set up for running from sample_position!"
            correct_from = True
        elif answer.run_from_ref is not None:
            message_from = "No, the instrument is set up to run from " + answer.run_from_ref + " instead of sample_position"
            correct_from = False
        else:
            message_from = "No, the instrument is set up to run from the start. Use the run_from method!"
            correct_from = False

        print_box(message_from, correct_from, valid=True)

        if answer.run_to_ref == "sample_position":
            message_to = "No, the instrument is set up for running to sample_position, it needs to run to the end, use None!"
            correct_to = False
        elif answer.run_to_ref is not None:
            message_to = "No, the instrument is set up to run to " + answer.run_to_ref + " instead of to the end, use None"
            correct_to = False
        else:
            message_to = "Yes, the instrument is set up to run to the end."
            correct_to = True

        print_box(message_to, correct_to, valid=True)