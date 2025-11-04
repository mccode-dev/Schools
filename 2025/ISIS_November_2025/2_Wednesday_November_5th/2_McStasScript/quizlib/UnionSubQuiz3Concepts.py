import mcstasscript as ms

from itertools import permutations

from .quiz import Quiz, make_red, make_green, make_orange, print_box
from .helpers import name_of_component_type, is_instrument_object

class UnionSubQuiz3Concepts(Quiz):
    def __init__(self):
        super().__init__()

    def question_1(self, answer=None):
        """
        What does a mask do?

        - A: Limits the volume where specified geometry component(s) is simulated to the volume of the mask
        - B: Remove the volume of the mask from specified geometry component(s)
        - C: Limit the volume where any geometry components is simulated to the volume of the mask
        """

        feedback = {"A": "Yes, the mask removes everything outside of itself for the specified geometries.",
                    "B": "No, only the part of the target volume inside the mask is simulated.",
                    "C": "No, masks need to be target to a specific list of geometries.",
                    }

        self.multiple_choice(answer=answer, correct_answer="A", feedback=feedback)

    def question_2(self, answer=None):
        """
        Can a mask target more than one geometry component?

        - A: No
        - B: Yes
        """

        feedback = {"A": "No, you can provide a comma separated list as the mask_string",
                    "B": "Yes, just use a comma separated list in the mask_string",
                    }

        self.multiple_choice(answer=answer, correct_answer="B", feedback=feedback)

    def question_3(self, answer=None):
        """
        How do you add a mask?

        - A: Use the specialized mask components
        - B: Use a geometry component with the mask_string parameter
        - C: Enter "mask" in the material_string of a geometry component
        """

        feedback = {"A": "No, there are no such components!",
                    "B": "Yes, the geometry components can act as masks",
                    "C": 'No, that can only be a material, "Exit" or "Vacuum"',
                    }

        self.multiple_choice(answer=answer, correct_answer="B", feedback=feedback)

    def question_4(self, answer=None):
        """
        What is the difference between mask mode "any" and "all"?

        - A: Whether all masks or just any mask have to cover a region of the masked geometry for it to be simulated
        - B: Whether a mask will mask all other geometries or just its target
        - C: Whether the entire masked geometry have to be contained or just part of it
        """

        feedback = {"A": "Yes, it only matters when multiple masks cover a geometry.",
                    "B": "No, it is related to the logic when multiple masks target one geometry.",
                    "C": "No, it is related to the logic when multiple masks target one geometry.",
                    }

        self.multiple_choice(answer=answer, correct_answer="A", feedback=feedback)

    def question_5(self, answer=None):
        """
        What does an exit volume do?

        - A: Releases the ray from the union master once a ray leaves an exit geometry
        - B: Releases the ray from the union master once a ray enters an exit geometry
        """

        feedback = {"A": "No, it is released as soon as it enters an Exit geometry.",
                    "B": "Yes, the Union_master simulation stops when a ray enters an Exit geometry.",
                    }

        self.multiple_choice(answer=answer, correct_answer="B", feedback=feedback)

    def question_6(self, answer=None):
        """
        What situations can exit volumes be helpful?

        - A: Want to use a non Union component within a Union system
        - B: Want to jump between Union masters
        """

        feedback = {"A": "Yes, an Exit geometry in combination with number_of_activations can achieve this!",
                    "B": "No, for that one would use the McStas jump feature, but shouldn't be needed!",
                    }

        self.multiple_choice(answer=answer, correct_answer="A", feedback=feedback)

    def question_7(self, answer=None):
        """
        What type of Union component have the number_of_activations parameter?

        - A: Process components
        - B: Material components
        - C: Geometry components
        - D: Master components
        """

        feedback = {"A": "No, process components do not have that parameter",
                    "B": "No, material components do not have that parameter ",
                    "C": "Yes, geometry components always have that parameter",
                    "D": "No, the master component does not have that parameter",
                    }

        self.multiple_choice(answer=answer, correct_answer="C", feedback=feedback)

    def question_8(self, answer=None):
        """
        What does the number_of_activations parameter do?

        - A: Sets the number of Union master components that will use this component
        - B: Sets how many copies of this component should be simulated in next master
        """

        feedback = {"A": "Yes, each subsequent master subtracts one from number_of_activations, and the geometry is simulated until it reaches 0.",
                    "B": "No, only one copy of each geometry component is simulated in each master",
                    }

        self.multiple_choice(answer=answer, correct_answer="A", feedback=feedback)

    def question_9(self, answer=None):
        """
        What is the default for number_of_activations?
        """

        self.insert_value(answer=answer, correct_answer=1, feedback_correct="",
                          feedback_below="No, then the component wouldn't be activated per default.",
                          feedback_above="No, then the default case would be each geometry being simulated in multiple masters.")

    def question_10(self, answer=None):
        """
        When would one use the number_of_activations?

        - A: When having an external component in a Union system
        - B: When wanting to disable a geometry like a WHEN statement
        - C: When it is necessary to simulate the same geometry in multiple masters
        """

        feedback = {"A": "Yes, in conjunction with an Exit geometry and an additional Union_master",
                    "B": "Yes, setting number_of_activations to 0 disables the geometry component",
                    "C": "Yes, the number_of_activation describes how many masters it will be simulated in",
                    }

        if not isinstance(answer, list):
            print('Hint: this question has more than one right answer, you can give a list ["A", "B"].')

        if not isinstance(answer, list):
            answer = [answer]

        for single_answer in answer:
            self.multiple_choice(answer=single_answer, correct_answer=["A", "B", "C"], feedback=feedback)







