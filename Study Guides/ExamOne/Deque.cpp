#include <iostream> 


template <typename T> 
struct Node
{
    Node* prev; 
    T data; 
    Node* next; 
};

template <typename T> 
class Deque
{

Node<T>* header = nullptr; 
Node<T>* trailer = nullptr; 

public: 
    Deque()
    {
        header = new Node<T>; 
        trailer = new Node<T>; 
        header->next = trailer; 
        trailer->prev = header; 
    }
    void EnqueueFront(const T& data)
    {
        Enqueue(header->next, data); 
    }       
    void EnqueueBack(const T& data)
    {
        Enqueue(trailer, data); 
    }
    void DequeueFront()
    {
        Dequeue(header->next); 
    }
    void DequeueBack()
    {
        Dequeue(trailer->prev); 
    }
    T front(){return header->next->data;}
    T back(){return trailer->prev->data;}
    bool isEmpty(){return header->next == trailer;}
    void printforward()
    {
        Node<T>* current = header->next; 
        while(current != trailer)
        {
            std::cout << current->next << " ";
            current = current->next;  
        }
        std::cout << std::endl; 
    }
protected: 
    void Enqueue(Node<T>* v, const T& data)
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
    Deque<int> deque;

    // Test case 1: EnqueueFront and front()
    deque.EnqueueFront(1);
    std::cout << "Front after EnqueueFront(1): " << deque.front() << std::endl;

    // Test case 2: EnqueueBack and back()
    deque.EnqueueBack(2);
    std::cout << "Back after EnqueueBack(2): " << deque.back() << std::endl;

    // Test case 3: DequeueFront
    deque.DequeueFront();
    std::cout << "Front after DequeueFront(): " << deque.front() << std::endl;

    // Test case 4: DequeueBack
    deque.DequeueBack();
    std::cout << "Is empty after DequeueBack(): " << (deque.isEmpty() ? "true" : "false") << std::endl;

    // Test case 5: isEmpty()
    std::cout << "Is empty initially: " << (deque.isEmpty() ? "true" : "false") << std::endl;

    // Test case 6: EnqueueFront and EnqueueBack
    deque.EnqueueFront(3);
    deque.EnqueueBack(4);
    std::cout << "Front after EnqueueFront(3): " << deque.front() << std::endl;
    std::cout << "Back after EnqueueBack(4): " << deque.back() << std::endl;

    // Test case 7: DequeueFront and DequeueBack
    deque.DequeueFront();
    deque.DequeueBack();
    std::cout << "Is empty after DequeueFront() and DequeueBack(): " << (deque.isEmpty() ? "true" : "false") << std::endl;

    return 0;
}

