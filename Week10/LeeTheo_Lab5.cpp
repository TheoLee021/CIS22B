// Theo Lee
// LeeTheo_Lab5.cpp
// 3/17/2023

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>
using namespace std;

const double load737 = 46000.00;
const double load767 = 116000.00;

class Cargo {
    public:
        Cargo();
        Cargo(const string uldtype, 
              const string abbrev, 
              const string uldid, 
              const int aircraft, 
              const double weight, 
              const string destination);

        Cargo(const Cargo &unit);

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

        virtual void maxWeight();

        void output();
    
    protected:
        string type;
        string abbr;
        string id;
        int air;
        double wt;
        string dest;
};

class Boeing737 : public Cargo {
    public:
        Boeing737();

        Boeing737(const string &uldtype, 
              const string &abbrev, 
              const string &uldid, 
              const int &aircraft, 
              const double &weight, 
              const string &destination);

        ~Boeing737() {};

        void maxWeight(double&, double, string);
    
    private:
        double total737wt;
};

class Boeing767 : public Cargo {
    public:
        Boeing767();

        Boeing767(const string &uldtype, 
              const string &abbrev, 
              const string &uldid, 
              const int &aircraft, 
              const double &weight, 
              const string &destination);

        ~Boeing767() {};

        void maxWeight(double&, double, string);
    
    private:
        double total767wt;
};

void input();
void checkPlane(int);
void checkType(string);
void checkAbrv(string, int);
void vectorPrint(vector<Boeing737> vectorPtr737, vector<Boeing767> vectorPtr767);

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
    // cout << "Cargo destructor called" << endl;
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
Boeing737::Boeing737(const string &uldtype, const string &abbrev, const string &uldid, const int &aircraft, const double &weight, const string &destination) {
    type = uldtype;
    abbr = abbrev;
    id = uldid;
    air = aircraft;
    wt = weight;
    dest = destination;
}
Boeing767::Boeing767(const string &uldtype, const string &abbrev, const string &uldid, const int &aircraft, const double &weight, const string &destination) {
    type = uldtype;
    abbr = abbrev;
    id = uldid;
    air = aircraft;
    wt = weight;
    dest = destination;
}
void Cargo::maxWeight() {}

void Boeing737::maxWeight(double &totwt737, double wt, string id) {
    if (totwt737 > load737) {
        totwt737 -= wt;
        cout << id << " ";
        throw runtime_error("would be overweight for 737\n\n");
    }
}
void Boeing767::maxWeight(double &totwt767, double wt, string id) {
    if (totwt767 > load767) {
        totwt767 -= wt;
        cout << id << " ";
        throw runtime_error("would be overweight for 767\n\n");
    }
}

void input() {
    string type;
    string abbr;
    string id;
    int air;
    double wt;
    string dest;
    string datafile;
    ifstream inputFile;
    double totwt737 = 0.0;
    double totwt767 = 0.0;
    vector<Boeing737> vectorPtr737;
    vector<Boeing767> vectorPtr767;

    inputFile.clear();
    cout << "What is the name of the data file? ";
    getline(cin, datafile);
    cout << "datafile is " << datafile << endl << endl;
    inputFile.open(datafile);
    try {
        if(!inputFile.is_open()) {
            throw runtime_error("Bad filename");
        }
    }
    catch(runtime_error &excpt) {
        cout << excpt.what() << endl;
        cout << "file open failure, quitting";
        return;
    }

    cout << datafile << " Errors\n";
    cout << "*********************************\n";

    while(inputFile >> type) {
    try {
        inputFile >> abbr;
        inputFile >> id;
        inputFile >> air;
        inputFile >> wt;
        inputFile >> dest;

        checkType(type);
        checkPlane(air);
        checkAbrv(abbr,air);
        if (air == 737) {
            totwt737 += wt;
            Boeing737 unitobj737(type, abbr, id, air, wt, dest);
            unitobj737.maxWeight(totwt737,wt,id);
            vectorPtr737.push_back(unitobj737);
        }
        if (air == 767) {
            totwt767 += wt;
            Boeing767 unitobj767(type, abbr, id, air, wt, dest);
            unitobj767.maxWeight(totwt767, wt, id);
            vectorPtr767.push_back(unitobj767);
        }
    }
    catch(runtime_error &excpt) {
        cout << excpt.what();
    }
    }
    inputFile.close();
    cout << "*********************************\n";
    cout << datafile << " End of errors\n\n";
    vectorPrint(vectorPtr737, vectorPtr767);
    cout << "\ntotal weight for 737 load is " << totwt737 << " pounds" << endl;
    cout << "\ntotal weight for 767 load is " << totwt767 << " pounds" << endl;
}
void checkPlane(int air) {
    if (air != 737 && air != 767) {
        cout << air;
        throw runtime_error(" no such plane\n\n");
    }
}

void checkType(string type) {
    if (type != "Container" && type != "Pallet") {
        cout << type;
        throw runtime_error(" rejected, not Container or Pallet\n\n");
    }
}

