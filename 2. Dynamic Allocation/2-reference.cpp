#include<iostream>
using namespace std;

void increment (int& n) //here 'n' is a refernce variable of 'k' in main function
{
    n++; //changes made to n would be seen in k as well in main function
}

int main()
{
    int i = 10;
    int& j = i; // This makes 'j' a refernce variable of 'i'
                // changes made to i would be seen in j and vise versa
                // refernce variable j and i have same memorey and address
    i++;
    cout << j << endl;
    j++;
    cout << i << endl;
    cout<<endl;

    int k = 20;
    cout << k << endl;
    increment(k); // pass by reference function
    cout << k << endl;
    return 0;
}