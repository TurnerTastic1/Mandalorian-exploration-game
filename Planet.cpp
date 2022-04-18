// Planet.cpp
// CSCI 1300 Spring 2022
// Author: Caroline Scheidt, Turner Naef
// Recitation: 202 - TA Alexander Ray
// Project 3

#include <iostream>
#include<fstream>

#include "Mando.h"
//#include "Weapon.h"
#include "Planet.h"

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



bool planetTravel(Mando myMando) {
    char choice;
    cout<<"Hello "<<myMando.getName()<<"."<<endl;
    cout<<"You currently have "<<myMando.getCredits()<<" credits. Travel cost will be "<<travelCost<<" credits."<<endl;
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

/*
1. Create stream object
2. Check if variable is open
3. Use a while loop to go through each line of the displayPlanetMap file
4. Check if the line is empty
5. Print each line of the file
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