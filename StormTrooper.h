#ifndef StormTrooper_h
#define StormTrooper_h

#include <iostream>

#include "Weapon.h"
#include "NPC.h"
#include "Planet.h"
#include "Mando.h"

using namespace std;

class StormTrooper {
    private:
        int difficulty;
        int hp;
        int damage;

    public:
        StormTrooper();
        int getDifficulty();
        int getHP();
        int getDamage();
        /// comment
};


#endif