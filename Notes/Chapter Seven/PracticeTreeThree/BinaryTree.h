#ifndef BIANRYTREE_H 
#define BINARYTREE_H

#include <list> 

template<typename T>
class BinaryTree
{
protected: 
    struct Node
    {
        Node* parent; 
        Node* right; 
        Node* left; 
        T data; 
        Node() : parent(nullptr), right(nullptr), left(nullptr), data() { }
    };
public: 
    // set up the position class to find try nodes and to create the list 
    class Position
    {
        Node* pos; 
    public: 
        Position(Node* _pos = nullptr) : pos(_pos) { } // create the constructor 
        bool isExternal() {return pos->left == nullptr && pos->right == nullptr;} // locate if it is an external branch
        bool isRoot() {return pos->parent == nullptr;} // check for the root branch 
        T& operator*() { return pos->data;} // check for the data 
        Position isLeft() {return Position(pos->left);} // check for the left branch
        Position isRight() {return Position(pos->right);} // check for the right branch
        bool operator==(const Position &p) {return pos == p.pos;} // compare two position nodes
        friend class BinaryTree;
    };
    typedef std::list<Position> PositionList; 
};


#endif