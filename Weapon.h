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
        Weapon(string name_, string type_, int rarity_, int damage_, string planet_, string planetRegion_);
        string getName();
        string getType();
        int getRarity(); // Temp
        int getDamage();
        string getPlanet();
        string getPlanetRegion();

        //setters
        void setName(string name_);
        void setType(string type_);
        void setRarity(int rarity_); // Temp
        void setDamage(int damage_);
        void setPlanet(string planet_);
        void setPlanetRegion(string planetRegion_);

};

#endif