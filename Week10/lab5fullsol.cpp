///lab 5.1 Prototype (with exception handling and vectors, no constructor inheritance)
#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
const double maxload737 = 46000.00;
const double maxload767 = 116000.00;

class Cargo   ///abstract due to pure virtual function
{
protected:
    string uldtype;
    string abbrev;
    string uldid;
    int aircraft;
    double weight;
    string destination;

public:
    ///Default constructor prototype
    Cargo();

    ///Full constructor prototype
    Cargo(const string &uldtype,
          const string &abbrev,
          const string &uldid,
          const int &aircraft,
          const double &weight,
          const string &destination);

    ///Copy constructor prototype
    Cargo(const Cargo &unit);

    ///Destructor prototype
    ~Cargo();

    ///Mutator (setters) prototypes
    void setuldtype(string);
    void setabbrev(string);
    void setuldid(string);
    void setaircraft(int);
    void setweight(double);
    void setdestination(string);

    ///Accessor (getters) prototypes
    string getuldtype() const;
    string getabbrev() const;
    string getuldid() const;
    int getaircraft() const;
    double getweight() const;
    string getdestination() const;

    virtual void maxweight();  ///pure virtual function to be overridden

    void output();
}; ///end of Cargo class

class Boeing737 : public Cargo  ///derived from Cargo
{
private:
   double total737wt;
public:
    Boeing737();

    Boeing737(const string &uldtype,
          const string &abbrev,
          const string &uldid,
          const int &aircraft,
          const double &weight,
          const string &destination);

    ~Boeing737(){};

    void maxweight(double&, double, string); ///overridden from Cargo class
};
class Boeing767 : public Cargo   ///derived from Cargo
{
private:
    double total767wt;
public:
     Boeing767(const string &uldtype,
          const string &abbrev,
          const string &uldid,
          const int &aircraft,
          const double &weight,
          const string &destination);

    ~Boeing767(){};
    void maxweight(double&, double, string); ///overridden from Cargo class
};

void input();
void checkPlane(int);
void checkType(string);
void checkAbrv(string,int);
void vectorprint(vector <Boeing737> vectorptr737, vector <Boeing767> vectorptr767);

