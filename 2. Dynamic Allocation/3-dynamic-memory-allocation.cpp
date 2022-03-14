#include<iostream>
using namespace std;

int main()
{
    int i = 10; // static memory allocation
                // memory allocated in stack
    int *p = new int;// 'new' keyword returns an address
                     // memory allocated in heap and its address stored in pointer
                     // size of heap is large so it is used for dynamic allocation
    *p = 10;
    cout << *p << endl;
    delete p; // memory in heap need to be freed manually
              // unlike stack where the data is itself removed after its scope
    /**** Dynamic Memmory Allocation in Array ****/
    int *p_arr1 = new int[50];
    int n;
    cin >> n;
    int *p_arr2 = new int [n];
    delete [] p_arr1; //syntax for freeing array memory in heap
    delete [] p_arr2;
    return 0;
}