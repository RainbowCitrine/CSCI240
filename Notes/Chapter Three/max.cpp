#include <iostream> 

template <typename T> 
struct Node 
{
    T data; 
    struct Node* next; 
};

int max(struct Node<int>*  p)
{
    int m = -32768; 
    while(p != NULL)
    {
        if(p->data > m)
        {
            m = p->data; 
        }
        p = p->next; 
    }
    return m; 
}

int main()
{
    int arr[] = {3, 5, 7, 10, 15}; 
    struct Node<int>* first, *tmp, *last; 
    first = new Node<int>; 
    first->data = arr[0]; 
    first->next = nullptr; 

    last = first; 

    for(int i = 1; i < 5; ++i)
    {
        tmp = new Node<int>; 
        tmp->data = arr[i]; 
        tmp->next = nullptr; 
        last->next = tmp; 
        last = tmp; 
    }
    std::cout << max(first) << std::endl; 
}