#include <iostream>
#include <time.h>

#include "map.h"

using namespace std;



int main() {

    srand(time(NULL));
    int randIsBrokenBruh = rand();
    //cout<<bleh<<endl;
    int xCoord = (((double)rand() / RAND_MAX) * 10) + 1;
    int yCoord = (((double)rand() / RAND_MAX) * 10) + 1;
    //cout<<xCoord<<" "<<yCoord<<endl;

    Map myMap = Map();

    cout<<"NPC"<<endl;
    myMap.spawnNPC(xCoord, yCoord);
    //myMap.setNPC(true);

    myMap.displayMap();

    // char move;
    // while(true) {
    //     myMap.displayMap();
    //     cout<<"Enter a move(w, a, s, d), or 'x' to quit."<<endl;
    //     cin >> move;
    //     if (move == 'x') {
    //         break;
    //     } else if (myMap.isNPCLocation()) {
    //         cout<<"You approach a stranger... Do you want to interact?(y/n)"<<endl;
    //         char choice;
    //         cin >>choice;
    //         if (choice == 'y') {
    //             cout<<"Interact etc..."<<endl;
    //             break;
    //         } else {
    //             myMap.executeMove(move);
    //         }
    //     } else {
    //         myMap.executeMove(move); // if ((move == "w") || (move == "a") || (move == "s") || (move == "d")) (if needed)
    //     } 
    // }
    // cout<<"Leaving the map"<<endl;

}