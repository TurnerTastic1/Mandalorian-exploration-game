// starGame.cpp
// CSCI 1300 Spring 2022
// Author: Caroline Scheidt, Turner naef
// Recitation: 202 - TA Alexander Ray
// Project 3



/*
General notes/ comments:

In order to run this code, compile startGame.cpp and all the prospective .cpp files for the below 'include' statements

*/



#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include <string>

#include "Mando.h"
#include "map.h"
//#include "NPC.h"
#include "Planet.h"
//#include "StormTrooper.h"
//#include "Weapon.h"

using namespace std;
using std::this_thread::sleep_for;
using namespace std::chrono_literals;


// Helper function, no story included
// Allows us to condense code and for the player to move freely around a region map

bool exploreRegion(Map myMap) {
    char move;
    while(true) {
        myMap.displayMap();
        if (myMap.isNPCLocation()) {
            cout<<"You approach a stranger... Do you want to interact?(y/n)"<<endl;
            char choice;
            cin >>choice;
            if (choice == 'y') {
                return true;
            }
        }
        cout<<"Enter a move(w, a, s, d), or 'x' to quit."<<endl;
        cin >> move;
        if (move == 'x') {
            break;
        } else {
            myMap.executeMove(move); // if ((move == "w") || (move == "a") || (move == "s") || (move == "d")) (if needed)
        } 
    }
    cout<<"Leaving the map"<<endl;
    return false;
}

// DO NOT ADD STORY
// BASELINE FUNCTION FOR ALL PLANETS NO STORY YET

void tatooine() {
    cout<<"Welcome to Tatooine!"<<endl;

    Planet tatooine = Planet();

    cout<<"Story goes here"<<endl; // must come after region map!
    // Region maps
    Map region1 = Map();
    Map region2 = Map();
    Map region3 = Map();
    Map region4 = Map();
    char regionChoice;

    while(true) {
        tatooine.displayPlanetMap("RegionMap1.txt");
        cout<<"What region would you like to visit?(1, 2, 3, 4, or '0' to leave tattoine)."<<endl;
        cin >> regionChoice;

        // Random npc Coords
        int randIsBrokenBruh = rand();
        int xCoord = (((double)rand() / RAND_MAX) * 10) + 1;
        int yCoord = (((double)rand() / RAND_MAX) * 10) + 1;

        switch(regionChoice) {
            case '0':
                cout<<"Now leaving tattooine!"<<endl;
                return;
            case '1': {
                // Rename regions possibly?/create diff maps?
                cout<<"Welcome to region1!"<<endl;
                sleep_for(1000ms);

                // stuff for each region here

                // spawn an npc (will make it random)
                cout<<xCoord<<" "<<yCoord<<endl;
                region1.spawnNPC(xCoord, yCoord);
                region1.setNPC(true);
                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region1);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"Have an interaction ... "<<endl;
                } else {
                    cout<<"No interaction"<<endl;
                }

                sleep_for(1000ms);
                break;
            }
            case '2': {
                // Rename regions possibly?/create diff maps?
                cout<<"Welcome to region2!"<<endl;
                sleep_for(1000ms);

                // stuff for each region here

                // spawn an npc (will make it random)
                cout<<xCoord<<" "<<yCoord<<endl;
                region2.spawnNPC(xCoord, yCoord);
                region2.setNPC(true);
                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region2);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"Have an interaction ... "<<endl;
                } else {
                    cout<<"No interaction"<<endl;
                }

                sleep_for(1000ms);
                break;
            }
            case '3': {
                // Rename regions possibly?/create diff maps?
                cout<<"Welcome to region3!"<<endl;
                sleep_for(1000ms);

                // stuff for each region here

                // spawn an npc (will make it random)

                region3.spawnNPC(xCoord, yCoord);
                region3.setNPC(true);
                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region3);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"Have an interaction ... "<<endl;
                } else {
                    cout<<"No interaction"<<endl;
                }

                sleep_for(1000ms);
                break;
            }
            case '4': {
                // Rename regions possibly?/create diff maps?
                cout<<"Welcome to region4!"<<endl;
                sleep_for(1000ms);

                // stuff for each region here

                // spawn an npc (will make it random)

                region4.spawnNPC(xCoord, yCoord);
                region4.setNPC(true);
                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region4);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"Have an interaction ... "<<endl;
                } else {
                    cout<<"No interaction"<<endl;
                }

                sleep_for(1000ms);
                break;
            }
            default:
                cout<<"Not a valid region!"<<endl;
                sleep_for(1000ms);
                break;
        }
    }
    

    // create maps for each planet region
    // create npcs for each planet region
    return;
}





// startGame uses an outside library to delay code in order to give the game a better feeling and build
void startGame() {
    // commented out to make testing easier

    // cout<<"Game startup..."<<endl;
    // sleep_for(2000ms);
    // cout<<"Loading..."<<endl;
    // sleep_for(2000ms);
    // cout<<"Game startup complete, continue? (y/n)"<<endl;

    // char choice;
    // cin >> choice;
    
    // if (choice == 'n') {
    //     cout<<"Closing down game."<<endl;
    //     return;
    // }

    srand(time(NULL));
    Mando myMando = Mando();
        // Will change later for development of the story
    cout<<"Welcome! Printing the map of the Galaxy!"<<endl;
    sleep_for(1000ms);

    cout<<"GAME STORY INTRO HERE"<<endl;

    int planetCode = 0;
    while(true) {
        myMando.displayGalaxyMap();
        cout<<"Enter your choice(Planet #/code)"<<endl<<"or enter 0 to quit"<<endl;
        cin >> planetCode;

        switch (planetCode) {
            case 145:
                tatooine();

                cout<<"Welcome back to space!"<<endl;
                cout<<"Loading Galaxy Map..."<<endl;
                sleep_for(1000ms);
                break;
            case 0:
                cout<<"Quitting the game"<<endl;
                return;
        }
    }
    return;
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

    //Map myMap = Map();
    //myMap.displayMap();

    // char move;
    // while(true) {
    //     myMap.displayMap();
    //     cout<<"Enter a move(w, a, s, d), or 'x' to quit."<<endl;
    //     cin >> move;
    //     if (move == 'x') {
    //         break;
    //     } else {
    //         myMap.executeMove(move); // if ((move == "w") || (move == "a") || (move == "s") || (move == "d")) (if needed)
    //     } 
    // }  

    // Planet tatooine = Planet();
    // tatooine.displayPlanetMap("RegionMap1.txt");

    return 0;
}