// FOR TESTING
// LOL, null-shit = bullshit but its "null" lol

#include "Mando.h"
#include "Planet.h"
#include "Weapon.h"

#include <iostream>

using namespace std;

int main() {
    Mando myMando = Mando("dude");
    Weapon myWeap = Weapon("Gun", "Gun", 4, 3);
    Weapon myWeap1 = Weapon("Sword", "Sword", 1, 5);
    myMando.addWeapon(myWeap);
    myMando.addWeapon(myWeap1);
    myMando.checkWeapons();
    myMando.sortWeapons();
    myMando.checkWeapons();
    
    //myWeap.printWeapon();
}