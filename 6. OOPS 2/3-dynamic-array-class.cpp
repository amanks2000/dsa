#include<iostream>
using namespace std;

class DynamicArray {
    int *data;
    int nextIndex;
    int capacity;

    public : 
    DynamicArray() {
        data = new int[5];
        nextIndex = 0;
        capacity = 5;
    }
    void addElement (int element) {
        if(nextIndex == capacity) {
            int *newData = new int[2*capacity];
            for(int i=0;i<capacity;i++)
                newData[i] = data[i];
            delete [] data; // deleting the old array as the capacity exceeded
            data = newData; // this makes data point to the array newData
            capacity *=2;
        }
        data[nextIndex] = element;
        nextIndex++;
    }
    int getData (int i) {
        if(i < nextIndex)
            return data[i];
        else    
            return -1;
    }

    void print() {
        for(int i=0;i<nextIndex;i++)
            cout << data[i] << endl;
    }
};

int main()
{
    
    return 0;
}