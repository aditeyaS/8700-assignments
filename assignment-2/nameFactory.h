// Aditeya Srivastava (aditeys@clemson.edu)
// https://github.com/aditeyaS/8700-assignment-2

#ifndef NAME_FACTORY_H
#define NAME_FACTORY_H

#include <string>
using namespace std;

class NameFactory {
    private:
        string nameList[50] = {
            "Zoro", "Luffy", "Ace", "Shanks", "Mihawk",
            "Itachi", "Kakashi", "Madara", "Hinata", "Gaara",
            "Vegeta", "Goku", "Beerus", "Jiren", "Gohan",
            "Asta", "Yami", "Yuno", "Toga", "Dabi",
            "Bakugo", "Hawks", "Gojo", "Sukuna", "Bojji",
            "Levi", "Mikasa", "Eren", "Nina", "Migi",
            "Gon", "Killua", "Edward", "Elric", "Genos",
            "Saitama", "Ryuk", "Zenitsu", "Senkuu", "Ichigo"
            "Thomas", "Baba", "Walter", "Jesse", "Wayne",
            "Ragnar", "Elliot", "Michael", "Pablo", "Joey"
        };

    public:
        // getters or accessors
        string getName(int index) {return nameList[index];}
};

#endif