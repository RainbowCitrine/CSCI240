#include <iostream> 

struct Node
{
    Node* next; 
    int data; 
};
Node* head = nullptr; 

void create(int data)
{
    head = new Node; 
    head->data = data; 
    head->next = nullptr; 
}
void insertFront(int data)
{
    Node* tmp = new Node; 
    tmp->data = data; 
    tmp->next = head; 
    head = tmp; 
}
int countNode(Node* current)
{
    if(current == nullptr) return 0; 


    return 1 + countNode(current->next); 
}
int main(int argc, char const *argv[])
{
    std::cout << countNode(head) << std::endl; 
    return 0;
}
