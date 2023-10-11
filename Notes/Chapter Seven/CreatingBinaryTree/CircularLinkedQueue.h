#ifndef CIRCULARLINKEDQUEUE_H
#define CIRCULARLINKEDQUEUE_H 

#include <stdexcept>

template <typename T> 
struct Node
{
    Node* lchild; 
    T data; 
    Node* rchild; 
};

template <typename T> 
struct Queue
{
    int size; 
    int front; 
    int rear; 
    Node<T> **Q; 
}; 

template <typename T> 
class CircularLinkedQueue
{
    Queue<T>* q; 
public: 
    CircularLinkedQueue(int size)
    {
        q = new Queue<T>; 
        q->size = size; 
        q->front = q->rear = -1; 
        q->Q = new Node<T>*[size]; 
    }
    ~CircularLinkedQueue()
    {
        delete[] q->Q; 
        delete q; 
    }
    bool isFull()
    {
        return((q->rear + 1) % q->size == q->front); 
    }
    bool isEmpty()
    {
        return (q->front == q->rear); 
    }
    void enqueue(Node<T>* data)
    {
        if(isFull()) throw std::out_of_range("Queue is full"); 
        q->rear = (q->rear + 1) % q->size; 
        q->Q[q->rear] = data; 
    }
    Node<T>* dequeue()
    {
        Node<T>* x = nullptr;  
        if(isEmpty()) throw std::out_of_range("Queue is empty"); 
        q->front = (q->front + 1) % q->size; 
        x = q->Q[q->front]; 
        return x; 
    }
};

#endif 