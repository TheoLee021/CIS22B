#include <iostream>
using namespace std;

class Store {
    public:
        Store(string storeName, string storeType);
        int getId();
        static int nextId; // Declare static member variable
    private:
        string name = "None";
        string type = "None";
        int id = 0;
};

Store::Store(string storeName, string storeType) {
    name = storeName;
    type = storeType;
    id = nextId;    // Assign object id with nextId

    ++nextId;
}

int Store::getId() {
    return id;
}

int Store::nextId = 101; // Define and initialize static data member

int main() {
    Store store1("Macy's", "Department");
    Store store2("Albertsons", "Grocery");
    Store store3("Ace", "Hardware");

    cout << "Store 1's ID: " << store1.getId() << endl;
    cout << "Store 2's ID: " << store2.getId() << endl;
    cout << "Store 3's ID: " << store3.getId() << endl;
    cout << "Next ID: " << Store::nextId << endl;

    return 0;
}