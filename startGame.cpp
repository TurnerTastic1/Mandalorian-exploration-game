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
    cout<<"Health: "<<myMando.getHP()<<"\nCredits: "<<myMando.getCredits()<<"\nHonor: "<<myMando.getHonorLevel()<<"\nSkill: "<<myMando.getSkillLevel()<<endl;
    cout<<"Weapons: "<<endl;
    myMando.checkWeapons();
    usleep(6*microsecond);
    return;
}

// Allows us to condense code and for the player to move freely around a region map
bool exploreRegion(Map myMap, Mando myMando) {
    unsigned int microsecond = 1000000;
    char move;
    cout<<"Map Legend: x = 'YOU', A = 'NPC'"<<endl;
    while(true) {
        myMap.displayMap();
        if (myMap.isNPCLocation()) {
            cout<<"You approach a stranger..."<<endl<<"Here are your current stats..."<<endl;
            mandoStats(myMando);

            cout<<endl<<"Do you want to interact?(y/n)"<<endl;
            char choice;
            cin >> choice;
            if (choice == 'y') {
                return true;
            }
        }
        cout<<"Enter a move(w, a, s, d), or 'x' to quit."<<endl;
        cin >> move;
        if ((move != 'x') || (move != 'w') || (move != 'a') || (move != 's') || (move != 'd')) {
            cout<<"Not a valid move!"<<endl;
            usleep(2*microsecond);
        } else if (move == 'x') {
            break;
        } else {
            myMap.executeMove(move); // if ((move == "w") || (move == "a") || (move == "s") || (move == "d")) (if needed)
        } 
    }
    cout<<"Leaving the map"<<endl;
    return false;
}

Weapon chooseWeapon(Mando myMando) {
    int choice;
    cout<<"Quickly you choose a weapon for the fight:"<<endl;
    for (int i = 0; i < myMando.getWeapons().size(); i++) {
        cout<<i+1<<": "<<myMando.getWeapons()[i].getName()<<endl;
    }
    cin >> choice;
    return myMando.retrieveWeapon(choice-1);
}

