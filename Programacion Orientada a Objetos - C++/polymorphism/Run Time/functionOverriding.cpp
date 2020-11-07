#include <iostream>

using namespace std;

/*
-Function overrinding:
On the other hand occurs when a derived class has a definition for one of the member functions of the
base class. That base function is said to be overriden.
*/

class Base 
{
    public:
    virtual void print()
    {
        cout << "Print base class" << endl;
    }

    void show()
    {
        cout << "Show base class" << endl;
    }
};

class Derived : public Base
{
    public:

    //Print() is already virtual function in derived class, we could also declared as virtual void print() explicitly
    void print()
    {
        cout << "Print derived class" << endl;
    }

    void show()
    {
        cout << "Show derived class" << endl;
    }
};

int main()
{
    Base *bptr;
    Derived d;
    bptr = &d;

    //Virtual function, binded at runtime (Runtime polymorphism)
    bptr->print();

    //Non-virtual function, binded at compile time
    bptr->show();
    
    return 0;
}