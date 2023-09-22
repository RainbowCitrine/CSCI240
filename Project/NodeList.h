#include "Node.h"

#ifndef NODELIST_H
#define NODELIST_H 

template <typename T> 
struct NodeList
{
    NodeList() {} 

    virtual void create(T data) = 0; 

    virtual void insertFront(T data) = 0; // Insert the front of a linked list
    
    virtual void insertBack(T data) = 0; // Insert the Back of a linked list 

    virtual void insertMiddle(int index, T data) = 0; // Insert at a given position

    virtual T Remove(T data) = 0; // removes 

    virtual bool isEmpty() const = 0; // Will be used to check if the student has no classes 

    virtual void Display() = 0; 
};

#endif 