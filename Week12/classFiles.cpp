#include <iostream>
#include "StoreItem.h"
#include "StoreItem.cpp"
using namespace std;

int main() {
    StoreItem item1;

    item1.SetWeightOunces(16);
    item1.Print();

    return 0;
}