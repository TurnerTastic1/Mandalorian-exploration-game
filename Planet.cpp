// Planet.cpp
// CSCI 1300 Spring 2022
// Author: Caroline Scheidt, Turner Naef
// Recitation: 202 - TA Alexander Ray
// Project 3

#include <iostream>
#include<fstream>

#include "Mando.h"
#include "Weapon.h"
#include "Planet.h"

#include <cmath>
#include <iomanip>

using namespace std;

// default constructor
Planet::Planet()
{
    name = "";
    type = "";
    region = "";
    travelCost = 0;
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

// getRegion()
string Planet::getRegion()
{
    return region;
}

// getTravelCost
int Planet::getTravelCost()
{
    return travelCost;
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