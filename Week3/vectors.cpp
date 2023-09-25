#include <iostream>
#include <vector>
using namespace std;

int main() {
    int nums[3];
    int numb;
    vector<int> numv(3,1); // initialized 1
    vector<int> numv2;

    numb = 1;

    nums[0] = 11;
    nums[1] = 5;
    nums[2] = 6;
    //nums[3] = 22;

    cout << "numb = " << numb << endl;
    //cout << "nums[3] = " << nums[3] << endl;
    cout << "&nums[3] = " << &nums[3] << endl;
    cout << "&nums[2] = " << &nums[2] << endl;
    cout << "&nums[1] = " << &nums[1] << endl;
    cout << "&nums[0] = " << &nums[0] << endl;
    cout << "&numb = " << &numb << endl;
    cout << "numv(0) = " << numv.at(0) << endl;
    cout << "numv(1) = " << numv.at(1) << endl;

    cout << "Array size = " << sizeof(nums) << endl;
    cout << "The vector size = " << numv.size() << endl;

    numv.at(0) = 1;
    numv[1] = 2;

    return 0;
}