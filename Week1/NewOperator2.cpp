#include <iostream>
using namespace std;

class Point {
public:
    Point(double xValue = 0, double yValue = 0);
    void Print();

    double X;
    double Y;
};

Point::Point(double xValue, double yValue) {
    X = xValue;
    Y = yValue;
}

void Point::Print() {
    cout << "(" << X << ", ";
    cout << Y << ")" << endl;
}

int main() {
    Point* point1 = new Point;
    (*point1).Print();

    Point* point2 = new Point(8, 9);
    (*point2).Print();

    return 0;
}