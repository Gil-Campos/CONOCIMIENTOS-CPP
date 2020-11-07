#include <iostream>

using namespace std;

/*
-Multiple inheritance:
Multiple inheritance is a feature of C++ where a class can inherit from more than one classes i.e one Subclass is inherited
from more than one base classes.
*/

//First base class
class Vehicle 
{
    public:
    Vehicle()
    {
        cout << "This is a vehicle" << endl;
    }
};

//Second base class
class FourWheeler
{
    public:
    FourWheeler()
    {
        cout << "This is a 4 wheeler Vehicle" << endl;
    }
};

//Subclass derived from two base classes
class Car: public Vehicle, public FourWheeler
{

};

int main()
{
    //Creating object of subclass will invoke the constructor of base classes
    Car obj;
    
    return 0;
}