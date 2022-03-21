// Using operator overloading to add 2 fractions

#include <iostream>
using namespace std;

class Fraction
{
    int numerator, denominator;

public:
    Fraction(int num, int den)
    {
        numerator = num;
        denominator = den;
    }
    void simplify()
    {
        int gcd = 1;
        int j = min(this->numerator, this->denominator);
        for (int i = 1; i <= j; i++)
        {
            if (this->numerator % i == 0 && this->denominator % i == 0)
            {
                gcd = i;
            }
        }
        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd;
    }
    // 1.Operator overloading '+' to add two objects f1 and f2
    // 2.We use a const object to avoid any changes to the object sent by user
    // 3.Since the below function does not change any property of the object which
    //   calls it, we can make it a const function (it is making a new object and
    //   returning it to main function)
    Fraction operator+(Fraction const &f2) const 
    {
        int lcm = denominator * f2.denominator;
        int x = lcm / denominator;
        int y = lcm / f2.denominator;

        int num = x * numerator + (y * f2.numerator);

        Fraction fNew(num, lcm);
        fNew.simplify();
        return fNew;
    }
    void print()
    {
        cout << numerator << "/" << denominator << endl;
    }
};

int main()
{
    Fraction f1(2,4);
    Fraction f2(8,9);
    Fraction f3 = f1 + f2; // same as Fraction f3 = f1.add(f2);
    f1.print();
    f2.print();
    f3.print();
    return 0;
}