#include <iostream>
using namespace std;

class Dalmatian {
    public:
        Dalmatian() {

        }
};

int main(){
    Dalmatian* dogs = new Dalmatian[101];

    delete[] dogs;

    return 0;
}