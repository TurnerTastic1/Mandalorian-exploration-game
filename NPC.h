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
#include "Mando.h"
#include "Planet.h"
#include "StormTrooper.h"

class NPC { // Use read movies/ read ratings to read sidechar from file
    private:
        string name;
        string species;
        string planet;
        string planetRegion;
        //Weapon weapon;
        int hp;
        bool friendly;
        string description;
        int damage;
        int creditReward;
        int skillLevel;

    public:
        NPC();
        string getName();
        string getSpecies();
        string getPlanet();
        string getPlanetRegion();
        //Weapon getWeapon();
        int getHP();
        bool getFriendly();
        string getDescription();// player can pass this info
        int getDamage();
        int getCreditReward();
        int getSkillLevel();


};





#endif