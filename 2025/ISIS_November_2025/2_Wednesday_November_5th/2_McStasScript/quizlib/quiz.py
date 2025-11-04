import textwrap

import mcstasscript as ms

class bcolors:
    """
    Helper class that contains formatting classes and functions
    """
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'

def make_green(input_string):
    return bcolors.OKGREEN + input_string + bcolors.ENDC


def make_orange(input_string):
    return bcolors.WARNING + input_string + bcolors.ENDC


def make_red(input_string):
    return bcolors.FAIL + input_string + bcolors.ENDC


def make_bold(input_string):
    return bcolors.BOLD + input_string + bcolors.ENDC


def print_box(text, correct, valid=True):
    if not valid:
        print(make_bold(make_orange("Not recognized")))
    else:
        if correct:
            print(make_bold(make_green("Correct!")))
        else:
            print(make_bold(make_red("Incorrect")))

    if text != "":
        print(textwrap.fill(text, 80))


class Quiz:
    def multiple_choice(self, answer, correct_answer, feedback):

        if answer is None:
            print("Insert your answer in the question above.")
            return

        if isinstance(correct_answer, list):
            correct = answer in correct_answer
        else:
            correct = answer == correct_answer
        
        if answer not in feedback:
            message = "This multiple choice question did not contain that option!"
            valid = False
        else:
            message = feedback[answer]
            valid = True

        print_box(message, correct, valid=valid)

    def insert_value(self, answer, correct_answer,
                     feedback_correct="", feedback_below="", feedback_above="",
                     tollerance_factor=None, tollerance_interval=None):

        if answer is None:
            print("Insert your answer in the question above.")
            return

        if tollerance_interval is not None and tollerance_factor is not None:
            print("Question bug, use only tollerance_factor or tollerance_interval!")

        lower_limit = correct_answer
        if tollerance_factor is not None:
            lower_limit *= 1 - tollerance_factor
        if tollerance_interval is not None:
            lower_limit -= 0.5*tollerance_interval

        upper_limit = correct_answer
        if tollerance_factor is not None:
            upper_limit *= 1 + tollerance_factor
        if tollerance_interval is not None:
            upper_limit += 0.5*tollerance_interval

        if not isinstance(answer, (float, int)):
            message = "This question needs a value as the answer"
            valid = False
            correct = False
        else:
            valid = True
            correct = lower_limit <= answer <= upper_limit
            if correct:
                message = feedback_correct
            else:
                if answer < correct_answer:
                    message = feedback_below
                else:
                    message = feedback_above

        print_box(message, correct, valid=valid)

    def type_and_attributes(self, answer, correct_type,
                            correct_object_msg="This is the correct type of object",
                            wrong_object_msg="This is not the correct type of object",
                            success_msg="The object is of the right type and its properties are as expected.",
                            required_attributes=None, missing_attr_msg=None, wrong_attr_msg=None):
        if answer is None:
            print("Insert your answer in the question above.")
            return

        correct_type = isinstance(answer, correct_type)

        if required_attributes is None:
            # only need to check type
            if correct_type:
                msg = correct_object_msg
            else:
                msg = wrong_object_msg

            print_box(msg, correct_type)
            return

        if missing_attr_msg is None:
            missing_attr_msg = {}

        if wrong_attr_msg is None:
            wrong_attr_msg = {}

        # If there are required attributes, check these and provide partial feedback
        if not correct_type:
            print(make_red(wrong_object_msg))
            return

        for req_attr in required_attributes:

            # Check if the attribute exists
            if not hasattr(answer, req_attr):
                if req_attr in missing_attr_msg:
                    msg = missing_attr_msg[req_attr]
                else:
                    msg = "Given answer object missed attribute called " + req_attr

                print(make_green(correct_object_msg))
                print_box(msg, False)
                return

            # Check if the value is as expected
            attribute_value = getattr(answer, req_attr)
            if not attribute_value == required_attributes[req_attr]:
                # Wrong value given
                if req_attr in wrong_attr_msg:
                    msg = wrong_attr_msg[req_attr]
                else:
                    msg = "Given answer object had wrong value in attribute called " + req_attr

                print(make_green(correct_object_msg))
                print_box(msg, False)
                return

        print_box(success_msg, True)

    def last_component_in_instr_check(self, answer, comp_type_str, required_pars=None,
                                      required_AT_relative=None,
                                      required_AT_data=None,
                                      required_ROTATED_relative=None,
                                      required_ROTATED_data=None,
                                      success_msg="Correct component found!",
                                      comp_name=None, print_output=True):
        if answer is None:
            print("Insert your answer in the question above.")
            return

        correct_type = isinstance(answer, ms.interface.instr.McStas_instr)
        if not correct_type:
            print(make_red("The answer should be an instrument object."))
            return

        if comp_name is None:
            comp = answer.get_last_component()
            specified_comp_str = " last component "
        else:
            comp = answer.get_component(comp_name)
            specified_comp_str = " " + comp_name + " "

        correct_component = comp.component_name == comp_type_str
        if not correct_component:
            print(make_red("The" + specified_comp_str + "in the instrument was not the expected type.\n"
                           "Found component of type: '" + comp.component_name + "' where '"
                           + comp_type_str + "' was expected."))
            return

        if required_AT_relative is not None:
            if required_AT_relative == "ABSOLUTE":
                correct_relative = comp.AT_relative == required_AT_relative
            else:
                correct_relative = comp.AT_reference == required_AT_relative

            if not correct_relative:
                print(make_green("Component type was correct!"))
                print(make_red("The" + specified_comp_str + "was not place relative to the expected component, '"
                               + required_AT_relative + "', but instead '"
                               + comp.AT_relative + "'."))
                return

            if required_AT_data is not None:
                for index in range(3):
                    if comp.AT_data[index] != required_AT_data[index]:
                        print(make_green("Component type was correct!"))
                        print(make_red("The" + specified_comp_str + "was not placed at the expected position of "
                                       + str(required_AT_data) + " but instead " + str(comp.AT_data) + "."))
                        return

        if required_ROTATED_relative is not None:
            if not comp.ROTATED_specified:
                print(make_green("Component type was correct!"))
                print(make_red("The" + specified_comp_str + "did not have any rotation specified which was required."))
                return

            if required_ROTATED_relative == "ABSOLUTE":
                correct_relative = comp.ROTATED_relative == required_ROTATED_relative
            else:
                correct_relative = comp.ROTATED_reference == required_ROTATED_relative

            if not correct_relative:
                print(make_green("Component type was correct!"))
                print(make_red("The" + specified_comp_str + "was not place relative to the expected component, '"
                               + required_ROTATED_relative + "', but instead '"
                               + comp.ROTATED_relative + "'."))
                return

            if required_ROTATED_data is not None:
                for index in range(3):
                    if comp.ROTATED_data[index] != required_ROTATED_data[index]:
                        print(make_green("Component type was correct!"))
                        print(make_red("The" + specified_comp_str + "was not placed at the expected position of "
                                       + str(required_ROTATED_data) + " but instead " + str(comp.ROTATED_data) + "."))
                        return

        if required_pars is None:
            # Stop here, question was correctly answered
            print_box(success_msg, True)
            return True

        for required_par in required_pars:
            if not hasattr(comp, required_par):
                print(make_orange("Bug in exercise, this component type didn't have the required parameter."))
            else:
                par_value = getattr(comp, required_par)
                expected_value_list = required_pars[required_par]
                if not isinstance(expected_value_list, list):
                    expected_value_list = [expected_value_list]

                if par_value not in expected_value_list:
                    print(make_green("Component type was correct!"))
                    msg = ("The parameter '" + required_par + "' was set to "
                           + str(par_value) + " instead of the expected "
                           + str(expected_value_list[0])) + "."
                    print_box(msg, False)
                    return

        if print_output:
            # All checks made but no problems found, all good!
            print_box(success_msg, True)

        return True













        
    
        

