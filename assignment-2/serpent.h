// Aditeya Srivastava (aditeys@clemson.edu)
// https://github.com/aditeyaS/8700-assignment-2

#ifndef SERPENT_H
#define SERPENT_H

#include "animal.h"

class Serpent : public Animal {
    private:
        static int count;

    public:
        // constructors
        Serpent() : Animal("serpent", "hiss", "mice") {}

        // destructor
        ~Serpent() {count--;}

        Animal* clone() {
            count++;
            return new Serpent(*this);
        }

        // getters or accessors
        static int getCount(){return count;}
};

#endif

int Serpent::count = 0;
