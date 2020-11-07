#include <iostream>

using namespace std;

/*
-Single inheritance:
In single inheritance, a class is allowed to inherit from only one class i.e. one sub class is inherited by one base class only.
*/

//Base class
class Vechicle
{
    public:
    Vechicle()
    {
        cout << "This is a Vehicle" << endl;
    }
};

//Subclass derived from one base class
class Car: public Vechicle
{

};

int main()
{
    //Creating object of Subclass will invoke the constructor of base class
    Car obj;

    return 0;
}