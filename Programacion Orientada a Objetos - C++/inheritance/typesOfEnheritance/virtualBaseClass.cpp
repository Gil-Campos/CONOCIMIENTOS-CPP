#include <iostream>

using namespace std;

class ClassA 
{
    public:
    int a;
};

class ClassB : virtual public ClassA
{
    public:
    int b;
};

class ClassC : virtual public ClassA
{
    public:
    int c;
};

class ClassD : public ClassB, public ClassC
{
    public:
    int d;
}; 

int main()
{
    ClassD obj;

    obj.a = 10;
    obj.a = 100;

    obj.b = 20;
    obj.c = 30;
    obj.d = 40;

    cout << "A : "<< obj.a << endl;
    cout << "B : "<< obj.b << endl;
    cout << "C : "<< obj.c << endl;
    cout << "D : "<< obj.d << endl;

    return 0;
};