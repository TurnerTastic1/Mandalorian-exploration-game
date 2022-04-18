// StormTrooper.h
// CSCI 1300 Spring 2022
// Author: Caroline Scheidt, Tuner Naef
// Recitation: 202 - TA Alexander Ray
// Project 3

#ifndef STORMTROOPER_H
#define STORMTROOPER_H

#include <iostream>

#include "Weapon.h"
#include "NPC.h"
#include "Planet.h"
#include "Mando.h"

using namespace std;

class StormTrooper {
    private:
        int difficulty;
        int hp;
        int damage;

    public:
        StormTrooper();
        int getDifficulty();
        int getHP();
        int getDamage();
        /// comment
};


#endif