#include<iostream>
using namespace std;

class Node 
{
public :
    int data;
    Node *next;

    Node (int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

Node* takeInput() {
    Node *head = NULL;
    Node *tail = NULL;
    int data;
    cin >> data;
    while (data != -1) {
        Node *newnode = new Node (data);
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

bool isPalindrome(Node *head)
{
    bool check = true;
    Node *tail = head;
    int count = 1;
    while (tail ->next != NULL) {
        tail = tail -> next;
        count ++;
    }
    int half = count/2;
    count = 0;
    while (count < half) {
        Node *temp1 = head;
        Node *temp2 = temp1->next;
        while (temp2->next != NULL) {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if (head->data != temp2->data) {
            check = false;
            break;
        }
        head = head->next;
        temp1->next = NULL;
        delete temp2;
        count++;       

    }
    return check;
    
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
    Node *head = takeInput();
    print(head);
    cout << "The Linked list is a Palindrome or not :" << endl;
    bool ans = isPalindrome(head);
	if (ans) 
        cout << "true";
	else 
        cout << "false";
    cout << endl;
    return 0;
}