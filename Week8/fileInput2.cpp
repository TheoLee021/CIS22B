// file indicator 같은 프로그램, 파일 안에 있는 int 데이터를 보여줌

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream inFS;
    int fileNum;

    cout << "Opening file myfile.txt." << endl;
    inFS.open("myfile.txt");

    if(!inFS.is_open()) {
        cout << "Could not open file myfile.txt." << endl;
        return 1;
    }

    cout << "Reading and printing numbers." << endl;

    inFS >> fileNum;
    while (!inFS.fail()) {
        cout << "num: " << fileNum << endl;
        inFS >> fileNum;
    }
    if (!inFS.eof()) {
        cout << "Input failure before reaching end of file." << endl;
    }

    cout << "Closing file myfile.txt." << endl;

    inFS.close();

    return 0;
}