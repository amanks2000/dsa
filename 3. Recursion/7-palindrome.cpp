// Program to check if the given string is a Palindron
// Palindrome String Example : racecar
#include <iostream>
using namespace std;
bool checkPalindrome(char input[])
{
    int size = 0, i = 0;
    while (input[i] != '\0')
    {
        size++;
        i++;
    }

    if (size > 0)
    {
        if (input[0] == input[size - 1])
            return true;
        else
            return false;

        input[size - 1] = '\0';
    }
    bool check = checkPalindrome(input + 1);
    return check;
}
int main()
{
    char str[100];
    cin >> str;
    if (checkPalindrome(str))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}