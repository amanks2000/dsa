#include<iostream>
using namespace std;

int main()
{
    int i = 10;
    int *p = &i; //pointers stores the address of a variable

    //By using pointer we can say *p is equivalent to i
    //Remember: p stores the adress whereas *p stores the value of the variable.

    cout << p << endl;
    cout << *p << endl; //here '*' is a deference operator used to point at the contents of i

    float f = 9.33;
    float *pf = &f;

    cout << pf << endl; // address is same for any data type (float,int,char, etc.)
    cout << *pf << endl; 

    cout << sizeof(pf) << endl; //size of pointer is same for all data types
    return 0;
}