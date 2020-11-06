#include <iostream>

using namespace std;

class Geeks
{
    public:
    string geekName;
    int id;

    //printName is not defined inside class definition
    void printName();

    //printID is defined inside class definition
    void printID()
    {
        cout << "Geek id is: " << id;
    }
};

//Definition of printName using scope resolution operator ::
void Geeks::printName()
{
    cout << "Geek name is: " << geekName;
}

int main()
{
    Geeks obj1;
    obj1.geekName = "User 2040";
    obj1.id = 15;

    //Call printName()
    obj1.printName();
    cout << endl;

    //Call printID()
    obj1.printID();
    
    return 0;
}