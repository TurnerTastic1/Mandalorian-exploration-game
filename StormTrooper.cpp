#include <iostream>
#include <vector>

#include "Weapon.h"

#include <cmath>
#include <iomanip>

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
StormTrooper::getDifficulty()
{
    return difficulty;
}

// getHp()
StormTrooper::getHp()
{
    return hp;
}
// getDamage()
StormTrooper::getDamage()
{
    return damage;
}
