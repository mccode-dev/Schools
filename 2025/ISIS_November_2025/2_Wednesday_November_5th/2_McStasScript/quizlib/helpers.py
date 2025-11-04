import mcstasscript as ms
from .quiz import make_red


def is_instrument_object(answer):
    if answer is None:
        print("Insert your answer in the question above, it has to be an instrument object.")
        return False

    if not isinstance(answer, ms.interface.instr.McStas_instr):
        if isinstance(answer, ms.helper.mcstas_objects.Component):
            print(make_red("The answer should be an instrument object, a component object was provided."))
        else:
            print(make_red("The answer should be an instrument object."))
        return False

    return True


def name_of_component_type(answer, required_component):
    # Find reference to existing component, last of the type
    if is_instrument_object(answer):
        type_name_dict = {x.component_name: x.name for x in answer.component_list}

        if required_component not in type_name_dict:
            print(make_red("Didn't find the " + required_component + " component in the instrument,"
                           + " you should continue to build on the instrument object from the last"
                           + " question."))
            return None

        return type_name_dict[required_component]
