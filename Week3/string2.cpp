#include <iostream>
#include <string>
using namespace std;

int main() {
   string userString;
   
   getline(cin, userString);
   
   if (userString.at(userString.size()-1) == '!')
      cout << "An exclamation" << endl;
   else
      cout << "Not an exclamation" << endl;

   return 0;
}