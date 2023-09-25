#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> test(5);

    cout << test.size() << endl;

    for (int i = 0; i < test.size(); i++) {
        cout << test.at(i) << " ";
    }

    test.pop_back();

    cout << endl;

    cout << test.size() << endl;

    for (int i = 0; i < test.size(); i++) {
        cout << test.at(i) << " ";
    }    

    return 0;
}