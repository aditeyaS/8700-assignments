# https://github.com/aditeyaS/8700-assignment-3

from abc import ABC, abstractmethod

class Vehicle(ABC):
    @abstractmethod
    def print(self):
        pass