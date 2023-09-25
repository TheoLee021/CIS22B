#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFS;
    int fileNum1;
    int fileNum2;

    cout << "Opening file numFile.txt." << endl;

    inFS.open("numFile.txt");
    if (!inFS.is_open()) {
        cout << "Could not open file numFile.txt." << endl;
        return 1; // 1 indicates error
    }

    // Can now use inFS stream like cin stream
    // numFile.txt should contain two integers, else problems
    cout << "Reading two integers." << endl;
    inFS >> fileNum1;
    inFS >> fileNum2;
    cout << "Closing file numFile.txt." << endl;
    inFS.close(); // Done with file, so close it

    // Output valies read from file
    cout << "num1: " << fileNum1 << endl;
    cout << "num2: " << fileNum2 << endl;
    cout << "num1 + num2: " << (fileNum1 + fileNum2) << endl;

    return 0;
}