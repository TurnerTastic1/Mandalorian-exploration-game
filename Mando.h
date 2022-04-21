// Mando.cpp
// CSCI 1300 Spring 2022
// Author: Caroline Scheidt, Turner Naef
// Recitation: 202 - TA Alexander Ray
// Project 3
#ifndef MANDO_H
#define MANDO_H 

#include <iostream>
#include <vector>

#include "Weapon.h"
#include "NPC.h"


using namespace std;

class Weapon;

class Mando {
    private:
        string name;
        int hp;
        int credits;
        vector <Weapon> weapons;
        int honorLevel;
        int skillLevel;
        bool alive;
        void setDefaultValues();
        // NPC newNPC = NPC();

    public:
        // Standard Functions

        Mando(); // set credits and first weapons here
        Mando(string name_);
        string getName();
        int getHP();
        void setHp(int hp_);
        int getCredits();
        void setCredits(int credits_);
        int getHonorLevel();
        int getSkillLevel();
        void setSkillLevel(int skill);
        bool getAlive();
        void setAlive(bool boo);
        void checkWeapons();
        vector<Weapon> getWeapons();
        Weapon retrieveWeapon(int index);
        
        // Personal functions

        vector<Weapon> sortWeapons(); // sort weapons by rarity best to least
        bool addWeapon(Weapon); // call sort function every time add weapon is called!!!
        int fightNPC(NPC npc1, Weapon mandoWeapon, int groguPowers); // cannot pass objects like that you need a pass by reference 
        void displayGalaxyMap();

};

#endif



