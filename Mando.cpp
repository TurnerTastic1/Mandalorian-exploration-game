// Mando.cpp
// CSCI 1300 Spring 2022
// Author: Caroline Scheidt,
// Recitation: 202 - TA Alexander Ray
// Project 3

#include "Mando.h"
#include "Weapon.h"
#include "NPC.h"

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;


// default constructor
Mando::Mando()
{
    name = "";
    credits = 50;
    weapons = weapons; 
    honorLevel = 100;
}

// parameterized constructor
Mando::Mando(string _name)
{
    name = _name;
}

string Mando::getName() {
    return name;
}
// getHp()
int Mando::getHp()
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
    credits = credits_;
}

// getHonorLevel
int Mando::getHonorLevel()
{
    return honorLevel;
}

// ~~~~personal functions~~~~

<<<<<<< HEAD
=======
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

>>>>>>> 25a51e65d14a56d493739ef65b02f98319da10a6
/*
//need more info one how we are going to do this one
1. Call this function everytime a weapon is add
2. Sort through the vector of weapons and compare the rarity ranking associated with the next adjacent weapon
3. Sort the weapons by most rare to least rare
4. Possible bubble sort method
*/


// sort weapons---not sure how to set up this one
int Mando::sortWeapons(vector<Weapon>)
{
    return 0;
}

// addWeapon

/*
1. Call this function everytime Mando gains a new weapon
2. Checks if the weapon being entered is a valid weapon/string
3. If second step is true, adds the new weapon name(string) to vector<Weapon> vector using weapon.push_back(); Returns 1;
4. If second step is not true, returns -2
*/

bool Mando::addWeapon(Weapon new_weapon)
{
    return true;
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

int Mando::fightNPC(NPC dude)
{
<<<<<<< HEAD
    return 0;
=======
    return -1;
>>>>>>> 25a51e65d14a56d493739ef65b02f98319da10a6
}

// displayGalaxyMap()

/*
1. Create stream object
2. Check if variable is open
3. Use a while loop to go through each line of the galaxyMap file
4. Check if the line is empty
5. Print each line of the file
*/

void Mando::displayGalaxyMap()
{
    ifstream fin;
    fin.open("GalaxyMap.txt");
    string line = "";
    if (fin.is_open() == false) {
        cout<< "Galaxy Map is not available!"<<endl;
        return;
    }
    // Printing the Galaxy map
    while (!fin.eof()) {
        getline(fin, line);
        cout<<line<<endl;
    }
}



