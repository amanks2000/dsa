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

Node *appendLastNToFirst(Node *head, int n)
{
    int count = 1;
    Node *tail = head;
    while (tail->next != NULL) {
        count++;
        tail = tail->next;
    }
    if (count <= n)
        return head;
    tail->next = head;
    int x = count - n;
    count = 0;
    Node *temp = head;
    while (count < x-1) {
        temp = temp -> next;
        count++;
    }
    head = temp -> next;
    temp -> next = NULL;
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
    int n;
    cin >> n;
    head = appendLastNToFirst(head,n);
    cout << "After Appending last " << n << " values at Front" << endl;
    print(head);
    return 0;
}