// input stream과 out stream은 따로 존재하는 여러 데이터를 한데 묶는 역할을 하는 것 같다.
// input stream은 input방식으로 buffer에서 stack으로 가져오면서 데이터를 하나로 조합하고 
// out stream은 output의 방식으로 stack에서 buffer로 내보내 산개된 데이터들을 조합한다.

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    ostringstream infoOSS;
    string infoStr;
    string firstName;
    string lastName;
    int userAge;

    cout << "Enter \"firstname lastname age\": " << endl;
    cin >> firstName;
    cin >> lastName;
    cin >> userAge;

    infoOSS << lastName << ", " << firstName;
    infoOSS << " " << userAge;

    if (userAge < 21) {
        infoOSS << " (minor)";
    }

    infoStr = infoOSS.str();

    cout << "Information: " << infoStr << endl;

    return 0;
}