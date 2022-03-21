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

Node* takeInput() {
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

int length(Node *head)
{
    Node *temp = head;
    int count=0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void print (Node *head) {
    cout << "Linked List:";
    Node *temp = head;
    while (temp != NULL) {
        cout << "->" << temp->data;
        temp = temp->next;
    }

}

int main()
{
    int t;
    cin >> t;
    while (t--) {
        Node *head = takeInput();
        print(head);
        cout << "\nLength of Linked List = " << length(head) << endl;
    }
    return 0;
}