Mando tatooine(Mando myMando, vector<NPC> vec) {

    // tests
    //myMando.setAlive(false);

    // Arriving at planet
    unsigned int microsecond = 1000000;
    Planet tatooine = Planet("Tatooine", "Terrestrial", 20);

    // Sources for description should be wookiepedia and in the below order

    string description = "\nRegion: Outer Rim Territories \nSector: Arkanis \nClass: Terrestrial \nAtmosphere: Breathable \nAffiliation: Hutt Crime Family \nSpecies: Jawa, Tusken Raider, Human, Hutt, Rodian...";
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
        if (myMando.getAlive() == false) {
            return myMando;
        }
        bool ultraBreak = false;
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
                cout<<"You have landed in a hangar owned by a ship engineer named Peli Motto."<<endl;
                usleep(2*microsecond);
                cout<<"Your ship has been dealt its usual wear and tear, reparing it would be a good idea."<<endl;
                usleep(2*microsecond);
                cout<<"Peli Motto offers to repair the Razor Crest for 25 credits. "<<"It is a fair deal, so you accept."<<endl;
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
                        usleep(1*microsecond);
                        cout<<"Without hesitation she reaches for her blaster, leading you to react..."<<endl;

                        // fight sequence, use for most fights but alter slightly if needed
                        Weapon mandoWeap = chooseWeapon(myMando);
                        int fightRV = myMando.fightNPC(dude, mandoWeap);
                        if (fightRV == -3) {
                            ultraBreak = true;
                            break;
                        } else if (fightRV == 1) {
                            cout<<"You are rewarded "<<dude.getCreditReward()<<" credits for capturing "<<dude.getName()<<" and turning them in to the Bounty Hunters Guild"<<endl;
                            usleep(3*microsecond);
                            myMando.setCredits(myMando.getCredits() + dude.getCreditReward());
                        }

                    } else {
                        cout<<"You wisely choose to leave the area"<<endl;
                    }
                } else {
                    cout<<"You wisely choose to leave the area"<<endl;
                }

                if (!ultraBreak) { 
                    cout<<"As you return to your ship Peli greets you, informing you that Tatooine has many criminals on the loose and information that could be of value to you."<<endl;
                    usleep(2*microsecond);
                    cout<<"She says that she has repaired your ship and that you are free to leave."<<endl;
                    usleep(4*microsecond);
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
                    if (vec[i].getPlanetRegion() == " region 2") {
                        dude = vec[i];
                        break;
                    }
                }

                cout<<"You have landed in a town near the Dune Sea."<<endl;
                usleep(2*microsecond);
                cout<<"Some locals surround your ship and who you assume to be their leader approaches you..."<<endl;
                usleep(2*microsecond);

                cout<<"The leader, a local, by the name of Soti Mel introduces herself and greets you."<<endl;
                usleep(2*microsecond);
                cout<<"'Hello Mandalorian. I am sorry to bombard you this way. But my town desparately needs your help.'"<<endl;
                usleep(3*microsecond);
                cout<<"'Our town's governors have been taken hostage by the Tusken Raiders.'"<<endl;
                usleep(3*microsecond);
                cout<<"'We are not strong enough to go against them. Will you help us? We will pay you a 50 credit reward.'(y/n)"<<endl;

                char helpChoice;
                cin >> helpChoice;

                if (helpChoice == 'y') {
                    // stuff for each region here
                    cout<<"'Thank you so much! The Tuskens or Tusken we think took our governors are out in the Dune Sea. Good luck Mandalorian!'"<<endl;
                    usleep(2*microsecond);
                    cout<<"You set out to search for the governors."<<endl;

                    // allow player to explore the region and if so, interact w the npc
                    bool interact = exploreRegion(region2, myMando);

                    // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                    if (interact) {
                        cout<<"You have found the governors."<<endl;
                        cout<<"Standing over the governors is the biggest Tusken Raider you have ever seen."<<endl;
                        usleep(3*microsecond);
                        cout<<"The Tusken pulls out a tribal Gaderffii stick and charges at you. Hoping to successfully free the hostages, you prepare to fight."<<endl;
                        
                        // fight sequence, use for most fights but alter slightly if needed
                        Weapon mandoWeap = chooseWeapon(myMando);
                        int fightRV = myMando.fightNPC(dude, mandoWeap);
                        if (fightRV == -3) {
                            ultraBreak = true;
                            break;
                        } else if (fightRV == 1) {
                            cout<<"You successfully defeated the "<<dude.getName()<<" and bring the governors back to the town."<<endl;
                            usleep(3*microsecond);
                        }
                        // spawn NPC here and complete challenge *gulp*
                    }

                } else {
                    cout<<"'We understand, goodluck with your travels Mandalorian.' says Soti Mel"<<endl;
                    usleep(1*microsecond);
                }

                if (!ultraBreak) { 
                    cout<<"As you return, the towns people greet you."<<endl;
                    usleep(2*microsecond);
                    cout<<"'Thank you so much for rescuing our town leaders. Here are your 50 credits.' says Soti Mel"<<endl;
                    myMando.setCredits(myMando.getCredits()+50);
                    usleep(2*microsecond);
                    cout<<"Without saying much more, you return to your ship and continue on your journey."<<endl;
                    usleep(2*microsecond);
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
                    if (vec[i].getPlanetRegion() == " region 3") {
                        dude = vec[i];
                        break;
                    }
                }

                // Outline:
                // cout<<""<<endl;
                // usleep(2*microsecond);

                cout<<"You have landed near the desert town Mos Pelgo."<<endl;
                usleep(2*microsecond);
                cout<<"Explore the region to find townspeople."<<endl;
                usleep(2*microsecond);

                // stuff for each region here

                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region3, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"'Hello Mandalorian. My name is Darro Anen, but you can call me Darro.'"<<endl;
                    usleep(3*microsecond);
                    cout<<"'I heard that you're looking for information about Moff Gideon and Jedis.'"<<endl;
                    usleep(4*microsecond);
                    cout<<"'Shocked? News travels fast 'round these parts... Especially when someone like you arrives...'"<<endl;
                    usleep(3*microsecond);

                    cout<<"Nervous, but desperate for information you ask what Darron can give you."<<endl;
                    usleep(4*microsecond);
                    cout<<"'Listen, I can help you but you're going to have to answer some of my questions first.' says Darro"<<endl;
                    cout<<"'I need to know that you aren't some Imperial bantha fodder'"<<endl;
                    usleep(3*microsecond);
                    cout<<"Do you accept this challenge?(y/n)"<<endl;
                    char chalChoice;
                    cin >> chalChoice;
                    if (chalChoice == 'y') {
                        char quest1;
                        char quest2;
                        char quest3;
                        cout<<"Question 1: Where are the Tusken Raiders located? \na.) Dune Sea \nb.) Coruscant \nc.) Mos Eisley \nd.) Jabba Palace"<<endl;
                        usleep(1*microsecond);
                        cout<<"Give the answer..."<<endl;
                        cin >> quest1;
                        if (quest1 != 'a') {
                            cout<<"Imperial scum, leave this planet at once!"<<endl;
                            break;
                        }

                        cout<<"Question 2: What do farms on Tattoine harvest? \na.) corn \nb.) wheat \nc.) moisture \nd.) rocks"<<endl;
                        usleep(1*microsecond);
                        cout<<"Give the answer..."<<endl;
                        cin >> quest2;
                        if (quest2 != 'c') {
                            cout<<"Imperial scum, leave this planet at once!"<<endl;
                            break;
                        }

                        cout<<"Question 3: Who is the leader of the Hutts right now? \na.) Greedo \nb.) Jabba \nc.) Lando \nd.) Jar Jar Binks"<<endl;
                        usleep(1*microsecond);
                        cout<<"Give the answer..."<<endl;
                        cin >> quest3;
                        if (quest3 != 'b') {
                            cout<<"Imperial scum, leave this planet at once!"<<endl;
                            break;
                        }

                        cout<<"'Alright, I can tell you are no imperial.'"<<endl;
                        usleep(1*microsecond);
                        cout<<"'I don't have any information about Moff Gideon, but I have information about that squishy green thing next to you.'"<<endl;
                        usleep(3*microsecond);
                        cout<<"'I've heard that he is able to control things with his mind. I have a farmer friend who lives on the planet Tython.'"<<endl;
                        usleep(3*microsecond);
                        cout<<"'He has told me of some broken down Jedi temples. His stories of the Jedi align with the powers that your friend has.'"<<endl;
                        usleep(3*microsecond);
                        cout<<"'I would go to Tython to find out more. If you see my friend, Shoan Madar, tell him Darron says hello.'"<<endl;
                        usleep(3*microsecond);
                        cout<<"'That's all I have. Good luck.'"<<endl;
                        usleep(5*microsecond);

                        cout<<"Excited, you rush back to your ship, thinking to either finish exploring Tatooine, or to travel to Tython."<<endl;
                        usleep(2*microsecond);
                    } else {
                        cout<<"You wisely choose to leave the area"<<endl;
                    }
                    // spawn NPC here and complete challenge *gulp*
                } else {
                    cout<<"You wisely choose to leave the area"<<endl;
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
                    if (vec[i].getPlanetRegion() == " region 4") {
                        dude = vec[i];
                        break;
                    }
                }

                cout<<"You have landed near the Jabba's Palace and have been invited to visit Jabba the Hutt."<<endl;
                usleep(2*microsecond);
                cout<<"You enter the Palace to see the powerful, giant Hutt sitting on his throne."<<endl;
                usleep(2*microsecond);
                cout<<"'Greetings Mandalorian. I have been looking forward to meeting you'"<<endl;
                usleep(3*microsecond);
                cout<<"'I have a quest that I believe can help both of us.'"<<endl;
                usleep(3*microsecond);
                cout<<"'I will let you choose a weapon from my arsenal and pay you a hefty credit reward.'"<<endl;
                usleep(3*microsecond);
                cout<<"'I need you to capture this traitor. His name is Kuna Randlo and he has been turning my people against me.'"<<endl;
                usleep(2*microsecond);

                cout<<"'Do you accept?'(y/n)"<<endl;
                char questChoice;
                cin >> questChoice;

                if (questChoice == 'y') {
                    // stuff for each region here

                    // allow player to explore the region and if so, interact w the npc
                    bool interact = exploreRegion(region4, myMando);

                    // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                    if (interact) {
                        // fight sequence, use for most fights but alter slightly if needed
                        Weapon mandoWeap = chooseWeapon(myMando);
                        int fightRV = myMando.fightNPC(dude, mandoWeap);
                        if (fightRV == -3) {
                            ultraBreak = true;
                            break;
                        } else if (fightRV == 1) {
                            cout<<"You return to Jabba's Palace with Kona Randlo to claim your reward."<<endl;
                            usleep(4*microsecond);
                        }
                    } else {
                        cout<<"You wisely choose to leave the area"<<endl;
                    }
                } else {
                    cout<<"You wisely choose to leave the area"<<endl;
                }

                if (!ultraBreak) { 
                    Weapon flameThrower = Weapon("Flamethrower", "Flamethrower", 5, 4);
                    cout<<"Jabba is excited to see you back so soon and gives you a 45 credit reward."<<endl<<endl;
                    myMando.setCredits(myMando.getCredits() + 45);
                    usleep(3*microsecond);
                    int choice;
                    cout<<"'Feel free to choose a weapon from my arsenal.' says Jabba."<<endl<<"#1:"<<endl;
                    flameThrower.printWeapon();
                    cout<<"#2"<<endl;
                    cout<<"The Jetpack gives the Mandalorian more agility and improves your skill level."<<endl;
                    while(true) {
                        cout<<"Choose a weapon by inputting the number or 0 to choose none."<<endl;
                        cin >> choice;
                        if (choice == 1) {
                            myMando.addWeapon(flameThrower);
                            cout<<"The flamethrower was successfully added to your arsenal! Check your weapons in the stat menu!"<<endl;
                            break;
                        } else if (choice == 2) {
                            myMando.setSkillLevel(myMando.getSkillLevel() + 2);
                            cout<<"You have attained the jetpack successfully and your skill has been increased by 2."<<endl;
                            break;
                        } else if (choice == 0) {
                            break;
                        } else {
                            cout<<"Not a valid choice"<<endl;
                        }
                    }
                    cout<<"Jabba thanks you again and you depart."<<endl;
                    usleep(3*microsecond);
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

    string description = "\nRegion: Deep Core \nSector: Unknown \nClass: Terrestrial \nAtmosphere: Breathable \nAffiliation: Jedi Order \nSpecies: Human";
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
        if (myMando.getAlive() == false) {
            return myMando;
        }
        bool ultraBreak = false;
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
                cout<<"You have landed in a grassy clearing."<<endl;
                usleep(1*microsecond);
                cout<<"You can explore the map to find Shaon Madar."<<endl;
                usleep(3*microsecond);
                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region1, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"You have found "<< dude.getName()<< " and he begins talking to you." <<endl;
                    cout<<" 'Hello. My name is Shoan Madar. You must be a Mandalorian; I can tell from your shiny armor.'" <<endl;
                    usleep(2*microsecond);
                    cout<<" 'What are you doing on Tython?' \n Darro Anen sent you? It's been a while since I've seen him. I'm glad to know he's doing well' " <<endl;
                    usleep(2*microsecond);
                    cout<<" 'Well, he's right about one thing. I have information about the Jedi Order, but I need your help first.' " <<endl;
                    usleep(4*microsecond);
                    cout<< " 'A storm blew over the fence for my livestock. Will you help me repair it?' " <<endl;
                    usleep(4*microsecond);
                    cout<< "Do you accept his request? It will cost you 20 credits for manual labor." << endl;
                    cout<< "Enter your choice (y/n)" <<endl;

                    char questChoice;
                    cin >> questChoice;
                    if (questChoice == 'y') {
                        myMando.setCredits(myMando.getCredits() - 20);
                        //image of fence
                        cout<<"=|===|===|(=)|===|==="<<endl;
                        usleep(1*microsecond);
                        cout<<"=|===|===|`='|===|==="<<endl;
                        usleep(1*microsecond);
                        cout<<"You have repaired the fence."<<endl;
                        cout<<"You now have " << myMando.getCredits()<< " credits." <<endl;
                        usleep(2*microsecond);
                        cout<< " Shoan thanks you and says, 'Thank you for helping me. It would have taken me days to fix it by myself.'" <<endl;
                        cout<< "'Now for the information you are looking for'" << endl;
                        usleep(4*microsecond);
                        cout<< "'Tython used to be home to the Jedi Order. The Jedi were an order of warrior monks who kept peace in the universe.'" << endl;
                        cout<< "'They were so reverant that they were able to connect the life force of the universe and use it to gain extrodinary powers and strength.'" << endl;
                        usleep(4*microsecond);
                        cout<< "'One of the temples on Tython was used for training Jedi padawons. If you go to Region 3, you will find this temple.'" << endl;
                        cout<< "'If you bring your youngling there, he may strengthen his powers.'" << endl;
                        usleep(4*microsecond);
                        cout<< "'If you want to learn more about your Mandalorian friends. I would suggest going to region 1 of the planet Trask.\n The last visitor I met mentioned a gang of Mandalorians stirring up trouble there.'" << endl;
                        usleep(2*microsecond);
                        cout<< "'That is all I have. Good luck.'" << endl;
                        usleep(2*microsecond);

                    }
                    else
                    {
                        cout<< "You have declined the task and have chosen to leave the area."<<endl;
                    }

                    //cout<<"'"
                    // spawn NPC here and complete challenge *gulp*
                }

                // Before the code breaks the player has some time to read what happened
                usleep(2*microsecond);
                break;
            }
            case '2': {
            
                // For polish: rename regions etc.


                // stuff for each region here

                // Spawns a random NPC
                //cout<<xCoord<<" "<<yCoord<<endl; - testing for randomness

                region2.spawnNPC(xCoord, yCoord);
                region2.setNPC(true);

                // create NPC object for interaction based on NPC vector
                NPC dude = NPC();
                for (int i = 0; i < vec.size(); i++) {
                    if (vec[i].getPlanetRegion() == " region 2") {
                        dude = vec[i];
                        break;
                    }
                }
                cout<<"You have landed at the edge of a forest."<<endl;
                usleep(2*microsecond);
                cout<<"You do not see anyone. Explore the region"<<endl;
                usleep(2*microsecond);

                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region2, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"You have been ambushed by a group of scavengers."<<endl;
                    cout<<"They won't let you pass through the region unless you defeat the leader."<<endl;
                    usleep(2*microsecond);
                    cout<<"The leader rushes at you with a sharp machete."<<endl;
                    usleep(2*microsecond);
                    // spawn NPC here and complete challenge *gulp*
                    // fight sequence, use for most fights but alter slightly if needed
                    Weapon mandoWeap = chooseWeapon(myMando);
                    int fightRV = myMando.fightNPC(dude, mandoWeap);
                    if (fightRV == -3) {
                        ultraBreak = true;
                        break;
                    } else if (fightRV == 1) {
                        cout<<"You successfully defeated the "<<dude.getName()<<endl;
                        usleep(2*microsecond);
                        cout<<"You have gained a new weapon called whistling birds"<<endl;
                        Weapon whistlingBirds = Weapon("Whistling Birds", "short-range", 5, 6);
                        whistlingBirds.printWeapon();
                        myMando.addWeapon(whistlingBirds);
                        usleep(3*microsecond);
                        cout<<"The whistling birds weapon was successfully added to your arsenal! Check your weapons in the stat menu!"<<endl;
                        usleep(2*microsecond);
                        break;
                    }
                }
                // Before the code breaks the player has some time to read what happened
                cout<<"The scanvengers allow you to pass through the rest of this area." << endl;
                usleep(2*microsecond);
                break;
            }
            case '3': {

                // Spawns a random NPC
                //cout<<xCoord<<" "<<yCoord<<endl; - testing for randomness

                region3.spawnNPC(xCoord, yCoord);
                region3.setNPC(true);

                // create NPC object for interaction based on NPC vector
                NPC dude = NPC();
                for (int i = 0; i < vec.size(); i++) {
                    if (vec[i].getPlanetRegion() == " region 3") {
                        dude = vec[i];
                        break;
                    }
                }
                cout<<"You have landed at the base of the mountain.\nExplore the region"<<endl;
                usleep(2*microsecond);

                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region3, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"*PEWWW PEW PEW*"<<endl;
                    cout<<"You quickly dodge the plasma hurling towards you and see a Stormtrooper trying to attack you."<<endl;
                    usleep(3*microsecond);
                    Weapon mandoWeap = chooseWeapon(myMando);
                    int fightRV = myMando.fightNPC(dude, mandoWeap);
                    if (fightRV == -3) {
                        ultraBreak = true;
                        break;
                    } else if (fightRV == 1) {
                        int choice;
                        Weapon flameThrower = Weapon("Flamethrower", "Flamethrower", 5, 4);
                        cout<<"You successfully defeated the "<<dude.getName() <<"."<<endl;
                        cout<<"You can add a weapon to add to your arsenal. You have two choices. Pick the weapon you are lacking."<<endl;
                        cout<<"#1"<<endl;
                        flameThrower.printWeapon();
                        cout<<"#2"<<endl;
                        cout<<"The Jetpack gives the Mandalorian more agility and improves your skill level."<<endl;
                        while(true) {
                        cout<<"Choose a weapon by inputting the number or 0 to choose none."<<endl;
                        cin >> choice;
                        if (choice == 1) {
                            myMando.addWeapon(flameThrower);
                            cout<<"The flamethrower was successfully added to your arsenal! Check your weapons in the stat menu!"<<endl;
                            break;
                        } else if (choice == 2) {
                            myMando.setSkillLevel(myMando.getSkillLevel() + 2);
                            cout<<"You have attained the jetpack successfully and your skill has been increased by 2."<<endl;
                            break;
                        } else if (choice == 0) {
                            break;
                        } else {
                            cout<<"Not a valid choice"<<endl;
                        }
                        cout<<"You pick up Grogu and continue on to the Jedi temple in Region 4" << endl;
                        usleep(3*microsecond);
                        }
                    }
                }
                // Before the code breaks the player has some time to read what happened
                usleep(2*microsecond);
                break;
            }
            case '4': {

                // Spawns a random NPC
                //cout<<xCoord<<" "<<yCoord<<endl; - testing for randomness

                region4.spawnNPC(xCoord, yCoord);
                region4.setNPC(true);

                // create NPC object for interaction based on NPC vector
                NPC dude = NPC();
                for (int i = 0; i < vec.size(); i++) {
                    if (vec[i].getPlanetRegion() == " region 4") {
                        dude = vec[i];
                        break;
                    }
                }

                // // allow player to explore the region and if so, interact w the npc
                // bool interact = exploreRegion(region4, myMando);
                // cout<<"You have discovered the old Jedi temple."<<endl;
                // usleep(2*microsecond);
                // cout<<"Explore the temple."<<endl;
                // usleep(2*microsecond);
                // // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (true) {
                    cout<<"You have discovered a writing on a wall that says:"<<endl;
                    usleep(2*microsecond);
                    cout<<"'If you want to train in the Jedi way,'"<<endl;
                    cout<<"'You have to do what I say,'\n'Answer four questions you must,'"<<endl;
                    cout<<"'In order to gain the temple's trust,'\n'There will be no gain,'"<<endl;
                    cout<<"'if you answer in vain.'" <<endl;
                    usleep(4*microsecond);
                    cout<<"Would you like to begin Grogu's training(y/n)?"<<endl;
                    char chalChoice;
                    cin>>chalChoice;
                    if (chalChoice == 'y') {
                        char quest1;
                        char quest2;
                        char quest3;
                        char quest4;
                        cout<<"Question 1: Which Jedi had a purple lightsaber? \na.) Yoda \nb.) Ahsoka Tano \nc.) Mace Windu \nd.) Obi-Wan Kenobi"<<endl;
                        usleep(1*microsecond);
                        cout<<"Give the answer..."<<endl;
                        cin >> quest1;
                        if (quest1 != 'c') {
                            cout<<"Traitor, leave this planet at once! \nThe temple will not strengthen your youngling."<<endl;
                            break;
                        }

                        cout<<"Question 2: Who were the Jedi's sworn enemies? \na.) The Sith \nb.) The Wookies \nc.) The Mandalorians \nd.) The Gungans"<<endl;
                        usleep(1*microsecond);
                        cout<<"Give the answer..."<<endl;
                        cin >> quest2;
                        if (quest2 != 'a') {
                            cout<<"Traitor, leave this planet at once! \nThe temple will not strengthen your youngling."<<endl;
                            break;
                        }

                        cout<<"Question 3: Which Jedi has a weird way of speaking? \na.) Anakin Skywalker \nb.) Yoda \nc.) Obi-Wan Kenobi \nd.) Qui-Gon Jin"<<endl;
                        usleep(1*microsecond);
                        cout<<"Give the answer..."<<endl;
                        cin >> quest3;
                        if (quest3 != 'b') {
                            cout<<"Traitor, leave this planet at once! \nThe temple will not strengthen your youngling."<<endl;
                            break;
                        }
                        cout<<"Question 4: Who is Luke Skywalker's Father? \na.) Qui-Gon Jin \nb.) Mace Windu \nc.) Emperor Palpatine \nd.) Darth Vadar"<<endl;
                        usleep(1*microsecond);
                        cout<<"Give the answer..."<<endl;
                        cin >> quest4;
                        if (quest4 != 'd') {
                            cout<<"Traitor, leave this planet at once! \nThe temple will not strengthen your youngling."<<endl;
                            break;
                        }
                        cout<<"You watch in wonder as a beam of light surrounds Grogu"<<endl;
                        cout<<"~*~~* <´(• ﻌ •)`> *~~*~" <<endl;
                        cout<<""<<endl;
                        cout<<""<<endl;
                        myMando.setBabyYoda(5);
                        cout<<"Grogu's powers have increased x2 and he now has a higher chance of saving you."<<endl;
                        usleep(1*microsecond);
                        cout<<"You leave the temple and return to your ship"<<endl;
                    }
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
            default: {
                cout<<"Not a valid option!"<<endl;
                usleep(2*microsecond);
                break;
            }
        }
    }
    
    return myMando;
}

