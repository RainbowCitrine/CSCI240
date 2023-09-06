#include <iostream> 

template <typename T> 
struct Node
{
    T data; 
    struct Node* next; 
};

int Add(struct Node<int>* p)
{
    int sum = 0; 
    while(p != 0)
    {
        sum += p->data;
        p = p->next;  
    }
    return sum; 
}

int RecursiveCount(struct Node<int>* p)
{
    if(p != nullptr)
        return RecursiveCount(p->next) + 1; 
    else 
        return 0; 
}

int RecursiveSum(struct Node<int>* p)
{
    if(p != nullptr)
        return RecursiveSum(p->next) + p->data; 
    else 
        return 0; 
}

int count(struct Node<int> *p)
{
    int counter = 0; 
    while(p != 0)
    {
        counter++; 
        p = p->next; 
    }
    return counter; 
}


int main(int argc, char const *argv[])
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

    std::cout << Add(first) << std::endl; 
    std::cout << count(first) << std::endl; 
    std::cout << RecursiveCount(first) << std::endl; 
    std::cout << RecursiveSum(first) << std::endl; 

    return 0;
}
