#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node<T> *next;

    Node(T num)
    {
        data = num;
        next = NULL;
    }
};

template <typename T>
class Stack
{
    Node<T> *head;
    int size = 0;

public:
    Stack()
    {
        head = NULL;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        if (head == NULL)
            return true;
        return false;
    }

    // Insertion at beginning
    void push(T element)
    {
        Node<T> *newNode = new Node<T>(element);
        newNode->next = head;
        head = newNode;
        size++;
    }

    // Deletion at beginning
    T pop()
    {
        if (isEmpty())
        {
            return 0;
        }
        T ans = head->data;
        Node<T> *temp = head;
        head = head->next;
        size--;
        delete temp;
        return ans;
    }

    T top()
    {
        if (isEmpty())
        {
            return 0;
        }
        return head->data;
    }
};

int main()
{
    Stack<int> st;

    int q;
    cin >> q;

    while (q--)
    {
        int choice, input;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cin >> input;
            st.push(input);
            break;
        case 2:
            cout << st.pop() << "\n";
            break;
        case 3:
            cout << st.top() << "\n";
            break;
        case 4:
            cout << st.getSize() << "\n";
            break;
        default:
            cout << ((st.isEmpty()) ? "true\n" : "false\n");
            break;
        }
    }
}