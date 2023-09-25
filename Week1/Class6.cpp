#include <iostream>
using namespace std;

class Pig {
   public:
      Pig();
      void Read();
      void Print();
      ~Pig();
   private:
      int age;
      int weight;
};
Pig::Pig() {
   age = 0;
   weight = 0;
}
void Pig::Read() {
   cin >> age;
   cin >> weight;
}
void Pig::Print() {
   cout << "Pig's age: " << age << endl;
   cout << "Pig's weight: " << weight << endl;
}
Pig::~Pig() { // Covered in section on Destructors.
   cout << "Pig with age " << age << " and weight " << weight << " is deallocated." <<  endl;
}

int main() {
   Pig* myPigs = nullptr;
   int count;
   int i;
   
   cin >> count;
   myPigs = new Pig[count];
   
   for(i = 0; i < count; i++) {
      myPigs[i].Read();
      myPigs[i].Print();
   }
   
   delete[] myPigs;
  
   return 0;
}