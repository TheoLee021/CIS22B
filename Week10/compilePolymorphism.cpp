#include <iostream>
using namespace std;

class Restaurant {
    public:
        void SetDescription();
        string GetDescription();
    private:
        string restaurant;

};

void DriveTo(string restaurant) {
    cout << "Driving to " << restaurant << endl;
}

void DriveTo(Restaurant restaurant) {
    cout << "Driving to " << restaurant.GetDescription() << endl;
}

int main() {
    Restaurant McDonals;

    DriveTo("Big Mac's");
}