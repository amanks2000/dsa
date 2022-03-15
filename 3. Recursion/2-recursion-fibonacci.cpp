// 0 1 1 2 3 5 8 13 21 34 ..... 
// Code to find nth Fibonacci Number. 
// Here 0th number = 0, 1st number = 1, 2nd number = 1, 3rd number = 2..
// Fib(n) = Fib(n-1) + Fib(n-2)
#include <iostream>
using namespace std;

int fib (int n)
{
    if(n==0) // Base Conditon 1 for fib(n-1)
        return 0;
    if (n==1) // Base Conditon 2 for fib(n-2) otherwise fib(1) calls fib(-1) i.e, wrong
        return 1;
    int small1 = fib(n-1);
    int small2 = fib(n-2);
    return small1 + small2;
}
int main()
{
    int n = 7;
    cout << fib(n) << endl;
    return 0;
}