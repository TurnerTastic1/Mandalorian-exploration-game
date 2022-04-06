#include<iostream>
#include <fstream>
#include "Mando.h"
#include "Weapon.h"
#include "StormTrooper.h"
#include "SideCharacter.h"
#include "Planet.h"
#include <cassert>

using namespace std;

/*Table of contents:
* 1. Weapon.h
* 2. Mando.h
* 3. StormTrooper.h
* 4. SideCharacter.h
* 5. Planet.h
* 6. Map.h

*/

int main()
{
    // ~~~~~~~~~~~~~~~ Weapon.h test ~~~~~~~~~~~~~~~~~~~~~~~~~
    // create Weapon object with the default constructor
    Weapon defWeapon;
    
    // test getters:
    // .getName() test
    assert(defWeapon.getName()=="");
    // .getType() test
    assert(defWeapon.getType()=="");
    // .getRarity() test
    assert(defWeapon.getRarity() == 0);
    // .getDamage() test
    assert(defWeapon.getDamage() == 0);
    // .getPlanet() test
    assert(defWeapon.getPlanet() == "");
    // .getPlanetRegion() test
    assert(defWeapon.getPlanetRegion() == "");

    // ~~~~~~~~~~~~~~~ Mando.h test ~~~~~~~~~~~~~~~~~~~~~~~~~
    // create Weapon object with the default constructor
}