#include<iostream>
using namespace std;

class ComplexNumbers {
    int real,imag;
    public : 
    ComplexNumbers(int x,int y)
    {
        real=x;
        imag=y;
    }
    void plus (ComplexNumbers c2)
    {
        this->real += c2.real;
        this->imag += c2.imag;
    }
    void multiply (ComplexNumbers c2)
    {
        int a = this->real, b = this->imag;
        int c = c2.real, d = c2.imag;
        this->real = (a*c)-(b*d);
        this->imag = (a*d)+(b*c);
    }
    void print ()
    {
        if(imag>=0)
            cout << real << " + i" << imag;
        else{
            cout << real << " - i" << (imag*-1);
        }
    }
};

int main() {
    int real1, imaginary1, real2, imaginary2;
    
    cin >> real1 >> imaginary1;
    cin >> real2 >> imaginary2;
    
    ComplexNumbers c1(real1, imaginary1);
    ComplexNumbers c2(real2, imaginary2);
    
    int choice;
    cin >> choice;
    
    if(choice == 1) {
        c1.plus(c2);
        c1.print();
    }
    else if(choice == 2) {
        c1.multiply(c2);
        c1.print();
    }
    else {
        return 0;
    }
    
}