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
    
}