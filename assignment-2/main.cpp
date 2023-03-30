// Aditeya Srivastava (aditeys@clemson.edu)
// https://github.com/aditeyaS/8700-assignment-2

#include "zoo.h"

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    vector<string> input;
    while(!cin.fail()) {
        string i;
        cin >> i;
        if (!i.empty())
            input.push_back(i);
    }
    Zoo* zoo = zoo->getInstance();
    zoo->read(input);
    zoo->display();
    return 0;
}
