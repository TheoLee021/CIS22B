#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string userInput;
    istringstream inSS;
    string data;

    cout << "Enter user input: " << flush;
    getline(cin, userInput);
    inSS.str(userInput);

    while(inSS >> data) {
        cout << data << endl;
    }
    
    return 0;
}