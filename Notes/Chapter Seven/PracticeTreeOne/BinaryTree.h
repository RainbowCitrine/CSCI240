#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <list> 
#include <queue>

template <typename T> 
class BinaryTree
{
protected: 
    struct Node
    {
        Node* parent; 
        Node* left; 
        Node* right; 
        T data; 
        Node() : parent(nullptr), left(nullptr), right(nullptr), data() { }
    };
public: 
    class Position
    {
        Node* v; 
    public: 
        Position(Node* _v = nullptr) : v(_v) { }
        bool operator==(const Position& p) {return v == p.v;}
        T& operator*() {return v->data;}
        Position parent() {return Position(v->parent);}
        Position isleft() {return Position(v->left);}
        Position isright() {return Position(v->right);}
        bool isExternal() {return v->right == nullptr && v->left == nullptr;}
        bool isRoot() {return v->parent == nullptr;}
        Node* getNode() const {return v;}
        friend class BinaryTree; 
    };
    typedef std::list<Position> PositionList; 
public: 
    BinaryTree() : _root(nullptr), num(0) { }
    int size() {return num;}
    bool isEmpty() {return size() == 0;}
    void addRoot() {_root = new Node; num = 1;}
    void expandExternal(const Position &p)
    {
        Node* w = p.v; 
        w->left = new Node; 
        w->right = new Node; 
        w->left->parent = w; 
        w->right->parent = w; 
        num += 2; 
    }
    void postorder(Node* v, PositionList &pl)
    {
        if(v != nullptr)
        {
            postorder(v->left, pl); 
            postorder(v->right, pl); 
            pl.push_back(v); 
        }
    }
    void preorder(Node* v, PositionList &pl)
    {
        pl.push_back(v); 
        if(v->left != nullptr)
            preorder(v->left, pl);
        if(v->right != nullptr)
            preorder(v->right, pl); 
    }
    void inorder(Node* v, PositionList &pl)
    {
        if(v != nullptr)
        {
            inorder(v->left, pl); 
            pl.push_back(v); 
            inorder(v->right, pl); 
        }
    }
    void levelorder(PositionList &pl) 
    {
        if(_root == nullptr)
            return; 
        
        std::queue<Node *> q; 
        q.push(_root); 

        while(!q.empty())
        {
            Node* current = q.front(); 
            q.pop(); 
            pl.push_back(current); 

            if(current->left != nullptr)
                q.push(current->left); 
            if(current->right != nullptr)
                q.push(current->right); 
        }
    }
    Position removeAboveExternal(const Position& p)
    {
        Node* w = p.v; // grab position of the external node 
        Node* v = w->parent; // grab the parent of the external node 

        //next find the sibling node 
        Node* sibling = (w == v->left ? v->right : v->left); 

        if(_root == v) // chekc if our root is equal to the parent 
        {
            _root = sibling; 
            sibling->parent = nullptr; 
        }
        else 
        {
            Node* grandparent = v->parent; // needs to be above the w->parent node to access 
            if(grandparent->left == v)
                grandparent->left = sibling; 
            if(grandparent->right == v)
                grandparent->right = sibling; 
            sibling->parent = grandparent; 
        }
        delete w; delete v; 
        num -= 2; 
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
            num++; 
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
            num++; 
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
        return pl;
    }
    PositionList preorder()
    {
        PositionList pl; 
        preorder(_root, pl); 
        return pl;
    }   
    PositionList inorder()
    {
        PositionList pl; 
        inorder(_root, pl); 
        return pl; 
    }
    PositionList postorder()
    {
        PositionList pl; 
        postorder(_root, pl); 
        return pl; 
    }
    PositionList levelorder()
    {
        Position pl; 
        postorder(_root, pl); 
        return pl; 
    }
private: 
    Node* _root; 
    int num;     
};

#endif