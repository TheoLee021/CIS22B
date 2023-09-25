#include <iostream>
#include <vector>
using namespace std;

int main() {
   int id1;
	int id2;
	int id3;
	int id4;
	unsigned int i;

   cin >> id1;
	cin >> id2;
	cin >> id3;
	cin >> id4;
	
	vector<int> idLogs(8);
   
   idLogs.at(1) = id1;
   idLogs.at(3) = id2;
   idLogs.at(5) = id3;
   idLogs.at(7) = id4;
   
   for (i = 0; i < idLogs.size(); ++i) {
      cout << idLogs.at(i) << " ";
   }
   cout << endl;
   
   return 0;
}