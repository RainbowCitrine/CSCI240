#include <iostream> 

template <typename T> 
struct Node
{
    Node* prev; 
    T data; 
    Node* next; 
};

template <typename T> 
class Queue
{
    Node<T>* header = nullptr; 
    Node<T>* trailer = nullptr;
public: 
    Queue()
    {
        header = new Node<T>; 
        trailer = new Node<T>; 
        header->next = trailer; 
        trailer->prev = header; 
    }
    void enqueueBack(const T& data)
    {
        enqueue(trailer, data);
    }
    void DequeueFront()
    {
        Dequeue(header->next);
    }
    bool isEmpty() {return header->next == trailer;}
    T front() {return trailer->prev->data; }
    void print()
    {
        Node<T>* current = header->next; 
        while(current != trailer)
        {
            std::cout << current->data << " "; 
            current = current->next; 
        }
        std::cout << std::endl; 
    }
protected: 
    void enqueue(Node<T>* v, const T& data)
    {
        Node<T>* tmp = new Node<T>; 
        tmp->data = data; 
        tmp->next = v; 
        tmp->prev = v->prev; 
        v->prev->next = tmp; 
        v->prev = tmp; 
    }
    void Dequeue(Node<T>* v)
    {
        Node<T>* previous = v->prev; 
        Node<T>* successor = v->next; 
        previous->next = successor; 
        successor->prev = previous; 
        delete v;
    }
};

int main() {
    Queue<int> queue;

    // Test case 1: enqueueBack and front()
    queue.enqueueBack(1);
    std::cout << "Front after enqueueBack(1): " << queue.front() << std::endl;

    // Test case 2: enqueueBack again
    queue.enqueueBack(2);
    std::cout << "Front after enqueueBack(2): " << queue.front() << std::endl;

    // Test case 3: DequeueFront
    queue.DequeueFront();
    std::cout << "Front after DequeueFront(): " << queue.front() << std::endl;

    // Test case 4: isEmpty()
    std::cout << "Is empty initially: " << (queue.isEmpty() ? "true" : "false") << std::endl;

    // Test case 5: DequeueFront when the queue is empty
    queue.DequeueFront();
    std::cout << "Is empty after DequeueFront(): " << (queue.isEmpty() ? "true" : "false") << std::endl;

    // Test case 6: enqueueBack after DequeueFront
    queue.enqueueBack(3);
    std::cout << "Front after enqueueBack(3): " << queue.front() << std::endl;

    // Test case 7: print
    std::cout << "Queue elements: ";
    queue.print();

    return 0;
}

