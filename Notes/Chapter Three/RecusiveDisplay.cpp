#include <iostream> 

template <typename T> 
struct Node
{
    T data; 
    Node* next; 
};

void display(struct Node<int>* p)
{
    if(p->next != nullptr)
    {
        std::cout << p->data << " "; 
        display(p->next); 
    }
}
void reverseDisplay(struct Node<int> *p)
{
    if(p->next != nullptr)
    {
        reverseDisplay(p->next); 
        std::cout << p->data << " "; 
    }
}
int main()
{
    int A[] = {3, 5, 7, 10, 15};

    struct Node<int>* first, *last, *temp; 
    
    first = new Node<int>; 
    first->data = A[0];  
    first->next= nullptr; // slways set equal to null

    last = first; 
    int i; 
    for(i = 1; i <= 5; ++i)
    {
        temp = new Node<int>; 
        temp->data = A[i]; 
        temp->next = nullptr; 
        last->next = temp; 
        last = temp; 
    }
    display(first); 
    std::cout << std::endl; 
    reverseDisplay(first); 
}
