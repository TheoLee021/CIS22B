#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Review {
    public:
        void SetRatingAndComment(int revRating, string revComment) {
            rating =  revRating;
            comment = revComment;
        }
        int GetRating() const { return rating; }
        string GetComment() const { return comment; }
        void printReview();
 
    private:
        int rating = -1;
        string comment = "NoComment";
};

// Equality (==) operator for two Review objects
bool operator==(const Review& lhs, const Review& rhs) {
    return (lhs.GetRating() == rhs.GetRating()) &&
            (lhs.GetComment() == rhs.GetComment());
}

// Less-than(<) operator for two Review objects
bool operator<(const Review& lhs, const Review& rhs) {
    return (lhs.GetRating() < rhs.GetRating());
}

bool operator!=(const Review& lhs, const Review& rhs) { return !(lhs == rhs); }
bool operator>(const Review& lhs, const Review& rhs) { return lhs > rhs; }
bool operator<=(const Review& lhs, const Review& rhs) { return !(lhs > rhs); }
bool operator>=(const Review& lhs, const Review& rhs) { return !(lhs < rhs); }

int main() {
    vector<Review> reviewList;
    Review currentReview;
    Review lowestReview;
    int currentRating;
    string currentComment;
    int i;

    cout << "Type rating + comments. To end: -1" << endl;
    cin >> currentRating;
    while (currentRating >= 0) {
        cout << "Enter your comment: ";
        cin >> currentComment;
        //getline(cin, currentComment);

        currentReview.SetRatingAndComment(currentRating, currentComment);
        reviewList.push_back(currentReview);
        
        cout << "Enter your rating: ";
        cin >> currentRating;
    }

    // Find and output lowest review
    lowestReview = reviewList.at(0);
    for(i = 1; i < reviewList.size(); i++) {
        if (reviewList.at(i) < lowestReview) {
            lowestReview = reviewList.at(i);
        }
    }

    // Sort reviews from lowest to highest
    sort(reviewList.begin(), reviewList.end());

    cout << endl;
    for(i = 0; i < reviewList.size(); i++) {
        reviewList.at(i).printReview();
    }

    cout << "Lowest Review is " << lowestReview.GetRating() << " "
         << lowestReview.GetComment() << endl;

    cout << "Lowest Review: ";
    reviewList.at(0).printReview();
    cout << "The Best Review: ";
    reviewList.at(reviewList.size()-1).printReview();

    return 0;
}

void Review::printReview() {
    cout << rating << " " << comment << endl;
}