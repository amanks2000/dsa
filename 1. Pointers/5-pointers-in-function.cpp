#include<iostream>
using namespace std;

void print(int *p)
{
    cout << *p << endl;
}
void incrementPointer (int *p) //p contains the address stored by pointer ptr in main func
{
    p = p + 1; //This doesn't affect the address stored in pointer ptr
}
void increment (int *p)
{
    (*p)++; //This changes(increments) the contents of the pointed variable
}
int main()
{
    int i = 21; 
    int *ptr = &i;
    print(ptr);

    cout << ptr << endl;
    incrementPointer (ptr);
    cout << ptr << endl; // same as before no effect on pointer ptr

    cout << *ptr << endl;
    increment(ptr);
    cout << *ptr << endl; // contents of ptr is different here

    return 0;
}