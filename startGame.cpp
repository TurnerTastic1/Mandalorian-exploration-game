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
#include "NPC.h"
#include "Planet.h"
//#include "StormTrooper.h"
#include "Weapon.h"

// Colors!!!
//the following are UBUNTU/LINUX, and MacOS ONLY terminal color codes.
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */



using namespace std;


// Helper functions, no story included


// The following three functions are used to read in a file of NPC's
// The NPC's have differing attributes and will be sorted into their prospective functions based on their planet variables

string toLower(string s) {
    for (int i = 0; i < s.length(); i++) {
        if ((int(s[i]) >= 65) && (int(s[i]) <= 90)) {
            s[i] = char(int(s[i]) + 32);
        }
    }
    return s;
}

int split(string inputString, char separator, string arr[], int size) {
    if (inputString == "") {
        return 0;
    }
    int num = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != "") {
            num++;
        }
    }
    if (num >= size) {
        return -1;
    }
    int count = 0;
    for (int i = 0; i < inputString.length(); i++) {
        if (inputString[i] == separator) {
            count++;
        }
    }
    if (count == 0) {
        arr[0] = inputString;
        return 1;
    } else if (count+1 > size) {
        int i = 0;
        inputString = inputString + string(1, separator);
        while (i < size) {
            string temp = "";
            for (int k = 0; k < inputString.length(); k++) {
                if (inputString[k] == separator) {
                    temp = inputString.substr(0, k);
                    inputString = inputString.substr(k + 1, inputString.length()-(k+1));
                    break;
                }
            }
            arr[i] = temp;
            i++;
        }
        return -1;
    } else {
        int i = 0;
        int count = 0;
        inputString = inputString + string(1, separator);
        while (i < size) {
            string temp = "";
            for (int k = 0; k < inputString.length(); k++) {
                if (inputString[k] == separator) {
                    count++;
                    temp = inputString.substr(0, k);
                    inputString = inputString.substr(k + 1, inputString.length()-(k+1));
                    break;
                }
            }
            arr[i] = temp;
            i++;
        }
        return count;
    }
    return 0;
}

vector<NPC> readNPC(string fileName) {

    vector<NPC> myNPCs;
    string line = "";
    Weapon basic = Weapon();
    bool boo = false;

    ifstream fin;
    fin.open(fileName);
    if (fin.is_open() == false) {
        cout<<"File cannot be opened"<<endl;
        return myNPCs;
    }

    while (true) {
        if (fin.eof()) {
            break;
        }
        boo = false;

        getline(fin, line);
        if (line.empty()) {
            continue;
        }
        
        string arr[8];
        int rvSplit = split(line, ',', arr, 8);

        if (arr[5] == " true") {
            boo = true;
        }

        NPC dude = NPC(arr[0], arr[1], arr[2], arr[3], stoi(arr[4]), boo, stoi(arr[6]), stoi(arr[7]), basic);
        myNPCs.push_back(dude);
    }
    return myNPCs;
}

// Allows us to condense code and for the player to have access to a menu of their mando functions
void mandoStats(Mando myMando) {
    unsigned int microsecond = 1000000;
    cout<<"Mando Stats"<<endl;
    cout<<"Health: "<<myMando.getHP()<<"\n Credits: "<<myMando.getCredits()<<"\n Honor: "<<myMando.getHonorLevel()<<"\n Skill: "<<myMando.getSkillLevel()<<endl;
    cout<<"Weapons: "<<endl;
    myMando.checkWeapons();
    usleep(6*microsecond);
    return;
}

