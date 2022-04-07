#include <iostream>
#include <fstream>
#include <thread>
#include <chrono>

#include "Mando.h"
#include "Map.h"
#include "NPC.h"
#include "Planet.h"
#include "StormTrooper.h"
#include "Weapon.h"

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
        // cout<<guy.getName()<<endl;
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