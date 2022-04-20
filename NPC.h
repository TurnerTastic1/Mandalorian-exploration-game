// NPC.h
// CSCI 1300 Spring 2022
// Author: Caroline Scheidt, Turner naef
// Recitation: 202 - TA Alexander Ray
// Project 3

#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <vector>

#include "Weapon.h"
// #include "Mando.h"
//#include "Planet.h"
//#include "StormTrooper.h"

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
        string getSpecies();
        string getPlanet();
        string getPlanetRegion();
        int getHP();
        bool getFriendly();
        int getCreditReward();
        int getSkillLevel();
        void getWeapon();
        vector<NPC> readNPC(string fileName);


};





#endif