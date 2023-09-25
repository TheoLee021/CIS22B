#include <iostream>
#include <string>
using namespace std;

class Player {
    public:
        Player();
        Player(string IpName, int IpScore) {
            name = new string(IpName);
            score = new int(IpScore);
        }
        ~Player() {
            cout << "delete " << this << endl;
            delete name;
            delete score;
        }
        Player& operator=(const Player& objToCopy);

        void setName(string IpName) { *name = IpName; }
        void setScore(int IpScore) { *score = IpScore; }
        string getName() { return *name; }
        int getScore() { return *score; }

        // copy constructor
        Player(const Player& origObj) {
            name = new string;
            *name = *(origObj.name);
            score = new int;
            *score = *(origObj.score);
        }

        void print() {
            cout << *name << " " << *score << endl;
        }
    private:
        string* name;
        int* score;
};

// copy Assingment Operator
Player& Player::operator=(const Player& objToCopy) {
    if (this != &objToCopy) {
        delete name;
        delete score;
        name = new string;
        score = new int;
        *name = *(objToCopy.name);
        *score = *(objToCopy.score);
    }

    return *this;
}

int main() {
    Player player1("Theo", 99);
    Player player2("Que", 82);
    Player player3("Kay", 76);

    player2 = player3;

    player1.print();
    player2.print();
    player3.print();

    player3.setName("T");
    player3.setScore(89);

    player1.print();
    player2.print();
    player3.print();

    return 0;
}