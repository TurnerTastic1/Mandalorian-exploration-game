// starGame.cpp
// CSCI 1300 Spring 2022
// Author: Caroline Scheidt, Turner naef
// Recitation: 202 - TA Alexander Ray
// Project 3

#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <string>

#include "Mando.h"
//#include "Map.h"
//#include "NPC.h"
//#include "Planet.h"
//#include "StormTrooper.h"
//#include "Weapon.h"

using namespace std;
using std::this_thread::sleep_for;
using namespace std::chrono_literals;

// startGame uses an outside library to delay code in order to give the game a better feeling and build
void startGame() {
    cout<<"Game startup..."<<endl;
    sleep_for(2000ms);
    cout<<"Loading..."<<endl;
    sleep_for(2000ms);
    cout<<"Game startup complete, continue? (y/n)"<<endl;

    char choice;
    cin >> choice;
    
    if (choice == 'n') {
        cout<<"Closing down game."<<endl;
        return;
    } else {
        Mando myMando = Mando();
        // Will change later for development of the story
        cout<<"Welcome! Printing the map of the Galaxy!"<<endl;
        sleep_for(1000ms);

        myMando.displayGalaxyMap();
        cout<<"GAME STORY INTRO HERE"<<endl;
        // cout<<guy.getName()<<endl;
    }

    while(true) {
        int planetCode = 0;
        cout<<"Enter your choice(Planet #/code)"<<endl<<"or enter 0 to quit"<<endl;
        cin >> planetCode;

        switch (planetCode) {
            case 145:
                int continue1 = 0;
                cout<<"Welcome to Tattoine!"<<endl;
                cout<<"Your ship sustained heavy damage from your battle with the stormtrooper."<<endl;
                cout<<"Luckily, you landed in Region 1, and you can repair your ship for a certain amount of credits." <<endl;
                cout<<"Would you like to continue? yes = 1; no = 2" << endl;
                cin >> continue1;

                if (continue1 == 1)
                {
                    tattoine
                }
                // automatically go into region 1
                // should we make a function for each region?

                return;
            case 0:
                cout<<"Quitting the game"<<endl;
                return;
        }
    }
    return;
}

void tatooine() {
    cout<<"Welcome to Tatooine"<<endl;
    // insert story here/later

    // print a planet map

    // create maps for each planet region
    // create npcs for each planet region


}


// functions to go to differtent planets
/*
-maybe we should send credits in? otherwise does it have a certain value for credits?
void PlanetTatooine()
{
    

}


*/



int main(){

    startGame();





    return 0;
}