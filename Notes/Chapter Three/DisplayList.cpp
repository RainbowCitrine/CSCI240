#include <iostream> 
template <typename T>
struct Node
{
    T data; 
    struct Node* next; 
}; // first global variable

int main()
{
    int A[] = {3, 5, 7, 10, 15}; 
    struct Node<int>* first, *tmp, *last; 
    first = new Node<int>; 
    
    //Assign data and then move to the next Node
    first->data = A[0]; 
    first->next = nullptr; 

    last = first; // making last point to first 

    // insert 
    for(int i = 1; i < 5; ++i)
    {
        tmp = new Node<int>; 
        tmp->data = A[i]; 
        tmp->next = nullptr; 
        last->next = tmp; 
        last = tmp; 
    }

    while(first != nullptr)
    {
        std::cout << first->data << std::endl; 
        first = first->next; 
    }
}