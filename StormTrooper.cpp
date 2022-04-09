// StormTrooper.cpp
// CSCI 1300 Spring 2022
// Author: Caroline Scheidt, Turner naef
// Recitation: 202 - TA Alexander Ray
// Project 3

#include <iostream>
#include <vector>

#include "StormTrooper.h"

#include <cmath>
#include <iomanip>

using namespace std;

// default constructor
StormTrooper::StormTrooper()
{
    // difficulty ranking out of 10?
    // starts out at difficulty level of 3
    int difficulty = 3;
    int hp = 10;
    // is this how much damage he has? if so start out at 0.
    int damage = 0;

}

// getDifficulty()
int StormTrooper::getDifficulty()
{
    return difficulty;
}

// getHp()
int StormTrooper::getHP()
{
    return hp;
}
// getDamage()
int StormTrooper::getDamage()
{
    return damage;
}
