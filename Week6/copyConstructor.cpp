#include <iostream>
using namespace std;

class IntNode {
    public:
        IntNode(int value) {
            numVal = new int;
            *numVal = value;
        }
        void SetNumVal(int val) { *numVal = val; }
        int GetNumVal() { return *numVal; }
        void Address() { cout << &numVal << endl; }
    private:
        int* numVal;
};

void classAddress(IntNode node) { cout << &node << endl;}

int main() {
    IntNode node1(1);
    IntNode node2(2);
    IntNode node3(3);

    node1 = node3;
    node3.SetNumVal(8);

    cout << node1.GetNumVal() << " " << node2.GetNumVal() << " " << node3.GetNumVal() << endl;

    node1.Address();
    node2.Address();
    node3.Address();

    classAddress(node1);
    classAddress(node2);
    classAddress(node3);

    return 0;
}

/*
8 8

Copy Construtor 사용시 Node1의 값이 node3의 값의 변화에 따라 달라짐

When normally declare class, not working like this.

pointer, New 개념이 잘이해가 안된듯 복습필요.
*/