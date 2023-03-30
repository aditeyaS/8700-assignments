// Aditeya Srivastava (aditeys@clemson.edu)
// https://github.com/aditeyaS/8700-assignment-1

#include "ppm.h"
#include "pgm.h"
#include "rotator.h"

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

Rotator* Rotator::instance;

void Rotator::rotate(string inputFile, string rotationMode, string angle, string outputFile) {
    // verifying input angle
    for (int i=0; i < angle.length(); i++) {
        if(!isdigit(angle[i])) {
            cout << "Invalid angle: " << angle << endl;
            cout << "90*n (n=0,1,2,..) are valid angles" << endl;
            return;
        }
    }

    int modAngle = stoi(angle) % 360;
    if (!(modAngle == 0 || modAngle == 90 || modAngle == 180 || modAngle == 270)) {
        cout << "Invalid angle: " << angle << endl;
        cout << "90*n (n=0,1,2,..) are valid angles" << endl;
        return;
    }

    // verifying input direction
    char direction;
    if (rotationMode.length() != 2) {
            cout << "Invalid rotation mode: " << rotationMode << endl;
            cout << "-r OR -l are valid modes" << endl;
            return;
    } else {
        direction = rotationMode.at(1);
        if (!(direction == 'r' || direction == 'l')) {
            cout << "Invalid rotation mode: " << rotationMode << endl;
            cout << "-r OR -l are valid modes" << endl;
            return;
        }
    }

    // getting the magic number
    ifstream infile(inputFile, ifstream::binary);
    string magicNumber;
    if (!infile.is_open()) {
        cout << "Opening " << inputFile << " failed!" << endl;
        return;
    }
    infile >> magicNumber;
    infile.close();

    if (magicNumber == "P2" || magicNumber == "P5") {
        // pgm files
        Pgm* pgm = new Pgm(inputFile);
        pgm->rotate(direction, modAngle, outputFile);
    } else if (magicNumber == "P3" || magicNumber == "P6") {
        // ppm files
        Ppm* ppm = new Ppm(inputFile);
        ppm->rotate(direction, modAngle, outputFile);
    } else {
        // other files
        cout << "Unsupported file with magic number: " << magicNumber << endl;
        cout << "Only pgm and ppm files (P2,P3,P5,P6) are supported." << endl;
    }
}
