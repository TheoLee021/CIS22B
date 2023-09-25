#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    istringstream inSS;
    string lineString;
    int areaCode;
    int officeCode;
    int stationNum;
    char dummyChar1;
    char dummyChar2;
    bool isValidNumber;

    cout << "Enter a 10-digit phone number (or -1 to exit):" << endl;
    getline(cin, lineString);

    while (lineString != "-1") {
        isValidNumber = false;
        dummyChar1 = ' ';
        dummyChar2 = ' ';

        inSS.clear();
        inSS.str(lineString);

        inSS >> areaCode;
        if(inSS.good()) {
            // Number format should be ###-###-####
            // The good() function returns true when a stream is not in an error state and false otherwise.
            // Ex: If a program attempts to read a character in a stream's buffer into an integer variable, the stream is placed into
            // an error state
            inSS >> dummyChar1 >> officeCode >> dummyChar2 >> stationNum;

            if(inSS.eof() && dummyChar1 == '-' &&dummyChar2 == '-') {
                isValidNumber = true;
            }
        }
        else {
            // Number format should be (###) ###-####

            // Clear inSS state, and try extracting with area code in ()
            inSS.clear();
            inSS >> dummyChar1 >> areaCode >> dummyChar2;

            if (inSS.good() && dummyChar1 == '(' && dummyChar2 == ')') {
                inSS >> officeCode >> dummyChar1 >> stationNum;
                if(inSS.eof() && dummyChar1 == '-') {
                    isValidNumber = true;
                }
            }
        }
        if (isValidNumber) {
            cout << "   Standardized format: (" << areaCode << ") " << officeCode << "-" << stationNum << endl << endl;;
        }
        else {
            cout << "   Invalid phone number." << endl << endl;
        }

        // Get next user input
        getline(cin, lineString);
    }

    return 0;
}