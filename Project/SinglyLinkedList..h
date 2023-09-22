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
        head = nullptr;
    }
    void create(T data)
    {
        head = new Node<T>; 
        head->data = data; 
        head->next = nullptr;
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
        if(isEmpty()) throw std::out_of_range("List is Empty cannot remove!"); 
        Node<T>* previous = nullptr; 
        Node<T>* current = head; 
      
        while(current != nullptr)
        {
            if(current->data == data)
            {
                break; 
            }
            else 
            {
                previous = current; 
                current = current->next; 
            }
        }
        if(current != nullptr)
        {
            if(previous != nullptr)
            {
                previous->next = current->next; 
            }
            else 
            {
                head = current->next; 
            } 
            data = current->data; 
            delete current; 
            return data; 
        }
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