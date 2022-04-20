#include "NPC.h"
#include "Weapon.h"
//#include "Mando.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

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

vector<NPC> NPC::readNPC(string fileName)
{
    // initialize variables
    ifstream fin(fileName);
    string line = "";
    int split_value = 0;
    const static int SIZE = 9;
    string arr[SIZE];
    vector<NPC> npcs;
    // check if file is open
    if (fin.is_open())
    {
        // read through each line
        while (!fin.eof())
        {
            string temp = "";
            // check if line is valid
            if ((line != "") || (line != "/"))
            {
                // split the line
                split_value = split(line, ',', arr, SIZE);
                // check if the line was split properly
                if (split_value == SIZE)
                {
                    // convert the strings into proper variables
                    // string HP --> int HP
                    string stringHP = arr[4];
                    int intHP = stoi(arr[4]);
                    // string friendly --> bool friendly
                    string stringFriendly = arr[5];
                    bool boolFriendly = false;
                    if (stringFriendly == "true")
                    {
                        boolFriendly = true;
                    }
                    else
                    {
                        boolFriendly = false;
                    }
                    // string damage --> int damage
                    string strDamage = arr[6];
                    int intDamage = stoi(strDamage);
                    // string creditReward --> int credit reward
                    string stringCredit = arr[7];
                    int intCredit = stoi(stringCredit);
                    // string skillLevel --> int skillLevel
                    string stringSkill = arr[8];
                    int intSkill = stoi(stringSkill);
                    // create new NPC
                    Weapon gun = Weapon("gun", "long-range", 2, 3, "tatooine", "region 1" );
                    NPC newNPC = NPC(arr[0], arr[1], arr[2], arr[3], intHP, boolFriendly, intDamage, intCredit, intSkill, gun);
                    npcs.push_back(newNPC);
                }
            }
        }
    }
    fin.close();
    return npcs;

}
int main()
{
    vector <NPC> npcTest = readNPC("NPC.txt");
    for (int i = 0; i < npcTest.size(); i++)
    {
        cout << npcTest[i] << endl;
    }
    return 0;
}