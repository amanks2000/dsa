#include<iostream>
using namespace std;

int search(int input[],int key,int first,int last)
{
    int mid = (first + last)/2;
    if(first>last)
        return -1;
    if(input[mid]==key)
        return mid;
    else if (input[mid] > key)
        return search(input,key,first,mid-1);
    else 
        return search(input,key,mid+1,last);
}

int binarySearch(int input[], int size, int element) 
{
    int index = search(input,element,0,size-1);
    return index;
}

int main() {
    int input[100000],length,element, ans;
    cin >> length;
    for(int i =0;i<length;i++)
    { 
        cin >> input[i];;
    }

    cin>>element;
    ans = binarySearch(input, length, element);
    cout<< ans << endl;
    return 0;
}
