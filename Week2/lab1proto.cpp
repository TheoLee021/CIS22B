///Prototype for 1, a proof of concept
#include<iostream>
#include<string>

using namespace std;

struct Cargo
{
      string loadType;
      string abbreviation;
      string identification;
      int aircraft;
      int weight;
      string destination;
};
void input(Cargo* cPtr);
void output(Cargo* cPtr);

int main ()
{
      Cargo* cPtr = new Cargo; // Cargo struct on the heap
      input(cPtr);
      output(cPtr);
      delete cPtr;// pointer gone
      cPtr = nullptr;
      return 0;
}
void input(Cargo* cPtr)
{
    cout << "input called\n";
    cout << "Please input Container or Pallet: ";
    getline(cin, cPtr->loadType); ///eliminates (*cPtr).loadType
    cout << "Please input the abbreviation for the unit: ";
    getline(cin, cPtr->abbreviation);
}
void output(Cargo *cPtr)
{
    cout << "output called\n";
    cout << cPtr->loadType << endl;
    cout << cPtr->abbreviation << endl;
}
