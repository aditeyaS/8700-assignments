// Aditeya Srivastava (aditeys@clemson.edu)
// https://github.com/aditeyaS/8700-assignment-2

#ifndef ZOO_H
#define ZOO_H

#include "animal.h"

#include <vector>
#include <string>
using namespace std;

class Zoo {
    private:
        vector<Animal*> animalList;
        bool readSuccess;

        static Zoo* instance;
        Zoo(){}

    public:
        // destructor
        ~Zoo() {animalList.clear();}

        // deleting copy and =
        Zoo(const Zoo&) = delete;
        void operator=(Zoo const&) = delete;

        static Zoo* getInstance() {
            if(!instance) instance = new Zoo;
            return instance;
        }

        void read(vector<string> input);
        void display();

        int getCount() {return animalList.size();}
};

#endif
