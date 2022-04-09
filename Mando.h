#ifndef Mando_h
#define Mando_h

#include <iostream>
#include <vector>

#include "Weapon.h"
#include "NPC.h"
#include "Planet.h"
#include "StormTrooper.h"

using namespace std;

class Mando {
    private:
        string name;
        int hp = 10;
        int credits;
        vector<Weapon> weapons;
        int honorLevel;

    public:
        // Standard Functions

        Mando(); // set credits and first weapons here
        Mando(string name_);
        string getName();
        int getHP();
        // void setHp(int hp_);
        int getCredits();
        void setCredits(int credits_);
        int getHonorLevel();
        
        // Personal functions

        int sortWeapons(vector<Weapon>); // sort weapons by rarity best to least
        bool addWeapon(Weapon); // call sort function every time add weapon is called!!!
        int fightNPC(NPC dude);
        void displayGalaxyMap();

};

#endif



