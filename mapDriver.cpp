#include <iostream>
#include <string>
#include "Map.h"

using namespace std;

int main(){
    // Map Driver examples 
    Map map;
    cout << "Initial map: " << endl;
    map.displayMap();
    while(true) {
        cout<< "Make a move: "<<endl;
        char move;
        cin >> move;
        if (move == 'x') {
            
        }
        map.displayMap();
        map.executeMove(move);
    }
    //map.displayMap(); // starting point
    
    map.displayMap();

    return 0;



    // Map Driver examples for Space Exploration game

    /*
    cout << "Default constructor: " << endl;
    cout << "Site #: " << map.getSiteCount() << endl;
    cout << "Is habitable: " << map.isHabitable() << endl;
    cout << "Let's add some sites: " << endl;
    map.spawnSite(2,2,1); 
    map.spawnSite(8,11,2); 
    map.spawnSite(2,7,3);
    map.spawnSite(15,15,1); // should not show on map nor error out, out of bounds
    map.spawnNPC(2,2); // will not do anything since space is occupied
    map.displayMap();
    cout << "Habitability now: " << map.isHabitable() << endl;
    cout << "Spawning an npc: " << endl;
    map.spawnNPC(4,4);
    map.displayMap();
    cout << "Lets add two sites which have 2 bad traits:" << endl;
    map.spawnSite(10,3,6); 
    map.spawnSite(7,2,4);
    cout << "Habitability now: " << map.isHabitable() << endl;
    cout << "Lets move a little" << endl;
    map.executeMove('s'); // go down
    map.executeMove('d'); // go right
    map.displayMap();
    cout << "Adding misfortune to the right of the player, should be hidden" << endl;
    map.spawnMisfortune(1,2,2);
    map.displayMap();
    cout << "On misfortune right now? " << map.isMisfortuneLocaton() << endl;
    cout << "Lets move onto it..." << endl;
    map.executeMove('d'); // go right
    cout << "On misfortune right now? " << map.isMisfortuneLocaton() << endl;
    map.displayMap();
    int playerPosX = map.getPlayerRowPosition();
    int playerPosY = map.getPlayerColPosition();
    map.executeMove('d'); // go right
    map.revealMisfortune(playerPosX, playerPosY);
    map.displayMap();
    cout << "On site right now? " << map.isSiteLocation() << endl;
    cout << "Lets move to a site" << endl;
    map.executeMove('s'); 
    map.executeMove('a'); 
    cout << "On site right now? " << map.isSiteLocation() << endl;
    map.displayMap();
    cout << "... and move right off" << endl;
    map.executeMove('a'); 
    map.displayMap();

    */
    //return 0;
}