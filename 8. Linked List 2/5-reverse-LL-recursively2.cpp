#include<iostream>
using namespace std;

class Node 
{
public :
    int data;
    Node *next;

    Node (int num) {
        data = num;
        next = NULL;
    }
};

// Whenever we need to return multiple parameters from a function, we just need
// to create a class and return the object of that class
// In this case we want to return the head and tail of the reversed linked list
class Pair 
{
    public :
    Node *head;
    Node *tail;
};


Node* takeInput () {
    Node *head = NULL;
    Node *tail = NULL;
    int data;
    cin >> data;
    while (data != -1) {
        Node *newNode = new Node (data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        }
        else {
            tail -> next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;
    cout << "Linked List:";
    while (temp != NULL) {
        cout << "->" << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

// Time complexity is O(n)
Pair reverseLL(Node *head) {
    if (head == NULL || head -> next == NULL) {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair small = reverseLL(head->next);

    small.tail -> next = head;
    head -> next = NULL;
    small.tail = head;
    return small;
}

int main()
{
    Node *head = takeInput();
    print(head);
    Pair ans = reverseLL(head); // copy constructor
    cout << "\nAfter Reversing using Recursion" << endl;
    print(ans.head);
    return 0;
}