#include<iostream>
using namespace std;

class Node 
{
public :
    int data;
    Node *next;

    Node (int num){
        data = num;
        next = NULL;
    }
};

Node *takeInput() {
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

void print(Node *head) {
    Node *temp = head;
    cout << "Linked List:";
    while (temp != NULL) {
        cout << "->" << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

Node *evenAfterOdd(Node *head)
{
    Node *temp = head;
    Node *oddTail = NULL, *evenTail = NULL, *head2 = NULL, *head3 = NULL;
    while (temp != NULL) {
        if (temp->data % 2 != 0) {
            if (head2 == NULL) {
                head2 = temp;
                oddTail = temp;
            }
            else {
                oddTail -> next = temp;
                oddTail = temp;
            }
        }
        else {
            if (head3 == NULL) {
                head3 = temp;
                evenTail = temp;
            }
            else {
                evenTail -> next = temp;
                evenTail = temp;
            }
        }
        temp = temp->next;
    }
    if (head3 != NULL)
        evenTail -> next = NULL;

    if (head2 == NULL)
        return head3;

    if (head3 == NULL)
        oddTail -> next = NULL;

    if (head2 != 0 && head3 != 0) {
        oddTail -> next = head3;
    }
    return head2;
}

int main()
{
    Node *head = takeInput();
    print (head);
    cout << "\nPrinting Even After Odd" << endl;
    head = evenAfterOdd(head);
    print(head);
    return 0;
}