
#include <iostream>
#include <vector>
#include "Weapon.h"

using namespace std;

Weapon::Weapon()
{
    name = "";
    type = "";
    rarity = 0;
    damage = 0;
    planet = "";
    planetRegion = "";
}

// getName()
string Weapon::getName()
{
    return name;
}
// getType()
string Weapon::getType()
{
    return type;
}
// getRarity
int Weapon::getRarity()
{
    return rarity;
}
// getDamage
int Weapon::getDamage()
{
    return damage;
}

string Weapon::getPlanet()
{
    return planet;
}

// getPlanetRegion
string Weapon::getPlanetRegion()
{
    return planetRegion;
}

// setName()
void Weapon::setName(string name_)
{
    name = name_;
}

// setType()
void Weapon::setType(string type_)
{
    type = type_;
}

// setRarity()
void Weapon::setRarity(int rarity_)
{
    rarity = rarity_;
}
// setDamage()
void Weapon::setDamage(int damage_)
{
    damage = damage_;
}
// setPlanet()
void Weapon::setPlanet(string planet_)
{
    planet = planet_;
}
//setPlanetRegion()
void Weapon::setPlanetRegion(string planetRegion_)
{
    planetRegion = planetRegion_;
}

