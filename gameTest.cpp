#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream fin;
    fin.open("RegionMap2.txt");
    string line = "";
    if (fin.is_open() == false) {
        cout<< "Nah"<<endl;
        return 0;
    }
    cout<<"THE MAP"<<endl;
    while (!fin.eof()) {
        getline(fin, line);
        cout<<line<<endl;
    }
    return 0;
}