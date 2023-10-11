#ifndef BINARYTREE_H 
#define BIANRYTREE_H

#include "CircularLinkedQueue.h"
#include <iostream> 

template <class T> 
class BinaryTree
{
    struct Node<T>* root = nullptr; 
public: 
    BinaryTree()
    {
        struct Node<T> *p, *t; 
        T x; 
        CircularLinkedQueue<int> q; 
        root = new root<T>;
        q.create(100); 
        std::cout << "Enter root value: "; 
        std::cin >> x; 
        root->data = x; 
        root->lchild = root->rchild = nullptr; 
        q.enqueue(root); 

        while(!q.isEmpty())
        {
            p = q.dequeue(); 
            std::cout << "Enter left child "; 
            std::cin >> x; 
            if(x != -1)
            {
                t = new Node<T>; 
                t->data = x; 
                t->lchild = t->rchild = nullptr;
                p->lchild = t; 
                q.enqueue(t); 
            }
            std::cout << "Enter right child "; 
            std::cin >> x; 
            if(x != -1)
            {
                t = new Node<T>; 
                t->data = x; 
                t->lchild = t->rchild = nullptr;
                p->rchild = t; 
                q.enqueue(t); 
            }
        }
    }
};
#endif