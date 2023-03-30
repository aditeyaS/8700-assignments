// Aditeya Srivastava (aditeys@clemson.edu)
// https://github.com/aditeyaS/8700-assignment-1

#ifndef PPM_H
#define PPM_H

#include "colorPixel.h"

#include <string>
#include <vector>
using namespace std;

class Ppm {
    private:
        string magicNumber;
        unsigned int width;
        unsigned int height;
        unsigned int pixelValueMax;
        vector<ColorPixel> pixels;

    public:
        // constructors
        Ppm() = default;
        Ppm(const string &file);

        // destructors
        ~Ppm();

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