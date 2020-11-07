#include <iostream>

using namespace std;

/*
-Hierarchical Enheritance:
In this type of inheritance, more than one sub class is inherited from a single base class i.e more than one derived class
is created from a single base class.
*/

//Base class
class Vehicle
{
    public:
    Vehicle()
    {
        cout << "This is a vehicle" << endl;
    }
};

//First Subclass
class Car : public Vehicle
{

};

//Second Subclass
class Bus : public Vehicle
{

};

int main()
{
    //Creating object of a subclass will invoke the constructor of the base class
    Car obj1;
    Bus obj2;
    
    return 0;
}