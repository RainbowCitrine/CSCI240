### Explain why you would get the same output in an inorder listing of the entries in a binary search tree, T, independent of whether T is self balanced like an AVL tree, splay tree, or red-black tree

---

A binary search tree has at max 2 children. The left child always has a value less than the root node and the right child always has a value greater than the root node. Even if the Binary Search Tree is not balanced, the above condition is always satisfied i.e. nodes with a value less than the root will be in the left, and values greater will be in the right.

In Inorder Traversal, we first visit the left node, root node, and then the right node. Left->Root->Right.

Since the ordering of nodes is always maintained in a binary search tree, the inorder traversal will first cover the left node(i.e smallest value) followed by the root and then the right node. Even if the tree is not self-balancing like an AVL, splay, or red-black tree, the order of elements traversed will be the same. This is because:

It is the same as the smallest node will always be visited first. In a binary search tree, this always lies in the left subtree. This will be followed by the root and then the right subtree.

For eg, if you have balanced BST with the following nodes


Inorder Traversal: 7,10,15,20,30,45,55.

Now, in the same example if I were to remove 55 and 30, then the BST would be:



Inorder Traversal: 7,10,15,20,45

As you can see, the order of elements listing is the same in both examples, even though BST is not self-balancing.