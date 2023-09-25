#include <iostream>
#include <string>
using namespace std;

template<typename TheType, typename TheType2, typename TheType3>
TheType TripleMin(TheType item1, TheType2 item2, TheType3 item3) {
    TheType minVal = item1;

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

    double dbl1 = 11.1;
    double dbl2 = 22.2;
    double dbl3 = 77.7;

    // Try TripleMin function with ints
    cout << "Items: " << num1 << " " << num2 << " " << num3 << endl;
    cout << "Min: " << TripleMin(num1, num2, num3) << endl << endl;

    // Try TripleMin function with chars
    cout << "Items: " << let1 << " " << let2 << " " << let3 << endl;
    cout << "Min: " << TripleMin(let1, let2, let3) << endl << endl;

    // Try TripleMin function with strings
    cout << "Items: " << str1 << " " << str2 << " " << str3 << endl;
    cout << "Min: " << TripleMin(str1, str2, str3) << endl << endl;

    // Try TripleMin function with mixed type: int, char, string (error)
    // cout << "Items: " << num1 << " " << let2 << " " << str3 << endl;
    // cout << "Min: " << TripleMin(num1, let2, str3) << endl << endl;

    // Try TripleMin function with mixed type2: int, double
    cout << "Items: " << dbl1 << " " << dbl2 << " " << num2 << endl;
    cout << "Min: " << TripleMin(dbl1, dbl2, num2) << endl << endl;

    // Try TripleMin function with mixed type3: char, string (error)
    // cout << "Items: " << let1 << " " << str2 << " " << str3 << endl;
    // cout << "Min: " << TripleMin(let1, str2, str3) << endl << endl;

    return 0;
}