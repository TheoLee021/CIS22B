#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
   string userPassword;
   
   bool noAlphas;
   
   getline(cin, userPassword);
   
   for (int i; i < userPassword.size(); i++) {
      if (!isalpha(userPassword.at(i))){
         noAlphas = true;
         break;
      }
      else
         noAlphas = false;
   }
   
   if (noAlphas) {
      cout << "Password is valid" << endl;
   }
   else {
      cout << "Password is not valid" << endl;
   }

   return 0;
}