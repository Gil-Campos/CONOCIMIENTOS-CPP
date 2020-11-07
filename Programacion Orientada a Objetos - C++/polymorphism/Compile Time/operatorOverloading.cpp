#include <iostream>

using namespace std;

/*
-Operator Overloading:
C++ also provides option to overload operators. For example, we can make the operator ('+') for string
class to concatenate two strings. We know that this is the addition operator whose task is to add to operands. So a single
operator '+' when placed between two integers operands, add them and when placed between string operands, concatenates them.
*/

class Complex
{
    private:
    int real, imag;

    public:
    Complex(int r = 0, int i = 0)
    {
        real = r;
        imag = i;
    }

    //This is automatically called when '+' is used with between two complex objects
    Complex operator + (Complex const &obj)
    {
        Complex res;
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }

    void print()
    {
        cout << real << " + i" << imag << endl;
    }
};

int main()
{
    Complex c1(10, 5), c2(2, 4);
    Complex c3 = c1 + c2; //An example call to "operator+"
    c3.print();
    
    return 0;
}