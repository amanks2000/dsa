// Using overloading to increment fraction by 1

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
    // Pre-increment ++i operator overloading function:
    Fraction operator++()
    {
        numerator = numerator + denominator;
        simplify();
        return *this; // 'this' is the pointer of the given object
    }
    // Post-increment ++i operator overloading function:
    Fraction operator++(int)
    {
        Fraction fnew(numerator,denominator);
        numerator = numerator + denominator;
        simplify();
        fnew.simplify();
        return fnew; // 'this' is the pointer of the given object
    }

    void print()
    {
        cout << numerator << "/" << denominator << endl;
    }
};

int main()
{
    Fraction f1(10, 2);
    f1.print();
    //++f1; --> Pre-increment operator overloading
    //f1.print();
    Fraction f2 = ++f1;
    f2.print();
    Fraction f3 = ++(++f1);
    f1.print(); // f1 increments only 1 time as after incrementing once
                // the function returns a fraction which is stored in a buffer
                // for next increment, thus it doesn't affect f1.
    f3.print();
    return 0;
}