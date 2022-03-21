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

// To take input from user and use it further we need to return the Head of the
// linked list from the function
Node* takeInput () // head is a pointer to a Node, thus return type is Node*
{
    // We assume that when user inputs -1 the linked list is over and no further
    // input will be taken
    Node *head = NULL;
    int data;
    cin >> data;
    while(data != -1) {
        /*
        Node n(data); // We don't store the Node values statically as we know
                      // after the scope of while loop it will no longer exist.
                      // Thus we store nodes Dynamically as it is not deleted by itself
        */
        Node *newNode = new Node (data);
        if(head == NULL) // This condition works only for the first node
            head = newNode;
        else { // This connects the new Node to previous Node
            Node *temp = head;
            // We need to traverse to the last node of the current Linked list
            // to further add a new node to our linked lists
            while(temp->next != NULL) { 
                temp = temp -> next;
            }
            temp->next = newNode; // links new node to linked list
        }
        
        cin >> data; // To take input of next Node
    }
    return head;
}

// The above function uses Time Complexity of O(n^2)
// To take input in a more efficient method we use another pointer 'tail' which 
// always points to the last node
Node* takeInput2 () 
{
    Node *head = NULL;
    Node *tail = NULL;
    int data;
    cin >> data;
    while (data != -1) {
        Node *newNode = new Node (data);
        if(head == NULL) // This condition works only for the first node
        {
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

void print (Node *head) {
    cout << "Linked List:";

    while (head != NULL) {
        cout << "->" << head->data;
        head = head->next;
    }

}

int main()
{
    Node *head = takeInput();
    print(head);
    return 0;
}