#include <iostream>
#include <string>

template <typename Key, typename Value>
struct TreeNode {
    Key key;
    Value value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(Key k, Value v) : key(k), value(v), left(nullptr), right(nullptr) {}
};

template <typename Key, typename Value>
class BinarySearchTree {
public:
    BinarySearchTree() : root(nullptr) {}

    void insert(const Key& key, const Value& value) {
        root = insertHelper(root, key, value);
    }

    void erase(const Key& key) {
        root = eraseHelper(root, key);
    }

    Value find(const Key& key) {
        TreeNode<Key, Value>* node = findHelper(root, key);
        if (node) {
            return node->value;
        } else {
            return "Key not found.";
        }
    }

    void printInOrder() {
        printInOrderHelper(root);
    }

private:
    TreeNode<Key, Value>* root;

    TreeNode<Key, Value>* insertHelper(TreeNode<Key, Value>* node, const Key& key, const Value& value) {
        if (!node) {
            return new TreeNode<Key, Value>(key, value);
        }

        if (key < node->key) {
            node->left = insertHelper(node->left, key, value);
        } else if (key > node->key) {
            node->right = insertHelper(node->right, key, value);
        }

        return node;
    }

    TreeNode<Key, Value>* eraseHelper(TreeNode<Key, Value>* node, const Key& key) {
        if (!node) {
            return node;
        }

        if (key < node->key) {
            node->left = eraseHelper(node->left, key);
        } else if (key > node->key) {
            node->right = eraseHelper(node->right, key);
        } else {
            if (!node->left) {
                TreeNode<Key, Value>* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                TreeNode<Key, Value>* temp = node->left;
                delete node;
                return temp;
            }

            TreeNode<Key, Value>* temp = findMin(node->right);
            node->key = temp->key;
            node->value = temp->value;
            node->right = eraseHelper(node->right, temp->key);
        }

        return node;
    }

    TreeNode<Key, Value>* findMin(TreeNode<Key, Value>* node) {
        while (node->left) {
            node = node->left;
        }
        return node;
    }

    TreeNode<Key, Value>* findHelper(TreeNode<Key, Value>* node, const Key& key) {
        if (!node || node->key == key) {
            return node;
        }

        if (key < node->key) {
            return findHelper(node->left, key);
        } else {
            return findHelper(node->right, key);
        }
    }

    void printInOrderHelper(TreeNode<Key, Value>* node) {
        if (node) {
            printInOrderHelper(node->left);
            std::cout << "Key: " << node->key << ", Value: " << node->value << std::endl;
            printInOrderHelper(node->right);
        }
    }
};

int main() {
    BinarySearchTree<int, std::string> bst;

    bst.insert(10, "Alice");
    bst.insert(20, "Bob");
    bst.insert(4, "Charlie");
    bst.insert(8, "David");
    bst.insert(15, "Eve");

    // Erase operations
    bst.erase(8);
    bst.erase(10);

    std::cout << "Results of search operations:" << std::endl;
    std::cout << "Key: 15, Value: " << bst.find(15) << std::endl;
    std::cout << "Key: 30, " << bst.find(30) << std::endl;
    std::cout << "Key: 8, " << bst.find(8) << std::endl;

    std::cout << "Printing the BST:" << std::endl;
    bst.printInOrder();

    return 0;
}
