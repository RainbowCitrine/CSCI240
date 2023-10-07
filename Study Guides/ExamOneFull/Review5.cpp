#include <iostream> 

struct Node
{
    int data; 
    struct Node* next; 
};

struct Node* head = new Node; 

void insertAfter(struct Node* p, int data)
{
    Node* tmp = new Node; 
    tmp->data = data; 
    tmp->next = nullptr; 

    tmp->next = p->next; 
    p->next = tmp; 
}