// Planet.h
// CSCI 1300 Spring 2022
// Author: Caroline Scheidt, Turner Naef
// Recitation: 202 - TA Alexander Ray
// Project 3

#ifndef Planet_h
#define Planet_h

#include <iostream>
#include <vector>

//#include "Weapon.h"
#include "NPC.h"
#include "Mando.h"
#include "StormTrooper.h"

using namespace std;

class Planet {
    extern:
        bool planetTravel(Mando myMando);

    private:
        string name;
        string type;
        int travelCost;

    public:
        Planet();
        Planet(string name_, string type_, int travelCost_);
        string getName();
        string getType();
        int getTravelCost();
        void displayPlanetMap(string filename);

};



#endif