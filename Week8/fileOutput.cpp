#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFS;
    outFS.open("helloWorld.txt");

    if (!outFS.is_open()) {
        cout << "Could not open file helloWorld.txt." << endl;
        return 1;
    }

    outFS << "Hello" << endl;
    outFS << "1 2 3" << endl;
    outFS << "World" << endl;

    outFS.close();

    return 0;
}