#include<iostream>
using namespace std;

int main()
{
    int **p = new int*[10];  // double pointer is used to allocate 2D array dynamically
    for(int i=0;i<10;i++){
        p[i] = new int [20]; // each index of p stores the address of the rows of 2D array
    }  
    for (int i=0;i<10;i++){
        delete [] p[i];
    }
    delete [] p; 
    return 0;
}