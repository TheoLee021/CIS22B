// The 'this' implicit parameter

#include <iostream>
using namespace std;

class ShapeSquare {
    public:
        void SetSideLength(double sideLength);
        double GetArea() const;
    private:
        double sideLength;
};

void ShapeSquare::SetSideLength(double sideLength) {
    this->sideLength = sideLength;
    // data member      Parameter
}

double ShapeSquare::GetArea() const{
    return sideLength * sideLength; // Both refer to data member
}

int main() {
    ShapeSquare square1;

    square1.SetSideLength(1.2);
    cout << "Square's area: " << square1.GetArea() << endl;

    return 0;
}

/*
this parameter는 생략되어있다. this를 입력하지 않고 컴파일하면 컴파일러는 this를 추가하여 실행한다. 
data member와 parameter를 명확히 구분하기 위해서 사용하기도 한다.
*/