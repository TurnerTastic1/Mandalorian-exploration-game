#ifndef Planet_h
#define Planet_h

#include <iostream>
#include <vector>

#include "Weapon.h"
#include "NPC.h"
#include "Mando.h"
#include "StormTrooper.h"

using namespace std;

class Planet {
    private:
        string name;
        string type;
        string region; // 3 regions per planet
        int travelCost;

    public:
        Planet();
        string getName();
        string getType();
        string getRegion();
        int getTravelCost();
        void displayPlanetMap();

};



#endif