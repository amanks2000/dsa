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

// Recursively deleting a Node to Linked List
Node *deleteNodeRec(Node *head, int pos) {
    if (head == NULL)
        return head;
    if (pos == 0) {
        Node *a = head;
        head = a->next;
        delete a;
        return head;
    }
    Node *small = deleteNodeRec(head->next,pos-1);
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
    head = deleteNodeRec(head,2);
    cout << "After Deletion" << endl;
    print(head);
    return 0;
}