#include <iostream> 

template <typename T> 
struct Node
{
    struct Node* lchild; 
    T data; 
    struct Node* rchild; 
}; 

Node<int>* root = nullptr; 

template <typename T> 
void insert(const T& key)
{
    struct Node<T>* t = root; 
    struct Node<T>* r, *p; 

    if(root == nullptr)
    {
        p = new Node<T>;
        p->data = key; 
        p->lchild= p->rchild = nullptr;  
    }
    while(t != nullptr)
    {
        r = t; 
        if(key < p->data)
        {
            t = t->lchild; 
        }
        else if(key > t->data)
            t = t->rchild;  
        else 
            return; 
    }
        p = new Node<T>;
        p->data = key; 
        p->lchild= p->rchild = nullptr; 

        if(key <r->data) r->lchild = p; 
        else r->rchild = p; 
}

template <typename T> 
void Inorder(struct Node<T>* p)
{
    if(p)
    {
        Inorder(p->lchild); 
        std::cout << p->data << " ";
        Inorder(p->rchild); 
    }
}

int main(int argc, char const *argv[])
{
    insert<int>(10); 
    insert<int>(5);
    insert<int>(20); 
    insert<int>(8); 
    insert<int>(30); 

    Inorder<int>(root); 
    std::cout << "\n"; 
    return 0;
}
