#include <iostream> 

template<typename T> 
struct Queue
{
    int front, rear; 
    size_t size; 
    T* arr; 
};

template<typename T> 
class MyCircularQueue
{
    struct Queue<int>* q; 
public: 
    void create()
    {
        q = new Queue<int>; 
        q->size = 100; 
        q->front = q->rear = -1; 
        q->arr = new T[q->size]; 
    }
    bool isFull(){return q->rear(q->rear + 1) % q->size == q->front;}
    bool isEmpty(){return q->rear == q->front;}
    void enqueue(T x)
    {
        if(isFull()) throw std::out_of_range("Queue is full"); 
        else 
        {
            q->rear = q->rear(q->rear + 1) % q->size; 
            q->arr[q->rear] = x; 
        }
    }
    T dequeue()
    {
        T x = T(); 
        if(isEmpty()) throw std::out_of_range("Queue is empty"); 
        q->front = q->front(q->front + 1); 
        x = q->arr[q->front]; 
        return x; 
    }
    void Display()
    {
        int i = q->front + 1; 
        do
        {
            std::cout << q->arr[i] << " "; 
            i = (i + 1) %q->size; 
        } while (i != q->rear + 1);
        std::cout << std::endl; 
    }
};
