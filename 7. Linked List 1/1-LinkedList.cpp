#include<iostream>
using namespace std;

// Syntax to create a Node of Linked List 
class Node 
{
public : 
    int data;
    Node *next;

    Node (int num) {
        this -> data = num;
        next = NULL;
    }
};

int main()
{
    // Statically making a Node
    Node n1(1); // calling this constructor, initialises the data of node as 1
                // and the next pointer as NULL
    // We always need to save the address of first node as Head
    Node *head = &n1;

    Node n2(2);

    // Now to link n1 and n2 we would need to store the address of n2 in next pointer
    // of n1 node
    n1.next = &n2;

    // Dynamically making a node
    Node *n3 = new Node(30);
    n2.next = n3;
    Node *n4 = new Node(40);
    n3 -> next = n4; // Since n3 and n4 are pointers to connect n3 with n4
                      // we need to use the arrow
    return 0;
}