#include <iostream>
using namespace std;

template<typename TheType>
class TripleItem {
    public:
        TripleItem(TheType val1 = 0, TheType val2 = 0, TheType val3 = 0);
        void PrintAll() const;
        TheType MinItem() const;
    private:
        TheType item1;
        TheType item2;
        TheType item3;
};

template<typename TheType>
TripleItem<TheType>::TripleItem(TheType i1, TheType i2, TheType i3) {
    item1 = i1;
    item2 = i2;
    item3 = i3;
}

template<typename TheType>
void TripleItem<TheType>::PrintAll() const {
    cout << "(" << item1 << "," << item2
         << "," << item3 << ")" << endl;
}

template<typename TheType>
TheType TripleItem<TheType>::MinItem() const {
    TheType minVal = item1;

    if (item2 < minVal)
        minVal = item2;
    if (item3 < minVal)
        minVal = item3;
    
    return minVal;
}

int main() {
    TripleItem<int> triInts(9999, 5555, 6666);
    TripleItem<short> triShorts(99, 55, 66);
    TripleItem<string> triString("SSZ", "ZZA", "AAA");

    triInts.PrintAll();
    cout << "Min: " << triInts.MinItem() << endl << endl;

    triShorts.PrintAll();
    cout << "Min: " << triShorts.MinItem() << endl << endl;

    triString.PrintAll();
    cout << "Min: " << triString.MinItem() << endl << endl;

    return 0;
}

// *vector = class template, so vector declaration is vector<int> ...