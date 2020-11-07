#include <iostream>

using namespace std;

/*
-Multilevel Inheritance: 
In this type of inheritance, a derived class is created from another derived class.
*/

//Base class
class Vehicle
{
    public:
    Vehicle()
    {
        cout << "This is a Vehicle" << endl;
    }
};

class FourWheeler : public Vehicle 
{
    public:
    FourWheeler()
    {
        cout << "Objects with 4 wheels are vehicles" << endl;
    }
};

//Subclass derived from two base classes
class Car : public FourWheeler
{
    public:
    Car()
    {
        cout << "Car has 4 wheels" << endl;
    }
};

int main()
{
    //Creating a object of subclass will invoke the constructor of the base classes.
    Car obj;
    
    return 0;
}