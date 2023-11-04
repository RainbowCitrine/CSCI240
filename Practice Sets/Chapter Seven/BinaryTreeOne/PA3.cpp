#include <iostream>
#include <list>
#include "linkedtree.h"
using namespace std;

int main() {
    BinaryTree<string> tree;
    tree.addRoot();
    BinaryTree<string>::Position root = tree.root();
    *root = "A";

    BinaryTree<string>::Position b = tree.insertLeft(root, "B");
    BinaryTree<string>::Position c = tree.insertRight(root, "C");
    BinaryTree<string>::Position d = tree.insertLeft(b, "D");
    BinaryTree<string>::Position e = tree.insertRight(b, "E");
    BinaryTree<string>::Position f = tree.insertRight(c, "F");
    std::cout << "Author: Noah Rainbow" << std::endl;
    std::cout << "Original Post-order traversal: ";
    BinaryTree<string>::PositionList postorder = tree.postorder();
    for (auto pos : postorder) {
        std::cout << *pos << " ";
    }
    std::cout << std::endl;

    // Remove node E
    tree.removeAboveExternal(e);

    std::cout << "Post-order traversal after removing E: ";
    postorder = tree.postorder();
    for (auto pos : postorder) {
        std::cout << *pos << " ";
    }
    std::cout << std::endl;

    return 0;
}
