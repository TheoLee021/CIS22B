#include <iostream>
using namespace std;

template<typename TheType>
TheType TripleMin(TheType item1, TheType item2, TheType item3) {
    TheType minVal = item1; // Holds min item value, init to first item

    if (item2 < minVal)
        minVal = item2;
    
    if (item3 < minVal)
        minVal = item3;

    return minVal;
}

int main() {
    int num1 = 55;
    int num2 = 99;
    int num3 = 66;

    char let1 = 'a';
    char let2 = 'z';
    char let3 = 'm';

    string str1 = "zzz";
    string str2 = "aaa";
    string str3 = "mmm";

    // Try TripleMin function with ints
    cout << "Items: " << num1 << " " << num2 << " " << num3 << endl;
    cout << "Min: " << TripleMin(num1, num2, num3) << endl << endl;

    // Try TripleMin function with chars
    cout << "Items: " << let1 << " " << let2 << " " << let3 << endl;
    cout << "Min: " << TripleMin(let1, let2, let3) << endl << endl;

    // Try TripleMin function with strings
    cout << "Items: " << str1 << " " << str2 << " " << str3 << endl;
    cout << "Min: " << TripleMin(str1, str2, str3) << endl << endl;

    // Try TripleMin function with mixed type: error
    //cout << "Items: " << num1 << " " << let2 << " " << str3 << endl;
    //cout << "Min: " << TripleMin(num1, let2, str3) << endl << endl;

    return 0;
}