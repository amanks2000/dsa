#include<iostream>
using namespace std;

class Node 
{
public :
    int data;
    Node *next;

    Node (int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

Node* takeInput() {
    Node *head = NULL;
    Node *tail = NULL;
    int data;
    cin >> data;
    while (data != -1) {
        Node *newnode = new Node (data);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        }
        else {
            tail -> next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

Node *removeDuplicates(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    while (temp != NULL && temp->next != NULL) {
        if ((temp->data)==(temp->next)->data) {
            Node *a = temp->next;
            temp -> next = a -> next;
            delete a;
        }
        else 
            temp = temp->next;
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

int main()
{
    Node *head = takeInput();
    print(head);
    head = removeDuplicates(head);
    cout << "After removing Duplicates" << endl;
    print(head);
    return 0;
}