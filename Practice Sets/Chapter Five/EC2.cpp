#include <iostream>

template <typename T>
struct Node
{
    T data;
    Node<T>* prev;
    Node<T>* next;
};

template <typename T>
class LinkedDeque
{
private:
    Node<T>* front;
    Node<T>* rear;
    int size;

public:
    LinkedDeque()
    {
        front = nullptr;
        rear = nullptr;
        size = 0;
    }
    void insertFront(T value)
    {
        Node<T>* newNode = new Node<T>;
        newNode->data = value;
        newNode->prev = nullptr;
        newNode->next = front;

        if (isEmpty())
        {
            rear = newNode;
        }
        else
        {
            front->prev = newNode;
        }

        front = newNode;
        size++;
    }

    void insertRear(T value)
    {
        Node<T>* newNode = new Node<T>;
        newNode->data = value;
        newNode->next = nullptr;
        newNode->prev = rear;

        if (isEmpty())
        {
            front = newNode;
        }
        else
        {
            rear->next = newNode;
        }

        rear = newNode;
        size++;
    }

    void removeFront()
    {
        if (isEmpty())
        {
            std::cout << "Deque is empty." << std::endl;
            return;
        }

        Node<T>* temp = front;
        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
        }
        else
        {
            front->prev = nullptr;
        }

        delete temp;
        size--;
    }

    void removeRear()
    {
        if (isEmpty())
        {
            std::cout << "Deque is empty." << std::endl;
            return;
        }

        Node<T>* temp = rear;
        rear = rear->prev;

        if (rear == nullptr)
        {
            front = nullptr;
        }
        else
        {
            rear->next = nullptr;
        }

        delete temp;
        size--;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty() {return size == 0;}

    T getFront()
    {
        if (isEmpty())
        {
            std::cout << "Deque is empty." << std::endl;
            return T(); 
        }

        return front->data;
    }
};

int main()
{
    LinkedDeque<std::string> deque;

    deque.insertFront("John");
    deque.insertFront("Jane");
    deque.insertRear("Jo");

    std::cout << "Front item: " << deque.getFront() << std::endl; 

    deque.removeRear();
    deque.removeFront();

    std::cout << "Size: " << deque.getSize() << std::endl; 

    return 0;
}
