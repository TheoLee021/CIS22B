#include <iostream>
using namespace std;

int main() {
   int* numItemsPointer;
   int numItems;

   cin >> numItems;

   if (numItems < 0 ) {
      numItemsPointer = nullptr;
   }
   else {
      numItemsPointer = &numItems;
      *numItemsPointer = numItems*10;
   }

   if (numItemsPointer == nullptr) {
      cout << "Items is negative" << endl;
   }
   else {
      cout << "Items: " << *numItemsPointer << endl;
   }

   cout << &numItems << endl;
   cout << &numItemsPointer << endl;

   return 0;
}