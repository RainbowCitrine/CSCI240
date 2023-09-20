#include <iostream> 

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
    LinkedQueue<int> lq; 
    lq.enqueue(2); 
    lq.enqueue(5); 
    lq.display(); 
    std::cout << lq.infront() << std::endl; 
    std::cout << lq.size() << std::endl;
    return 0;
}
