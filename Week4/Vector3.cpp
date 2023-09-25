#include <iostream>
#include <vector>
using namespace std;

int main() {
   vector<int> numberVect;
   int value;
   int i;

   cin >> value;
   while (value != -1) {
      numberVect.push_back(value);
      cin >> value;
   }

   for (i = numberVect.size(); i > -1; i--) {
      if ( numberVect.at(i) % 2 == 0 )
         cout << numberVect.at(i) << endl;
   }

   return 0;
}