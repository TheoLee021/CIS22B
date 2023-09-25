#include <iostream>
#include <iomanip>
using namespace std;

class Goose {
    public:
        Goose();
        void Print();

        double age;
        double weight;
};
Goose::Goose() {
    age = 0.0;
    weight = 0.0;
}
void Goose::Print() {
    cout << "Goose's age: " << fixed << setprecision(1) << age << endl;
    cout << "Goose's weight: " << fixed << setprecision(1) << weight << endl;
}

int main() {
    double ageValue;
    double weightValue;

    Goose *myGoose = new Goose();

    cin >> ageValue;
    cin >> weightValue;

    myGoose->age = ageValue;
    myGoose->weight = weightValue;

    myGoose->Print();

    return 0;
}