// Aditeya Srivastava (aditeys@clemson.edu)
// https://github.com/aditeyaS/8700-assignment-2

#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>
using namespace std;

class Animal {
    private:
        string animalName;
        string givenName;
        string speak;
        string food;

    public:
        // constructers
        Animal(string animalName, string speak, string food);

        // destructor
        ~Animal(){}

        // clone (for cloning animals)
        virtual Animal* clone() = 0;

        // getters or accessors
        string getAnimalName() {return animalName;}
        string getGivenName() {return givenName;}
        string getSpeak() {return speak;}
        string getFood() {return food;}

        // setters or modifiers
        void setAnimalName(string animalName) {this->animalName = animalName;}
        void setGivenName(string givenName) {this->givenName = givenName;}
        void setSpeak(string speak) {this->speak = speak;}
        void setFood(string food) {this->food = food;}

        friend ostream& operator<<(ostream &out, const Animal &animal);
};

#endif