#include <iostream>
#include <iomanip>
using namespace std;

class SoundWave {
   public:
      SoundWave();
      void Read();
      void Print();
      ~SoundWave();
   private:
      double power;
      double distance;
};
SoundWave::SoundWave() {
   power = 0.0;
   distance = 0.0;
}
void SoundWave::Read() {
   cin >> power;
   cin >> distance;
}  
void SoundWave::Print() {
   cout << "SoundWave's power: " << fixed << setprecision(1) << power << endl;
   cout << "SoundWave's distance: " << fixed << setprecision(1) << distance << endl;
}  
SoundWave::~SoundWave() { // Covered in section on Destructors.
   cout << "SoundWave with power " << power << " and distance " << distance << " is deallocated." <<  endl;
}

int main() {
   SoundWave* mySoundWave = nullptr;
   
   mySoundWave = new SoundWave();
   mySoundWave->Read();
   mySoundWave->Print();
   mySoundWave->~SoundWave();

   return 0;
}