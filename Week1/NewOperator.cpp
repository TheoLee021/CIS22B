#include <iostream>
using namespace std;

class Point {
public:
    Point();

    double X;
    double Y;
};

Point::Point() {
    cout << "In Point default constructor" << endl;

    X = 0;
    Y = 0;
}

int main()
{
    Point* sample = new Point;
    cout << "Exiting main()" << endl;
    return 0;
}