#include <iostream>
using namespace std;

class Cylinder {
   public:
      Cylinder(int radiusValue, int heightValue);
      void IncreaseRadiusAndHeight();
      void Print();
   private:
      int radius;
      int height;
};
Cylinder::Cylinder(int radiusValue, int heightValue) {
   radius = radiusValue;
   height = heightValue;
}
void Cylinder::IncreaseRadiusAndHeight() {
	radius = radius * 4;
	height = height * 4;
   cout << "Cylinder's radius and height are increased." << endl;
}
void Cylinder::Print() {
   cout << "Cylinder's radius: " << radius << endl;
   cout << "Cylinder's height: " << height <<  endl;
}


int main() {
   
   int radius, height;
   cin >> radius >> height;
   Cylinder* myCylinder = new Cylinder(radius, height);

   myCylinder->IncreaseRadiusAndHeight();
   myCylinder->Print();
   
   return 0;
}