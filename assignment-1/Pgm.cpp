// Aditeya Srivastava (aditeys@clemson.edu)
// https://github.com/aditeyaS/8700-assignment-1

#include "pgm.h"
#include "grayPixel.h"

#include <string>
#include <fstream>
#include <iostream>
using namespace std;

Pgm::Pgm (const string &file) {
    read(file);
}

Pgm::~Pgm() {
    pixels.clear();
}

void Pgm::read (const string &file) {
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

    // read data
    if (magicNumber == "P2") {
        // read ASCII
        while(!input.eof()) {
            getline(input, line);
            pixels.push_back(GrayPixel(atoi(line.c_str())));
        }
    } else {
        // read binary
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                char c;
                input.read(&c, 1);
                pixels.push_back(GrayPixel((unsigned char) c));
            }
        }
    }
    input.close();
}

void Pgm::rotate (char direction, int angle, string newFileName) {
    ofstream output;
    output.open(newFileName, ios::binary);
    if (!output) {
        std::cout << "Writing " << newFileName << " failed!" << std::endl;
        return;
    }

    int outputWidth = width, outputHeight = height;
    vector<GrayPixel> rotatedPixels;
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
        if (magicNumber == "P2") {
            // ASCII
            output << to_string(rotatedPixels.at(i).getGray()) << endl;
        } else {
            // binary
            output << (unsigned char)rotatedPixels.at(i).getGray();
        }
    }

    rotatedPixels.clear();
    output.close();
}
