
#include <iostream>
#include <fstream>

#include "Mando.h"
//#include "Weapon.h"
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



bool Planet::planetTravel(Mando &myMando, string description) {
    char choice;
    cout<<"Greetings "<<myMando.getName()<<"."<<endl;
    // Brief description about the planet
    cout<<"Planet description: "<<description<<endl;
    cout<<"You currently have "<<myMando.getCredits()<<" credits. To travel to "<<name<<" it will cost "<<travelCost<<" credits."<<endl;

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