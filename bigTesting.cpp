// FOR TESTING
// LOL, null-shit = bullshit but its "null" lol

#include "Mando.h"
#include "Planet.h"
#include "Weapon.h"
#include "NPC.h"

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

string toLower(string s) {
    for (int i = 0; i < s.length(); i++) {
        if ((int(s[i]) >= 65) && (int(s[i]) <= 90)) {
            s[i] = char(int(s[i]) + 32);
        }
    }
    return s;
}

int split(string inputString, char separator, string arr[], int size) {
    if (inputString == "") {
        return 0;
    }
    int num = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] != "") {
            num++;
        }
    }
    if (num >= size) {
        return -1;
    }
    int count = 0;
    for (int i = 0; i < inputString.length(); i++) {
        if (inputString[i] == separator) {
            count++;
        }
    }
    if (count == 0) {
        arr[0] = inputString;
        return 1;
    } else if (count+1 > size) {
        int i = 0;
        inputString = inputString + string(1, separator);
        while (i < size) {
            string temp = "";
            for (int k = 0; k < inputString.length(); k++) {
                if (inputString[k] == separator) {
                    temp = inputString.substr(0, k);
                    inputString = inputString.substr(k + 1, inputString.length()-(k+1));
                    break;
                }
            }
            arr[i] = temp;
            i++;
        }
        return -1;
    } else {
        int i = 0;
        int count = 0;
        inputString = inputString + string(1, separator);
        while (i < size) {
            string temp = "";
            for (int k = 0; k < inputString.length(); k++) {
                if (inputString[k] == separator) {
                    count++;
                    temp = inputString.substr(0, k);
                    inputString = inputString.substr(k + 1, inputString.length()-(k+1));
                    break;
                }
            }
            arr[i] = temp;
            i++;
        }
        return count;
    }
    return 0;
}

vector<NPC> readNPC(string fileName) {

    vector<NPC> myNPCs;
    string line = "";
    Weapon basic = Weapon();
    bool boo = false;

    ifstream fin;
    fin.open(fileName);
    if (fin.is_open() == false) {
        cout<<"File cannot be opened"<<endl;
        return myNPCs;
    }

    while (true) {
        if (fin.eof()) {
            break;
        }
        boo = false;

        getline(fin, line);
        if (line.empty()) {
            continue;
        }
        
        string arr[8];
        int rvSplit = split(line, ',', arr, 8);

        if (arr[5] == " true") {
            boo = true;
        }

        NPC dude = NPC(arr[0], arr[1], arr[2], arr[3], stoi(arr[4]), boo, stoi(arr[6]), stoi(arr[7]), basic);
        myNPCs.push_back(dude);
    }
    return myNPCs;
}



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
/* 
    Mando myMando = Mando("dude");
    Weapon gun = Weapon("Gun", "Gun", 9, 3);
    Weapon sword = Weapon("Sword", "Sword", 1, 5);
    Weapon apple = Weapon("Apple", "Apple", 6, 10);
    myMando.addWeapon(gun);
    myMando.addWeapon(sword);
    myMando.addWeapon(apple);
    myMando.checkWeapons();

 */


    // tests for NPCs and fighting!
   
    // Weapon dudesWeapon = Weapon("Gun", "Gun", 1, 2);
    // NPC dude = NPC();
    // dudesWeapon.printWeapon();
    // cout<<dude.getName()<<endl;
    // dude.printWeapon();

    vector<NPC> vec = readNPC("NPCtest.txt");

    for (int i = 0; i < vec.size(); i++) {
        cout<<vec[i].getName()<<endl;
        cout<<vec[i].getFriendly()<<endl;
    }

}