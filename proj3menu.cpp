
#include <iostream>
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


// int fightScene(Mando myMando, NPC npc1){
//     // initialize variables
//     int mando_pt_counter = 0;
//     int npc_pt_counter = 0;
//     int mando_hp = myMando.getHP();
//     int npc_hp = npc1.getHP();
//     int mando_weapon = 5;
//     int npc_weapon = 4;
//     int npc_skill = npc1.getSkillLevel();
//     int mando_skill = myMando.getSkillLevel();

//     // compare hp
//     if (mando_hp > npc_hp){
//         mando_pt_counter += 10;
//     }
//     else if (mando_hp == npc_hp)
//     {
//         mando_pt_counter += 0;
//     }
//     else
//     {
//         npc_pt_counter += 10;
//     }

//     // compare weapon rarity
//     if (mando_weapon > npc_weapon)
//     {
//         mando_pt_counter += (mando_weapon-npc_weapon);

//     }
//     else if (mando_hp == npc_hp)
//     {
//         mando_pt_counter += 0;
//     }
//     else
//     {
//         npc_pt_counter += (npc_weapon-mando_weapon);
//     }

//     // compare skill Level
//     if (mando_skill > npc_skill)
//     {
//         mando_pt_counter += (mando_skill - npc_skill);
//     }
//     else if (mando_skill == npc_skill)
//     {
//         mando_pt_counter += 0;
//     }
//     else 
//     {
//         npc_pt_counter += (npc_skill-mando_skill);
//     }

//     // fight is done
//     // compare the pt counters
//     // change mando hp?

//     if (mando_pt_counter > npc_pt_counter)
//     {
//         return 1;
//     }
//     else if (mando_pt_counter == npc_pt_counter)
//     {
//         // what happens if they tie? i think mando should win
//         return 1;
//     }
//     else
//     {
//         mando_hp -= (npc_pt_counter - mando_pt_counter);
//         return -3;
//     }
//     return 0;
// }

int main()
{
    // // start game
    // // testing project
    Mando myMando = Mando("test");
    Weapon gun = Weapon("IB-94 blaster pistol", "Gun", 3, 3);
    myMando.addWeapon(gun);
    NPC npc1 = NPC();
    //myMando.retrieveWeapon(0).printWeapon();
    int fight_value = myMando.fightNPC(npc1, myMando.retrieveWeapon(0));
    cout << fight_value << endl;

    
    return 0;



}