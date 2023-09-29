#include <iostream>
#include <vector> 
#include <list> 

template <typename T> 
struct Node
{
    Node* prev; 
    T data; 
    Node* next; 
};

template <typename> 
class Bag
{
    std::vector<std::list<int>> elements; 
    int size; 
public: 
    Bag(int maxSize) : elements(maxSize), size(0) {}
    void add(int e)
    {
        elements[e].push_back(e); 
        size++; 
    }
    int remove()
    {
        do
        {
            
        }
    }
};