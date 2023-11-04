#ifndef PRIORITYHEAPQUEUE_H
#define PRIORITYHEAPQUEUE_H 

#include <queue>
#include <vector>
#include <functional>

template <typename E>
class VectorCompleteTree
{
private:
    std::vector<E> V;

public:
    typedef typename std::vector<E>::iterator Position;

protected:
    Position pos(int i)
    {
        return V.begin() + i;
    }

    int idx(const Position &p) const
    {
        return p - V.begin();
    }

public:
    VectorCompleteTree() : V(1) {}
    int size() const { return V.size() - 1; }
    Position left(const Position &p) { return pos(2 * idx(p)); }
    Position right(const Position &p) { return pos(2 * idx(p) + 1); }
    Position parent(const Position &p) { return pos(idx(p) / 2); }
    bool hasLeft(const Position &p) const { return 2 * idx(p) <= size(); }
    bool hasRight(const Position &p) const { return 2 * idx(p) + 1 <= size(); }
    bool isRoot(const Position &p) const { return idx(p) == 1; }
    Position root() { return pos(1); }
    Position last() { return pos(size()); }
    void addLast(const E &e) { V.push_back(e); }
    void removeLast() { V.pop_back(); }
    void swap(const Position &p, const Position &q)
    {
        E e = *q;
        *q = *p;
        *p = e;
    }
};

template <typename T>
struct MaxComparator
{
    bool operator()(const T a, const T b) const
    {
        return a > b;
    }
};

template <typename T>
struct MinComparator
{
    bool operator()(T a, T b) const
    {
        return a < b;
    }
};

template <typename E, typename C>
class HeapPriorityQueue
{
public:
    int size() const;
    bool empty() const;
    void insert(const E &e);
    const E &min();
    void removeMin();

private:
    VectorCompleteTree<E> T;
    C isLess;
    typedef typename VectorCompleteTree<E>::Position Position;
};

template <typename E, typename C>
int HeapPriorityQueue<E, C>::size() const
{
    return T.size();
}

template <typename E, typename C>
bool HeapPriorityQueue<E, C>::empty() const
{
    return size() == 0;
}

template <typename E, typename C>
const E &HeapPriorityQueue<E, C>::min()
{
    return *(T.root());
}

template <typename E, typename C> // remove minimum
void HeapPriorityQueue<E, C>::removeMin()
{
    if (size() == 1)    // only one node?
        T.removeLast(); // ...remove it
    else
    {
        Position u = T.root(); // root position
        T.swap(u, T.last());   // swap last with root
        T.removeLast();        // ...and remove last
        while (T.hasLeft(u))
        { // down-heap bubbling
            Position v = T.left(u);
            if (T.hasRight(u) && isLess(*(T.right(u)), *v))
                v = T.right(u); // v is u's smaller child
            if (isLess(*v, *u))
            {                 // is u out of order?
                T.swap(u, v); // ...then swap
                u = v;
            }
            else
                break; // else we're done
        }
    }
}

template <typename E, typename C>
void HeapPriorityQueue<E, C>::insert(const E &e)
{
    T.addLast(e);
    Position v = T.last();
    while (!T.isRoot(v))
    {
        Position u = T.parent(v);
        if (!isLess(*v, *u))
            break;
        T.swap(v, u);
        v = u;
    }
}

#endif