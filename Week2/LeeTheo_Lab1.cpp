// Theo Lee
// LeeTheo_Lab1.cpp
// 1/19/2023
// Description: Code to store freight data using a structure

#include <iostream>
#include <string>
using namespace std;

struct Cargo {
    string uld;
    string abbr;
    string uldid;
    int air;
    int weight;
    string dest;
};

void getCargoData(Cargo *cPtr);
void printCargoData(const Cargo *cPtr);

int main()
{
    Cargo *cPtr = new Cargo;

    getCargoData(cPtr);
    printCargoData(cPtr);

    delete cPtr;
    cPtr = nullptr;

    return 0;
}

void getCargoData(Cargo *cPtr) {
    cout << "Enter Unit type(Container/Pallet): " << endl;
    cin >> cPtr->uld;
    cout << "Enter Unit abbreviation: " << endl;
    cin >> cPtr->abbr;
    cout << "Enter Unit ID: " << endl;
    cin >> cPtr->uldid;
    cout << "Enter Aircraft: " << endl;
    cin >> cPtr->air;
    cout << "Enter Weight: " << endl;
    cin >> cPtr->weight;
    cout << "Enter Destination: " << endl;
    cin >> cPtr->dest;
    cout << endl;
}

void printCargoData(const Cargo *cPtr) {
    cout << "Unit type " << cPtr->uld << endl;
    cout << "Unit abbreviation " << cPtr->abbr << endl;
    cout << "Unit ID " << cPtr->uldid << endl;
    cout << "Aircraft " << cPtr->air << endl;
    cout << "Weight " << cPtr->weight << " pounds" << endl;
    cout << "Destination " << cPtr->dest << endl;
}

/* == Sample Run:
Enter Unit type(Container/Pallet):  
Container
Enter Unit abbreviation: 
AYF
Enter Unit ID: 
AYF12345IB
Enter Aircraft: 
737
Enter Weight: 
1104
Enter Destination: 
SMF

Unit type Container
Unit abbreviation AYF
Unit ID AYF12345IB
Aircraft 737
Weight 1104 pounds
Destination SMF
===
*/