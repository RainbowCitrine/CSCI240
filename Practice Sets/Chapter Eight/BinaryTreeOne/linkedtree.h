#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <list>
using namespace std;

template <typename Elem>
class BinaryTree {
protected:
    struct Node {
        Elem    elt;
        Node*   par;
        Node*   left;
        Node*   right;

        Node() : elt(), par(nullptr), left(nullptr), right(nullptr) { }
    };

public:
    class Position {
    private:
        Node* v;
    public:
        Position(Node* _v = nullptr) : v(_v) { }

        Node* getNode() const
        {
            return v; 
        }

        Elem& operator*()
        { return v->elt; }

        Position left() const
        { return Position(v->left); }

        Position right() const
        { return Position(v->right); }

        Position parent() const
        { return Position(v->par); }

        bool isRoot() const
        { return v->par == nullptr; }

        bool isExternal() const
        { return v->left == nullptr && v->right == nullptr; }

        bool operator==(const Position& p) const
        { return v == p.v; }

        friend class BinaryTree;
    };

    typedef std::list<Position> PositionList;

public:
    BinaryTree();
    int size() const;
    bool empty() const;
    Position root() const
    { return Position(_root); }

    PositionList positions() const
    {
        PositionList pl;
        preorder(_root, pl);
        return PositionList(pl);
    }

    void addRoot();
    void expandExternal(const Position& p);

    Position removeAboveExternal(const Position& p)
    {
        Node* w = p.v;  Node* v = w->par;
        Node* sib = (w == v->left ?  v->right : v->left);
        if (v == _root) {
            _root = sib;
            sib->par = nullptr;
        }
        else {
            Node* gpar = v->par;
            if (v == gpar->left) gpar->left = sib;
            else gpar->right = sib;
            sib->par = gpar;
        }
        delete w; delete v;
        n -= 2;
        return Position(sib);
    }

    Position insertLeft(const Position& p, const Elem& value);
    Position insertRight(const Position& p, const Elem& value);

    PositionList postorder() const
    {
        PositionList pl;
        postorder(_root, pl);
        return PositionList(pl);
    }

protected:
    void preorder(Node* v, PositionList& pl) const;
    void postorder(Node* v, PositionList& pl) const;

private:
    Node* _root;
    int n;
};

template <typename Elem>
BinaryTree<Elem>::BinaryTree()
    : _root(nullptr), n(0) { }

template <typename Elem>
int BinaryTree<Elem>::size() const
{ return n; }

template <typename Elem>
bool BinaryTree<Elem>::empty() const
{ return size() == 0; }

template <typename Elem>
void BinaryTree<Elem>::addRoot()
{ _root = new Node; n = 1; }

template <typename Elem>
void BinaryTree<Elem>::expandExternal(const Position& p) {
    Node* v = p.v;
    v->left = new Node;
    v->left->par = v;
    v->right = new Node;
    v->right->par = v;
    n += 2;
}

template <typename Elem>
typename BinaryTree<Elem>::Position BinaryTree<Elem>::insertLeft(const Position& p, const Elem& value) {
    Node* parent = p.v;
    Node* new_node = new Node();
    new_node->elt = value;
    new_node->par = parent;

    if (parent->left == nullptr) {
        parent->left = new_node;
        n++;
    }

    return Position(new_node);
}

template <typename Elem>
typename BinaryTree<Elem>::Position BinaryTree<Elem>::insertRight(const Position& p, const Elem& value) {
    Node* parent = p.v;
    Node* new_node = new Node();
    new_node->elt = value;
    new_node->par = parent;

    if (parent->right == nullptr) {
        parent->right = new_node;
        n++;
    }

    return Position(new_node);
}

template <typename Elem>
void BinaryTree<Elem>::preorder(Node* v, PositionList& pl) const {
    pl.push_back(Position(v));
    if (v->left != nullptr)
        preorder(v->left, pl);
    if (v->right != nullptr)
        preorder(v->right, pl);
}

template <typename Elem>
void BinaryTree<Elem>::postorder(Node* v, PositionList& pl) const {
    if (v != nullptr) {
        postorder(v->left, pl);
        postorder(v->right, pl);
        pl.push_back(Position(v));
    }
}


#endif
