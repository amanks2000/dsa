#include<iostream>
using namespace std;

int main()
{
    string s = "abc";
    cout << s << endl;
    // string can be treated like a character array :
    cout << s[0] << endl; // prints the 0th index of character array s

    string *str = new string; // dynamically creating a string
    *str = "def";
    cout << str << endl;  // address of the string
    cout << *str << endl; // the actual string

    string str2;
    getline(cin,str2); // to take an input which includes space
    cout << str2 << endl; 

    // multiple strings can also be added to a single string (concatenation)
    string str3 = *str + str2;
    cout << str3 << endl;

    // we can use size() function to get size of any string directly
    cout << str3.size() << endl;

    // we can get a substring of the string from a given index
    cout << str3.substr(5) << endl; 

    // we can get a substring of the string from a given index to a given length
    cout << str3.substr(5,3) << endl; 

    // we can use find() function to find the index of a given substring in the string
    cout << str3.find("coding") << endl; 
    return 0;
}