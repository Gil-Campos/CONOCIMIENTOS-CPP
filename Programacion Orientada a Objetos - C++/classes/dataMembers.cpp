#include <iostream>

using namespace std;

class Geeks
{
    //Access specifier
    public:

    //Data members
    string geekName;

    //Member Functions()
    void printName()
    {
        cout << "Geekname is: " << geekName;
    } 
};

int main()
{
    //Declare an object of class geeks
    Geeks obj1;

    //Accessing data member
    obj1.geekName = "User 2020";

    //Accesing member function
    obj1.printName();

    return 0;
}