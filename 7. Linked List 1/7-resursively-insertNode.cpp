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

// Recursively inserting a Node to Linked List
Node* insertNode(Node *head, int i, int data) {
    if (head == NULL)
        return head;
    if (i==0) {
        Node *newNode = new Node (data);
        newNode->next = head;
        head = newNode;
        return head;
    }
    Node *small = insertNode(head->next,i-1,data); 
    head -> next = small;
    return head;
}

void print (Node *head) {
    Node *temp = head;
    cout << "Linked List:";
    while (temp != NULL) {
        cout << "->" << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = takeInput();
    print(head);
    head = insertNode(head,2,100);
    cout << "After Insertion" << endl;
    print(head);
    return 0;
}