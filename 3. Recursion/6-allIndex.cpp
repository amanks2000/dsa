// Program to display all indexes of the given numbers
// 2 4 2 3 2 3, x = 3, All Indexes of x is 3 5
#include<iostream>
using namespace std;

int all(int input[], int size, int x, int output[]) {
    if(size == 0)
        return 0;
    int ans = all(input+1,size-1,x,output);
    if(input[0] == x)
    {
        for(int i=0;i<ans;i++)
            output[i+1] = output[i] + 1;
        output[0]=0;
        ans++;
    }
    else
    {
        for(int i=0;i<ans;i++)
            output[i] = output[i] + 1;
    }   
    return ans;
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
    int output[n];
    cout << "All Indexes of "<<x<<" are: " << endl;
    for (int i=0; i<all(arr,n,x,output); i++)
        cout << output[i] << " ";
    cout<<endl;
    return 0;
}