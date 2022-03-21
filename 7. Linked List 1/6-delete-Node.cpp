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

Node* deleteNode (Node *head,int i) {
    if(head==NULL)
        return head;
    Node *temp = head;
    int count = 0;
    
    if (i == 0) {
        Node *a = head;
        head = a -> next;
        delete a;
    }
    else {   
        while (temp->next != NULL && count < i-1) {
            count++;
            temp = temp->next;
        }
        if (temp->next == NULL)
            return head;
        Node *nextNode = temp->next;
        temp -> next = nextNode -> next; 
    	delete nextNode;
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
    int pos;
    cin >> pos;
    head = deleteNode(head,pos);
    print(head);
    return 0;
}