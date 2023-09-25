#include <iostream>
using namespace std;

class IntNode {
    public:
        IntNode(int value) {
            numVal = value;
        }
        void SetNumVal(int val) { numVal = val; }
        int GetNumVal() { return numVal; }
        void Address() { cout << &numVal << endl; }
    private:
        int numVal;
};

void classAddress(IntNode node) { cout << &node << endl; }
void classAddress2(IntNode& node) { cout << &node << endl; }

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

    classAddress2(node1);
    classAddress2(node2);
    classAddress2(node3);

    return 0;
}

/*


*/