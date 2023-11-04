#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H 

#include <list> 
#include <iterator>

template <typename T>
struct MinC
{
    bool operator()(const T& a, const T& b) const 
    {
        return a < b; 
    }
};

template <typename T> 
struct MaxC 
{
    bool operator()(const T& a, const T& b)
    {
        return a > b; 
    }
};

template <typename T, typename C> 
class PriorityQueue
{
private: 
    std::list<T> L; 
    C isLess; 
public: 
    int size()
    {
        return L.size(); 
    }
    bool isEmpty()
    {
        return L.empty(); 
    }
    const T& min()
    {
        return L.front(); 
    }
    void insert(const T& element)
    {
        typename std::list<T>::iterator p; 
        p = L.begin(); 
        while(p != L.end() && !isLess(element, *p)) ++p; 
        L.insert(p, element); 
    }
    void removeMin()
    {
        L.pop_front(); 
    }
    void print() const 
    {
       std::cout << "Queue contents: "; 
       for(const T& element : L)
            std::cout << element << " "; 
       std::cout << std::endl; 
    }
};

#endif