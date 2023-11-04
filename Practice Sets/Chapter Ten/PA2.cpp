#include <iostream>
#include <fstream>
#include <string>

// Definition of a node in the binary search tree
struct TreeNode {
    int code;
    std::string data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int code, const std::string& data) : code(code), data(data), left(nullptr), right(nullptr) {}
};

class PopMap {
private:
    TreeNode* root;

    // Helper function to insert a new node into the tree
    TreeNode* insert(TreeNode* node, int code, const std::string& popCounty) {
        if (node == nullptr) {
            return new TreeNode(code, popCounty);
        }

        if (code < node->code) {
            node->left = insert(node->left, code, popCounty);
        } else if (code > node->code) {
            node->right = insert(node->right, code, popCounty);
        } else {
            // If the key already exists, update the data
            node->data = popCounty;
        }

        return node;
    }

    // Helper function to find and return a node by its key
    TreeNode* find(TreeNode* node, int code) {
        if (node == nullptr) {
            return nullptr;
        }

        if (code < node->code) {
            return find(node->left, code);
        } else if (code > node->code) {
            return find(node->right, code);
        } else {
            return node;
        }
    }

    // Helper function to perform an in-order traversal and print the records
    void printInOrder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }

        printInOrder(node->left);
        std::cout << "Code: " << node->code << ", Data: " << node->data << std::endl;
        printInOrder(node->right);
    }

public:
    // Constructor that accepts a filename and constructs the search tree
    PopMap(const std::string& filename) : root(nullptr) {
        // Read data from the input file and insert into the tree
        std::ifstream file(filename);
        if (file.is_open()) {
            int code;
            std::string popCounty;
            while (file >> code) {
                file.ignore(); // Ignore the comma
                std::getline(file, popCounty);
                root = insert(root, code, popCounty);
            }
            file.close();
        }
    }

    // Find and print a record with the given code
    void find(int code) {
        TreeNode* node = find(root, code);
        if (node != nullptr) {
            std::cout << "Found Record - Code: " << node->code << ", Data: " << node->data << std::endl;
        } else {
            std::cout << "Record with code " << code << " not found." << std::endl;
        }
    }

    // Insert or update a record with the given code and data
    void insert(int code, const std::string& popCounty) {
        root = insert(root, code, popCounty);
        std::cout << "Inserted/Updated Record - Code: " << code << ", Data: " << popCounty << std::endl;
    }

    // Erase a record with the given code
    void erase(int code) {
        TreeNode* node = find(root, code);
        if (node != nullptr) {
            root = erase(root, code);
            std::cout << "Deleted Record - Code: " << code << ", Data: " << node->data << std::endl;
        } else {
            std::cout << "Record with code " << code << " not found." << std::endl;
        }
    }

    // Helper function to erase a node from the tree
    TreeNode* erase(TreeNode* node, int code) {
        if (node == nullptr) {
            return node;
        }

        if (code < node->code) {
            node->left = erase(node->left, code);
        } else if (code > node->code) {
            node->right = erase(node->right, code);
        } else {
            if (node->left == nullptr) {
                TreeNode* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                TreeNode* temp = node->left;
                delete node;
                return temp;
            }
            // Node with two children: Get the in-order successor (smallest in the right subtree)
            TreeNode* temp = minValueNode(node->right);
            // Copy the in-order successor's content to this node
            node->code = temp->code;
            node->data = temp->data;
            // Delete the in-order successor
            node->right = erase(node->right, temp->code);
        }

        return node;
    }

    // Helper function to find the node with the smallest key in a subtree
    TreeNode* minValueNode(TreeNode* node) {
        TreeNode* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // Print all records using an in-order traversal
    void print() {
        if (root == nullptr) {
            std::cout << "No records to print." << std::endl;
        } else {
            std::cout << "All Records:" << std::endl;
            printInOrder(root);
        }
    }
};


int main() {
    PopMap popDatabase("popSmall.txt");

    // Test cases
    popDatabase.print(); // List all records
    popDatabase.find(6037); // Search for 6037
    popDatabase.find(6000); // Search for 6000
    popDatabase.insert(6066, "1, New County, CA"); // Insert 6066
    popDatabase.insert(6065, "2000, Riverside, CA"); // Insert 6065
    popDatabase.erase(6999); // Delete 6999
    popDatabase.erase(6075); // Delete 6075
    popDatabase.erase(6055); // Delete 6055
    popDatabase.print(); // List all records

    return 0;
}

