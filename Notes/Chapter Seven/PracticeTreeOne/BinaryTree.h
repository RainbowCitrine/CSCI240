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
    BinaryTree() : _root(nullptr), n(0) {}
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
    int size() { return n; }
    bool isEmpty() { return size() == 0; }
    void addRoot()
    {
        _root = new Node;
        n = 1;
    } // add new root by creating a new node and adding 1 to the size
    void expandExternal(const Position &p)
    {
        Node *v = p.v; // grab from the position of where the node is
        v->left = new Node;
        v->left->parent = v; // point the left to the parent node
        v->right = new Node;
        v->right->parent = v; // point the right to the parent node
        n += 2;               // add two
    }
    void preorder(Node *v, PositionList &pl)
    {
        pl.push_back(Position(v));
        if (v->left != nullptr)
            preorder(v->left, pl);
        if (v->right != nullptr)
            preorder(v->right, pl);
    }
    void postorder(Node *v, PositionList &pl)
    {
        if (v != nullptr)
        {
            postorder(v->left, pl);
            postorder(v->right, pl);
            pl.push_back(Position(v));
        }
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
    Position removeAboveExternal(const Position &p)
    {
        Node *w = p.v;
        Node *v = w->parent;
        Node *sibling = (w == v->left ? v->right : v->left);
        if (v == _root)
        {
            _root = sibling;
            sibling->parent = nullptr;
        }
        else
        {
            Node *GrandParent = v->parent;
            if (v == GrandParent->left)
                GrandParent->left = sibling;
            else
                GrandParent->right = sibling;
            sibling->parent = GrandParent;
        }
        delete w;
        delete v;
        n -= 2;
        return Position(sibling);
    }
    Position insertLeft(const Position &p, const T &value)
    {
        Node *par = p.getNode();
        Node *newNode = new Node;
        newNode->data = value;
        newNode->parent = par; // setting the parent

        if (par->left == nullptr)
        {
            par->left = newNode; // create a new left pointer
            n++;                 // increase the size
        }
        return Position(newNode); // return the position
    }

    Position insertRight(const Position &p, const T &value)
    {
        Node *par = p.getNode();
        Node *newNode = new Node;
        newNode->data = value;
        newNode->parent = par;

        if (par->right == nullptr)
        {
            par->right = newNode;
            n++;
        }
        return Position(newNode);
    }

private:
    Node *_root;
    int n;
};

#endif