#ifndef SINGLYLINKEDLIST_H 
#define SINGLYLINKEDLIST_H

#include <iostream> 
#include "Node.h"
#include "NodeList.h"

template <typename T> 
class SinglyLinkedList : public NodeList<T>
{
    struct Node<T>* head = nullptr; 
public: 
    SinglyLinkedList()
    {
        head = new Node<T>;
        head->next = nullptr; 
    }
    void create(T data)
    {
        head->data = data; 
    }
    void insertFront(T data)
    {
        struct Node<T>* tmp = new Node<T>; 
        tmp->data = data; 
        tmp->next = head; 
        head = tmp; 
    }
    
    void insertBack(T data)
    {
        struct Node<T>* tmp = new Node<T>; 
        struct Node<T>* current = head; 
        tmp->data = data; 
        tmp->next = nullptr; 

        if(current == nullptr)
            current = tmp; 
        else 
        {
            while(current->next != nullptr)
            {
                current = current->next; 
            }
            current->next = tmp; 
        }
    } 

    void insertMiddle(int index, T data)
    {
        Node<T>* current = head; 
        Node<T>* tmp = new Node<T>; 
        tmp->data = data; 
        
        for(int i = 0; i < index - 1 && current->next != nullptr; ++i)
        {
            current = current->next; 
        }
        tmp->next = current->next; 
        current->next = tmp; 
    }
    T Remove(T data)
    {
        Node<T>* current = head; 
        Node<T>* tmp = nullptr; 
        T x = T(); 

        while(current != nullptr)
        {
            if(current->data == data)
                break; 
            else 
            {
                tmp = current; 
                current = current->next; 
            }
        }
        if(current != nullptr)
        {
           if(tmp != nullptr)
           {
                tmp->next = current->next; 
           }
           else 
           {
                head = head->next; 
           }
        }
        x = current->data; 
        delete current; 
        return x; 
    }

    bool isEmpty() const 
    {
        return head == nullptr; 
    }

    void Display()
    {
        Node<T>* current = head; 
        while(current != nullptr)
        {
            std::cout << current->data << " "; 
            current = current->next; 
        }
        std::cout << std::endl; 
    }
};

#endif