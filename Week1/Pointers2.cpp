#include <iostream>
using namespace std;

int main()
{
    int* pointer;
    int num;

    pointer = &num;

    num = 5;

    cout << "*pointer = " << *pointer << endl;
    cout << "pointer = " << pointer << endl;

    return 0;
}