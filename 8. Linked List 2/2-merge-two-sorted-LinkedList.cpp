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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    Node *fhead = NULL, *ftail = NULL;
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;
    while (head1 != NULL && head2 != NULL) {
        if (head1->data <= head2->data) {
            if (fhead == NULL)  
                fhead = head1;
            if (ftail != NULL)
                ftail -> next = head1;
            ftail = head1;
            head1 = head1 -> next;
        }
        else {
            if (fhead == NULL)  
                fhead = head2;
            if (ftail != NULL)
                ftail -> next = head2;
            ftail = head2;
            head2 = head2 -> next;
        }
    }
    while (head1 != NULL) {
        ftail -> next = head1; 
        ftail = head1;           
        head1 = head1 -> next;
    }
    while (head2 != NULL) {
        ftail -> next = head2; 
        ftail = head2;           
        head2 = head2 -> next;
    }
    return fhead;
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
    Node *head1 = takeInput();
    Node *head2 = takeInput();
    print(head1);
    print(head2);
    head1 = mergeTwoSortedLinkedLists(head1,head2);
    cout << "\nAfter Merging" << endl;
    print(head1);
    return 0;
}