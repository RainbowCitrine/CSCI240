#include <iostream> 
#include <stdexcept>

template <typename T> 
class CircularQueue
{
    T* ArrQueue; 
    int Max; 
    int currentElements; 
    int front; 
    int rear; 
public: 
    CircularQueue(int capacity) : Max(capacity), front(0), rear(0), currentElements(0)
    {
        ArrQueue = new T[Max]; 
    }
    int size()
    {
        return currentElements; 
    }
    bool empty()
    {
        return currentElements == 0; 
    }
    T& frontqueue()
    {
        return ArrQueue[front]; 
    }
    void enequue(const T& data)
    {
        ArrQueue[rear] = data; // Add the data to the array 
        rear = (rear + 1) % Max; // move the data in a circular manner
        currentElements++; // increment the number of elements
    }
    void dequeue()
    {
        front = (front + 1) % Max; 
        currentElements--; 
    }
    void print()
    {
        int current = front; 
        for(int i = 0; i < currentElements; ++i)
        {
            std::cout << ArrQueue[current] << " "; 
            current = (current + 1) % Max; 
        }
        std::cout << std::endl; 
    }
};

int main(int argc, char const *argv[])
{
    CircularQueue<int> myqueue(5); 
    myqueue.enequue(1); 
    myqueue.enequue(2); 
    myqueue.enequue(3); 

    std::cout << "Queue elements: "; 
    myqueue.print(); 
    
    myqueue.dequeue(); 
    myqueue.enequue(4); 

    while (!myqueue.empty()) {
        std::cout << "Front: " << myqueue.frontqueue() << ", Size: " << myqueue.size() << std::endl;
        myqueue.dequeue();
    }

    return 0;
}
