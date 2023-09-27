#include <iostream> 

#pragma once
typedef std::string Elem; // list base element type
class NodeList {
private:
	struct Node { // a node of the list
		Elem elem; // element value
		Node* prev; // previous in list
		Node* next; // next in list
	};
public:
	class Iterator { // an iterator for the list
	public:
		Elem& operator*(); // reference to the element
		bool operator==(const Iterator& p) const; // compare positions
		bool operator!=(const Iterator& p) const;
		Iterator& operator++(); // move to next position, pre-increment
		Iterator& operator--(); // move to previous position, pre-decrement
		friend class NodeList; // give NodeList access
	private:
		Node* v; // pointer to the node
		Iterator(Node* u); // create from node
	};
public:
	NodeList(); // default constructor
	int size() const; // list size
	bool empty() const; // is the list empty?
	Iterator begin() const; // beginning position
	Iterator end() const; // (just beyond) last position
	void insertFront(const Elem& e); // insert at front
	void insertBack(const Elem& e); // insert at rear
	void insert(const Iterator& p, const Elem& e); // insert e before p
	void eraseFront(); // remove first
	void eraseBack(); // remove last
	void erase(const Iterator& p); // remove p
	// housekeeping functions omitted...
    int indexOf(const Iterator& p) const; 
    Iterator atIndex(int i) const; 
private: // data members
	int n; // number of items
	Node* header; // head-of-list sentinel
	Node* trailer; // tail-of-list sentinel
};

NodeList::NodeList() { // constructor
	n = 0; // initially empty
	header = new Node; // create sentinels
	trailer = new Node;
	header->next = trailer; // have them point to each other
	trailer->prev = header;
}

int NodeList::size() const // list size
{
	return n;
}

bool NodeList::empty() const // is the list empty?
{
	return (n == 0);
}
void NodeList::insert(const NodeList::Iterator& p, const Elem& e) {
	Node* w = p.v; // p's node
	Node* u = w->prev; // p's predecessor
	Node* v = new Node; // new node to insert
	v->elem = e;
	v->next = w; w->prev = v; // link in v before w
	v->prev = u; u->next = v; // link in v after u
	n++;
}
void NodeList::erase(const Iterator& p) { // remove p
	Node* v = p.v; // node to remove
	Node* w = v->next; // successor
	Node* u = v->prev; // predecessor
	u->next = w; w->prev = u; // unlink p
	delete v; // delete this node
	n--; // one fewer element
}
NodeList::Iterator NodeList::begin() const // begin position is first item
{
	return Iterator(header->next);
}

NodeList::Iterator NodeList::end() const // end position is just beyond last
{
	return Iterator(trailer);
}
NodeList::Iterator::Iterator(Node* u) // constructor from Node*
{
	v = u;
}

Elem& NodeList::Iterator::operator*() // reference to the element
{
	return v->elem;
}
// compare positions
bool NodeList::Iterator::operator==(const Iterator& p) const
{
	return v == p.v;
}

bool NodeList::Iterator::operator!=(const Iterator& p) const
{
	return v != p.v;
}
// move to next position
NodeList::Iterator& NodeList::Iterator::operator++()
{
	v = v->next; return *this;
}
// move to previous position
NodeList::Iterator& NodeList::Iterator::operator--()
{
	v = v->prev; return *this;
}
void NodeList::eraseFront() // remove first
{
	erase(begin());
}

void NodeList::eraseBack() // remove last
{
	erase(--end());
}
void NodeList::insertFront(const Elem& e) // insert at front
{
	insert(begin(), e);
}

void NodeList::insertBack(const Elem& e) // insert at rear
{
	insert(end(), e);
}

int NodeList::indexOf(const Iterator& p) const 
{
    int index = 0;
    NodeList::Iterator current = begin();

    while (current != p && current != end()) {
        ++index;
        ++current;
    }

    if (current == end()) {
        // Position p is not found in the list
        return -1;
    }

    return index;
}

NodeList::Iterator NodeList::atIndex(int i) const 
{
    if (i < 0 || i >= n) {
        // Invalid index, return the end iterator
        return end();
    }

    NodeList::Iterator current = begin();
    for (int j = 0; j < i; ++j) {
        ++current;
    }

    return current;
}
