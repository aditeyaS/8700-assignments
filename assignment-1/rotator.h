// Aditeya Srivastava (aditeys@clemson.edu)
// https://github.com/aditeyaS/8700-assignment-1

#ifndef ROTATOR_H
#define ROTATOR_H

#include <string>
using namespace std;

class Rotator {
    private:
        static Rotator* instance;
        Rotator(){}

    public:
        // delete copy constructor
        Rotator(const Rotator&) = delete;

        static Rotator* getInstance() {
            if (!instance) instance = new Rotator;
            return instance;
        }
        void rotate(string inputFile, string rotationMode, string angle, string outputFile);
};

#endif