Mando trask(Mando myMando, vector<NPC> vec) {
    // Arriving at planet
    unsigned int microsecond = 1000000;
    Planet trask = Planet("Trask", "Terrestrial", 40);

    // Sources for description should be wookiepedia and in the below order

    string description = "\nRegion: Outer Rim Territories \nSector: Arkanis \nClass: Ocean \nAtmosphere: Breathable \nAffiliation: Unknown \nSpecies: Human, Mon Calamari, Quarren, Unidentified Anthropoid";
    if(trask.planetTravel(myMando, description)) {
        cout<<"Welcome to Trask!"<<endl;
        cout<<"You currently have "<<myMando.getCredits()<<" credits remaining."<<endl;
        usleep(3*microsecond);
    } else {
        cout<<"You may not have enough credits for this planet!"<<endl;
        usleep(3*microsecond);
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
        if (myMando.getAlive() == false) {
            return myMando;
        }
        bool ultraBreak = false;
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
                cout<<"Welcome to Region 1!"<<endl;
                usleep(3*microsecond);
                cout<<"You have landed on a dock next to a vast ocean."<<endl;
                usleep(3*microsecond);
                cout<<"You can explore the map to find townspeople or Mandalorians."<<endl;
                usleep(3*microsecond);


                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region1, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"You have found "<< dude.getName()<< " and he begins talking to you." <<endl;
                    cout<<"Mitikk: 'Hello, Mandalorian. What do you want?\nWe don't need anymore of your kind stirring up trouble around here y'know.'"<<endl;
                    usleep(4*microsecond);
                    cout<<"Where are the other Mandalorian? They've been sighted in Region 2.'\n'Follow me.'"<<endl;
                    usleep(4*microsecond);
                    cout<<"Follow Mitikk to Region 2 by choosing Region 2 for the next question."<<endl;
            
                    // spawn NPC here and complete challenge *gulp*
                }

                // Before the code breaks the player has some time to read what happened
                usleep(2*microsecond);
                break;
            }
            case '2': {
                

                // stuff for each region here

                // Spawns a random NPC
                //cout<<xCoord<<" "<<yCoord<<endl; - testing for randomness

                region2.spawnNPC(xCoord, yCoord);
                region2.setNPC(true);

                // create NPC object for interaction based on NPC vector
                NPC dude = NPC();
                for (int i = 0; i < vec.size(); i++) {
                    if (vec[i].getPlanetRegion() == " region 2") {
                        dude = vec[i];
                        break;
                    }
                }
                cout<<"You have lost Mitikk somehow."<<endl;
                usleep(3*microsecond);
                cout<<"Explore the region to find him or the other Mandalorian."<<endl;
                usleep(3*microsecond);
                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region2, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"It's a trap! You've been ambushed by a quarren sent by Mitikk."<<endl;
                    cout<<"You have to fight!"<<endl;
                    usleep(3*microsecond);
                    Weapon mandoWeap = chooseWeapon(myMando);
                    int fightRV = myMando.fightNPC(dude, mandoWeap);
                    if (fightRV == -3) {
                        ultraBreak = true;
                        break;
                    } else if (fightRV == 1) {
                        cout<<"You successfully defeated the "<<dude.getName()<<endl;
                        usleep(3*microsecond);
                        cout<<"You find a speeder to take you to another region"<<endl;
                        break;
                    }
                    // spawn NPC here and complete challenge *gulp*
                }
                // Before the code breaks the player has some time to read what happened
                usleep(2*microsecond);
                break;
            }
            case '3': {
                // stuff for each region here

                // Spawns a random NPC
                //cout<<xCoord<<" "<<yCoord<<endl; - testing for randomness

                region3.spawnNPC(xCoord, yCoord);
                region3.setNPC(true);

                // create NPC object for interaction based on NPC vector
                NPC dude = NPC();
                for (int i = 0; i < vec.size(); i++) {
                    if (vec[i].getPlanetRegion() == " region 3") {
                        dude = vec[i];
                        break;
                    }
                }
                

                // allow player to explore the region and if so, interact w the npc
                cout<<"You have been dropped off at the scene of an intense fight."<<endl;
                usleep(4*microsecond);
                cout<<"You see Mandalorian fighting against a motley street gang."<<endl;
                usleep(4*microsecond);
                cout<<"A figure shouts to you."<<endl;
                cout<<"'Hey, Mandalorian! Come give your brothers some help. My name is Bo-Katan Kyrze.'"<<endl;
                usleep(4*microsecond);
                cout<<"'If you help my team, I can tell you where Moff Gideon is.'"<<endl;
                cout<<"'Help us defeat this dangerous gang. Go after the leader over there!"<<endl;
                usleep(4*microsecond);
                cout<<"Explore the region to find the leader, Wuglugh."<<endl;
                usleep(4*microsecond);
                bool interact = exploreRegion(region3, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"You spot Wuglugh and begin shooting at him from behind a barrel."<<endl;
                    usleep(2*microsecond);
                    Weapon mandoWeap = chooseWeapon(myMando);
                    int fightRV = myMando.fightNPC(dude, mandoWeap);
                    if (fightRV == -3) {
                        ultraBreak = true;
                        break;
                    } else if (fightRV == 1) {
                        cout<<"You successfully defeated the "<<dude.getName()<<endl;
                        usleep(4*microsecond);
                        cout<<"Bo-Katan approaches you and says, 'Thanks for your help.'"<<endl;
                        cout<<"'Moff Gideon is currently hiding out on Navarro and is trying to destroy the Mandalorian clan there.'"<<endl;
                        usleep(4*microsecond);
                        cout<<"'He currently possesses the Dark Saber.'"<<endl;
                        cout<<"'You know the rules, if you want to be able to wield the Dark Saber, you must defeat him in battle.'"<<endl;
                        usleep(4*microsecond);
                        cout<<"'That not be an easy task.'"<<endl;
                        cout<<"'You don't seem to have all of your weapons. I would go to the blacksmith, Pana Shulo, in Region 4.'"<<endl;
                        usleep(4*microsecond);
                        cout<<"'She will make you what you need.'"<<endl;
                        break;
                    }


                    // spawn NPC here and complete challenge *gulp*
                }
                // Before the code breaks the player has some time to read what happened
                usleep(2*microsecond);
                break;
            }
            case '4': {

                // stuff for each region here

                // Spawns a random NPC
                //cout<<xCoord<<" "<<yCoord<<endl; - testing for randomness

                region4.spawnNPC(xCoord, yCoord);
                region4.setNPC(true);

                // create NPC object for interaction based on NPC vector
                NPC dude = NPC();
                for (int i = 0; i < vec.size(); i++) {
                    if (vec[i].getPlanetRegion() == " region 4") {
                        dude = vec[i];
                        break;
                    }
                }
                cout<<"Explore the region to find the blacksmith."<<endl;
                usleep(2*microsecond);
                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region4, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    char choice1;
                    cout<<"You have found the blacksmith, Pana Shulo."<<endl;
                    cout<<"'Pana Shulo: Hello Mandalorian. Bo-Katan told me you would pay me a visit.'"<<endl;
                    usleep(4*microsecond);
                    cout<<"'I can help you. I have enough money to craft you a Beskar spear, but it will cost you a lot.'"<<endl;
                    cout<<"'It will cost you 50 credits.'"<<endl;
                    usleep(4*microsecond);
                    cout<<"Do you pay the 50 credits? You currently have "<< myMando.getCredits()<<" credits."<<endl;
                    cout<<"Enter your choice (y/n):"<<endl;
                    cin >>choice1;
                    if(choice1 == 'y')
                    {
                        if ((myMando.getCredits()-50) >= 0){
                            myMando.setCredits(myMando.getCredits()-50);
                            cout<<"You have paid Pana Shulo. You now have "<<myMando.getCredits() <<endl;
                            cout<<"You wait as she makes your spear"<<endl;
                            cout<<""<<endl;
                            cout<<""<<endl;
                            cout<<"===============>>>>>" <<endl;
                            usleep(3*microsecond);
                            cout<<"Pana Shulo: 'Your weapon is complete. Thank you for your business'"<<endl;
                            Weapon spear = Weapon("Beskar spear", "short-range", 7, 8);
                            myMando.addWeapon(spear);
                            cout<<"The Beskar spear was successfully added to your arsenal! Check your weapons in the stat menu!"<<endl;
                            break;
                        }
                        else
                        {
                            cout<<"You do not have enough credits to pay for the spear."<<endl;
                            break;
                        }
                    }
                    else if (choice1 == 'n')
                    {
                        cout<<"You have declined her service."<<endl;
                        break;
                    }
                    else
                    {
                        cout<<"Invalid choice."<<endl;
                    }
                    usleep(3*microsecond);
                    
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

    string description = "\nRegion: Outer Rim Territories \nSector: Nevarro's sector \nClass: Terrestrial \nAtmosphere: Breathable \nPower: Galactic Empire \nSpecies: Humans, Jawas, Rodians, Trandoshans, Twi'leks, Zabraks...";
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
        if (myMando.getAlive() == false) {
            return myMando;
        }
        bool ultraBreak = false;
        nevarro.displayPlanetMap("nevarroRegion.txt");
        cout<<"What region would you like to visit?('1', '2', '3', '4' to view stats, or '0' to leave Nevarro)"<<endl;
        cin >> regionChoice;

        // Random npc Coords
        int randIsBrokenBruh = rand();
        int xCoord = (((double)rand() / RAND_MAX) * 10) + 1;
        int yCoord = (((double)rand() / RAND_MAX) * 10) + 1;

        switch(regionChoice) {
            case '0':
                cout<<"Now leaving Nevarro!"<<endl;
                return myMando;
            case '1': {

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

                 // For polish: rename regions etc. if needed

                cout<<"You have landed near the Mandalorian settlement."<<endl;
                usleep(2*microsecond);
                // mando covert not cohert ------------
                cout<<"You explore and find the Mandalorian covert. "<<dude.getName()<<"sees you and approaches"<<endl;
                usleep(2*microsecond);

                cout<<"'Mando! You're back. I'm glad to see your safe.' says "<<dude.getName()<<endl;
                usleep(2*microsecond);
                cout<<"I know why you came back to Navarro. You're searching for Moff Gideon."<<endl;
                usleep(2*microsecond);
                cout<<"That's not going to be an easy task. He is currently hiding out somewhere in the southern part of the planet."<<endl;
                usleep(2*microsecond);
                cout<<"I have heard some rumors coming from region 2 of the planet about his whearabouts, you might want to check there."<<endl;
                usleep(2*microsecond);
                cout<<"In order to defeat him, you will need to use your most powerful weapons. Good luck Mando."<<endl;
                usleep(2*microsecond);

                // Before the code breaks the player has some time to read what happened
                usleep(2*microsecond);
                break;
            }
            case '2': {
                
                // For polish: rename regions etc.

                // stuff for each region here

                // Spawns a random NPC
                //cout<<xCoord<<" "<<yCoord<<endl; - testing for randomness

                region2.spawnNPC(xCoord, yCoord);
                region2.setNPC(true);

                // create NPC object for interaction based on NPC vector
                NPC dude = NPC();
                for (int i = 0; i < vec.size(); i++) {
                    if (vec[i].getPlanetRegion() == " region 2") {
                        dude = vec[i];
                        break;
                    }
                }

                cout<<"You have landed in region 2 but do not see anyone so decide to walk around."<<endl;
                usleep(2*microsecond);

                // allow player to explore the region and if so, interact w the npc
                bool interact = exploreRegion(region2, myMando);

                // if the player chooses to interact w/ NPC they will be taken back to this point and fed cout statements
                if (interact) {
                    cout<<"The stranger appears to be an old clone..."<<endl;
                    usleep(2*microsecond);
                    cout<<"Hey, Tinny. Yeah, you. What are you doing way out here?"<<endl;
                    usleep(2*microsecond);
                    cout<<"You dont respond. 'Ahhh, you're looking for Moff Gideon?'"<<endl;
                    usleep(2*microsecond);
                    cout<<"'That's not going to be an easy battle, but it's important for you to win.'"<<endl;
                    usleep(2*microsecond);
                    cout<<"'With a weapon like the Dark Sabar in Moff Gideon's hand, civilizations will be conquered and entire planets will descend into chaos.'"<<endl;
                    usleep(2*microsecond);
                    cout<<"He is in region 3, south of here."<<endl;
                    usleep(2*microsecond);
                    cout<<"You are now ready to fight Moff Gideon."<<endl;
                    // spawn NPC here and complete challenge *gulp*
                } else {
                    cout<<"You wisely choose to leave the area"<<endl;
                }
                // Before the code breaks the player has some time to read what happened
                usleep(2*microsecond);
                break;
            }
            case '3': {
                // Spawns a random NPC
                //cout<<xCoord<<" "<<yCoord<<endl; - testing for randomness

                region3.spawnNPC(xCoord, yCoord);
                region3.setNPC(true);

                // create NPC object for interaction based on NPC vector
                NPC dude = NPC();
                for (int i = 0; i < vec.size(); i++) {
                    if (vec[i].getPlanetRegion() == " region 3") {
                        dude = vec[i];
                        break;
                    }
                }
                Weapon darkSaber = Weapon("Dark Saber", "Light Saber Variant", 10, 9);
                dude.setWeapon(darkSaber);

                cout<<"You land in region 3 of Nevarro."<<endl;
                usleep(2*microsecond);
                cout<<"You leave your ship, and begin the search for Moff Gideon."<<endl;
                usleep(2*microsecond);
                cout<<"Suddenly, a strange ignition noise sounds and Moff Gideon himself steps in front of you."<<endl;
                usleep(2*microsecond);
                cout<<"'So, you are the Mandalorian. You're work has not gone unnoticed.' says Moff Gideon"<<endl;
                usleep(2*microsecond);
                cout<<"You stare into the Moff's eyes, waiting for his move. Not wanting to waste time with small talk, you refuse to talk."<<endl;
                usleep(2*microsecond);

                // fight sequence, use for most fights but alter slightly if needed
                Weapon mandoWeap = chooseWeapon(myMando);
                int fightRV = myMando.fightNPC(dude, mandoWeap);
                if (fightRV == -3) {
                    ultraBreak = true;
                    cout<<"Moff Gideon has defeated you..."<<endl;
                    break;
                } else if (fightRV == 1) {
                    cout<<"Congratulations!!"<<endl;

                    myMando.setCredits(myMando.getCredits() + dude.getCreditReward());
                    cout<<"For defeating Moff Gideon, you are rewarded "<<dude.getCreditReward()<<" credits."<<endl;
                    usleep(3*microsecond);
                    myMando.addWeapon(darkSaber);
                    cout<<"You also earn the Dark Saber by law as you defeated it previous owner in combat."<<endl;
                    usleep(3*microsecond);
                    cout<<"You have freed the Galaxy and are now free to meet new character or explore the maps."<<endl;
                    usleep(4*microsecond);
                } else {
                    cout<<"Moff Gideon has defeated you..."<<endl;
                }
                
                // Before the code breaks the player has some time to read what happened
                usleep(2*microsecond);
                break;
            }
            case '4': {
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
    myMando.setAlive(true);
    Weapon gun = Weapon("IB-94 blaster pistol", "Gun", 3, 3);
    myMando.addWeapon(gun);

    cout<<"Greetings "<<myMando.getName()<<"! Printing the map of the Galaxy!"<<endl;
    usleep(2*microsecond);
    myMando.displayGalaxyMap();
    usleep(1*microsecond);
    cout<<"There are four planets that Moff Gideon is rumored to be on."<<endl;
    usleep(3*microsecond);
    cout<<"They are Tatooine(145), Tython (346), Trask(457), and Navarro(789)."<<endl;
    usleep(3*microsecond);
    cout<<"Planet travel costs a certain amount of credits. You currently have "<<myMando.getCredits()<<" credits."<<endl;
    usleep(3*microsecond);
    cout<<"Select a planet by typing in it's planet code, check your stats(1), or quit the game(0)."<<endl;

    int planetCode = -1;
    while(true) {
        if(myMando.getAlive() == false) {
            cout<<"You have chosen to face the perils of the galaxy, but have sadly perished."<<endl;
            planetCode = 0;
        } else {
            cin >> planetCode;
        }

        switch (planetCode) {
            case 145: {
                myMando = tatooine(myMando, tatooineNPC);
                usleep(2*microsecond);
                break;
            }
            case 346: {
                myMando = tython(myMando, tythonNPC);
                usleep(2*microsecond);
                break;
            }
            case 457: {
                myMando = trask(myMando, traskNPC);
                usleep(2*microsecond);
                break;
            }
            case 789: {
                myMando = nevarro(myMando, nevarroNPC);
                usleep(2*microsecond);
                break;
            }
            case 0: {
                cout<<"Thank you for playing the 'Star Wars Mandalorian Exploration' game!"<<endl;
                usleep(2*microsecond);
                cout<<"You did a great job!"<<endl;
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
        if(myMando.getAlive() == false) {
            cout<<"You have chosen to face the perils of the galaxy, but have sadly perished."<<endl;
            usleep(2*microsecond);
            cout<<"You were so close! Try again but make sure to explore some easier planets like Tatooine and Tython in order to get better weaponry!"<<endl;
            usleep(4*microsecond);
                
            return;
        }
        cout<<"Welcome back to space!"<<endl;
        cout<<"Loading Galaxy Map..."<<endl;
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

