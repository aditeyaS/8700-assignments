// Aditeya Srivastava (aditeys@clemson.edu)
// https://github.com/aditeyaS/8700-assignment-2

#ifndef WOLF_H
#define WOLF_H

#include "animal.h"

class Wolf : public Animal {
    private:
        static int count;

    public:
        // constructors
        Wolf() : Animal("wolf", "growl", "chicken") {}

        // destructor
        ~Wolf() {count--;}

        Animal* clone() {
            count++;
            return new Wolf(*this);
        }

        // getters or accessors
        static int getCount(){return count;}
};

#endif

int Wolf::count = 0;