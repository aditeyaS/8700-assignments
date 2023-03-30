// Aditeya Srivastava (aditeys@clemson.edu)
// https://github.com/aditeyaS/8700-assignment-1

#ifndef GRAY_PIXEL_H
#define GRAY_PIXEL_H

class GrayPixel {
    private:
        unsigned char gray;

    public:
        // constructors
        GrayPixel();
        GrayPixel(unsigned char gray) {
            this->gray = gray;
        }

        // destructor
        ~GrayPixel(){}

        // getters
        unsigned char getGray() {return gray;}

        // setters
        void setGray(unsigned char gray) {this->gray = gray;}
};

#endif