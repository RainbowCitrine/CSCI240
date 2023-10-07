#include <iostream> 

struct Node
{
    Node* prev; 
    int data; 
    Node* next; 
};

struct Node* header;
struct Node* trailer;  

void create()
{
    header = new Node; 
    trailer = new Node; 
    header->next = trailer;
    trailer->prev = header;  
}

void insertAfter(Node* p, int data)
{
    insert(p->next, data); 
}

void insertBefore(Node* p, int data)
{
    insert(p, data); 
}

void insert(Node* v, int data)
{
    Node* tmp = new Node; 
    tmp->data = data; 
    tmp->next = v; 
    tmp->prev = v->prev; 
    v->prev->next = tmp; 
    v->prev = tmp; 
}

void remove(Node* v)
{
    Node* predecessor = v->prev; 
    Node* successor = v->next; 

    predecessor->next = successor; 
    successor->prev = predecessor; 
    delete v; 
}