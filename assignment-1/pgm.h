// Aditeya Srivastava (aditeys@clemson.edu)
// https://github.com/aditeyaS/8700-assignment-1

#ifndef PGM_H
#define PGM_H

#include "grayPixel.h"

#include <string>
#include <vector>
using namespace std;

class Pgm {
    private:
        string magicNumber;
        int width;
        int height;
        int pixelValueMax;
        vector<GrayPixel> pixels;

    public:
        // constructors
        Pgm() = default;
        Pgm(const string &file);

        // destructors
        ~Pgm();

        // methods
        void read(const string &file);
        void rotate(char direction, int angle, string newFileName);

        // getters
        string getMagicNumber() {return magicNumber;}
        int getWidth() {return width;}
        int getHeight() {return height;}
        int getPixelValueMax() {return pixelValueMax;}
};

#endif
