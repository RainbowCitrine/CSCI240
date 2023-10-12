#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <list>

template <typename T>
class BinaryTree
{
protected:
    struct Node
    {
        T data;
        Node *parent;
        Node *left;
        Node *right;
        Node() : data(), parent(nullptr), left(nullptr), right(nullptr) {}
    };

public:
    class Position
    {
    private:
        Node *v;

    public:
        Position(Node *_v = nullptr) : v(_v) {}
        Node *getNode() const { return v; }
        T &operator*() { return v->data; }
        Position toLeft() { return Position(v->left); }
        Position toRight() { return Position(v->right); }
        bool isRoot() { return v->parent == nullptr; }
        bool isExternal() { return v->left == nullptr && v->right == nullptr; }
        bool operator==(const Position &p) { return v == p.v; }
        friend class BinaryTree;
    };
    typedef std::list<Position> PositionList;

public:
    /*
        step 1 create constructor 
        step 2 return size 
        step 3 check empty 
        step 4 add your root 
        step 5 expand your binary tree by expanding internal nodes 
        step 6 do the three traversals: preorder, postorder, inorder    

    */
    BinaryTree() : _root(nullptr), n(0) {}
    int size() {return n;}
    bool isEmpty() {return size() == 0;}
    void addRoot() {_root = new Node; n = 1;}
    void expandExternal(const Position& p)
    {
        Node* v = p.v;
        v->left = new Node; 
        v->right = new Node; 
        v->left->parent = v; 
        v->right->parent = v; 
        n += 2; 
    }
    void postorder(Node* v, PositionList& pl)
    {
        if(v != nullptr)
        {
            postorder(v->left, pl); 
            postorder(v->right, pl); 
            pl.push_back(Position(v)); // starting from the first node
        }
    }
    void preorder(Node* v, PositionList& pl)
    {
        pl.push_back(Position(v)); 
        if(v->left != nullptr)
            preorder(v->left, pl); 
        if(v->right != nullptr)
            preorder(v->right, pl); 
    }
    void inorder(Node* v, PositionList& pl)
    {
        if(v != nullptr)
        {
            inorder(v->left, pl); 
            pl.push_back(Position(v)); 
            inorder(v->right, pl); 
        }
    }
    Position removeAboveExternal(const Position& p)
    {
        Node* w = p.v; 
        Node* v = w->parent; 
        Node* sibling = (w == v->left ? v->right : v->left); 

        if(_root == v)
        {
            _root = sibling; 
            sibling->parent = nullptr; 
        }
        else 
        {
            Node* grandParent = v->parent; 
            if(grandParent->left == v)
                grandParent->left = sibling; 
            else 
                grandParent->right = sibling; 
            sibling->parent = grandParent; 
        }
        delete w; delete v; 
        n -= 2; 
        return Position(sibling); 
    }
    Position insertLeft(const Position& p, const T& data)
    {
        Node* par = p.getNode(); 
        Node* newNode = new Node; 
        newNode->data = data; 
        newNode->parent = par; 

        if(newNode->left == nullptr)
        {
            par->left = newNode;  
            n++; 
        }
        return Position(newNode); 
    }
    Position insertRight(const Position& p, const T& data)
    {
        Node* par = p.getNode(); 
        Node* newNode = new Node; 
        newNode->data = data; 
        newNode->parent = par; 

        if(newNode->right == nullptr)
        {
            par->right = newNode; 
            n++; 
        }
        return Position(newNode); 
    }
    Position root()
    {
        return Position(_root);
    }
    PositionList Positions()
    {
        PositionList pl;
        preorder(_root, pl);
        return PositionList(pl);
    }
    PositionList preorder() 
    {
        PositionList pl; 
        preorder(_root, pl); 
        return pl; 
    }
    PositionList postorder() 
    {
        PositionList pl;
        postorder(_root, pl);
        return pl;
    }
    PositionList inorder() 
    {
        PositionList pl; 
        inorder(_root, pl); 
        return PositionList(pl); 
    }
private:
    Node *_root;
    int n;
};

#endif