#ifndef PLANET_H
#define PLANET_H


#include <iostream>
#include <vector>

#include "Weapon.h"
#include "NPC.h"
#include "Mando.h"
#include "map.h"

using namespace std;

class Mando;

class Planet {
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
        bool planetTravel(Mando &myMando, string description);
        void displayPlanetMap(string filename);

};



#endif