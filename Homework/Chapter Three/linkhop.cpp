#include <iostream> 

struct Node
{
    int data; 
    Node* next; 
};

struct Node* head = nullptr; 
void create(int data)
{
    head = new Node; 
    head->data = data; 
    head->next = nullptr; 
}

void insertFront(int data)
{
    struct Node* tmp = new Node; 
    tmp->data = data; 
    tmp->next = head; 
    head = tmp; 
}

void insertBack(int data)
{
    struct Node* current = head; 
    struct Node* temp = new Node; 
    temp->data = data; 
    temp->next = nullptr; 
    while(current->next != nullptr)
    {
        current = current->next; 
    }
    current->next = temp; 
}

void insertMiddle(int index, int data)
{
    struct Node* tmp = new Node; 
    struct Node* current = head; 
    tmp->data = data; 
    tmp->next = nullptr; 
    for(int i = 0; i < index - 1 && current != nullptr; ++i)
    {
        current = current->next; 
    }
    //connect the tmp node 
    tmp->next = current->next; 
    current->next = tmp; 
}

int main(int argc, char const *argv[])
{
    create(2); 
    insertFront(1);  
    insertBack(4); 
    insertMiddle(2, 3); 
    struct Node* current = head; 
    while(current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;  
    }
    
    return 0;
}
