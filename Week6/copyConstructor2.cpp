#include <iostream>
using namespace std;

class IntNode {
    public:
        IntNode(int value) {
            numVal = new int;
            *numVal = value;
        }
        IntNode(const IntNode& origObject) {
            cout << "Copying " << *(origObject.numVal) << endl;
            numVal = new int;
            *numVal = *(origObject.numVal);
        }
        ~IntNode() {
            cout << "Deleting" << endl;
            delete numVal;
        }
        void SetNumVal(int val) { *numVal = val; }
        int GetNumVal() { return *numVal; }
        void Address() { cout << &numVal << endl; }
    private:
        int* numVal;
};

void ClassAddress(const IntNode nodetest) { cout << &nodetest << endl;}

int main() {
    cout << "Code Start" << endl << endl;
    IntNode node1(1);
    IntNode node2 = node1;
    IntNode node3(3);

    node1.SetNumVal(5);
    cout << node2.GetNumVal() << " " << node1.GetNumVal() << endl;

    node1.Address();
    node2.Address();
    node3.Address();
    ClassAddress(node1);
    ClassAddress(node2);
    ClassAddress(node3);

    return 0;
}

/*

*/