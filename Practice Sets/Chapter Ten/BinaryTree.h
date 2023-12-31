#ifndef BINARY_TREE_H
#define BINARY_TREE_H
// Modified for CSCI 220 Fall 13
// Updated Fall 21

#include <list>
using namespace std;
  
//typedef int Elem;					// base element type
template <typename Elem>
class BinaryTree {
protected:
    // insert Node declaration here...
    struct Node {					// a node of the tree
      Elem    elt;					// element value
      Node*   par;					// parent
      Node*   left;					// left child
      Node*   right;				// right child
      Node() : elt(), par(nullptr), left(nullptr), right(nullptr) { } // constructor
    };

public:
    // insert Position declaration here...
    class Position {					            // position in the tree
    private:
        Node* v;						            // pointer to the node
    public:
        Position(Node* _v = nullptr) : v(_v) { }		// constructor
        Elem& operator*()					        // get element
        { return v->elt; }

        Position left() const				        // get left child
        { return Position(v->left); }

        Position right() const				        // get right child
        { return Position(v->right); }

        Position parent() const				        // get parent
        { return Position(v->par); }

        bool isRoot() const				            // root of the tree?
        { return v->par == nullptr; }

        bool isExternal() const				        // an external node?
        { return v->left == nullptr && v->right == nullptr; }

        bool operator==(const Position& p) const    // compare two positions
        { return v == p.v; }

        friend class BinaryTree;			        // give tree access
    };

    typedef std::list<Position> PositionList;		// list of positions

 public:
    BinaryTree();					                // constructor
    int size() const ;					            // number of nodes
    bool empty() const;                             // is tree empty?

    Position root() const				            // get the root
	{ return Position(_root); }
	
	PositionList positions() const  			    // list of nodes
	{
		PositionList pl;
		preorder(_root, pl);					    // preorder traversal
		return PositionList(pl);				    // return resulting list
	}
	
	void addRoot();					                // add root to empty tree
    void expandExternal(const Position& p);		    // expand external node

    Position removeAboveExternal(const Position& p)	// remove p and parent
	{
		Node* w = p.v;  Node* v = w->par;			// get p's node and parent
		Node* sib = (w == v->left ?  v->right : v->left);
		if (v == _root) {					        // child of root?
		  _root = sib;					            // ...make sibling root
		  sib->par = nullptr;
		}
		else {
		  Node* gpar = v->par;				        // w's grandparent
		  if (v == gpar->left) gpar->left = sib; 	// replace parent by sib
		  else gpar->right = sib;
		  sib->par = gpar;
		}
		delete w; delete v;					        // delete removed nodes
		n -= 2;						                // two fewer nodes
		return Position(sib);
  }

	// housekeeping functions omitted...
protected: 						// local utilities
    void preorder(Node* v, PositionList& pl) const;	// preorder utility
private:
    Node* _root;					                // pointer to the root
    int n;						                    // number of nodes
  };

template <typename Elem>
BinaryTree<Elem>::BinaryTree()			            // constructor
    : _root(nullptr), n(0) { }

template <typename Elem>
int BinaryTree<Elem>::size() const			        // number of nodes
    { return n; }

template <typename Elem>
bool BinaryTree<Elem>::empty() const			    // is tree empty?
    { return size() == 0; }

template <typename Elem>
void BinaryTree<Elem>::addRoot()			        // add root to empty tree
    { _root = new Node; n = 1; }

template <typename Elem>
void BinaryTree<Elem>::expandExternal(const Position& p) {
    Node* v = p.v;					                // p's node
    v->left = new Node;					            // add a new left child
    v->left->par = v;					            // v is its parent
    v->right = new Node;				            // and a new right child
    v->right->par = v;					            // v is its parent
    n += 2;						                    // two more nodes
 }

							// preorder traversal
template <typename Elem>
void BinaryTree<Elem>::preorder(Node* v, PositionList& pl) const {
    pl.push_back(Position(v));				// add this node
    if (v->left != nullptr)					// traverse left subtree
        preorder(v->left, pl);
    if (v->right != nullptr)					// traverse right subtree
        preorder(v->right, pl);
}


#endif