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

Node *swapNodes(Node *head, int i, int j)
{
    Node *temp1 = head, *temp2 = NULL;
    int count = 0;
    Node *p1 = NULL, *n1 = NULL, *p2 = NULL;
    while (count < i - 1)
    {
        temp1 = temp1->next;
        count++;
    }

    p1 = temp1;
    temp2 = temp1;
    if (i != 0)
        temp1 = temp1->next;
    n1 = temp1->next;

    while (count < j - 1)
    {
        temp2 = temp2->next;
        count++;
    }
    p2 = temp2;
    temp2 = temp2->next;

    temp1->next = temp2->next;
    if (i != 0)
        p1->next = temp2;
    else
        head = temp2;
    if (n1 != temp2)
        temp2->next = n1;
    if (p2 != temp1)
        p2->next = temp1;
    else
        temp2->next = temp1;
    return head;
}

int main()
{
    Node *head = takeInput();
    print(head);
    int m, n;
    cin >> m >> n;
    cout << "\nSwapping Nodes" << endl;
    head = swapNodes(head, m, n);
    print(head);
    return 0;
}