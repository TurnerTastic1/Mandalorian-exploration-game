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
    // weapon
    hp = 0;
    friendly = true;
    damage = 0;
    creditReward = 0;
    description = "";
    skillLevel = 0;

}
NPC::NPC(string name_, string species_, string planet_, string planetRegion_, int hp_, bool friendly_, int skillLevl_, int creditReward_, Weapon npcWeapon_)
{
    name = name_;
    species = species_;
    planet = planet_;
    planetRegion = planetRegion_;
    hp = hp_;
    friendly = friendly_;
    damage = damage_;
    creditReward = creditReward_;
    description = "temp description";
    skillLevel = skillLevel_;
    Weapon npcWeapon = npcWeapon_;
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
// getDescription()
string NPC::getDescription()
{  
    return description;
}
// getDamage()
int NPC::getDamage()
{
    return damage;
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