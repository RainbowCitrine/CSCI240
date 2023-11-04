#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    string data;
    vector<TreeNode*> children;
};

// Function to compute and print the string and height for internal nodes
int printStringAndHeight(TreeNode* node) {
    if (node->children.empty()) {
        // If the node has no children, it's a leaf node.
        // Print the string value stored at the leaf node and return a height of 1.
        cout << "Node: " << node->data << ", Height: " << 0 << endl;
        return 1;
    }

    int height = 0; // Initialize the height for this node.

    // Loop through the children of the current node.
    for (TreeNode* child : node->children) {
        // Recursively calculate the height of the subtree rooted at the child.
        // Take the maximum height among all children.
        height = max(height, printStringAndHeight(child));
    }

    // After processing all children, print the string value stored at the current node
    // and the height, which is the maximum child height plus 1.
    cout << "Node: " << node->data << ", Height: " << height << endl;
    return height + 1; // Return the height of the subtree rooted at this node.
}

int main() {
    // Create a sample tree
    TreeNode* root = new TreeNode{"Root", {}};
    TreeNode* node1 = new TreeNode{"Node 1", {}};
    TreeNode* node2 = new TreeNode{"Node 2", {}};
    TreeNode* node3 = new TreeNode{"Node 3", {}};
    TreeNode* node4 = new TreeNode{"Node 4", {}};
    TreeNode* node5 = new TreeNode{"Node 5", {}};

    // Define the tree structure by adding children to nodes.
    root->children = {node1, node2, node3};
    node2->children = {node4};
    node4->children = {node5};

    // Start the traversal from the root node.
    printStringAndHeight(root);

    return 0;
}
