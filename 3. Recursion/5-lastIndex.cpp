// Program to display the Last index of the given numbers
// 2 4 2 3 2 3, x = 3, Last Index of x is 5
#include<iostream>
using namespace std;

int last (int input[], int size, int x) {
    if(size == 0)
        return -1;
    if(input[size-1] == x)
        return (size-1);
    else {
        int ans = last(input,size-1,x);
        return ans;
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
    cout << "Last Index of "<<x<<" is: "<<last(arr,n,x)<<endl;
    return 0;
}