#include <iostream>
#include <queue>
using namespace std;

class WaitingLine {
    public:
        WaitingLine& operator<<(const string& name) {
            line.push(name);

            cout << name << " enters the back of the line" << endl;

            return *this;
        }

        WaitingLine& operator>>(string& frontName) {
            frontName = line.front();
            line.pop();

            return *this;
        }
        friend ostream& operator<<(ostream& out, const WaitingLine& line) {
            out << "(front)";
            queue<string> lineCopy = line.line;
            while (!lineCopy.empty()) {
                string lineItem = lineCopy.front();
                lineCopy.pop();
                out << " " << lineItem;
            }
            out << " (back)";
            return out;
        }
        friend istream& operator>>(istream& in, WaitingLine& line) {
            string inString;
            in >> inString;
            line << inString;
            return in;
        }

        queue<string> line;
};