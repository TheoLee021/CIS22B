#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream teamFS;
    string teamName;
    int numWins;
    int numLosses;

    teamFS.open("teams.txt");

    if(!teamFS.is_open()) {
        cout << "Could not open file teams.txt." << endl;
        return 1;
    }

    getline(teamFS, teamName);

    while(!teamFS.fail()) {
        teamFS >> numWins;

        if(teamFS.fail()) {
            cout << teamName << " has no wins or losses" << endl;
        }
        else {
            // Attempt to read losses
            teamFS >> numLosses;
        
            if (teamFS.fail()) {
                cout << teamName << " has " << numWins << " wins" << endl;
            }
            else {
            cout << teamName << " win average is " << static_cast<double>(numWins) / (numWins +numLosses) << endl;
            }
        // Remove newline
        teamFS.ignore();
        }
        // Clear the error state
        teamFS.clear();

        // Attempt to read next team
        getline(teamFS, teamName);
    }

    teamFS.close();

    return 0;
}

