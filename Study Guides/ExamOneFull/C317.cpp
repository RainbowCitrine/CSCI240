#include <iostream>

/*

Describe a recursive algorithm that counts the number of nodes in a singly
linked list.

*/


struct Node
{
    int data; 
    Node* next; 
};

int numNodes(struct Node* first)
{
    int size = 0;

    Node* current = first; 

    
    return 1 + numNodes(current->next);  // start fromt one
}