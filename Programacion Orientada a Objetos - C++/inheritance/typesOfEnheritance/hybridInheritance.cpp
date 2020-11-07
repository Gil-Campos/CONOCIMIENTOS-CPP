#include <iostream>

using namespace std;

/*
-Hybrid (Virtual) Inheritance:
Hybrid Inheritance is implemented by combining more than one type of inheritance. For example:
Combining Hierarchical and Multiple Inheritance.
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

//Base class
class Fare
{
    public:
    Fare()
    {
        cout << "Fare of Vehicle" << endl;
    }
};

//First subclass
class Car : public Vehicle
{

};

//Second subclass
class Bus : public Vehicle, public Fare
{

};

int main()
{

    //Creating a object of subclass will invoke the constructor of the base class
    Bus obj2;
    
    return 0;
}