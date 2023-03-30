from car import Car

class Ev(Car):
    __range: float
    __gen: int

    # default constructor
    def __init__(self) -> None:
        super().__init__()
        self.__range = 0.0
        self.__gen = 0

    # parameterized constructor
    def __init__(self, speed: int, model: str, color: str, range: float, gen: int) -> None:
        super().__init__(speed, model, color)
        self.__range = range
        self.__gen = gen

    # getters or accessors
    def getRange(self) -> float:
        return self.__range
    def getGen(self) -> int:
        return self.__gen

    # setters or modifers
    def setRange(self, range: float) -> None:
        self.__range = range
    def setGen(self, gen: int) -> None:
        self.__gen = gen

    # methods
    def print(self) -> None:
        print("I am a " + str(self.__gen) + " gen " + super().getColor() + " "\
            + super().getModel() + " at speed " + str(super().getSpeed()) + " mph. Range "\
            + str(self.__range) + " miles.")