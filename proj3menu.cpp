// proj3menu.cpp
// CSCI 1300 Spring 2022
// Author: Caroline Scheidt, Turner naef
// Recitation: 202 - TA Alexander Ray
// Project 3

#include<iostream>
#include <fstream>
#include "Mando.h"
#include "Weapon.h"
#include "StormTrooper.h"
#include "NPC.h"
#include "Planet.h"
#include <cassert>

using namespace std;

// void fighting function
// if mando won, return 1
// if mando lost, return -3


int fightScene(Mando myMando, NPC npc1){
    // initialize variables
    int mando_pt_counter = 0;
    int npc_pt_counter = 0;
    int mando_hp = myMando.getHP();
    int npc_hp = npc1.getHP();
    int mando_weapon = 5;
    int npc_weapon = 4;
    int npc_skill = npc1.getSkillLevel();
    int mando_skill = myMando.getSkillLevel();

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
        return 1;
    }
    else if (mando_pt_counter == npc_pt_counter)
    {
        // what happens if they tie? i think mando should win
        return 1;
    }
    else
    {
        mando_hp -= (npc_pt_counter - mando_pt_counter);
        return -3;
    }
    return 0;
}

int main()
{
    // start game
    // testing project
    Mando myMando = Mando("test");
    NPC npc1 = NPC();
    int fight_value = fightScene(myMando, npc1);
    cout << fight_value << endl;
    
    return 0;



}