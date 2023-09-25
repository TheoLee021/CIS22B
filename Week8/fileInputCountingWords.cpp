#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFS;
    string userWord;
    int wordFreq = 0;
    string currWord;

    cout << "Opening file wordFile.txt." << endl;
    inFS.open("wordFile.txt");

    if(!inFS.is_open()) {
        cout << "Could not open file wordFile.txt." << endl;
        return 1;
    }

    cout << "Enter a word: ";
    cin >> userWord;

    while(!inFS.eof()) {
        inFS >> currWord;
        if(!inFS.fail()) {
            if(currWord == userWord) {
                ++wordFreq;
            }
        }
    }

    cout << userWord << " appears in the file " << wordFreq << " times." << endl;

    inFS.close();

    return 0;
}