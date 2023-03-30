// Aditeya Srivastava (aditeys@clemson.edu)
// https://github.com/aditeyaS/8700-assignment-2

#ifndef LEMUR_H
#define LEMUR_H

#include "animal.h"

class Lemur : public Animal {
    private:
        static int count;

    public:
        // constructors
        Lemur() : Animal("lemur", "squeak", "fruit") {}

        // destructor
        ~Lemur() {count--;}

        Animal* clone() {
            count++;
            return new Lemur(*this);
        }

        // getters or accessors
        static int getCount(){return count;}
};

#endif

int Lemur::count = 0;