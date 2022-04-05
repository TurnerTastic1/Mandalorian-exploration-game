#ifndef Mando_h
#define Mando_h

#include <iostream>
#include <vector>

#include "Weapon.h"
#include "SideCharacter.h"

using namespace std;

class Mando {
    private:
        string name;
        const static int hp = 10;
        int credits;
        vector<Weapon> weapons;
        int honorLevel;

    public:
        // Standard Functions

        Mando(); // set credits and first weapons here
        Mando(string name_);
        string getName();
        int getHp();
        void setHp(int hp_);
        int getCredits();
        void setCredits(int credits_);
        int getHonorLevel();
        
        // Personal functions

        vector<Weapon> sortWeapons(vector<Weapon>); // sort weapons by rarity best to least
        bool addWeapon(Weapon); // call sort function every time add weapon is called!!!
        int fightNPC(SideCharacter dude);



};

#endif



