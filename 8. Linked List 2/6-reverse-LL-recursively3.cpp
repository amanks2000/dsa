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

// Time complexity is O(n) which is not very good
// Let the LL = 1 2 3 4 5 null
Node *reverseLL(Node *head)
{
    if (head == NULL || head -> next == NULL)
        return head;
    Node *ans = reverseLL(head->next); // LL : 5 4 3 2 , Here tail = &2, ans = &5

    Node *tail = head -> next; // head -> next = next to 1 = 2
    tail -> next = head; // tail -> next = 1 , LL : 5 4 3 2 1 
    head -> next = NULL; // LL : 5 4 3 2 1 null
    return ans;
}

int main()
{
    Node *head = takeInput();
    print(head);
    head = reverseLL(head);
    cout << "\nAfter Reversing using Recursion" << endl;
    print(head);
    return 0;
}