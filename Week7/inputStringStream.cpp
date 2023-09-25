#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string userInfo = "Theo Lee 25";
    istringstream inSS(userInfo);
    string firstName;
    string lastName;
    int age;

    inSS >> firstName;
    inSS >> lastName;
    inSS >> age;

    cout << "First Name: " << firstName << endl;
    cout << "Last Name: " << lastName << endl;
    cout << "Age: " << age << endl;
    
    return 0;
}