// StormTrooper.h
// CSCI 1300 Spring 2022
// Author: Caroline Scheidt, Tuner Naef
// Recitation: 202 - TA Alexander Ray
// Project 3

#ifndef StormTrooper_h
#define StormTrooper_h

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