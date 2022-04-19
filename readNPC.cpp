#include "NPC.h"
#include <iostream>
#include <vector>

using namespace std;

vector<NPC> NPC::readNPC(string fileName)
{
    // initialize variables
    ifstream fin(filename);
    string line = ""
    int split_value = 0;
    const static int SIZE = 8;
    string arr[SIZE];
    if (fin.is_open())
    {
        while (!fin.eof)
        {
            string temp = "";
            if ((line != "") || (line != "//"))
            {
                split_value = split(line, ',', arr, SIZE);
                if (split_value == SIZE)
                {
                    
                }
            }
        }
    }

}
int main()
{

}