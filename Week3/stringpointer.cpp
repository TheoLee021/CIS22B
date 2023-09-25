#include <iostream>
using namespace std;

int main() {
    char string1[10] = "abcxyz";
    char* subStr = nullptr;

    subStr = &string1[3];

    cout << subStr << endl;

    return 0;
}