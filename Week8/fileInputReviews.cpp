#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream inFS;
    string restaurantName;
    string userName;
    int userRating;
    int userRatingSum = 0;
    int userRatingCount = 0;

    inFS.open("Trattoria_Reviews.txt");

    if(!inFS.is_open()) {
        cout << "Could not open file Trattoria_Reviews.txt." << endl;
        return 1;
    }

    getline(inFS, restaurantName);
    cout << endl << restaurantName << endl;
    cout << "------------------------" << endl;

    while(!inFS.eof()) {
        inFS >> userName;
        inFS >> userRating;

        if(!inFS.fail()) {
            cout << "User name: " << userName << endl;
            cout << "   Rating: " << userRating << endl;
            cout << endl;

            userRatingSum += userRating;

            userRatingCount++;
        }
    }

    cout << "------------------------" << endl;
    cout << "Average rating: ";
    cout << ((double)userRatingSum / userRatingCount) << endl;

    inFS.close();

    return 0;
}