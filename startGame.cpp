// starGame.cpp
// CSCI 1300 Spring 2022
// Author: Caroline Scheidt, Turner naef
// Recitation: 202 - TA Alexander Ray
// Project 3



/*
General notes/ comments:

In order to run this code, compile startGame.cpp and all the prospective .cpp files for the below 'include' statements

*/

// Include to allow code to be delayed from: https://stackoverflow.com/questions/158585/how-do-you-add-a-timed-delay-to-a-c-program 
#include<unistd.h>


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
#include "Weapon.h"

using namespace std;


// Helper functions, no story included

// Allows us to condense code and for the player to have access to a menu of their mando functions
void mandoStats(Mando myMando) {
    unsigned int microsecond = 1000000;
    cout<<"Mando Stats"<<endl;
    cout<<"\n Health: "<<myMando.getHP()<<"\n Credits: "<<myMando.getCredits()<<"\n Honor: "<<myMando.getHonorLevel()<<"\n Skill: "<<myMando.getSkillLevel()<<endl;
    cout<<"Weapons: "<<endl;
    myMando.checkWeapons();
    usleep(6*microsecond);
    return;
}

// Allows us to condense code and for the player to move freely around a region map
bool exploreRegion(Map myMap, Mando myMando) {
    char move;
    while(true) {
        myMap.displayMap();
        if (myMap.isNPCLocation()) {
            cout<<"You approach a stranger..."<<endl<<"Here are your current stats..."<<endl;
            mandoStats(myMando);
            cout<<"Do you want to interact?(y/n)"<<endl;
            char choice;
            cin >> choice;
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

void tatooine(Mando myMando) {
    // Arriving at planet
    unsigned int microsecond = 1000000;
    Planet tatooine = Planet("Tatooine", "Terrestrial", 50);

    // Sources for description should be wookiepedia and in the below order

    string description = "\n Region: Outer Rim Territories \n Sector: Arkanis \n Class: Terrestrial \n Atmosphere: Breathable \n Power: Hutt Crime Family";
    if(tatooine.planetTravel(myMando, description)) {
        cout<<"Welcome to Tatooine!"<<endl;
        cout<<"You currently have "<<myMando.getCredits()<<" credits remaining."<<endl;
        usleep(2*microsecond);
    } else {
        cout<<"Returning to the galaxy map."<<endl;
        usleep(1*microsecond);
        return;
    }

    // Player gets to read about story
    cout<<"Story goes here"<<endl;

    // Region maps created
    Map region1 = Map();
    Map region2 = Map();
    Map region3 = Map();
    Map region4 = Map();
    char regionChoice;

    // Loop to go through the regions of each planet map
    // NPC's are placed at random on the maps within a 1 - 11 x and y range
    // Player can leave the planet should they choose to
    // Player can choose to visit a region
        // Player is then prompted with a map and allowed to roam
        // If the player finds an NPC they may choose to interact with them via y/n question
        // If the player interacts they will be taken to planet map and shown the interaction they had, ie fight, conversation, knowledge, etc.

    while(true) {
        tatooine.displayPlanetMap("RegionMap1.txt");
        cout<<"What region would you like to visit?('1', '2', '3', '4', '5' to view stats, or '0' to leave tattoine)."<<endl;
        cin >> regionChoice;

        // Random npc Coords
        int randIsBrokenBruh = rand();
        int xCoord = (((double)rand() / RAND_MAX) * 10) + 1;
        int yCoord = (((double)rand() / RAND_MAX) * 10) + 1;

        switch(regionChoice) {
            case '0':
                cout<<"Now leaving Tattooine!"<<endl;
                return;
            case '1': {
                
                // For polish: rename regions etc.

                cout<<"Welcome to Region 1!"<<endl;
                usleep(1*microsecond);
                cout<<"Your ship sustained heavy damage from the fight with the stormtrooper."<<endl;
                cout<<"Explore the region to find someone to help you repair it."<<endl;

                // stuff for each region here

                // Spawns a random NPC
                //cout<<xCoord<<" "<<yCoord<<endl; - testing for randomness

                region1.spawnNPC(xCoord, yCoord);
                region1.setNPC(true);

                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region1, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    //char choice;
                    // cout<<"You have found a local spaceport engineer called Peli Motto."<<endl;
                    // // spawn NPC here and complete challenge *gulp*
                    // cout<<"Would you like to ask her to repair your ship? (press y/n)" <<endl;
                    // cin>>choice;
                    // if (choice == 'y')
                    // {
                    //     cout<< "Peli Motto: I will help you repair your ship but it will cost you ___ credits" <<endl;
                        
                    // }
                    // else
                    // {

                    // }
                    cout<<"Interaction"<<endl;
                } else {
                    cout<<"No interaction"<<endl;
                }
                // Before the code breaks the player has some time to read what happened
                usleep(2*microsecond);
                break;
            }
            case '2': {
                
                // For polish: rename regions etc.

                cout<<"Welcome to Region 2!"<<endl;
                usleep(1*microsecond);

                // stuff for each region here

                // Spawns a random NPC
                //cout<<xCoord<<" "<<yCoord<<endl; - testing for randomness

                region2.spawnNPC(xCoord, yCoord);
                region2.setNPC(true);

                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region2, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"Have an interaction ... "<<endl;
                    // spawn NPC here and complete challenge *gulp*
                } else {
                    cout<<"No interaction"<<endl;
                }
                // Before the code breaks the player has some time to read what happened
                usleep(2*microsecond);
                break;
            }
            case '3': {
                
                // For polish: rename regions etc.

                cout<<"Welcome to Region 3!"<<endl;
                usleep(1*microsecond);

                // stuff for each region here

                // Spawns a random NPC
                //cout<<xCoord<<" "<<yCoord<<endl; - testing for randomness

                region3.spawnNPC(xCoord, yCoord);
                region3.setNPC(true);

                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region3, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"Have an interaction ... "<<endl;
                    // spawn NPC here and complete challenge *gulp*
                } else {
                    cout<<"No interaction"<<endl;
                }
                // Before the code breaks the player has some time to read what happened
                usleep(2*microsecond);
                break;
            }
            case '4': {
                
                // For polish: rename regions etc.

                cout<<"Welcome to Region 4!"<<endl;
                usleep(1*microsecond);

                // stuff for each region here

                // Spawns a random NPC
                //cout<<xCoord<<" "<<yCoord<<endl; - testing for randomness

                region4.spawnNPC(xCoord, yCoord);
                region4.setNPC(true);

                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region4, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"Have an interaction ... "<<endl;
                    // spawn NPC here and complete challenge *gulp*
                } else {
                    cout<<"No interaction"<<endl;
                }
                // Before the code breaks the player has some time to read what happened
                usleep(2*microsecond);
                break;
            }
            case '5': {
                mandoStats(myMando);
                break;
            }
            default:
                cout<<"Not a valid option!"<<endl;
                usleep(2*microsecond);
                break;
        }
    }
    

    // create maps for each planet region
    // create npcs for each planet region
    return;
}





