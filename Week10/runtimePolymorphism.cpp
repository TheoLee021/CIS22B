#include <iostream>
using namespace std;

class Business* {
    public:

    private:
};

void DriveTo(Business* businessPtr) {
    cout << "Driving to " << businessPtr->GetDescription() <<endl;
}

int main() {
    int index;
    vector<Business*> businessList;
    Business* businessPtr;
    Business* restaurantPtr;
    
    businessList.push_back(businessPtr);
    businessList.push_back(restaurantPtr);
}