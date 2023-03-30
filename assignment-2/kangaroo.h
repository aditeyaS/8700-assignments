// Aditeya Srivastava (aditeys@clemson.edu)
// https://github.com/aditeyaS/8700-assignment-2

#ifndef KANGAROO_H
#define KANGAROO_H

#include "animal.h"

class Kangaroo : public Animal {
    private:
        static int count;

    public:
        // constructors
        Kangaroo() : Animal("kangaroo", "click", "carrots"){}

        // destructor
        ~Kangaroo() {count--;}

        Animal* clone() {
            count++;
            return new Kangaroo(*this);
        }

        // getters or accessors
        static int getCount(){return count;}
};

#endif

int Kangaroo::count = 0;