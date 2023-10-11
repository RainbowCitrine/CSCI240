#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <list>

template <class T>
struct Node
{
    T data;
    Node* parent;
    Node* left;
    Node* right;
    Node() : data(), parent(nullptr), left(nullptr), right(nullptr) { }
};

template <typename T>
class LinkedBinaryTree;

template <typename T>
class Position
{
public:
    Node<T>* v;
public:
    Position(Node<T>* w = nullptr) : v(w) { }

    Position left() const
    {
        return Position(v->left);
    }

    Position right() const
    {
        return Position(v->right);
    }

    Position parent() const
    {
        return Position(v->parent);
    }

    bool isRoot() const
    {
        return v->parent == nullptr;
    }

    bool isExternal() const
    {
        return v->left == nullptr && v->right == nullptr;
    }

    friend class LinkedBinaryTree<T>;
};

typedef std::list<Position<int>> PositionList;

template <class T>
class LinkedBinaryTree
{
public:
    LinkedBinaryTree() : _root(nullptr), n(0) { }
    int size() const { return n; }
    bool empty() const { return size() == 0; }
    Position<T> root() const { return Position<T>(_root); }
    PositionList positions() const
    {
        PositionList pl;
        preorder(_root, pl);
        return pl;
    }
    void addRoot() { _root = new Node<T>; n = 1; }
    void expandExternal(const Position<T>& p)
    {
        Node<T>* v = p.v;
        v->left = new Node<T>;
        v->left->parent = v;
        v->right = new Node<T>;
        v->right->parent = v;
        n += 2;
    }
    Position<T> removeAboveExternal(const Position<T>& p)
    {
        Node<T>* w = p.v;
        Node<T>* v = w->parent;
        Node<T>* sibling = (w == v->left) ? v->right : v->left;
        if (v == _root)
        {
            _root = sibling;
            sibling->parent = nullptr;
        }
        else
        {
            Node<T>* gparent = v->parent;
            if (v == gparent->left) gparent->left = sibling;
            else gparent->right = sibling;
            sibling->parent = gparent;
        }
        delete w;
        delete v;
        n -= 2;
        return Position<T>(sibling);
    }

protected:
    void preorder(Node<T>* v, PositionList& pl) const
    {
        if (v != nullptr)
        {
            pl.push_back(Position<T>(v));
            preorder(v->left, pl);
            preorder(v->right, pl);
        }
    }

private:
    Node<T>* _root;
    int n;
};
#endif
