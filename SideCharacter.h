#ifndef SideCharacter_h
#define SideCharacter_h

#include <iostream>
#include <vector>

#include "Weapon.h"

class SideCharacter { // Use read movies/ read ratings to read sidechar from file
    private:
        string name;
        string species;
        string planet;
        string planetRegion;
        Weapon weapon;
        int hp;
        bool friendly;
        string description;
        int damage;
        int creditReward;

    public:
        SideCharacter();
        string getName();
        string getSpecies();
        string getPlanet();
        string getPlanetRegion();
        Weapon getWeapon();
        int getHp();
        bool getFriendly();
        string getDescription();
        int getDamage();
        int getCreditReward();


};





#endif