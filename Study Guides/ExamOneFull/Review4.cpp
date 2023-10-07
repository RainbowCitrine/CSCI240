#include <iostream> 

struct Node
{
    int data; 
    struct Node* next; 
};

struct Node* head = new Node; 

int remove(int data)
{
    Node* current = head; 
    Node* tmp = nullptr;
    int x; 

    while(current != nullptr)
    {
        if(current->data == data)
            break; 
        else 
        {
            tmp = current; 
            current = current->next; 
        }
    }
    int x = current->data; 
    if(current != nullptr)
    {
        if(tmp != nullptr)
        {
            tmp->next = current->next; 
 
        }
        else if(head == nullptr)
        {
            head = head->next; 
        }
    }
    x = current->data; 
    return x; 
}