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
        int planetCode = 000;
        cout<<"Enter your choice(Planet #/code)"<<endl<<"or enter 0 to quit";
        cin >> choice;

        switch (choice) {
            case 145:
                cout<<"Welcome to Tattoine - test"<<endl;
                return;
            case 0:
                cout<<"Quitting the game"<<endl;
                return;
        }
    }
    return;
}

int main(){
    // Testing use of a wait/period/delay between print statements

    startGame();

    //Mando myMando = Mando("guy");
    
    //myMando.displayGalaxyMap();





    // Testing to read from galaxy map(ascii art)

    // ifstream fin;
    // fin.open("RegionMap2.txt");
    // string line = "";
    // if (fin.is_open() == false) {
    //     cout<< "Nah"<<endl;
    //     return 0;
    // }
    // cout<<"THE MAP"<<endl;
    // while (!fin.eof()) {
    //     getline(fin, line);
    //     cout<<line<<endl;
    // }
    return 0;
}