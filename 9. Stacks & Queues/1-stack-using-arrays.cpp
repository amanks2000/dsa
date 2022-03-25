#include<iostream>
#include<climits>
using namespace std;

class StackUsingArrays 
{
    int *data;
    int nextIndex;
    int capacity;

    public :

    StackUsingArrays (int totSize) {
        data = new int [totSize];
        nextIndex = 0;
        capacity = totSize;
    }

    int size() {
        return nextIndex;
    }

    bool isEmpty () {
        if (nextIndex == 0)
            return true;
        return false;

        // return nextIndex == 0;
    }

    void push (int element) {
        if (nextIndex == capacity) {
            cout << "Stack is Full" << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex++;
    }

    int pop () {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        nextIndex--;
        return data[nextIndex];
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        return data[nextIndex-1];
    }

};

int main()
{
    StackUsingArrays s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

    cout << s.top() << endl;

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;

    cout << s.isEmpty() << endl;
    cout << s.top() << endl;
    cout << s.size() << endl;
    return 0;
}