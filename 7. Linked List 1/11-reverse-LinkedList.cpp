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

void printReverse(Node *head)
{
    while (head->next != NULL) {
        Node *temp1 = head ,*temp2 = temp1->next;
        while (temp2->next != NULL) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        cout << temp2->data << " ";
        temp1->next = NULL;
        delete temp2;
    }
    cout << head->data;
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
    cout << "After Reversing" << endl;
    printReverse(head);
    return 0;
}