// Aditeya Srivastava (aditeys@clemson.edu)
// https://github.com/aditeyaS/8700-assignment-1

#include "ppm.h"
#include "colorPixel.h"

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Ppm::Ppm (const string &file) {
    read(file);
}

Ppm::~Ppm() {
    pixels.clear();
}

void Ppm::read (const string &file) {
    ifstream input;
    input.open(file.c_str(), ios::binary);
    if (!input) {
        cout << "Opening " << file << " failed!" << endl;
        return;
    }

    string line;
    int step = 0;

    // read header
    while (!input.eof()) {
        getline(input, line);
        if (line[0] == '#' || line.length() == 0) {
            // skip all comments
            continue;
        }
        if (step == 0) {
            // read magic number
            magicNumber = line;
            step ++;
        } else if (step == 1) {
            // read width and height
            width = stoi(line.substr(0, line.find(" ")));
            height = stoi(line.substr(line.find(" ") + 1));
            step ++;
        } else if (step ==2) {
            // read maximum grayscale value
            pixelValueMax = stoi(line);
            break;
        }
    }

    // read ASCII
    if (magicNumber == "P3") {
        // read ASCII
        while(!input.eof()) {
            string r, g, b;
            getline(input, r);
            getline(input, g);
            getline(input, b);
            pixels.push_back(ColorPixel(atoi(r.c_str()), atoi(g.c_str()), atoi(b.c_str())));
        }
    } else {
        // read binary
        for (int i = 0; i < width * height * 3; i++) {
            char r, g, b;
            input.read(&r, 1);
            input.read(&g, 1);
            input.read(&b, 1);
            ColorPixel cp((unsigned char) r, (unsigned char) g, (unsigned char) b);
            pixels.push_back(cp);
        }
    }
    input.close();
}

void Ppm::rotate (char direction, int angle, string newFileName) {
    ofstream output;
    output.open(newFileName, ios::binary);
    if (!output) {
        std::cout << "Writing " << newFileName << " failed!" << std::endl;
        return;
    }

    int outputWidth = width, outputHeight = height;
    vector<ColorPixel> rotatedPixels;
    if (angle == 0) {
        // 0  deg
        rotatedPixels = pixels;
    } else if ((direction == 'r' && angle == 90) || (direction == 'l' && angle == 270)) {
        // 90 deg clockwise OR 270 deg counter-clockwise
        outputWidth = height;
        outputHeight = width;
        for (int i = (height - 1) * width; i < width * height; i++) {
            for (int j = i; j >= 0; j = j- width) {
                rotatedPixels.push_back(pixels[j]);
            }
        }
    } else if ((direction == 'r' && angle == 270) || (direction == 'l' && angle == 90)) {
        // 270 deg clockwise OR 90 deg counter-clockwise
        outputWidth = height;
        outputHeight = width;
        for (int i = width - 1; i >= 0; i--) {
            for (int j = 0; j < width * height; j = j + width) {
                rotatedPixels.push_back(pixels[i+j]);
            }
        }
    } else {
        // 180 deg for both will be same
        for(int i = height * width - 1; i > 0; i = i - width) {
            for (int j = 0; j < width; j++) {
                rotatedPixels.push_back(pixels[i-j]);
            }
        }
    }

    // write header
    output << magicNumber << "\n# created by Aditeya (aditeys) assignment 1\n"
            << outputWidth << " " << outputHeight << endl
            << pixelValueMax << endl;

    // write data
    for (int i = 0; i < rotatedPixels.size(); i++) {
        if (magicNumber == "P3") {
            // write ASCII
            output << to_string(rotatedPixels.at(i).getRed()) << endl
                   << to_string(rotatedPixels.at(i).getGreen()) << endl
                   << to_string(rotatedPixels.at(i).getBlue()) << endl;
        } else {
            // write binary
            output << (unsigned char)rotatedPixels.at(i).getRed()
                   << (unsigned char)rotatedPixels.at(i).getGreen()
                   << (unsigned char)rotatedPixels.at(i).getBlue();
        }
    }

    rotatedPixels.clear();
    output.close();
}
