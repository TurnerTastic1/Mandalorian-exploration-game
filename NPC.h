#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <vector>

#include "Weapon.h"
#include "Mando.h"
#include "Planet.h"

class NPC { // Use read movies/ read ratings to read sidechar from file
    private:
        string name;
        string species;
        string planet;
        string planetRegion;
        int hp;
        bool friendly;
        int creditReward;
        int skillLevel;
        Weapon weapon;

    public:
        NPC();
        NPC(string name_, string species_, string planet_, string planetRegion_, int hp_, bool friendly_, int creditReward_, int skillLevel_, Weapon weapon_);
        string getName();
        void setName(string _name);
        string getSpecies();
        string getPlanet();
        string getPlanetRegion();
        int getHP();
        bool getFriendly();
        int getCreditReward();
        int getSkillLevel();
        void printWeapon();
        Weapon getWeapon();
        void setWeapon(Weapon weap);
        //vector<NPC> readNPC(string fileName);


};





#endif