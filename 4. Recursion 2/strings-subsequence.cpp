// Program to print all subsequence of a string
// subsequence of string "abc" : "","a","b","c","ab","bc","ac","abc"
// Total subsequence of a string of n characters = 2^n
#include<iostream> 
using namespace std;
int subs (string input, string output[])
{
    if(input.size()==0){
        output[0] = "";
        return 1;
    }
    int smallSize = subs(input.substr(1),output);
    for(int i=0; i<smallSize; i++){
        output[i+smallSize] = input[0] + output[i];
    }
    return 2*smallSize;
}
int main()
{
    string str;
    cin >> str;
    string* output = new string[1000];
    int count = subs (str, output);
    for(int i=0;i<count;i++){
        cout << output[i] << endl;
    }
    return 0;
}