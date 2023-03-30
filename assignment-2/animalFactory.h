// Aditeya Srivastava (aditeys@clemson.edu)
// https://github.com/aditeyaS/8700-assignment-2

#ifndef ANIMAL_FACTORY_H
#define ANIMAL_FACTORY_H

#include "abstractFactory.h"
#include "animal.h"
#include "tiger.h"
#include "wolf.h"
#include "lemur.h"
#include "kangaroo.h"
#include "serpent.h"

class AnimalFactory: public AbstractFactory{
    private:
        static Animal* tiger;
        static Animal* wolf;
        static Animal* lemur;
        static Animal* kangaroo;
        static Animal* serpent;

    public:
        // constructors
        AnimalFactory() {}

        //destructor
        ~AnimalFactory () {
            delete tiger;
            delete wolf;
            delete lemur;
            delete kangaroo;
            delete serpent;
        }

        Animal* CreateTiger () {
            return tiger->clone();
        }
        Animal* CreateWolf () {
            return wolf->clone();
        }
        Animal* CreateLemur () {
            return lemur->clone();
        }
        Animal* CreateKangaroo () {
            return kangaroo->clone();
        }
        Animal* CreateSerpent () {
            return serpent->clone();
        }
};

#endif

Animal* AnimalFactory::tiger = new Tiger();
Animal* AnimalFactory::wolf = new Wolf();
Animal* AnimalFactory::lemur = new Lemur();
Animal* AnimalFactory::kangaroo = new Kangaroo();
Animal* AnimalFactory::serpent = new Serpent();
