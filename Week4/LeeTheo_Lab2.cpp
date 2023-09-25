// Theo Lee
// LeeTheo_Lab2.cpp
// 2/03/2023
// Description: Code to store freight data using a class

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Cargo {
    public:
        Cargo();
        Cargo(const string uldtype, 
              const string abbrev, 
              const string uldid, 
              const int aircraft, 
              const int weight, 
              const string destination);
        ~Cargo();
        void setuldtype(string uldtype);
        void setabbrev(string abbrev);
        void setuldid(string uldid);
        void setaircraft(int aircraft);
        void setweight(int weight);
        void setdestination(string destination);
        string getuldtype() const;
        string getabbrev() const;
        string getuldid() const;
        int getaircraft() const;
        int getweight() const;
        string getdestination() const;
        void input(Cargo &);
        void output(Cargo &);
    
    private:
        string type;
        string abbr;
        string id;
        int air;
        int wt;
        string dest;
};

int main()
{
    Cargo *cPtr = new Cargo;
    Cargo *xPtr = new Cargo;
    (*cPtr).input(*cPtr);
    cPtr->output(*cPtr);
    cout << "default constructor output\n";
    xPtr->output(*xPtr);
    delete cPtr;

    return 0;
}

Cargo::Cargo() {
    type = "none";
    abbr = "none";
    id = "none";
    air = 700;
    wt = 0;
    dest = "unknown";
}
Cargo::Cargo(const string uldtype, const string abbrev, const string uldid, const int aircraft, const int weight, const string destination) {
    type = uldtype;
    abbr = abbrev;
    id = uldid;
    air = aircraft;
    wt = weight;
    dest = destination;
}
Cargo::~Cargo() {
    cout << "Cargo destructor called" << endl;
}
void Cargo::setuldtype(string uldtype) {
    type = uldtype;
}
void Cargo::setabbrev(string abbrev) {
    abbr = abbrev;
}
void Cargo::setuldid(string uldid) {
    id = uldid;
}
void Cargo::setaircraft(int aircraft) {
    air = aircraft;
}
void Cargo::setweight(int weight) {
    wt = weight;
}
void Cargo::setdestination(string destination) {
    dest = destination;
}
string Cargo::getuldtype() const {
    return type;
}
string Cargo::getabbrev() const {
    return abbr;
}
string Cargo::getuldid() const {
    return id;
}
int Cargo::getaircraft() const {
    return air;
}
int Cargo::getweight() const {
    return wt;
}
string Cargo::getdestination() const {
    return dest;
}
void Cargo::input(Cargo &) {
    string type;
    string abbr;
    string id;
    int air;
    int wt;
    string dest;

    cout << "Enter Unit type(Container/Pallet): ";
    getline(cin,type);
    setuldtype(type);
    cout << "Enter Unit abbreviation: ";
    getline(cin,abbr);
    setabbrev(abbr);
    cout << "Enter Unit ID: ";
    getline(cin,id);
    setuldid(id);
    cout << "Enter Aircraft: ";
    cin >> air;
    setaircraft(air);
    cout << "Enter Weight: ";
    cin >> wt;
    setweight(wt);
    cin.ignore();
    cout << "Enter Destination: ";
    getline(cin,dest);
    setdestination(dest);
    cout << endl;
}
void Cargo::output(Cargo &) {
    cout << setw(19) << "Unit type " << getuldtype() << endl;
    cout << setw(19) << "Unit abbreviation " << getabbrev() << endl;
    cout << setw(19) << "Unit ID " << getabbrev() << getuldid() << endl;
    cout << setw(19) << "Aircraft " << getaircraft() << endl;
    cout << setw(19) << "Weight " << getweight() << endl;
    cout << setw(19) << "Destination " << getdestination() << endl;
    cout << endl;
}

/* == Sample Run:
Enter Unit type(Container/Pallet): Container
Enter Unit abbreviation: AYF
Enter Unit ID: 97326IB
Enter Aircraft: 737
Enter Weight: 1710
Enter Destination: SMF

         Unit type Container
 Unit abbreviation AYF
           Unit ID AYF97326IB
          Aircraft 737
            Weight 1710
       Destination SMF

default constructor output
         Unit type none
 Unit abbreviation none
           Unit ID nonenone
          Aircraft 700
            Weight 0
       Destination unknown

Cargo destructor called
===
*/