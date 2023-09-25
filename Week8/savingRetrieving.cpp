#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

void ReadReviews(vector<string> &reviewList) {
    ifstream reviewFS;
    string review;

    reviewFS.open("review.txt");

    if (!reviewFS.is_open()) {
        cout << "Could not open file review.txt." << endl;
    }
    else {
        getline(reviewFS, review);
        while (!reviewFS.fail()) {
            reviewList.push_back(review);
            getline(reviewFS, review);
        }

        reviewFS.close();
    }
}

void DisplayReviews(const vector<string> &reviewList) {
    cout << endl << "Reviews:" << endl;
    for(int i = 0; i < reviewList.size(); i++) {
        cout << i + 1 << ". " << reviewList.at(i) << endl;
    }
    cout << endl;
}

int main() {
    vector<string> reviewList;
    string newReview;

    // Read reviews from file into reviews vector and display
    ReadReviews(reviewList);
    DisplayReviews(reviewList);

    cout << "Enter new review or QUIT:" << endl;
    getline(cin, newReview);
    while (newReview != "QUIT") {
        // Add new reviews to the vector and display new list
        reviewList.push_back(newReview);
        DisplayReviews(reviewList);

        cout << "Enter new review or QUIT:" << endl;
        getline(cin, newReview);
    }

    return 0;
}