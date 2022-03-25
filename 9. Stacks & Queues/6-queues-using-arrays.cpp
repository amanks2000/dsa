#include<iostream>
using namespace std;

template <typename T>

class QueuesUsingArrays
{
    T *data;
    int nextIndex;
    int firstIndex;
    int size;
    int capacity;

    public :
    QueuesUsingArrays (int s) // Constructor to give max size of the queue
    {
        data = new T[s];
        nextIndex = 0;
        firstIndex = -1;
        size = 0;
        capacity = s;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size==0;
    }

    // inserting elements
    void enqueue(T element) {
        if (size == capacity) {
            cout << "Queue Full! " << endl;
            return;
        }
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity; /* This line uses array in a circular way, Say we 
        dequeue the front element, now by using the above formula we can insert the new
        element in the starting position if the end of the linear array has arrived. */

        if (firstIndex == -1)
            firstIndex = 0;
        size++;
    }
    
    // Display front element
    T front() {
        if(isEmpty()) {
            cout << "Queue Empty!" << endl;
            return 0;
        }
        return data[firstIndex];
    }

    // deleting elements
    T dequeue() {
        if(isEmpty()) {
            cout << "Queue Empty!" << endl;
            return 0;
        }
        T ans = data[firstIndex];
        firstIndex = (firstIndex + 1) % capacity;
        size--;

        if (size == 0) {
            firstIndex = -1;
            nextIndex = 0;
        }

        return ans;
    }

};

int main()
{
    QueuesUsingArrays<int> q(5);
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    cout << q.front() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    cout << q.getSize() << endl;
    cout << q.isEmpty() << endl; // false = 0, true != 0

    return 0;
}