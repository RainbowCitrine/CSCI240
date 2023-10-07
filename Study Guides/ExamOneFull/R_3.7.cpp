#include <iostream> 

/*

Give an algorithm for finding the penultimate (second to last) node in a
singly linked list where the last element is indicated by a null next link.

*/

struct Node
{
    int data; 
    Node* next; 
};

int findSecondToLast(struct Node* first)
{
    Node* tmp = new Node; 
    tmp = first; 
    
    while(tmp != nullptr)
    {
        if(tmp->next->next == nullptr)
            return tmp->data; 
        tmp = tmp->next; 
    }

}