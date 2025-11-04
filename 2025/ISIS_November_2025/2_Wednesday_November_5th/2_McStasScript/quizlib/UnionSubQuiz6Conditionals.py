import mcstasscript as ms

from itertools import permutations

from .quiz import Quiz, make_red, make_green, make_orange, print_box
from .helpers import name_of_component_type, is_instrument_object

class UnionSubQuiz6Conditionals(Quiz):
    def __init__(self):
        super().__init__()

    def question_1(self, answer=None):
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

    def question_2(self, answer=None):
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