int main()
{
    input();
    return 0;
}
    Cargo::Cargo()
    {
        uldtype = "XXX";
        abbrev = " ";
        uldid = "xxxxxIB";
        aircraft = 700;
        weight = 0.0;
        destination = "NONE";
    }
    Cargo::Cargo(const string &uld,
          const string &abrv,
          const string &id,
          const int &craft,
          const double &wt,
          const string &dest)
    {
        uldtype = uld;
        abbrev = abrv;
        uldid = id;
        aircraft = craft;
        weight = wt;
        destination = dest;
    }
    Cargo::Cargo(const Cargo &unit1)
{
    uldtype=unit1.uldtype;
    abbrev=unit1.abbrev;
    uldid=unit1.uldid;
    aircraft=unit1.aircraft;
    weight=unit1.weight;
    destination=unit1.destination;
}
    Cargo::~Cargo()
    {
        ///cout << "destructor called\n\n";
    }
    void Cargo::setuldtype(string type)
    {
        uldtype = type;
    }
    void Cargo::setabbrev(string abrv)
    {
        abbrev = abrv;
    }
    void Cargo::setuldid(string id)
    {
        uldid = id;
    }
    void Cargo::setaircraft(int air)
    {
        aircraft = air;
    }
    void Cargo::setweight(double wt)
    {
        weight = wt;
    }
    void Cargo::setdestination(string dest)
    {
        destination = dest;
    }
    string Cargo::getuldtype() const
    {
        return uldtype;
    }
    string Cargo::getabbrev() const
    {
        return abbrev;
    }
    string Cargo::getuldid() const
    {
        return uldid;
    }
    int Cargo::getaircraft() const
    {
        return aircraft;
    }
    double Cargo::getweight() const
    {
        return weight;
    }
    string Cargo::getdestination() const
    {
        return destination;
    }
    Boeing737::Boeing737(const string &uld,
          const string &abrv,
          const string &id,
          const int &craft,
          const double &wt,
          const string &dest)
    {
        uldtype = uld;
        abbrev = abrv;
        uldid = id;
        aircraft = craft;
        weight = wt;
        destination = dest;
    }

    Boeing767::Boeing767(const string &uld,
          const string &abrv,
          const string &id,
          const int &craft,
          const double &wt,
          const string &dest)
    {
        uldtype = uld;
        abbrev = abrv;
        uldid = id;
        aircraft = craft;
        weight = wt;
        destination = dest;
    }

    void Cargo::maxweight()  ///not used by Cargo, only by Boeing737 and Boeing767
    {}

    void Boeing737::maxweight(double &totwt737, double wt, string id){
        if (totwt737 > maxload737){
            totwt737 -= wt; ///remove from total if overweight
            cout << id << " ";
            throw runtime_error("would be overweight for 737\n\n");
        }
    }
    void Boeing767::maxweight(double &totwt767, double wt, string id){
         if (totwt767 > maxload767){
            totwt767 -= wt; ///remove from total if overweight
            cout << id << " ";
            throw runtime_error("would be overweight for 767\n\n");
        }
    }
    void Cargo::output()
    {
        cout << fixed << showpoint << setprecision(2);
        cout << setw(19) << "Unit load type: " << uldtype << endl;
        cout << setw(19) << "Unit abbreviation: " << abbrev << endl;
        cout << setw(19) << "Unit identifier: " << uldid << endl;
        cout << setw(19) << "Aircraft type: " << aircraft << endl;
        cout << setw(19) << "Unit weight: " << weight << " pounds" << endl;
        cout << setw(19) << "Destination code: " << destination << endl;
    }
    /*
    input handles all data input from file, checks all data for validity,
    and calls print routine when data reads have completed
    */
    void input()
    {
        string type;
        string abrv;
        string id;
        int air;
        double wt;
        string dest;
        double totwt737 = 0.0;
        double totwt767 = 0.0;
        string datafile;
        ifstream inputFile;
        vector<Boeing737> vectorptr737;
        vector<Boeing767> vectorptr767;

        do{
        try{
            inputFile.clear();
            cout << "\nWhat's the name of your data file? ";
            getline(cin,datafile);
            inputFile.open(datafile);
            if (!inputFile){
                cout << datafile << " ";
                throw runtime_error("Bad filename\n\n");
            }
            else
                cout << endl << datafile << " is open\n\n";
        }
        catch(runtime_error &excpt){
            cout << excpt.what();
        }
        }
        while(!inputFile);

        cout << datafile << " Errors\n";
        cout << "*********************************\n";
        while (inputFile >> type){
        try{
            inputFile >> abrv;
            inputFile >> id;
            inputFile >> air;
            inputFile >> wt;
            inputFile >> dest;

            checkType(type);///check for Container or Pallet via function
            checkPlane(air);///check for valid plane type via function
            checkAbrv(abrv, air);///check for valid container or pallet type by plane type
            if (air == 737){
            totwt737 += wt;
            Boeing737 unitobj737(type,abrv,id,air,wt,dest); ///constructor from Boeing737 class
            unitobj737.maxweight(totwt737,wt,id); ///call to overridden function, if too heavy, throw exception
            vectorptr737.push_back(unitobj737); ///if everything is ok, push onto vector
            }
            if (air == 767){
            totwt767 += wt;
            Boeing767 unitobj767(type,abrv,id,air,wt,dest); ///constructor from Boeing767 class
            unitobj767.maxweight(totwt767,wt,id); ///call to overridden function, if too heavy, throw exception
            vectorptr767.push_back(unitobj767);
            }
        }
        catch(runtime_error &excpt){
            cout << excpt.what();
        }
        }
        inputFile.close();
        cout << "*********************************\n";
        cout << datafile << " End of errors\n\n";
        vectorprint(vectorptr737, vectorptr767);
        cout << "\ntotal weight for 737 load is " << totwt737 << " pounds" << endl;
        cout << "\ntotal weight for 767 load is " << totwt767 << " pounds" << endl;
    }

    void checkPlane(int air){
        if (air != 737 && air != 767){
            cout << air;
            throw runtime_error(" no such plane\n\n");
        }
    }

    void checkType(string type){
        if (type != "Container" && type != "Pallet"){
            cout << type;
            throw runtime_error(" rejected, not Container or Pallet\n\n");
        }
    }

    void checkAbrv(string abrv, int air){
        if (air == 737){
            if (abrv != "AYF" &&
                    abrv != "AYK" &&
                    abrv != "AAA" &&
                    abrv != "AYY" &&
                    abrv != "PAG" &&
                    abrv != "PMC" &&
                    abrv != "PLA" ){
            cout << abrv;
            throw runtime_error(" bad type for 737\n\n");
            }
        }
        else if (air == 767){
            if (abrv != "AKE" &&
                    abrv != "APE" &&
                    abrv != "AKC" &&
                    abrv != "AQP" &&
                    abrv != "AQF" &&
                    abrv != "AAP" &&
                    abrv != "P1P" &&
                    abrv != "P6P" ){
            cout << abrv;
            throw runtime_error(" bad type for 767\n\n");
                    }
                }
    }
    void vectorprint(vector <Boeing737> vectorptr737, vector <Boeing767> vectorptr767) {
    cout << "***** 737 Load Data *****\n";
    for (int i = 0; i < vectorptr737.size(); i++)
        {
           cout << "\n737 unit number " << i + 1 << endl;
           cout << fixed << setprecision(2);
           cout << left << setw(20) << "Unit load type: " << vectorptr737[i].getuldtype() << endl;
           cout << left << setw(20) << "Unit abbreviation: " << vectorptr737[i].getabbrev() << endl;
           cout << left << setw(20) << "Unit identifier: " << vectorptr737[i].getuldid() << endl;
           cout << left << setw(20) << "Aircraft type: " << vectorptr737[i].getaircraft() << endl;
           cout << left << setw(20) << "Unit weight: " << vectorptr737[i].getweight() << " pounds" << endl;
           cout << left << setw(20) << "Destination code: " << vectorptr737[i].getdestination() << endl << endl;
           }
           cout << "***** 767 Load Data *****\n";
    for (int i = 0; i < vectorptr767.size(); i++) {
           cout << "\n767 unit number " << i + 1 << endl;
           cout << fixed << setprecision(2);
           cout << left << setw(20) << "Unit load type: " << vectorptr767[i].getuldtype() << endl;
           cout << left << setw(20) << "Unit abbreviation: " << vectorptr767[i].getabbrev() << endl;
           cout << left << setw(20) << "Unit identifier: " << vectorptr767[i].getuldid() << endl;
           cout << left << setw(20) << "Aircraft type: " << vectorptr767[i].getaircraft() << endl;
           cout << left << setw(20) << "Unit weight: " << vectorptr767[i].getweight() << " pounds" << endl;
           cout << left << setw(20) << "Destination code: " << vectorptr767[i].getdestination() << endl;
           }
    }

/*
What's the name of your data file? lab5data01.txt

lab5data01.txt is open

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
Unit weight:        4978.00 pounds
Destination code:   OAK


737 unit number 2
Unit load type:     Container
Unit abbreviation:  AYF
Unit identifier:    AYF23409AA
Aircraft type:      737
Unit weight:        2209.00 pounds
Destination code:   LAS


737 unit number 3
Unit load type:     Container
Unit abbreviation:  AAA
Unit identifier:    AAA89023DL
Aircraft type:      737
Unit weight:        5932.00 pounds
Destination code:   DFW

***** 767 Load Data *****

total weight for 737 load is 13119.00 pounds

total weight for 767 load is 0.00 pounds
*/