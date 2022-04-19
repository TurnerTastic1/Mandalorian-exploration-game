#include "Mando.h"
#include "Planet.h"

#include <iostream>

using namespace std;

int main() {
    Mando myMando = Mando("Dude");
    cout<<myMando.getName()<<endl;

    Planet p1 = Planet("P1", "Desert", 50);

    cout<<p1.getTravelCost()<<endl;

    cout<<p1.planetTravel(myMando)<<endl;

}