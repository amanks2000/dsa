#include <iostream>
using namespace std;

void print(int num, string output)
{
    string key[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    if (num == 0)
    {
        cout << output << endl;
        return;
    }
    int tot = 1, temp = num;
    while (temp > 9)
    {
        temp /= 10;
        tot *= 10;
    }
    int first = temp;
    //int last = num % 10;
    for (int i = 0; i < key[first].size(); i++)
    {
        print(num % tot, output + key[first].at(i));
    }
}

void printKeypad(int num)
{
    string output = "";
    print(num, output);
}

int main()
{
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
