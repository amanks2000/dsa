#include <iostream>
using namespace std;

int keypad(int num, string output[])
{
    string key[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    if (num == 0)
    {
        output[0] = "";
        return 1;
    }
    int tot = 1, temp = num;
    while (temp > 9)
    {
        temp /= 10;
        tot *= 10;
    }
    int first = temp;
    int smallSize = keypad(num % tot, output);
    int count = key[first].size();
    for (int i = count - 1; i >= 0; i--)
    {
        for (int j = 0; j < smallSize; j++)
        {
            output[j + (i * smallSize)] = key[first].at(i) + output[j];
        }
    }
    return count * smallSize;
}

int main()
{
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for (int i = 0; i < count && i < 10000; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}