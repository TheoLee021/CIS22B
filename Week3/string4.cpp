#include <iostream>
using namespace std;

void modify(char a[]) {
    for (int i=0; i < strlen(a); i++) {
        if (a[i] == ' ')
            a[i] = '-';
    }
}

int main() {
    char cha[20];

    cha[0] = 'H';
    cha[1] = 'E';
    cha[2] = 'L';
    cha[3] = 'L';
    cha[4] = 'O';
    cha[5] = '\0';

    for (int i=0; i < 20; i++) {
        if (cha[i] == '\0') {
            cout << i << endl;
            break;
        }
    }

    // cha[5] = '!';

    // for (int i=0; i < 20; i++) {
    //     if (cha[i] == '\0') {
    //         cout << i << endl;
    //         break;
    //     }
    // }

    // cha[15] = 'K';
    // cha[17] = 'O';

    // for (int i=0; i < 20; i++) {
    //     if (cha[i] == '\0') {
    //         cout << i << endl;
    //         break;
    //     }
    // }

    cout << cha << endl;

    cout << strchr(cha, 'L') << endl;

    int x;
    x = strlen(cha);
    cout << x << endl;

    cout << strcmp(cha, "HELLO") << endl;

    // if(cha > "Hi")
    //     cout << "Good" << endl;
    // else
    //     cout << "Fine" << endl;

    strcat(cha, " World");
    cout << cha << endl;

    // for (int i=0; i < strlen(cha); i++) {
    //     if (cha[i] == ' ')
    //         cha[i] = '_';
    // }

    modify(cha);

    cout << cha << endl;


    return 0;
}