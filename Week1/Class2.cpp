#include <iostream>
using namespace std;

class Cylinder {
    public:
        Cylinder(int radiusValue, int heightValue);
        void Print();
    private:
        int radius;
        int height;
};
Cylinder::Cylinder(int radiusValue, int heightValue) {
    radius = radiusValue;
    height = heightValue;
}
void Cylinder::Print() {
    cout << "Cylinder's radius: " << radius << endl;
    cout << "Cylinder's height: " << height << endl;
}

int main() {
    Cylinder* myCylinder = nullptr;
    int radiusValue;
    int heightValue;

    cin >> radiusValue;
    cin >> heightValue;

    myCylinder = new Cylinder(radiusValue, heightValue);

    myCylinder->Print();

    return 0;
}