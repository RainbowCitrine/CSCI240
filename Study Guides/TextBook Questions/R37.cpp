/*

Give an algorithm for finding the penultimate (second to last) node in a
singly linked list where the last element is indicated by a null next link.

*/

struct Node
{
    Node* next; 
    int data; 
};

int penimultate(struct Node* head, int data)
{
    Node* current = head; 
    while(current != nullptr)
    {
        if(current->next->next == nullptr)
            return current->data; 
        current = current->next; 
    }
}