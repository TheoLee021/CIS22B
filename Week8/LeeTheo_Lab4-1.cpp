// Theo Lee
// LeeTheo_Lab4-1.cpp
// 3/03/2023

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
        friend bool operator==(const Cargo& lhs, const Cargo& rhs);
    
    private:
        string type;
        string abbr;
        string id;
        int air;
        double wt;
        string dest;
};

void kilotopound(double&);

int main()
{
    Cargo unit1;
    unit1.input();
    Cargo unit2(unit1);
    Cargo unit3;

    cout << "unit1" << endl;
    unit1.output();
    cout << "unit2" << endl;
    unit2.output();
    cout << "unit3" << endl;
    unit3.output();
    if (unit1 == unit2) 
        cout << "unit1 is the same as unit2" << endl;
    else
        cout << "unit1 is not the same as unit2" << endl;
    if (unit2 == unit3)
        cout << "unit2 is the same as unit3" << endl;
    else
        cout << "unit2 is not the same as unit3" << endl;

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
Cargo::Cargo(const Cargo& unit) {
    type = unit.type;
    abbr = unit.abbr;
    id = unit.id;
    air = unit.air;
    wt = unit.wt;
    dest = unit.dest;
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
void kilotopound(double& weight) {
    weight = weight * 2.2;
    cout << "friend called " << weight << endl;
}
bool operator==(const Cargo& left, const Cargo& right) {
    return (left.abbr == right.abbr && left.id == right.id);
}

/* == Sample Run:
Enter Unit type(Container/Pallet): Pallet
Enter Unit abbreviation: PAG
Enter Unit ID: 32597IB
Enter Aircraft: 737
Enter Weight: 3321
The weight is kilos(K) or pound(P)? K
friend called 7306.2
Enter Destination: SEA

unit1
         Unit type Pallet
 Unit abbreviation PAG
           Unit ID PAG32597IB
          Aircraft 737
            Weight 3321
       Destination SEA

unit2
         Unit type Pallet
 Unit abbreviation PAG
           Unit ID PAG32597IB
          Aircraft 737
            Weight 3321
       Destination SEA

unit3
         Unit type none
 Unit abbreviation none
           Unit ID nonenone
          Aircraft 700
            Weight 0
       Destination unknown

unit1 is the same as unit2
unit2 is not the same as unit3
Cargo destructor called
Cargo destructor called
Cargo destructor called
===
*/