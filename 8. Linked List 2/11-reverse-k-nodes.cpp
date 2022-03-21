#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int num)
    {
        data = num;
        next = NULL;
    }
};

Node *takeInput()
{
    Node *head = NULL, *tail = NULL;
    int data;
    cin >> data;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    cout << "Linked List:";
    while (temp != NULL)
    {
        cout << "->" << temp->data;
        temp = temp->next;
    }
    cout << endl;
}

Node *reverseLL (Node *head) 
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *ans = reverseLL(head->next);

    Node *tail = head->next;
    tail -> next = head;
    head -> next = NULL;
    return ans;
}

Node *kReverse(Node *head, int k)
{
    Node *temp = head;
    int count = 0;
    while (count < k-1 && temp->next != NULL) {
        temp = temp->next;
        count++;
    }
    Node *temp2 = temp->next;
    if (temp2 != NULL) {
        Node *smallAns = kReverse(temp2,k);
        temp -> next = NULL;
        head = reverseLL(head);
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = smallAns;
    }
    else {
        head = reverseLL(head);
    }
    
    return head;
}

int main()
{
    Node *head = takeInput();
    print(head);
    int k;
    cin >> k;
    cout << "\nReversing k Nodes" << endl;
    head = kReverse(head, k);
    print(head);
    return 0;
}