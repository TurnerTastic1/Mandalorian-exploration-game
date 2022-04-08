#include<iostream>
#include <fstream>
#include "Mando.h"
#include "Weapon.h"
#include "StormTrooper.h"
#include "NPC.h"
#include "Planet.h"
#include <cassert>

using namespace std;

/*Table of contents:
* 1. Weapon.h
* 2. Mando.h
* 3. StormTrooper.h
* 4. NPC.h
* 5. Planet.h
* 6. Map.h

*/

int main()
{
    // ~~~~~~~~~~~~~~~ Weapon.h test ~~~~~~~~~~~~~~~~~~~~~~~~~
    // create Weapon object with the default constructor
    Weapon defWeapon = Weapon();
    
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

    // parameterized constructor tests
    Weapon paramWeapon = Weapon("knife", "short-range", 1, 3, "tatooine", "1");
    // test getters:
    // .getName() test
    assert(paramWeapon.getName()=="knife");
    // .getType() test
    assert(paramWeapon.getType()=="short-range");
    // .getRarity() test
    assert(paramWeapon.getRarity() == 1);
    // .getDamage() test
    assert(paramWeapon.getDamage() == 3);
    // .getPlanet() test
    assert(paramWeapon.getPlanet() == "tatooine");
    // .getPlanetRegion() test
    assert(paramWeapon.getPlanetRegion() == "1");



    // ~~~~~~~~~~~~~~~ Mando.h test ~~~~~~~~~~~~~~~~~~~~~~~~~
    // create Mando object with the default constructor
    Mando defMando = Mando();
    // test getters:
    // .getName() test
    assert(defMando.getName()=="");
    // .getType() test
    assert(defMando.getHP()==10);
    // .getRarity() test
    assert(defMando.getCredits() == 50);
    // .getDamage() test
    assert(defMando.getHonorLevel() == 100);
    // .getPlanet() test
    // assert(defMando.setHP(50) == 50);
    // .getPlanetRegion() test
    defMando.setCredits(100);
    assert(defMando.getCredits() == 100);

    // parameterized constructor
    Mando paramMando = Mando("cassie");
    // test getters:
    // .getName() test
    assert(paramMando.getName()=="cassie");
    // .getHP() test
    assert(paramMando.getHP()==10);
    // .getHonorLevel() test
    assert(paramMando.getHonorLevel() == 0);
    // .setHP() test
    // assert(defWeapon.setHp(75) == 75);
    // .setCredits() test
    // expected to be set to 90
    paramMando.setCredits(90);
    assert(paramMando.getCredits() == 90);

    // ~~~~~~~~~~~~~~~ StormTrooper.h test ~~~~~~~~~~~~~~~~~~~~~~~~~
    // create StormTrooper object with the default constructor
    StormTrooper defTrooper = StormTrooper();
    // getDifficulty() test
    // test getters:
    // getDifficulty() test
    assert(defTrooper.getDifficulty()==3);
    // .getHp() test
    assert(defTrooper.getHP()==10);
    // .getDamage() test
    assert(defTrooper.getDamage() == 0);

    // ~~~~~~~~~~~~~~~ NPC.h test ~~~~~~~~~~~~~~~~~~~~~~~~~
    // create NPC object with the default constructor
    NPC defNPC = NPC();
    // test getters:
    // .getName() test
    assert(defNPC.getName()=="");
    // .getType() test
    assert(defNPC.getSpecies()=="");
    // .getRarity() test
    assert(defNPC.getPlanet() == "");
    // .getDamage() test
    assert(defNPC.getPlanetRegion() == "");
    // .getPlanet() test
    // assert(defNPC.getWeapon() == "");
    // .getPlanetRegion() test
    assert(defNPC.getHP() == 0);
    // .getFriendly()
    assert(defNPC.getFriendly() == true);
    // .getDescription()
    assert(defNPC.getDescription() == "");
    // .getDamage()
    assert(defNPC.getDamage() == 0);
    // .getCreditReward
    assert(defNPC.getCreditReward() == 0);

    // ~~~~~~~~~~~~~~~ Planet.h test ~~~~~~~~~~~~~~~~~~~~~~~~~
    // create Planet object with the default constructor
    Planet defPlanet = Planet();
    // getName() test
    assert(defPlanet.getName()=="");
    // getType() test
    assert(defPlanet.getType() == "");
    // getPlanet() test
    assert(defPlanet.getRegion() == "");
    // getTravelCost()
    assert(defPlanet.getTravelCost() == 0);

    // ~~~~~~~~~~~~~~~ Map.h test ~~~~~~~~~~~~~~~~~~~~~~~~~
    // create Map object with the default constructor

}