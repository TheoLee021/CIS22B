#include <iostream>
//#include <string>
using namespace std;

int main() {
    string str = "Hello World";
    char cha[10] = "Hello";
    char cha2[10] = "Bye";

    cout << str << endl;
    cout << cha << endl;
    
    str.push_back(' ');
    str.append(cha);

    cout << str << endl;

    cha[0] = 'G';
    cout << cha << endl;

    cout << cha[10] << endl;

    for (int i=0; i < 20; i++) {
        if (cha[i] == '\0') {
            cout << i << endl;
            break;
        }
    }

    cha[5] = '!';

    for (int i=0; i < 20; i++) {
        if (cha[i] == '\0') {
            cout << i << endl;
            break;
        }
    }

//    strcat(cha, "World");
//    cout << cha << endl;

    return 0;
}