#include<iostream>
using namespace std;

int main()
{
    int a[] = {1,2,3};
    char s[] = "abc";
    cout << a << endl; // This prints the address of the first index of array a
    cout << s << endl; // This prints the entire content of character array s

    char *str = &s[0];
    cout << str << endl; // This also prints the entire content of character array s
                         // 'char *str' is similar to 'char str[]'
    char ch = 'a';
    char *c = &ch;
    cout << ch << endl;
    cout << c << endl; //In this case when the pointer is pointing only to a 
                       //single character, here the compiler prints garbage values after
                       //the given character until it finds a null character '\0'
    
    return 0;
}