// startGame uses an outside library to delay code in order to give the game a better feeling and build
void startGame() {
    // https://stackoverflow.com/questions/158585/how-do-you-add-a-timed-delay-to-a-c-program 
    unsigned int microsecond = 1000000;

    // usleep(3*microsecond);//sleeps for 3 second
    // commented out to make testing easier

    // cout<<"Game startup..."<<endl;
    // usleep(2*microsecond);
    // cout<<"Loading..."<<endl;
    // usleep(2*microsecond);
    // cout<<"Game startup complete, continue? (y/n)"<<endl;

    // char choice;
    // cin >> choice;
    
    // if (choice == 'n') {
    //     cout<<"Closing down game."<<endl;
    //     return;
    // }

    srand(time(NULL));
    string name;
    cout<<"Greetings Mandalorian!"<<endl;
    cout<<"What should we call you?"<<endl;
    cin >> name;
    // add a name for the mando later
    Mando myMando = Mando(name);
    Weapon gun = Weapon("IB-94 blaster pistol", "Gun", 3, 3);
    myMando.addWeapon(gun);
        // Will change later for development of the story
    cout<<"Hello "<<myMando.getName()<<" and welcome! Printing the map of the Galaxy!"<<endl;
    usleep(1*microsecond);

    cout<<"GAME STORY INTRO HERE"<<endl;

    int planetCode = -1;
    while(true) {
        myMando.displayGalaxyMap();
        cout<<"Welcome to the galaxy "<<myMando.getName()<<"! Select a planet by typing in it's planet code, check your stats(1), or quit the game(0)."<<endl;
        cin >> planetCode;

        switch (planetCode) {
            case 145: {
                tatooine(myMando);

                cout<<"Welcome back to space!"<<endl;
                cout<<"Loading Galaxy Map..."<<endl;
                usleep(1*microsecond);
                break;
            }
            case 346: {
                cout<<"Planet not accessable yet"<<endl;
                break;
            }
            case 457: {
                cout<<"Planet not accessable yet"<<endl;
                break;
            }
            case 789: {
                cout<<"Planet not accessable yet"<<endl;
                break;
            }
            case 0: {
                cout<<"Quitting the game"<<endl;
                return;
            }
            case 1: {
                mandoStats(myMando);
                break;
            }
            default:
                cout<<"Not a valid input!"<<endl;
                break;  
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







// int Blockbustr::readRatings(string fileName) {
//     int maxRatings = sizeMovie;
//     if (numUsers == sizeUser) {
//         return -2;
//     }
//     ifstream fin;
//     fin.open(fileName);
//     if (fin.is_open() == false) {
//         return -1;
//     }
//     string line = "";

//     while (numUsers < sizeUser) {
//         if (fin.eof()) {
//             break;
//         }
//         getline(fin, line);
//         if (line.empty()) {
//             continue;
//         }
//         // cout << "Ratings from file: " << line << "endl";
//         string arr[1+maxRatings];
//         int rvSplit = split(line, ',', arr, 1+maxRatings);
//         if (rvSplit >= 1) {
//             int rates[maxRatings];
//             for (int i = 1; i < rvSplit; i++) {
//                 rates[i-1] = stoi(arr[i]);
//             }
//             User a(arr[0], rates, maxRatings);
//             users[numUsers] = a;
//             numUsers++;
//         }
//     }
//     return numUsers;
// }


// int split(string inputString, char separator, string arr[], int size) {
//     if (inputString == "") {
//         return 0;
//     }
//     int num = 0;
//     for (int i = 0; i < size; i++) {
//         if (arr[i] != "") {
//             num++;
//         }
//     }
//     if (num >= size) {
//         return -1;
//     }
//     int count = 0;
//     for (int i = 0; i < inputString.length(); i++) {
//         if (inputString[i] == separator) {
//             count++;
//         }
//     }
//     if (count == 0) {
//         arr[0] = inputString;
//         return 1;
//     } else if (count+1 > size) {
//         int i = 0;
//         inputString = inputString + string(1, separator);
//         while (i < size) {
//             string temp = "";
//             for (int k = 0; k < inputString.length(); k++) {
//                 if (inputString[k] == separator) {
//                     temp = inputString.substr(0, k);
//                     inputString = inputString.substr(k + 1, inputString.length()-(k+1));
//                     break;
//                 }
//             }
//             arr[i] = temp;
//             i++;
//         }
//         return -1;
//     } else {
//         int i = 0;
//         int count = 0;
//         inputString = inputString + string(1, separator);
//         while (i < size) {
//             string temp = "";
//             for (int k = 0; k < inputString.length(); k++) {
//                 if (inputString[k] == separator) {
//                     count++;
//                     temp = inputString.substr(0, k);
//                     inputString = inputString.substr(k + 1, inputString.length()-(k+1));
//                     break;
//                 }
//             }
//             arr[i] = temp;
//             i++;
//         }
//         return count;
//     }
//     return 0;
// }

// string toLower(string s) {
//     for (int i = 0; i < s.length(); i++) {
//         if ((int(s[i]) >= 65) && (int(s[i]) <= 90)) {
//             s[i] = char(int(s[i]) + 32);
//         }
//     }
//     return s;
// }
