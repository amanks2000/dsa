// Program to display the first index of the given numbers
// 2 4 2 3 2 3, x = 3, First Index of x is 3
#include<iostream>
using namespace std;

int first(int input[], int size, int x) {
    if(size == 0)
        return -1;
    if(input[0] == x)
        return 0;
    else {
        int ans = first(input+1,size-1,x);
        if(ans==-1) 
            return ans;
        else
            return ans+1;
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    int x;
    cin >> x;
    cout << "First Index of "<<x<<" is: "<<first(arr,n,x)<<endl;
    return 0;
}