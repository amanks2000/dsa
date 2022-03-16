/*
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
*/
#include<iostream>
using namespace std;
int strsize(char s[]){
    int count=0,i=0;
    while(s[i]!='\0'){
        count++;
        i++;
    }
    return count;
}

bool checkAB(char input[]) {
    if(input[0]=='\0')
        return true;
    if(input[0]=='a')
    {
        if((strsize(input+1)>1)&&(input[1]=='b' && input[2]=='b'))
            return checkAB(input+3);
        else 
            return checkAB(input+1);
    }
    return false;
}

int main() {
    char input[100];
    bool ans;
    cin >> input;
    ans=checkAB(input);
    if(ans)
        cout<< "true" << endl;
    else
        cout<< "false" << endl;
    return 0;
}
