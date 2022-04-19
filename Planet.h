
#include <iostream>
#include <vector>

//#include "Weapon.h"
#include "NPC.h"
#include "Mando.h"
#include "StormTrooper.h"
#include "map.h"

#ifndef PLANET_H
#define PLANET_H

using namespace std;

class Planet {

    extern Mando myMando;

    private:
        string name;
        string type;
        int travelCost;
        


    public:
        Planet();
        Planet(string name_, string type_, int travelCost_, Mando myMando_;
        string getName();
        string getType();
        int getTravelCost();
        bool planetTravel();
        void displayPlanetMap(string filename);

};



#endif