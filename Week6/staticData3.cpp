// The code for the test private static data member
#include <iostream>
using namespace std;

class Store {
    public:
        Store(string storeName, string storeType);
        int getId();
        static int getNextId();
        
    private:
        string name = "None";
        string type = "None";
        int id = 0;
        static int nextId;
};

Store::Store(string storeName, string storeType) {
    name = storeName;
    type = storeType;
    id = nextId;    // Assign object id with nextId

    ++nextId;
}

int Store::nextId = 101;

int Store::getNextId() {
    return nextId;
}

int Store::getId() {
    return id;
}

// int Store::nextId = 101; // Define and initialize static data member

int main() {
    Store store1("Macy's", "Department");
    Store store2("Albertsons", "Grocery");
    Store store3("Ace", "Hardware");

    cout << "Store 1's ID: " << store1.getId() << endl;
    cout << "Store 2's ID: " << store2.getId() << endl;
    cout << "Store 3's ID: " << store3.getId() << endl;
//    cout << "Next ID: " << Store::nextId << endl; // Can't access to private data
    cout << "Next ID: " << Store::getNextId() << endl;

    return 0;
}