// Allows us to condense code and for the player to move freely around a region map
bool exploreRegion(Map myMap, Mando myMando) {
    char move;
    cout<<"Map Legend: x = 'YOU', A = 'NPC'"<<endl;
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

Mando tatooine(Mando myMando, vector<NPC> vec) {
    // Arriving at planet
    unsigned int microsecond = 1000000;
    Planet tatooine = Planet("Tatooine", "Terrestrial", 20);

    // Sources for description should be wookiepedia and in the below order

    string description = "\n Region: Outer Rim Territories \n Sector: Arkanis \n Class: Terrestrial \n Atmosphere: Breathable \n Affiliation: Hutt Crime Family \n Species: Jawa, Tusken Raider, Human, Hutt, Rodian...";
    if(tatooine.planetTravel(myMando, description)) {
        cout<<"Welcome to Tatooine!"<<endl;
        cout<<"You currently have "<<myMando.getCredits()<<" credits remaining."<<endl;
        usleep(2*microsecond);
    } else {
        cout<<"You may not have enough credits for this planet!"<<endl;
        usleep(1*microsecond);
        return myMando;
    }

    // Player gets to read about story

    // Region maps created
    Map region1 = Map();
    Map region2 = Map();
    Map region3 = Map();
    Map region4 = Map();
    char regionChoice;

    // NPC's are taken in and configured to their regions

    // Loop to go through the regions of each planet map
    // NPC's are placed at random on the maps within a 1 - 11 x and y range
    // Player can leave the planet should they choose to
    // Player can choose to visit a region
        // Player is then prompted with a map and allowed to roam
        // If the player finds an NPC they may choose to interact with them via y/n question
        // If the player interacts they will be taken to planet map and shown the interaction they had, ie fight, conversation, knowledge, etc.

    while(true) {
        tatooine.displayPlanetMap("tatooineRegion.txt");
        cout<<"What region would you like to visit?('1', '2', '3', '4', '5' to view stats, or '0' to leave Tattoine)."<<endl;
        cin >> regionChoice;

        // Random npc Coords
        int randIsBrokenBruh = rand();
        int xCoord = (((double)rand() / RAND_MAX) * 10) + 1;
        int yCoord = (((double)rand() / RAND_MAX) * 10) + 1;

        switch(regionChoice) {
            case '0':
                cout<<"Now leaving Tattooine!"<<endl;
                return myMando;
            case '1': {

                region1.spawnNPC(xCoord, yCoord);
                region1.setNPC(true);

                // create NPC object for interaction based on NPC vector
                NPC dude = NPC();
                for (int i = 0; i < vec.size(); i++) {
                    if (vec[i].getPlanetRegion() == " region 1") {
                        dude = vec[i];
                        break;
                    }
                }
                    
                // For polish: rename regions etc. if needed
                

                // story
                cout<<"Welcome to Region 1!"<<endl;
                cout<<"You have landed in a hangar owned by a ship engineer named Peli Motto."<<endl;
                usleep(2*microsecond);
                cout<<"Your ship has been dealt its usual wear and tear, reparing it would be a good idea."<<endl;
                usleep(2*microsecond);
                cout<<"Peli Motto offers to repair the Razor Crest for 25 credits."<<"It is a fair deal, so you accept."<<endl;
                usleep(2*microsecond);
                myMando.setCredits(myMando.getCredits() - 25);
                
                // interactions/play
                cout<<"Peli glances at your appearence..."<<endl;
                usleep(1*microsecond);
                cout<<"'Say, you wouldn't be interested in making some credits now would you?'"<<endl;
                usleep(2*microsecond);
                cout<<"'There is this assasin you see, Fennec Shand I think, hiding out beyond the dune sea. If you want you could go take a look. The bounty is around 70 credits.'"<<endl;
                usleep(2*microsecond);
                cout<<"Would you like to accept this quest (y/n)?"<<endl;

                char choice1;
                cin >> choice1;
                if (choice1 == 'y') {
                    // allow player to explore the region and if so, interact w the npc
                    bool interact = exploreRegion(region1, myMando);

                    // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                    if (interact) {
                        // spawn NPC here and complete challenge *gulp*
                        cout<<"You have found "<<dude.getName()<<" and she begins to approach you"<<endl;
                        cout<<"Without hesitation she reaches for her blaster, leading you to react..."<<endl;

                        // Have them fight here


                    } else {
                        cout<<"You wisely choose to leave the area"<<endl;
                    }
                } else {
                    cout<<"You wisely choose to leave the area"<<endl;
                }

                // Before the code breaks the player has some time to read what happened
                usleep(2*microsecond);
                break;
            }
            case '2': {
                
                // For polish: rename regions etc.


                // Spawns a random NPC
                //cout<<xCoord<<" "<<yCoord<<endl; - testing for randomness

                region2.spawnNPC(xCoord, yCoord);
                region2.setNPC(true);

                // create NPC object for interaction based on NPC vector
                NPC dude = NPC();
                for (int i = 0; i < vec.size(); i++) {
                    if (vec[i].getPlanetRegion() == " region 1") {
                        dude = vec[i];
                        break;
                    }
                }

                cout<<"Welcome to Region 2!"<<endl;
                usleep(1*microsecond);

                // stuff for each region here

                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region2, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"Have an interaction ... "<<endl;
                    // spawn NPC here and complete challenge *gulp*
                }
                // Before the code breaks the player has some time to read what happened
                usleep(2*microsecond);
                break;
            }
            case '3': {
                
                // For polish: rename regions etc.


                // Spawns a random NPC
                //cout<<xCoord<<" "<<yCoord<<endl; - testing for randomness

                region3.spawnNPC(xCoord, yCoord);
                region3.setNPC(true);

                // create NPC object for interaction based on NPC vector
                NPC dude = NPC();
                for (int i = 0; i < vec.size(); i++) {
                    if (vec[i].getPlanetRegion() == " region 1") {
                        dude = vec[i];
                        break;
                    }
                }

                cout<<"Welcome to Region 3!"<<endl;
                usleep(1*microsecond);

                // stuff for each region here

                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region3, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"Have an interaction ... "<<endl;
                    // spawn NPC here and complete challenge *gulp*
                }
                // Before the code breaks the player has some time to read what happened
                usleep(2*microsecond);
                break;
            }
            case '4': {
                
                // For polish: rename regions etc.


                // Spawns a random NPC
                //cout<<xCoord<<" "<<yCoord<<endl; - testing for randomness

                region4.spawnNPC(xCoord, yCoord);
                region4.setNPC(true);

                // create NPC object for interaction based on NPC vector
                NPC dude = NPC();
                for (int i = 0; i < vec.size(); i++) {
                    if (vec[i].getPlanetRegion() == " region 1") {
                        dude = vec[i];
                        break;
                    }
                }

                cout<<"Welcome to Region 4!"<<endl;
                usleep(1*microsecond);

                // stuff for each region here

                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region4, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"Have an interaction ... "<<endl;
                    // spawn NPC here and complete challenge *gulp*
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
    
    return myMando;
}

Mando tython(Mando myMando, vector<NPC> vec) {
    // Arriving at planet
    unsigned int microsecond = 1000000;
    Planet tython = Planet("Tython", "Terrestrial", 30);

    // Sources for description should be wookiepedia and in the below order

    string description = "\n Region: Deep Core \n Sector: Unknown \n Class: Terrestrial \n Atmosphere: Breathable \n Affiliation: Jedi Order \n Species: Human";
    if(tython.planetTravel(myMando, description)) {
        cout<<"Welcome to Tython!"<<endl;
        cout<<"You currently have "<<myMando.getCredits()<<" credits remaining."<<endl;
        usleep(2*microsecond);
    } else {
        cout<<"You may not have enough credits for this planet!"<<endl;
        usleep(1*microsecond);
        return myMando;
    }

    // Player gets to read about story
    cout<<"Story goes here"<<endl;

    // Region maps created
    Map region1 = Map();
    Map region2 = Map();
    Map region3 = Map();
    Map region4 = Map();
    char regionChoice;

    // NPC's are taken in and configured to their regions

    // Loop to go through the regions of each planet map
    // NPC's are placed at random on the maps within a 1 - 11 x and y range
    // Player can leave the planet should they choose to
    // Player can choose to visit a region
        // Player is then prompted with a map and allowed to roam
        // If the player finds an NPC they may choose to interact with them via y/n question
        // If the player interacts they will be taken to planet map and shown the interaction they had, ie fight, conversation, knowledge, etc.

    while(true) {
        tython.displayPlanetMap("tythonRegion.txt");
        cout<<"What region would you like to visit?('1', '2', '3', '4', '5' to view stats, or '0' to leave Tython)."<<endl;
        cin >> regionChoice;

        // Random npc Coords
        int randIsBrokenBruh = rand();
        int xCoord = (((double)rand() / RAND_MAX) * 10) + 1;
        int yCoord = (((double)rand() / RAND_MAX) * 10) + 1;

        switch(regionChoice) {
            case '0':
                cout<<"Now leaving Tython!"<<endl;
                return myMando;
            case '1': {
                
                // For polish: rename regions etc. if needed

                cout<<"Welcome to Region 1!"<<endl;
                usleep(1*microsecond);

                // stuff for each region here

                // Spawns a random NPC

                region1.spawnNPC(xCoord, yCoord);
                region1.setNPC(true);
                
                // create NPC object for interaction based on NPC vector
                NPC dude = NPC();
                for (int i = 0; i < vec.size(); i++) {
                    if (vec[i].getPlanetRegion() == " region 1") {
                        dude = vec[i];
                        break;
                    }
                }

                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region1, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"Have an interaction ... "<<endl;
                    // spawn NPC here and complete challenge *gulp*
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

                // create NPC object for interaction based on NPC vector
                NPC dude = NPC();
                for (int i = 0; i < vec.size(); i++) {
                    if (vec[i].getPlanetRegion() == " region 1") {
                        dude = vec[i];
                        break;
                    }
                }

                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region2, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"Have an interaction ... "<<endl;
                    // spawn NPC here and complete challenge *gulp*
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

                // create NPC object for interaction based on NPC vector
                NPC dude = NPC();
                for (int i = 0; i < vec.size(); i++) {
                    if (vec[i].getPlanetRegion() == " region 1") {
                        dude = vec[i];
                        break;
                    }
                }

                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region3, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"Have an interaction ... "<<endl;
                    // spawn NPC here and complete challenge *gulp*
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

                // create NPC object for interaction based on NPC vector
                NPC dude = NPC();
                for (int i = 0; i < vec.size(); i++) {
                    if (vec[i].getPlanetRegion() == " region 1") {
                        dude = vec[i];
                        break;
                    }
                }

                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region4, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"Have an interaction ... "<<endl;
                    // spawn NPC here and complete challenge *gulp*
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
    
    return myMando;
}

Mando trask(Mando myMando, vector<NPC> vec) {
    // Arriving at planet
    unsigned int microsecond = 1000000;
    Planet trask = Planet("Trask", "Terrestrial", 40);

    // Sources for description should be wookiepedia and in the below order

    string description = "\n Region: Outer Rim Territories \n Sector: Arkanis \n Class: Ocean \n Atmosphere: Breathable \n Affiliation: Unknown \n Species: Human, Mon Calamari, Quarren, Unidentified Anthropoid";
    if(trask.planetTravel(myMando, description)) {
        cout<<"Welcome to Trask!"<<endl;
        cout<<"You currently have "<<myMando.getCredits()<<" credits remaining."<<endl;
        usleep(2*microsecond);
    } else {
        cout<<"You may not have enough credits for this planet!"<<endl;
        usleep(1*microsecond);
        return myMando;
    }

    // Player gets to read about story
    cout<<"Story goes here"<<endl;

    // Region maps created
    Map region1 = Map();
    Map region2 = Map();
    Map region3 = Map();
    Map region4 = Map();
    char regionChoice;

    // NPC's are taken in and configured to their regions

    // Loop to go through the regions of each planet map
    // NPC's are placed at random on the maps within a 1 - 11 x and y range
    // Player can leave the planet should they choose to
    // Player can choose to visit a region
        // Player is then prompted with a map and allowed to roam
        // If the player finds an NPC they may choose to interact with them via y/n question
        // If the player interacts they will be taken to planet map and shown the interaction they had, ie fight, conversation, knowledge, etc.

    while(true) {
        trask.displayPlanetMap("traskRegion.txt");
        cout<<"What region would you like to visit?('1', '2', '3', '4', '5' to view stats, or '0' to leave Trask)."<<endl;
        cin >> regionChoice;

        // Random npc Coords
        int randIsBrokenBruh = rand();
        int xCoord = (((double)rand() / RAND_MAX) * 10) + 1;
        int yCoord = (((double)rand() / RAND_MAX) * 10) + 1;

        switch(regionChoice) {
            case '0':
                cout<<"Now leaving Trask!"<<endl;
                return myMando;
            case '1': {
                
                // For polish: rename regions etc. if needed

                cout<<"Welcome to Region 1!"<<endl;
                usleep(1*microsecond);

                // stuff for each region here

                // Spawns a random NPC

                region1.spawnNPC(xCoord, yCoord);
                region1.setNPC(true);
                
                // create NPC object for interaction based on NPC vector
                NPC dude = NPC();
                for (int i = 0; i < vec.size(); i++) {
                    if (vec[i].getPlanetRegion() == " region 1") {
                        dude = vec[i];
                        break;
                    }
                }

                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region1, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"Have an interaction ... "<<endl;
                    // spawn NPC here and complete challenge *gulp*
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

                // create NPC object for interaction based on NPC vector
                NPC dude = NPC();
                for (int i = 0; i < vec.size(); i++) {
                    if (vec[i].getPlanetRegion() == " region 1") {
                        dude = vec[i];
                        break;
                    }
                }

                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region2, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"Have an interaction ... "<<endl;
                    // spawn NPC here and complete challenge *gulp*
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

                // create NPC object for interaction based on NPC vector
                NPC dude = NPC();
                for (int i = 0; i < vec.size(); i++) {
                    if (vec[i].getPlanetRegion() == " region 1") {
                        dude = vec[i];
                        break;
                    }
                }

                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region3, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"Have an interaction ... "<<endl;
                    // spawn NPC here and complete challenge *gulp*
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

                // create NPC object for interaction based on NPC vector
                NPC dude = NPC();
                for (int i = 0; i < vec.size(); i++) {
                    if (vec[i].getPlanetRegion() == " region 1") {
                        dude = vec[i];
                        break;
                    }
                }

                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region4, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"Have an interaction ... "<<endl;
                    // spawn NPC here and complete challenge *gulp*
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
    
    return myMando;
}

Mando nevarro(Mando myMando, vector<NPC> vec) {
    // Arriving at planet
    unsigned int microsecond = 1000000;
    Planet nevarro = Planet("Nevarro", "Terrestrial", 60);

    // Sources for description should be wookiepedia and in the below order

    string description = "\n Region: Outer Rim Territories \n Sector: Nevarro's sector \n Class: Terrestrial \n Atmosphere: Breathable \n Power: Galactic Empire \n Species: Humans, Jawas, Rodians, Trandoshans, Twi'leks, Zabraks...";
    if(nevarro.planetTravel(myMando, description)) {
        cout<<"Welcome to Nevarro!"<<endl;
        cout<<"You currently have "<<myMando.getCredits()<<" credits remaining."<<endl;
        usleep(2*microsecond);
    } else {
        cout<<"You may not have enough credits for this planet!"<<endl;
        usleep(1*microsecond);
        return myMando;
    }

    // Player gets to read about story
    cout<<"Story goes here"<<endl;

    // Region maps created
    Map region1 = Map();
    Map region2 = Map();
    Map region3 = Map();
    Map region4 = Map();
    char regionChoice;

    // NPC's are taken in and configured to their regions

    // Loop to go through the regions of each planet map
    // NPC's are placed at random on the maps within a 1 - 11 x and y range
    // Player can leave the planet should they choose to
    // Player can choose to visit a region
        // Player is then prompted with a map and allowed to roam
        // If the player finds an NPC they may choose to interact with them via y/n question
        // If the player interacts they will be taken to planet map and shown the interaction they had, ie fight, conversation, knowledge, etc.

    while(true) {
        nevarro.displayPlanetMap("tatooineRegion.txt");
        cout<<"What region would you like to visit?('1', '2', '3', '4', '5' to view stats, or '0' to leave Tattoine)."<<endl;
        cin >> regionChoice;

        // Random npc Coords
        int randIsBrokenBruh = rand();
        int xCoord = (((double)rand() / RAND_MAX) * 10) + 1;
        int yCoord = (((double)rand() / RAND_MAX) * 10) + 1;

        switch(regionChoice) {
            case '0':
                cout<<"Now leaving Tattooine!"<<endl;
                return myMando;
            case '1': {
                
                // For polish: rename regions etc. if needed

                cout<<"Welcome to Region 1!"<<endl;
                usleep(1*microsecond);

                // stuff for each region here

                // Spawns a random NPC

                region1.spawnNPC(xCoord, yCoord);
                region1.setNPC(true);
                
                // create NPC object for interaction based on NPC vector
                NPC dude = NPC();
                for (int i = 0; i < vec.size(); i++) {
                    if (vec[i].getPlanetRegion() == " region 1") {
                        dude = vec[i];
                        break;
                    }
                }

                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region1, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"Have an interaction ... "<<endl;
                    // spawn NPC here and complete challenge *gulp*
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

                // create NPC object for interaction based on NPC vector
                NPC dude = NPC();
                for (int i = 0; i < vec.size(); i++) {
                    if (vec[i].getPlanetRegion() == " region 1") {
                        dude = vec[i];
                        break;
                    }
                }

                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region2, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"Have an interaction ... "<<endl;
                    // spawn NPC here and complete challenge *gulp*
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

                // create NPC object for interaction based on NPC vector
                NPC dude = NPC();
                for (int i = 0; i < vec.size(); i++) {
                    if (vec[i].getPlanetRegion() == " region 1") {
                        dude = vec[i];
                        break;
                    }
                }

                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region3, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"Have an interaction ... "<<endl;
                    // spawn NPC here and complete challenge *gulp*
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

                // create NPC object for interaction based on NPC vector
                NPC dude = NPC();
                for (int i = 0; i < vec.size(); i++) {
                    if (vec[i].getPlanetRegion() == " region 1") {
                        dude = vec[i];
                        break;
                    }
                }

                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region4, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"Have an interaction ... "<<endl;
                    // spawn NPC here and complete challenge *gulp*
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
    
    return myMando;
}

// generates space/delay between code and uses a given number of times to do so
void genSpace(int n) {
    unsigned int microsecond = 1000000;
    for (int i = 0; i < n; i++) {
        cout<<endl;
        usleep(1*microsecond);
    }
    return;
}

// prints a graphic to the screen
// source: https://patorjk.com/software/taag/#p=display&f=Big&t=A%20long%20time%20ago%20in%20a%20galaxy%20far%2C%20%0Afar%20away... 
void introGraphic() {
    unsigned int microsecond = 1000000;
    
    // font = block
    ifstream fin;
    fin.open("introLongTime.txt");
    string line = "";
    if (fin.is_open() == false) {
        cout<< "Intro graphic is not available!"<<endl;
        return;
    }
    while (!fin.eof()) {
        getline(fin, line);
        cout<< CYAN<<line<< RESET<<endl;
    }
    fin.close();

    cout<<endl<<endl<<endl<<endl<<endl;
    genSpace(3);

    // font = big
    ifstream fin1;
    fin1.open("introTitle.txt");
    string line1 = "";
    if (fin1.is_open() == false) {
        cout<< "Intro graphic is not available!"<<endl;
        return;
    }
    while (!fin1.eof()) {
        getline(fin1, line1);
        cout<< YELLOW <<line1<< RESET<<endl;
    }
    fin1.close();

    genSpace(5);

    // font = stick letters
    ifstream fin2;
    fin2.open("introStory1.txt");
    string line2 = "";
    if (fin2.is_open() == false) {
        cout<< "Intro graphic is not available!"<<endl;
        return;
    }
    while (!fin2.eof()) {
        getline(fin2, line2);
        cout<< YELLOW <<line2<< RESET<<endl;
    }
    fin2.close();

    genSpace(7);

    // font = stick letters
    ifstream fin3;
    fin3.open("introStory2.txt");
    string line3 = "";
    if (fin3.is_open() == false) {
        cout<< "Intro graphic is not available!"<<endl;
        return;
    }
    while (!fin3.eof()) {
        getline(fin3, line3);
        cout<< YELLOW <<line3<< RESET<<endl;
    }
    fin3.close();

    genSpace(7);

    // font = stick letters
    ifstream fin4;
    fin4.open("introStory3.txt");
    string line4 = "";
    if (fin4.is_open() == false) {
        cout<< "Intro graphic is not available!"<<endl;
        return;
    }
    while (!fin4.eof()) {
        getline(fin4, line4);
        cout<< YELLOW <<line4<< RESET<<endl;
    }
    fin4.close();

    genSpace(7);
    
    return;
}

// startGame uses an outside library to delay code in order to give the game a better feeling and build
void startGame() {
    // https://stackoverflow.com/questions/158585/how-do-you-add-a-timed-delay-to-a-c-program 
    unsigned int microsecond = 1000000;

    // usleep(3*microsecond);//sleeps for 3 second
    // commented out to make testing easier

    // Prints the intro ascii graphics!
    introGraphic();

    cout<<"Your goal..."<<endl;
    usleep(2*microsecond);
    cout<<"Stop Moff Gideon at all costs..."<<endl;
    usleep(2*microsecond);
    cout<<"Do you wish to continue?(y/n)"<<endl;

    char choice;
    cin >> choice;
    
    if (choice == 'n') {
        cout<<"Closing the game."<<endl;
        return;
    }

    vector<NPC> NPCs = readNPC("NPCtest.txt");
    
    // Sorting NPC's for planets
    vector<NPC> tatooineNPC;
    vector<NPC> tythonNPC;
    vector<NPC> traskNPC;
    vector<NPC> nevarroNPC;


    for (int i = 0; i <NPCs.size(); i++) {
        if (NPCs[i].getPlanet() == " Tatooine") {
            tatooineNPC.push_back(NPCs[i]);
        } else if (NPCs[i].getPlanet() == " Tython") {
            tythonNPC.push_back(NPCs[i]);
        } else if (NPCs[i].getPlanet() == " Trask") {
            traskNPC.push_back(NPCs[i]);
        } else if (NPCs[i].getPlanet() == " Nevarro") {
            nevarroNPC.push_back(NPCs[i]);
        }
    }
    //cout<<tatooineNPC[0].getName()<<endl;


    srand(time(NULL));
    string name;
    cout<<"Greetings Mandalorian!"<<endl;
    cout<<"What should we call you?"<<endl;
    cin >> name;

    Mando myMando = Mando(name);
    Weapon gun = Weapon("IB-94 blaster pistol", "Gun", 3, 3);
    myMando.addWeapon(gun);

    cout<<"Greetings "<<myMando.getName()<<"! Printing the map of the Galaxy!"<<endl;
    usleep(2*microsecond);
    myMando.displayGalaxyMap();
    usleep(3*microsecond);
    cout<<"There are four planets that Moff Gideon is rumored to be on."<<endl;
    usleep(3*microsecond);
    cout<<"They are Tatooine(145), Tython (346), Trask(457), and Navarro(789)."<<endl;
    usleep(3*microsecond);
    cout<<"Planet travel costs a certain amount of credits. You currently have "<<myMando.getCredits()<<" credits."<<endl;
    usleep(3*microsecond);
    cout<<"Select a planet by typing in it's planet code, check your stats(1), or quit the game(0)."<<endl;

    int planetCode = -1;
    while(true) {
        cin >> planetCode;

        switch (planetCode) {
            case 145: {
                myMando = tatooine(myMando, tatooineNPC);

                cout<<"Welcome back to space!"<<endl;
                cout<<"Loading Galaxy Map..."<<endl;
                usleep(1*microsecond);
                break;
            }
            case 346: {
                myMando = tython(myMando, tythonNPC);

                cout<<"Welcome back to space!"<<endl;
                cout<<"Loading Galaxy Map..."<<endl;
                usleep(1*microsecond);
                break;
            }
            case 457: {
                myMando = trask(myMando, traskNPC);

                cout<<"Welcome back to space!"<<endl;
                cout<<"Loading Galaxy Map..."<<endl;
                usleep(1*microsecond);
                break;
            }
            case 789: {
                myMando = nevarro(myMando, nevarroNPC);

                cout<<"Welcome back to space!"<<endl;
                cout<<"Loading Galaxy Map..."<<endl;
                usleep(1*microsecond);
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
        myMando.displayGalaxyMap();
        cout<<"Select a planet by typing in it's planet code, check your stats(1), or quit the game(0)."<<endl;
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
    //introGraphic();
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

