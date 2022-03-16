#include <iostream>
using namespace std;

int getCodes(string input, string output[10000])
{
    string abc[] = {"", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
    if (input.length() == 0){
        return 1;
    }
    if(input.size()==1)
    {
        output[0]=output[0]+abc[input[0]-'0'];
        return 1;
    }

    string out1[10000],out2[10000];
    int smallOutput1 = getCodes(input.substr(1), out1);
    int index = input.at(0) - '0';
    int smallOutput2=0;
    int index2 = stoi(input.substr(0, 2));
    if(input.length()>=2){
        if (index2 >= 10 && index2 < 27)
        {
            smallOutput2 = getCodes(input.substr(2), out2);
        }
        
    }
    for (int i = 0; i < smallOutput1; i++)
    {
        output[i] = abc[index] + out1[i];
    }
    for (int i = 0; i < smallOutput2; i++)
    {
        output[i+smallOutput1] = abc[index2] + out2[i];
    }
    return (smallOutput1 + smallOutput2);
}

int main()
{
    string input;
    cin >> input;

    string output[10000];
    int count = getCodes(input, output);
    for (int i = 0; i < count && i < 10000; i++)
        cout << output[i] << endl;
    return 0;
}
