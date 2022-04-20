// NPC.cpp
// CSCI 1300 Spring 2022
// Author: Caroline Scheidt, Turner naef
// Recitation: 202 - TA Alexander Ray
// Project 3

#include <iostream>
#include <vector>

#include "Weapon.h"
#include "NPC.h"

#include <cmath>
#include <iomanip>

// default constructor
NPC::NPC()
{
    name = "";
    species = "";
    planet = "";
    planetRegion = "";
    hp = 0;
    friendly = true;
    creditReward = 0;
    skillLevel = 0;
    Weapon weapon = Weapon("Gun", "Gun", 2, 3);

}
NPC::NPC(string name_, string species_, string planet_, string planetRegion_, int hp_, bool friendly_, int creditReward_, int skillLevel_, Weapon weapon_)
{
    name = name_;
    species = species_;
    planet = planet_;
    planetRegion = planetRegion_;
    hp = hp_;
    friendly = friendly_;
    creditReward = creditReward_;
    //description = "temp description";
    skillLevel = skillLevel_;
    Weapon weapon = Weapon("Gun", "Gun", 2, 3);;
}   
// getName()
string NPC::getName()
{
    return name;
}
// getSpecies()
string NPC::getSpecies()
{
    return species;
}
// getPlanet()
string NPC::getPlanet()
{
    return planet;
}
// getPlanetRegion()
string NPC::getPlanetRegion()
{
    return planetRegion;
}
// Weapon getWeapon();
int NPC::getHP()
{
    return hp;
}
// getFriendly()
bool NPC::getFriendly()
{
    return friendly;
}

// getCreditReward()
int NPC::getCreditReward()
{
    return creditReward;
}

// getSkillLevel()
int NPC::getSkillLevel()
{
    return skillLevel;
}

void NPC::getWeapon() {
    weapon.printWeapon();
    return;
}