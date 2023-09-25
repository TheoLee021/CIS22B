#include <iostream>
using namespace std;

class IntNode {
    public:
        IntNode(int value) {
            numVal = new int;
            *numVal = value;
        }
        ~IntNode() {
            cout << "Destructor called" << endl;
            delete numVal;
        }
        void SetNumVal(int val) { *numVal = val; }
        int GetNumVal() { return *numVal; }
        void Address() { cout << &numVal << endl; }
    private:
        int* numVal;
};

void somefuction(IntNode localNode) { }

int main() {
    IntNode node1(1);
    IntNode node2(2);
    IntNode node3(3);

    node3.SetNumVal(8);

    cout << node1.GetNumVal() << " " << node2.GetNumVal() << " " << node3.GetNumVal() << endl;

//    somefuction(node1);

//    cout << node1.GetNumVal() << endl;

    return 0;
}

/*
No errors if there is no destructor
The destructor causing errors?
What is the destructor for?
*/