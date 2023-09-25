#include <iostream>
#include <string>
#include<iomanip>

using namespace std;

class Demo
{
private:
    int value1;
    int value2;
public:
    Demo ();

    Demo (const int one, const int two);

    void setvalue1 (int one);

    int getvalue1 () const;

    void setvalue2 (int two);

    int getvalue2 () const;

    ~Demo()
    { };
};
int main ()
{
    Demo object1; //default constructor
    cout << object1.getvalue1() << endl;
    cout << object1.getvalue2() << endl;
    object1.setvalue1(99);
    object1.setvalue2(55);
    cout << object1.getvalue1() << endl;
    cout << object1.getvalue2() << endl;
    Demo object2(66,33); //regular constructor
    cout << object2.getvalue1() << endl;
    cout << object2.getvalue2() << endl;
    return 0;
}
Demo::Demo ()
    {
        value1 = 0;
        value2 = 0;
    }
Demo::Demo (const int one, const int two)
    {
        value1 = one;
        value2 = two;
    }
    void Demo::setvalue1 (int one)
    {
        cout << "enter an integer\n";
        cin >> one;
        value1 = one;
    }
    int Demo::getvalue1 () const
    {
        return value1;
    }
    void Demo::setvalue2 (int two)
    {
        value2 = two;
    }
    int Demo::getvalue2 () const
    {
        return value2;
    }
