#include <iostream> 

template<typename T> 
struct Node
{
    T data; 
    struct Node* next; 
};

void InsertFront(struct Node<int>* &first, int element)
{
    struct Node<int>* tmp = new Node<int>; 
    tmp->data = element; 
    tmp->next = first; 
    first = tmp; 
}

void InsertPos(struct Node<int>* &first, int index, int x)
{
    Node<int>* temp = new Node<int>; 
    temp->data = x; 

    if(index == 0)
    {
        temp->next = first; 
        first = temp; 
    }
    else 
    {
        Node<int>* current = first; // set a temp node
        for(int i = 0; i < index -1 && current->next != nullptr; ++i)
        {
            current = current->next; 
        }
        temp->next = current->next; 
        current->next = temp; 
    }
    
}

void InsertBack(struct Node<int>* &first, int x)
{
    Node<int>* newNode = new Node<int>; 
    newNode->data = x;
    newNode->next = NULL; 
    if(first == nullptr)
        first = newNode; 
    else 
    {
        Node<int>* temp = first; 
        while(temp->next != nullptr)
            temp = temp->next; 
        temp->next = newNode; 
    }
}

void Delete(struct Node<int>* &first, int index, int x)
{
    Node<int>* temp = new Node<int>; 
}

void display(struct Node<int>* p)
{
    while(p!=nullptr)
    {
        std::cout << p->data << " "; 
        p = p->next; 
    }
    std::cout << std::endl; 
}

int main(int argc, char const *argv[])
{
    Node<int>* first = new Node<int>; 
    first->data = 2; 
    first->next = NULL; 

    InsertFront(first, 100); 
    InsertPos(first, 0, 10);
    InsertPos(first, 1, 20); 
    InsertPos(first, 3, 40);
    InsertBack(first, 200);
    display(first); 

    return 0;
}
