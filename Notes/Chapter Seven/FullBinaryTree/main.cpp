#include <iostream>
#include "BinaryTree.h"

int main() {
    // Create an empty binary tree
    LinkedBinaryTree<int> tree;

    // Test adding root node
    tree.addRoot();
    Position<int> root = tree.root();
    std::cout << "Root data: " << root.v->data << std::endl; // Should be 0 (default)

    // Test adding child nodes
    tree.expandExternal(root);
    Position<int> leftChild = root.left();
    Position<int> rightChild = root.right();

    // Set data for left and right children
    leftChild.v->data = 1;
    rightChild.v->data = 2;

    std::cout << "Left child data: " << leftChild.v->data << std::endl;   // Should be 1
    std::cout << "Right child data: " << rightChild.v->data << std::endl; // Should be 2

    // Test tree size and empty
    std::cout << "Tree size: " << tree.size() << std::endl; // Should be 3
    std::cout << "Is tree empty? " << (tree.empty() ? "Yes" : "No") << std::endl; // Should be No

    // Test positions() method
    PositionList positions = tree.positions();
    std::cout << "Positions in the tree: ";
    for (const Position<int>& pos : positions) {
        std::cout << pos.v->data << " ";
    }
    std::cout << std::endl; // Should be 0 1 2

    // Test removeAboveExternal
    Position<int> removedPosition = tree.removeAboveExternal(leftChild);
    std::cout << "Removed position data: " << removedPosition.v->data << std::endl; // Should be 1

    // Test tree size and empty after removal
    std::cout << "Tree size after removal: " << tree.size() << std::endl; // Should be 2
    std::cout << "Is tree empty after removal? " << (tree.empty() ? "Yes" : "No") << std::endl; // Should be No

    return 0;
}
