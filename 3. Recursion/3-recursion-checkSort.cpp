// Program to check if the given array is sorted (ascending order) or not using Recursion
#include<iostream>
using namespace std;

bool isSorted (int a[], int size)
{
    if(size == 0 || size == 1) // base condition
        return true;

    if (a[0] > a[1])
        return false;

    bool isSmallSorted = isSorted(a+1, size-1);

    return isSmallSorted;
    /*if(isSmallSorted)
        return true;
    else
        return false;*/
    
}

int main()
{
    int size;
    cin >> size;
    int arr[size];
    for(int i = 0;i<size;i++)
        cin >> arr[i];
    if(isSorted(arr,size))
        cout << "Array is sorted" << endl;
    else  
        cout << "Array is not sorted" << endl;
    return 0;
}