#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

class Volume {
   public:
      Volume(double liters = 0.0, double milliliters = 0.0);
      void Print() const;
      Volume operator-(Volume rhs);
      Volume operator-(double rhs);
   private:
      double numLiters;
      double numMilliliters;
};

Volume::Volume(double liters, double milliliters) {
   numLiters = liters;
   numMilliliters = milliliters;
}

// No need to accommodate for overflow or negative values

Volume Volume::operator-(Volume rhs) {
    Volume total;

    total.numLiters = numLiters - rhs.numLiters;
    total.numMilliliters = numMilliliters - rhs.numMilliliters;

    return total;
}

Volume Volume::operator-(double rhs) {
    Volume Total;

    Total.numLiters = numLiters - rhs;
    Total.numMilliliters = numMilliliters;

    return Total;
}

void Volume::Print() const {
   cout << numLiters << " liters, " << numMilliliters << " milliliters";
}

int main() {
   double liters1;
	double milliliters1;
	double liters2;
	double milliliters2;
   
   cin >> liters1;
	cin >> milliliters1;
	cin >> liters2;
	cin >> milliliters2;
   
   Volume volume1(liters1, milliliters1);
   Volume volume2(liters2, milliliters2);
   
   Volume difference1 = volume1 - volume2;
   Volume difference2 = volume1 - liters2;
   
   volume1.Print();
	cout << endl;
	volume2.Print();
	cout << endl;
	cout << "Difference: ";
	difference1.Print();
	cout << endl;
   
   cout << endl;
   
   volume1.Print();
	cout << endl;
	cout << liters2 << " liters" << endl;
	cout << "Difference: ";
	difference2.Print();
	cout << endl;
   
   return 0;
}