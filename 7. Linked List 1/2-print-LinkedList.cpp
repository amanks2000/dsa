#include<iostream>
using namespace std;

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

// To print the data of Linked list we need to traverse using loops through the 
// nodes of the linked list until the head is NULL
// Note: If we stop the loop when head->next is NULL we won't be able to print the
// last node where the next pointer is NULL
void print (Node *head) {
    cout << "Linked List:";

    while (head != NULL) {
        cout << "->" << head->data;
        head = head->next; // This line makes the head point to the next node
    }

}

int main()
{
    Node n1(10);
    Node *head = &n1;
    Node n2(20);
    Node n3(30);
    Node n4(40);
    Node n5(50);

    // Connecting nodes of linked list -
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;

    print(head); // To print a linked list we only need to send the head of the
                 // linked list to the function
    // Note: Changes made to head inside a function won't affect the address of the
    // head in the main function
    return 0;
}