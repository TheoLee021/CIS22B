// Theo Lee
// LeeTheo_Lab3-2.cpp
// 2/17/2023
// Copy constructor added

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
              const double weight, 
              const string destination);

        Cargo(const Cargo&);

        ~Cargo();

        void setuldtype(string uldtype);
        void setabbrev(string abbrev);
        void setuldid(string uldid);
        void setaircraft(int aircraft);
        void setweight(double weight);
        void setdestination(string destination);

        string getuldtype() const;
        string getabbrev() const;
        string getuldid() const;
        int getaircraft() const;
        int getweight() const;
        string getdestination() const;

        void input();
        void output();

        friend void kilotopound(double &);
    
    private:
        string type;
        string abbr;
        string id;
        int air;
        double wt;
        string dest;
};

void kilotopound(double &);

int main()
{
    Cargo unit1;

    cout << "default constructor output" << endl;
    unit1.output();
    unit1.input();
    cout << "Unit1: " << endl;
    unit1.output();

    Cargo unit2(unit1);
    cout << "Unit2: " << endl;
    unit2.output();

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
Cargo::Cargo(const string uldtype, const string abbrev, const string uldid, const int aircraft, const double weight, const string destination) {
    type = uldtype;
    abbr = abbrev;
    id = uldid;
    air = aircraft;
    wt = weight;
    dest = destination;
}
Cargo::Cargo(const Cargo& unit1) {
    type = unit1.type;
    abbr = unit1.abbr;
    id = unit1.id;
    air = unit1.air;
    wt = unit1.wt;
    dest = unit1.dest;
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
void Cargo::setweight(double weight) {
    string ans;

    cout << "The weight is kilos(K) or pound(P)? ";
    cin >> ans;
    wt = weight;
    if (ans == "K" || ans == "k")
        kilotopound(weight);
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
void Cargo::input() {
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
void Cargo::output() {
    cout << setw(19) << "Unit type " << getuldtype() << endl;
    cout << setw(19) << "Unit abbreviation " << getabbrev() << endl;
    cout << setw(19) << "Unit ID " << getabbrev() << getuldid() << endl;
    cout << setw(19) << "Aircraft " << getaircraft() << endl;
    cout << setw(19) << "Weight " << getweight() << endl;
    cout << setw(19) << "Destination " << getdestination() << endl;
    cout << endl;
}
void kilotopound(double& weight){
    weight = weight * 2.2;
    cout << "friend called " << weight << endl;
}

/* == Sample Run:
default constructor output
         Unit type none
 Unit abbreviation none
           Unit ID nonenone
          Aircraft 700
            Weight 0
       Destination unknown

Enter Unit type(Container/Pallet): Container
Enter Unit abbreviation: ABB
Enter Unit ID: 31545IB
Enter Aircraft: 737
Enter Weight: 1156
The weight is kg or pound? kg
Enter Destination: BUR

Unit1: 
         Unit type Container
 Unit abbreviation ABB
           Unit ID ABB31545IB
          Aircraft 737
            Weight 2543
       Destination BUR

Unit2: 
         Unit type Container
 Unit abbreviation ABB
           Unit ID ABB31545IB
          Aircraft 737
            Weight 2543
       Destination BUR

Cargo destructor called
Cargo destructor called
===
*/