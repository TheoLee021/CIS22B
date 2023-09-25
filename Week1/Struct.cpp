#include <iostream>
using namespace std;

struct height {
    int feet;
    int inch;
};

height conFtIn(int totalcm) {
    height heightStruct;

    heightStruct.feet = totalcm / 30;
    heightStruct.inch = (totalcm % 30)/2.5;

    return heightStruct;
}

int main() {
    int inHeight;
    height height1;

    cout << "Enter your height in cm: ";
    cin >> inHeight;

    height1 = conFtIn(inHeight);

    cout << "Your height in US unit: ";
    cout << height1.feet << " feet ";
    cout << height1.inch << " inches.";

    return 0;
}