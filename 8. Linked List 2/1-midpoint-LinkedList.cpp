#include<iostream>
using namespace std;

class Node 
{
public :
    int data;
    Node *next;

    Node(int num) {
        data = num;
        next = NULL;
    }
};

Node* takeInput () {
    Node *head = NULL, *tail = NULL;
    int data;
    cin >> data;
    while (data != -1) {
        Node *newnode = new Node(data);
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

Node* midpoint (Node *head) {
    Node *slow = head;
    Node *fast = head -> next;
    while (fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }
    return slow;
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
    Node *mid = midpoint(head);
    cout << "Mid point of Linked list = " << mid->data << endl;
    return 0;
}