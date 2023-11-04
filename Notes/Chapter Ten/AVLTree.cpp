#include <iostream> 

template <typename T> 
struct Node 
{
    struct Node* lchild; 
    T data; 
    int height; 
    struct Node* rchild; 
};

struct Node<int>* root = nullptr; 

template <typename T> 
int NodeHeight(struct Node<T>* p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height:0;
    hr = p && p->rchild ? p->rchild->height:0;

    return hl > hr ? hl + 1 : hr + 1; 
}

template <typename T> 
int BalanceFactor(struct Node<T>* p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height:0;
    hr = p && p->rchild ? p->rchild->height:0;
    
    return hl - hr; 
}

template <typename T> 
struct Node<T>* LLRotation(struct Node<T>* p)
{
    struct Node<T>* pl = p->lchild;
    struct Node<T>* plr = p->rchild; 

    pl->rchild = p; 
    p->rchild = plr; 
    p->height = NodeHeight(p); 
    pl->height = NodeHeight(pl); 

    if(root == p)
        root = pl; 
    return pl; 
}

template <typename T> 
struct Node<T>* RRRotation(struct Node<T> *p)
{
    return NULL; 
}

template <typename T> 
struct Node<T>* LRRotation(struct Node<T>* p)
{
    struct Node<T>* pl = pl->lchild; 
    struct Node<T>* plr = pl->rchild; 

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild; 

    plr->lchild = pl; 
    plr->rchild = p; 

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);
    plr->height = NodeHeight(plr);

    if(root == p)
        root = plr;
    return plr;

}

template <typename T> 
struct Node<T>* RLRotation(struct Node<T>* p)
{
    return NULL; 
}


template <typename T> 
struct Node<T>* RInsert(struct Node<T> *p, int key)
{
    struct Node<T>* t = nullptr; 

    if(p == nullptr)
    {
        t = new Node<T>; 
        t->data = key; 
        t->height = 1; 
        t->lchild = t->rchild = nullptr; 
        return t; 
    }
    if(key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if(key > p->data)
        p->rchild = RInsert(p->rchild, key);
    p->height = NodeHeight(p);

    if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
        return LRRotation(p); 
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->rchild) == -1)
        return RRRotation(p); 
    else if(BalanceFactor(p) == 2 && BalanceFactor(p->rchild) == 1)
        return RLRotation(p);
    return p; 
}
int main(int argc, char const *argv[])
{
    root = RInsert(root, 10);
    RInsert(root, 5);
    RInsert(root, 2);

    return 0;
}
