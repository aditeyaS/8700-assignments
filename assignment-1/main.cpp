// Aditeya Srivastava (aditeys@clemson.edu)
// https://github.com/aditeyaS/8700-assignment-1

#include "rotator.h"

#include <string>
#include <iostream>
using namespace std;

int main(int nArg, char** argList) {
    if (nArg != 5) {
        cout << "Invalid input" << endl;
        cout << "Eg command: ./rotator input.ppm output.ppm -r 90" << endl;
        return 0;
    } else {
        Rotator *rotator = rotator->getInstance();
        rotator->rotate(argList[1], argList[3], argList[4], argList[2]);
    }
    return 0;
}