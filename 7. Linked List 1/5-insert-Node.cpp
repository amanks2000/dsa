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

Node* insertElement (Node *head, int i, int data) {
    Node *newNode = new Node (data);
    Node *temp = head;
    int count = 0;
    if (i == 0) {
        newNode -> next = head;
        head = newNode;
        temp = newNode;
    }
    else {
        while (temp != NULL && count < i-1) {
            count++;
            temp = temp->next;
        }
        if (temp == NULL)
        
    newNode -> next = temp -> next;
    temp -> next = newNode;
    }
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
    head = insertElement(head,0,100);
    cout << "After Inserting Element" << endl;
    print(head);
    return 0;
}