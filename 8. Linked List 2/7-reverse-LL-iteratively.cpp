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

Node *reverseLinkedList(Node *head) {
    if (head == NULL || head -> next == NULL)
        return head;
    Node *c = head;
    Node *prev = NULL, *n = c -> next;
    while (c != NULL) {
        c -> next = prev;
        prev = c;
        c = n;
        if (n != NULL)
            n = n -> next;
    }
    return prev;
}

int main()
{
    Node *head = takeInput();
    print(head);
    head = reverseLinkedList(head);
    cout << "\nAfter Reversing using Iteration" << endl;
    print(head);
    return 0;
}