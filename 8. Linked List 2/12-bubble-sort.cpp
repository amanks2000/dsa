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

Node *bSort(Node *head)
{
    Node *temp = head, *prev = NULL;
    while (temp->next != NULL)
    {
        Node *temp2 = temp->next;
        if (temp->data > temp2->data)
        {
            if (prev == NULL)
            {
                head = temp2;
                temp->next = temp2->next;
                temp2->next = temp;
            }
            else
            {
                temp->next = temp2->next;
                prev->next = temp2;
                temp2->next = temp;
            }
            prev = temp2;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}

Node *bubbleSort(Node *head)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    for (int i = 0; i < count; i++)
    {
        head = bSort(head);
    }
    return head;
}

int main()
{
    Node *head = takeInput();
    print(head);
    cout << "\nAfter Bubble Sort" << endl;
    head = bubbleSort(head);
    print(head);
    return 0;
}