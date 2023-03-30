# https://github.com/aditeyaS/8700-assignment-3

from car import Car
from ev import Ev

c = Car(50, "Ferrari", "red")
c.print()
print(c.getModel() + " accelerated. New speed is " + str(c.accelerate()) + " mph.\n")

c = Car(70, "Lamborghini", "black")
c.print()
print(c.getModel() + " decelerated. New speed is " + str(c.decelerate()) + " mph.\n")

print("Car count: " + str(Car.getNumCars()) + "\n")

ev = Ev(40, "Tesla", "white", 120.0, 3)
ev.print()
print(ev.getModel() + " accelerated. New speed is " + str(ev.accelerate()) + " mph.\n")

ev = Ev(60, "Nissan", "blue", 100.0, 2)
ev.print()
print(ev.getModel() + " decelerated. New speed is " + str(ev.decelerate()) + " mph.\n")

print("Car count: " + str(Car.getNumCars()))