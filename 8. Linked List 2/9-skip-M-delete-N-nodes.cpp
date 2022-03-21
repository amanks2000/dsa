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

Node *skipMdeleteN(Node *head, int M, int N)
{
    Node *temp = head;
    Node *temp1 = head, *temp2 = head;
    int cm = 1, cn = 0;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (cm < M)
        {
            cm++;
            temp1 = temp1->next;
            temp2 = temp1->next;
        }
        else if (cm == M)
        {
            if (cn < N)
            {
                cn++;
                Node *t = temp2;
                temp2 = temp2->next;
                delete t;
                if (temp2 == NULL)
                    temp1->next = temp2;
            }
            else if (cn == N)
            {
                temp1->next = temp2;
                cn = 0;
                cm = 0;
            }
        }
    }
    return head;
}

int main()
{
    Node *head = takeInput();
    print(head);
    int m, n;
    cin >> m >> n;
    cout << "\nSkipping M and deleting N nodes" << endl;
    head = skipMdeleteN(head, m, n);
    print(head);
    return 0;
}