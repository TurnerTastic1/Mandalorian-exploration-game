// Mando.cpp
// CSCI 1300 Spring 2022
// Author: Caroline Scheidt,
// Recitation: 202 - TA Alexander Ray
// Project 3

#include <iostream>
#include<fstream>

#include "Mando.h"
#include "Weapon.h"
#include "NPC.h"

#include <cmath>
#include <iomanip>

using namespace std;


// default constructor
Mando::Mando()
{
    name = "";
    credits = 50;
    weapons.push_back("gun"); // not sure how to do a default constructor for vectors
    honorLevel = 100;
}

// parameterized constructor
Mando::Mando(string _name)
{
    name = _name;
}

// getHp()
int Mando::getHP()
{
    return hp;
}

// setHp()
void Mando::setHp(int hp_)
{
    hp = hp_;
}

// getCredits()
int Mando::getCredits()
{
    return credits;
}

// setCredits()
void Mando::setCredits(int credits_)
{
    credits = credits_
}

// getHonorLevel
int Mando::getHonorLevel()
{
    return honorLevel;
}

// ~~~~personal functions~~~~

// addWeapon

/*
1. Call this function everytime Mando gains a new weapon
2. Checks if the weapon being entered is a valid weapon/string
3. If second step is true, adds the new weapon name(string) to vector<Weapon> vector using weapon.push_back(); Returns 1;
4. If second step is not true, returns -2
*/

bool addWeapon(Weapon new_weapon)
{

}

/*
//need more info one how we are going to do this one
1. Call this function everytime a weapon is add
2. Sort through the vector of weapons and compare the rarity ranking associated with the next adjacent weapon
3. Sort the weapons by most rare to least rare
4. Possible bubble sort method
*/


// sort weapons---not sure how to set up this one
int Mando::vector<Weapon> sortWeapons(vector<Weapon>)
{

}

// fightNPC()

// ~~ do I have to go into the super specifics of how we are determining if Mando wins or not=-09/8

/*
1. Call this function when fighting a side character
2. Compares the sideCharacters stats(weapon ranking, hP level, damage) to Mando/main character's values
3. If Mando's weapon ranking is less than side character's weapon ranking, subtract 5 from Mando's hP level. Else, add 5 to Mando's hp Level.
4. If Mando's hP level is less than side character's hP level,
5. If Mando's damage level
4. If second step is not true, returns -2
*/

int fightNPC(NPC dude)
{
    return -1;
}

// displayGalaxyMap()

/*
1. Create stream object
2. Check if variable is open
3. Use a while loop to go through each line of the galaxyMap file
4. Check if the line is empty
5. Print each line of the file
*/

void displayGalaxyMap()
{

}




