#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string objectInfo = "Book 18 19";
    istringstream objectISS(objectInfo);
    string object;
    int quantity;
    int price;

    objectISS >> object >> quantity >> price;

    cout << object << " x" << quantity << endl;
    cout << "Price: " << price;

    return 0;
}