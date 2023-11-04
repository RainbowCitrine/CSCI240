#ifndef PRIORITYHEAP_H
#define PRIORITYHEAP_H


#include <vector>
#include <iterator>

template <typename T> 
class VectorCompleteTree
{
private: 
    std::vector<T> V; // Tree contents 
public: 
    typedef typename std::vector<T>::iterator Position; // locating the position of a tree
protected: 
    Position pos(int i) {return V.begin() + i;} // map at an index to a positon 
    int idx(const Position& p) const {return p - V.begin();} // map a position to an index
public: 
    VectorCompleteTree() : V(1) { }
    int size() const {return V.size() - 1;} // return the size of the tree
    Position left(const Position &p) {return pos(2*idx(p));}
    Position right(const Position &p) {return pos(2*idx(p) +1);}
    Position parent(const Position &p) {return pos(idx(p)/2);}
    bool hasLeft(const Position &p) {return 2*idx(p) <= size();}
    bool hasRight(const Position &p) {return 2* idx(p) + 1 <= size();}
    bool isRoot(const Position &p) {return idx(p) == 1;}
    Position root() {return pos(1);}
    Position last() {return pos(size());}
    void addLast(const T& e) {V.push_back(e);}
    void removeLast() {V.pop_back();}
    void swap(const Position &p, const Position &q) {T e = *q; *q = *p; *p = e;}
};

template <typename T, typename C>
class HeapPriorityQueue
{

public: 
    int size() const 
    {
        return Tree.size(); 
    }
    bool empty() const 
    {
        return size() == 0; 
    }
    const T& min()
    {
        return *(Tree.root());
    }
    void insert(const T& e)
    {
        Tree.addLast(e); // add e to heap 
        Position v = Tree.last(); // e's position
        while(!Tree.isRoot(v)) // up heap bubbling
        {
            Position u = Tree.parent(v); 
            if(!isLess(*v, *u)) break; // if v is in order we're down 
            Tree.swap(v, u); // else swap parent
            v = u; 
        }
    }
    void removeMin()
    {
        if(size() == 1)
            Tree.removeLast(); 
        else
        {
            Position u = Tree.root(); // root position 
            Tree.swap(u, Tree.last()); // swap last with root
            Tree.removeLast(); // remove last 
            while(Tree.hasLeft(u)) // down heap bubbling
            {
                Position v = Tree.left(u); 
                if(Tree.hasRight(u) && isLess(*(Tree.right(u)), *v))
                    v = Tree.right(u); // v is u's smaller child
                if(isLess(*v, *u)) // is u out of order
                {
                    Tree.swap(u, v); // then swap 
                    u = v; 
                }
                else break; 
            }
        }
    }
private: 
    VectorCompleteTree<T> Tree; 
    C isLess; 
    typedef typename VectorCompleteTree<T>::Position Position; 
};

template <typename T> 
struct MaxComp
{
    bool operator()(const T& a, const T& b) {return a > b;}
};

template <typename T> 
struct MinComp
{
    bool operator()(const T& a, const T& b) {return a < b;}
};

#endif 