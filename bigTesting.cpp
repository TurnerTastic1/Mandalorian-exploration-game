// FOR TESTING
// LOL, null-shit = bullshit but its "null" lol

#include "Mando.h"
#include "Planet.h"
#include "Weapon.h"
#include "NPC.h"

#include <iostream>
#include <vector>

using namespace std;

vector<int> sortLol(vector<int> nums) {
    int temp = 0;
    for (int i = 0; i < nums.size() - 1; i++) {
        for (int j = 0; j < nums.size() - i - 1; j++) {
            if (nums[j] < nums[j + 1]) {
                temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
            }
        }
    }
    return nums;
}

int main() {
    // tests for above basic sorting function ************

    // vector<int> vec;
    // vec.push_back(1);
    // vec.push_back(2);
    // vec.push_back(3);
    // vec.push_back(4);

    // vec = sortLol(vec);

    // for (int i = 0; i< vec.size(); i++) {
    //     cout<<vec[i]<<endl;
    // }



    // tests for mando and weapon sorting *************
    // NO NEED TO CALL SORT WEAPONS! Sort weapons is called whenever a weapon is added to improve code speed/clarity

    // Mando myMando = Mando("dude");
    // Weapon gun = Weapon("Gun", "Gun", 2, 3);
    // Weapon sword = Weapon("Sword", "Sword", 6, 5);
    // Weapon apple = Weapon("Apple", "Apple", 9, 10);
    // myMando.addWeapon(gun);
    // myMando.addWeapon(sword);
    // myMando.addWeapon(apple);
    // myMando.checkWeapons();




    // tests for NPCs and fighting!
    Weapon dudesWeapon = Weapon("Gun", "Gun", 1, 2);
    NPC dude = NPC();
    dudesWeapon.printWeapon();
    cout<<dude.getName()<<endl;
    dude.getWeapon();
}