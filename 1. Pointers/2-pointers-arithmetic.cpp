#include<iostream>
using namespace std;

int main()
{
    int i = 10;
    int *p = &i;
    cout << (int)p << endl;

    p = p + 1; // this operation makes the pointer p point at the next address
               // with respect to the data type          
    cout << (int)p << endl; // stores the next int address i.e, previous address + 4
                            // 4 being the size of data type int.

    p = p - 3;
    cout << (int)p << endl;
    return 0;
}