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

// Time complexity is O(n^2) which is not very good
Node *reverseLinkedListRec(Node *head)
{
    if (head == NULL || head -> next == NULL)
        return head;
    Node *ans = reverseLinkedListRec(head->next);
    Node *temp = ans;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp -> next = head;
    head -> next = NULL;
    return ans;
}

int main()
{
    Node *head = takeInput();
    print(head);
    head = reverseLinkedListRec(head);
    cout << "\nAfter Reversing using Recursion" << endl;
    print(head);
    return 0;
}