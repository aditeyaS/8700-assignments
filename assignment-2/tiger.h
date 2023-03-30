// Aditeya Srivastava (aditeys@clemson.edu)
// https://github.com/aditeyaS/8700-assignment-2

#ifndef TIGER_H
#define TIGER_H

#include "animal.h"

class Tiger : public Animal {
    private:
        static int count;

    public:
        // constructors
        Tiger() : Animal("tiger", "roar", "meat") {}

        // destructor
        ~Tiger(){count--;}

        Animal* clone() {
            count++;
            return new Tiger(*this);
        }

        // getters or accessors
        static int getCount(){return count;}
};

#endif

int Tiger::count = 0;
