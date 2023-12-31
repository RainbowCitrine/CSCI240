#include <iostream> 
#include <ctime> 
#include <stdlib.h>

template <typename T> 
struct Node
{
    T data; 
    struct Node* next; 
};

template <typename T>
class LinkedQueue
{
    struct Node<int>* front = nullptr, *rear = nullptr; 
    size_t queueSize = 0; 
public: 
    bool isEmpty() {front == rear;}
    void enqueue(T x)
    {
        struct Node<int>* tmp = new Node<int>; 
        tmp->data = x; 
        tmp->next = nullptr; 

        if(front == nullptr) front = rear = tmp; 
        else 
        {
            rear->next = tmp; 
            rear = tmp; 
        }
        queueSize++; 
    }
    
    T dequeue()
    {
        T x = T(); 
        Node<int>* tmp = new Node<int>; 
        tmp = front; 
        front = front->next; 
        x = tmp->data; 
        delete tmp; 
        queueSize--; 
        return x; 
    }
    size_t size(){return queueSize;}
    T infront(){return front->data;}
    void display()
    {
        struct Node<int>* current = front; 

        while(current != nullptr)
        {
            std::cout << current->data << " ";
            current = current->next; 
        }
        std::cout << std::endl;
    }
};

int main(int argc, char const *argv[])
{
    std::srand(std::time(0)); 
    LinkedQueue<int> lq; 
   
    for(int i = 1; i <=5; ++i)
    {
        int unit = std::rand() % 10 + 1; 
        lq.enqueue(unit); 
        std::cout << "Enqueue Job " << i << " with " << unit << " units" << std::endl; 
    }
   
    int cy = 1; 
    while(!lq.isEmpty())
    {
        std::cout << cy << " Processing job " << lq.infront() << std::endl; 
        int rem = lq.infront() - 1; 
        lq.dequeue(); 

        if(rem > 0) lq.enqueue(rem); 
        else std::cout << "Done with job " << cy << std::endl; 
        cy++;
    }
    return 0;
}
