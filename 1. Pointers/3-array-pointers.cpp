#include<iostream>
using namespace std;

int main()
{
    int a[10]; 
    // Here 'a' behaves like a pointer which stores the address of the first array element
    cout << a << endl; 
    cout << &a[0] << endl;

    a[0] = 10;
    a[1] = 16;
    cout << *a << endl; //points to first element of array at index 0
    cout << *(a+1) << endl; //points to second element of array at index 1
    // a[i] is effectively *(a + i)

    int i = 1;
    cout << i[a] << endl; //Fun Fact: This is effectively *(i + a) which is same as *(a + i)
                          //Therefore value of i[a] is same as a[i]
    
    /************* Difference Between Arrays and Pointers *************/
    int *p = &a[0];
    cout << a << endl;
    cout << p << endl; // both a and p  stores the address of the first element of array a
    cout << endl;
    /*A pointer stores the address of a variable while it itself is stored in a container 
    which has a specific different address to the variable it points to.
    Whereas in case of array it doesn't store the address at someplace different than the 
    address it points to*/
    cout << a << endl;
    cout << &a << endl; //a and &a have the same address 
    cout << &p << endl; //a and &p have different address
    
    return 0;
}