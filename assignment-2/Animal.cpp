// Aditeya Srivastava (aditeys@clemson.edu)
// https://github.com/aditeyaS/8700-assignment-2

#include "animal.h"

Animal::Animal(string animalName, string speak, string food) {
    this->animalName = animalName;
    this->givenName = "";
    this->speak = speak;
    this->food = food;
}

ostream& operator<<(ostream& out, const Animal& animal) {
    out << "I am a " << animal.animalName <<
        ", my name is " << animal.givenName <<
        ", I " << animal.speak << ", and I eat " << animal.food;
    return out;
}