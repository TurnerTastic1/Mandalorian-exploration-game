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
    vector<Weapon> weapons;
    // Weapon weapon1 = Weapon();
    // weapons.push_back(weapon1);
    honorLevel = 100;
    skillLevel = 5;
    bool alive = true;
    int babyYoda = 3;
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

void Mando::setSkillLevel(int skill) {
    skillLevel = skill;
}

int Mando::getBabyYoda() {
    return babyYoda;
}

void Mando::setBabyYoda(int prob) {
    babyYoda = prob;
}

bool Mando::getAlive() {
    return alive;
}

void Mando::setAlive(bool boo) {
    alive = boo;
    return;
}

vector<Weapon> Mando::getWeapons() {
    return weapons;
}

Weapon Mando::retrieveWeapon(int index) {
    return weapons[index];
}

void Mando::checkWeapons() {
    if (weapons.size() == 0) {
        cout<<"You currently have no weapons!"<<endl;
        return;
    }
    for (int i = 0; i < weapons.size(); i++) {
        weapons[i].printWeapon();
    }
    return;
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

vector<Weapon> Mando::sortWeapons()
{
    Weapon temp = Weapon();
    for (int i = 0; i < weapons.size() - 1; i++) {
        for (int j = 0; j < weapons.size() - i - 1; j++) {
            if (weapons[j].getRarity() < weapons[j + 1].getRarity()) {
                temp = weapons[j];
                weapons[j] = weapons[j+1];
                weapons[j+1] = temp;
            }
        }
    }
    return weapons;

// old code: still kinda works

//     int max = 0;
//     int min = 0;
//     int k = 0;
//     vector<Weapon> temp1;
//     vector<Weapon> temp2;
//    for (int i = 0; i < weapons.size() / 2; i++)
//    {
//        if (weapons[i].getRarity() > weapons[i+1].getRarity()) // neeeds to be less than
//        {
//            temp1[k] = weapons[i];
//            temp2[k] = weapons[i+1];
//            weapons[i] = temp2[k];
//            weapons[i+2] = temp1[k];
//            k++; 
//        }
//    }
}

// addWeapon

/*Algorithm: adds a new weapon to the weapon vector
*1. Call this function everytime Mando gains a new weapon
*2. Adds the weapon to the weapon vector
*3. sorts Weapons.
Parameters: new_weapon (Weapon)
Returns: true
*/

bool Mando::addWeapon(Weapon new_weapon)
{
    // adds a new weapon to the weapon vector
    weapons.push_back(new_weapon);
    sortWeapons();
    return true;
} 

// fightNPC()

// ~~ do I have to go into the super specifics of how we are determining if Mando wins or not=-09/8

/*Algorithm: this function determines the winner of a battle between Mando and the NPC
*1. Call this function when fighting a side character
*2. Compares the NPC's stats(hP level, weapon rarity, skill) to Mando/main character's values
*3. Compare the stats and designate points to whichever character wins the comparison
*4. If Mando looses the fight, he has the chance to be revived by Grogu 
Parameters: npc1 (NPC object), mandoWeapon (Weapon object), groguPowers(int)
Returns: 1 if Mando won, returns -3 if Mando looses and dies 
*/

int Mando::fightNPC(NPC npc1, Weapon mandoWeapon) {
    // initialize variables
    int mando_pt_counter = 0;
    int npc_pt_counter = 0;

    int mando_hp = hp;
    int npc_hp = npc1.getHP();
    int mando_weapon = mandoWeapon.getRarity();
    int npc_weapon = npc1.getWeapon().getRarity();
    int npc_skill = npc1.getSkillLevel();
    int mando_skill = skillLevel;

    // compare hp
    if (mando_hp > npc_hp){
        mando_pt_counter += 10;
    }
    else if (mando_hp == npc_hp)
    {
        mando_pt_counter += 0;
    }
    else
    {
        npc_pt_counter += 10;
    }

    // compare weapon rarity
    if (mando_weapon > npc_weapon)
    {
        mando_pt_counter += (mando_weapon-npc_weapon);

    }
    else if (mando_hp == npc_hp)
    {
        mando_pt_counter += 0;
    }
    else
    {
        npc_pt_counter += (npc_weapon-mando_weapon);
    }

    // compare skill Level
    if (mando_skill > npc_skill)
    {
        mando_pt_counter += (mando_skill - npc_skill);
    }
    else if (mando_skill == npc_skill)
    {
        mando_pt_counter += 0;
    }
    else 
    {
        npc_pt_counter += (npc_skill-mando_skill);
    }

    // fight is done
    // compare the pt counters
    // change mando hp?

    if (mando_pt_counter > npc_pt_counter)
    {
        cout<<"You swiftly take down "<<npc1.getName()<<"."<<endl;
        return 1;
    }
    else if (mando_pt_counter == npc_pt_counter)
    {
        // what happens if they tie? i think mando should win
        cout<<"The two of you are almost evenly matched, your mysterious green friend helps you to defeat "<<npc1.getName()<<"."<<endl;
        return 1;
    }
    else
    {
        // maybe need: srand(time(null));
        int randIsBrokenBruh = rand();
        int save = (((double)rand() / RAND_MAX) * 10);
        if (save <= babyYoda) {
            cout<<"Baby Yoda has saved you and helps you to defeat "<<npc1.getName()<<"."<<endl;
            return 1;
        }
        //mando_hp -= (npc_pt_counter - mando_pt_counter);
        cout<<npc1.getName()<<" destroys you on the field of battle, leaving Moff Gideon to roam free..."<<endl;
        alive = false;
        return -3;
    }
    return 0;
}

/*Algorithm: this function displays the galaxy map
*1. Creates an ifstream variable
*2. Opens the GalaxyMap.txt file
*3. Creates a temporary line variable.
*4  Checks if the file is open. 
    *if it isn't, print that the map is not available
    *if it is, print each line of the file
Parameters: none
Returns: void function
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


