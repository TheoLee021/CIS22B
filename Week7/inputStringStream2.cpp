#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    string userInfo;
    istringstream inSS;
    string firstName;
    string lastName;
    int age;

    cout << "Enter your \"firstname lastname age\"" << endl;
    getline(cin, userInfo);
    inSS.clear();
    inSS.str(userInfo);

    inSS >> firstName;
    inSS >> lastName;
    inSS >> age;

    cout << left << setw(14) << "  First Name: " << firstName << endl;
    cout << setw(14) << "  Last Name: " << lastName << endl;
    cout << setw(14) << "  Age: " << age << endl;
    
    return 0;
}