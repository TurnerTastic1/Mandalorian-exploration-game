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