void checkAbrv(string abbr, int air) {
    if (air == 737) {
        if (abbr != "AYF" &&
                abbr != "AYK" &&
                abbr != "AAA" &&
                abbr != "AYY" &&
                abbr != "PAG" &&
                abbr != "PMC" &&
                abbr != "PLA" ) {
            cout << abbr;
            throw runtime_error(" bad type for 737\n\n");
            }
    }
    else if (air == 767) {
        if (abbr != "AKE" &&
                abbr != "APE" &&
                abbr != "AKC" &&
                abbr != "AQP" &&
                abbr != "AQF" &&
                abbr != "AAP" &&
                abbr != "P1P" &&
                abbr != "P6P" ) {
            cout << abbr;
            throw runtime_error(" bad type for 737\n\n");
            }
    }
}
void Cargo::output() {
    cout << fixed << showpoint << setprecision(2);
    cout << setw(19) << "Unit type " << getuldtype() << endl;
    cout << setw(19) << "Unit abbreviation " << getabbrev() << endl;
    cout << setw(19) << "Unit ID " << getuldid() << endl;
    cout << setw(19) << "Aircraft " << getaircraft() << endl;
    cout << setw(19) << "Weight " << getweight() << endl;
    cout << setw(19) << "Destination " << getdestination() << endl;
    cout << endl;
}
void vectorPrint(vector<Boeing737> vectorPtr737, vector<Boeing767> vectorPtr767) {
        cout << "***** 737 Load Data *****" << endl;
    for (int i = 0; i < vectorPtr737.size(); i++) {
        cout << "\n737 unit number " << i + 1 << endl;
        cout << fixed << setprecision(2);
        cout << left << setw(20) << "Unit load type: " << vectorPtr737[i].getuldtype() << endl;
        cout << left << setw(20) << "Unit abbreviation: " << vectorPtr737[i].getabbrev() << endl;
        cout << left << setw(20) << "Unit identifier: " << vectorPtr737[i].getuldid() << endl;
        cout << left << setw(20) << "Aircraft type: " << vectorPtr737[i].getaircraft() << endl;
        cout << left << setw(20) << "Unit weight: " << vectorPtr737[i].getweight() << " pounds" << endl;
        cout << left << setw(20) << "Destination code: " << vectorPtr737[i].getdestination() << endl << endl;
    }
        cout << "***** 767 Load Data *****\n";
    for (int i = 0; i < vectorPtr767.size(); i++) {
        cout << "\n767 unit number " << i + 1 << endl;
        cout << fixed << setprecision(2);
        cout << left << setw(20) << "Unit load type: " << vectorPtr767[i].getuldtype() << endl;
        cout << left << setw(20) << "Unit abbreviation: " << vectorPtr767[i].getabbrev() << endl;
        cout << left << setw(20) << "Unit identifier: " << vectorPtr767[i].getuldid() << endl;
        cout << left << setw(20) << "Aircraft type: " << vectorPtr767[i].getaircraft() << endl;
        cout << left << setw(20) << "Unit weight: " << vectorPtr767[i].getweight() << " pounds" << endl;
        cout << left << setw(20) << "Destination code: " << vectorPtr767[i].getdestination() << endl << endl;
}
}

/* == Sample Run:
What is the name of the data file? lab5data01.txt
datafile is lab5data01.txt

lab5data01.txt Errors
*********************************
*********************************
lab5data01.txt End of errors

***** 737 Load Data *****

737 unit number 1
Unit load type:     Pallet
Unit abbreviation:  PAG
Unit identifier:    PAG45982IB
Aircraft type:      737
Unit weight:        4978 pounds
Destination code:   OAK


737 unit number 2
Unit load type:     Container
Unit abbreviation:  AYF
Unit identifier:    AYF23409AA
Aircraft type:      737
Unit weight:        2209 pounds
Destination code:   LAS


737 unit number 3
Unit load type:     Container
Unit abbreviation:  AAA
Unit identifier:    AAA89023DL
Aircraft type:      737
Unit weight:        5932 pounds
Destination code:   DFW

***** 767 Load Data *****

767 unit number 1
Unit load type:     Container
Unit abbreviation:  AKE
Unit identifier:    AKE34258KF
Aircraft type:      767
Unit weight:        8915 pounds
Destination code:   ICN


767 unit number 2
Unit load type:     Pallet
Unit abbreviation:  P1P
Unit identifier:    AKC84932LT
Aircraft type:      767
Unit weight:        10284 pounds
Destination code:   JFK


767 unit number 3
Unit load type:     Container
Unit abbreviation:  AQF
Unit identifier:    AQF93211FG
Aircraft type:      767
Unit weight:        14124 pounds
Destination code:   LAX


total weight for 737 load is 13119.00 pounds

total weight for 767 load is 33323.00 pounds

== Fail:
What is the name of the data file?lab5data
datafile is lab5data

Bad filename
file open failure, quitting
===
*/