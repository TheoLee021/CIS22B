// Theo Lee
// LeeTheo_Lab4-2.cpp
// 3/03/2023

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
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

        void output();
        
        // friend void kilotopound(double &);
        // friend bool operator==(const Cargo& lhs, const Cargo& rhs);
    
    private:
        string type;
        string abbr;
        string id;
        int air;
        double wt;
        string dest;
};

// void kilotopound(double&);

void input();

int main()
{
    input();

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
    // string ans;

    // cout << "The weight is kilos(K) or pound(P)? ";
    // cin >> ans;
    wt = weight;
    // if (ans == "K" || ans == "k")
    //     kilotopound(weight);
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
void input() {
    ifstream inputFile;
    string datafile;
    string type;
    string abbr;
    string id;
    int air;
    double wt;
    string dest;

    inputFile.clear();
    cout << "What is the name of the data file?" << endl;
    getline(cin, datafile);
    cout << "datafile is " << datafile << endl;
    inputFile.open(datafile);
    try {
    if(!inputFile.is_open()) {
        throw runtime_error("file not open");
    }
    }
    catch(runtime_error &excpt) {
        cout << excpt.what() << endl;
        cout << "file open failure, quitting";
        return;
    }
    while(inputFile >> type) {
        inputFile >> abbr;
        inputFile >> id;
        inputFile >> air;
        inputFile >> wt;
        inputFile >> dest;

        Cargo temp(type, abbr, id, air, wt, dest);
        temp.output();
    }
    inputFile.close();
}
void Cargo::output() {
    cout << setw(19) << "Unit type " << getuldtype() << endl;
    cout << setw(19) << "Unit abbreviation " << getabbrev() << endl;
    cout << setw(19) << "Unit ID " << getuldid() << endl;
    cout << setw(19) << "Aircraft " << getaircraft() << endl;
    cout << setw(19) << "Weight " << getweight() << endl;
    cout << setw(19) << "Destination " << getdestination() << endl;
    cout << endl;
}
/*
void kilotopound(double& weight) {
    weight = weight * 2.2;
    cout << "friend called " << weight << endl;
}
bool operator==(const Cargo& left, const Cargo& right) {
    return (left.abbr == right.abbr && left.id == right.id);
}
*/
/* == Sample Run:
What is the name of the data file?
cardata4.txt
datafile is cardata4.txt
         Unit type Pallet
 Unit abbreviation PAG
           Unit ID PAG45982IB
          Aircraft 737
            Weight 4978
       Destination OAK

Cargo destructor called
         Unit type Container
 Unit abbreviation AYF
           Unit ID AYF23409AA
          Aircraft 737
            Weight 2209
       Destination LAS

Cargo destructor called
         Unit type Container
 Unit abbreviation AAA
           Unit ID AAA89023DL
          Aircraft 737
            Weight 5932
       Destination DFW

Cargo destructor called

== Fail:
What is the name of the data file?
cardata.txt
datafile is cardata.txt
file not open
file open failure, quitting%   
===
*/