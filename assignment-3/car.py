# https://github.com/aditeyaS/8700-assignment-3

from vehicle import Vehicle

class Car(Vehicle):
    __speed: int
    __model: str
    __color: str
    # static variable
    numCars = 0

    # default constructor
    def __init__(self) -> None:
        self.__speed = 0
        self.__model = ""
        self.__color = ""

    # parameterized constructor
    def __init__(self, speed: int, model: str, color: str) -> None:
        self.__speed = speed
        self.__model = model
        self.__color = color
        Car.numCars += 1

    #getters or accessors
    def getSpeed(self) -> int:
        return self.__speed
    def getModel(self) -> str:
        return self.__model
    def getColor(self) -> str:
        return self.__color

    # setters or modifers
    def setSpeed(self, speed: int) -> None:
        self.__speed = speed
    def setModel(self, model: str) -> None:
        self.__model = model
    def setColor(self, color: str) -> None:
        self.__color = color

    @staticmethod
    def getNumCars() -> int:
        return Car.numCars

    # methods
    def accelerate(self) -> float:
        self.__speed += 10.0
        return self.__speed

    def decelerate(self) -> float:
        self.__speed -= 10.0
        return self.__speed

    def print(self) -> None:
        print("I am a " + self.__color + " " + self.__model + " at speed "\
            + str(self.__speed) + " mph")