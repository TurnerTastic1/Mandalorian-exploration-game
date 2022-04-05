#ifndef Weapon_h
#define Weapon_h

#include <iostream>
#include <vector>

using namespace std;

class Weapon {
    private:
        string name;
        string type;
        int rarity; // Temp
        int damage;
        string planet;
        string planetRegion;

    
    public:
        Weapon();
        string getName();
        string getType();
        int getRarity(); // Temp
        int getDamage();
        string getPlanet();
        string getPlanetRegion();

};

#endif