#include <iostream> 

template <typename T> 
struct Queue
{
    size_t size = 100; 
    int front; 
    int rear; 
    T* arr; 
};

template <typename T> 
class MyArrayQueue
{
    struct Queue<int>* q; 

public: 
    void create()
    {
        q = new Queue<int>; 
        q->size = 100; 
        q->front = -1; 
        q->rear = -1; 
        q->arr = new T[q->size]; 
    }
    bool isFull() {return q->rear == q->size - 1;}
    bool isEmpty() {return q->front == q->rear;}
    void enqueue(T x)
    {
        if(isFull()) throw std::out_of_range("Queue is full"); 
        q->rear++; 
        q->arr[q->rear] = x; 
    }
    T dequeue()
    {
        if(isEmpty()) throw std::out_of_range("Queue is full"); 
        T x = T(); 
        q->front++; 
        x = q->arr[q->front]; 
        return x; 
    }
    void display()
    {
        for(int i = q->front + 1; i <= q->rear; ++i)
            std::cout << q->arr[i]; 
        std::cout << std::endl; 
    }
};

int main(int argc, char const *argv[])
{
    MyArrayQueue<int> q; 
    q.create(); 
    q.enqueue(1); 
    q.enqueue(2); 
    q.dequeue();
    q.display(); 
    return 0;
}
