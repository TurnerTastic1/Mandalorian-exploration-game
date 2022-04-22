#include <iostream>
#include <fstream>

// Discussed in StartGame.cpp
#include<unistd.h>

#include "Mando.h"
#include "Weapon.h"
#include "Planet.h"
#include "map.h"

#include <cmath>
#include <iomanip>

using namespace std;

// default constructor
Planet::Planet()
{
    name = "";
    type = "";
    travelCost = 0;
}

Planet::Planet(string name_, string type_, int travelCost_) {
    name = name_;
    type = type_;
    travelCost = travelCost_;
}

// getName()
string Planet::getName()
{
    return name;
}

// getType()

string Planet::getType()
{
    return type;
}

// getTravelCost
int Planet::getTravelCost()
{
    return travelCost;
}

/*Algorithm: this function checks if Mando can travel to the correct planet
*1. Prints a greeting and the Mando's username
*2. Prints the planet description
*3. Prints the current amount of credits Mando has
*4. Checks if Mando wants to travel to a certain planet
*5. If yes, then the correct amount of credits are deducted as the travel cost.
    * Prints "Making the jump to hyperspace!"
*6 If no, or Mando does not have enough credits to travel, Mando cannot travel to planet
Parameters: &myMando (Mando object), description (string)
Returns: true if Mando travels to planet, returns false if Mando cannot travel to the planet
**/



bool Planet::planetTravel(Mando &myMando, string description) {
    unsigned int microsecond = 1000000;
    char choice;
    cout<<"Greetings "<<myMando.getName()<<"."<<endl;
    // Brief description about the planet
    cout<<"Planet description: "<<description<<endl<<endl;
    usleep(2*microsecond);
    cout<<"You currently have "<<myMando.getCredits()<<" credits. To travel to "<<name<<" it will cost "<<travelCost<<" credits."<<endl;
    usleep(2*microsecond);
    cout<<"Do you wish to travel to "<<name<<"? (y/n)"<<endl;
    cin >> choice;
    if ((choice == 'y') && (myMando.getCredits() >= travelCost)) {
        myMando.setCredits(myMando.getCredits() - travelCost);
        cout<<"Making the jump to hyperspace!"<<endl;
        return true;
    } else {
        return false;
    }
}

// displayPlanetMap

/*Algorithm: this function displays the planet map
*1. Creates an ifstream variable
*2. Opens the given file
*3. Creates a temporary line variable.
*4  Checks if the file is open. 
    *if it isn't, print that the map is not available
    *if it is, print each line of the file
Parameters: fileName (string)
Returns: void function
*/

void Planet::displayPlanetMap(string filename)
{
    ifstream fin;
    fin.open(filename);
    string line = "";
    if (fin.is_open() == false) {
        cout<< "Galaxy Map is not available!"<<endl;
        return;
    }
    // Printing the Galaxy map
    while (!fin.eof()) {
        getline(fin, line);
        cout<<line<<endl;
    }

}