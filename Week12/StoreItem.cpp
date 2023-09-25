#include <iostream>
#include "StoreItem.h"
using namespace std;

void StoreItem::SetWeightOunces(int ounces) {
    weightOunces = ounces;
}

void StoreItem::Print() const {
    cout << "Weight (ounces): " << weightOunces << endl;
}