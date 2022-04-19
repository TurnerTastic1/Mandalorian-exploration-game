// Mando.cpp
// CSCI 1300 Spring 2022
// Author: Caroline Scheidt, Turner naef
// Recitation: 202 - TA Alexander Ray
// Project 3


#include "Mando.h"
#include "Planet.h"
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
    setDefaultValues();
}

// parameterized constructor
Mando::Mando(string _name)
{
    setDefaultValues();
    name = _name;
}

void Mando::setDefaultValues() {
    name = "";
    credits = 100;
    hp = 10;
    // weapons.push_back("gun"); // not sure how to do a default constructor for vectors
    honorLevel = 100;
    skillLevel = 10;
}

string Mando::getName() {
    return name;
}
// getHp()
int Mando::getHP()
{
    return hp;
}

// setHp()--can't have because we made hp a static int
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

int Mando::getSkillLevel()
{
    return skillLevel;
}

// ~~~~personal functions~~~~

/*
//need more info one how we are going to do this one
1. Call this function everytime a weapon is add
2. Sort through the vector of weapons and compare the rarity ranking associated with the next adjacent weapon
3. Sort the weapons by most rare to least rare
4. Possible bubble sort method
*/

// if sorted properly, return 1; else return -3

// I set this to void for now

void Mando::sortWeapons(vector<Weapon> weapon)
{
//     int max = 0;
//     int min = 0;
//     int k = 0;
//     vector<Weapon> temp1;
//     vector<Weapon> temp2;
//    for (int i = 0; i < weapon.size() / 2; i++)
//    {
//        if (weapon[i].getRarity() > weapon[i+1].getRarity())
//        {
//            temp1[k] = weapon[i];
//            temp2[k] = weapon[i+1];
//            weapon[i] = temp2[k];
//            weapon[i+2] = temp1[k];
//            k++; 
//        }
//    }
//    return weapon;
    return;
}

// addWeapon

/*
1. Call this function everytime Mando gains a new weapon
2. Checks if the weapon being entered is a valid weapon/string
3. If second step is true, adds the new weapon name(string) to vector<Weapon> vector using weapon.push_back(); Returns 1;
4. If second step is not true, returns -2
*/

/*bool Mando::addWeapon(Weapon new_weapon)
{
    return true;
} */

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
    return 0;
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

// int main()
// {
//     Mando myMando = Mando();
//     Weapon gun = Weapon("gun", "long-range", 2, 3, "tatooine", "region 1");
//     vector<Weapon> weapons;
//     vector<Weapon> weapons2;
//     weapons.push_back(gun);
//     Weapon jetpack = Weapon("jetpack", "flight", 1, 0, "tatooine", "region 1");
//     weapons.push_back(jetpack);
//     Weapon flamethrower = Weapon("flamethrower", "mid-range", 3, 5, "tatooine", "region 4" );
//     weapons.push_back(flamethrower);
//     Weapon spear = Weapon("Beskar spear", "short-range", 4, 4, "trask", "region 2" );
//     weapons.push_back(spear);
//     Weapon w_birds = Weapon("whistling birds", "short-range", 5, 7, "tython", "region 3" );
//     weapons.push_back(w_birds);
//     Weapon saber = Weapon("dark saber", "mid-range", 6, 10, "navarro", "region 3" );
//     weapons.push_back(saber);

//     // TEST SORT FUNCTION
//     weapons2 = myMando.sortWeapons(weapons);
//     for (int k = 0; k < weapons.size(); k++)
//     { 
//         cout<< weapons2[k].getName()<< " ";
//     }

// }
