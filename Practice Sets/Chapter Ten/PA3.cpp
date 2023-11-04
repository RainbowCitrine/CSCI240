#include <iostream>
#include <string>


class AVLNode {
public:
    int key;
    std::string value;
    AVLNode* left;
    AVLNode* right;
    int height;

    AVLNode(int key, const std::string& value)
        : key(key), value(value), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree {
private:
    AVLNode* root;

    int getHeight(AVLNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->height;
    }

    int getBalanceFactor(AVLNode* node) {
        if (node == nullptr) {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    void updateHeight(AVLNode* node) {
        if (node != nullptr) {
            node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        }
    }

    AVLNode* rotateRight(AVLNode* y) {
        AVLNode* x = y->left;
        AVLNode* T2 = x->right;

        x->right = y;
        y->left = T2;

        updateHeight(y);
        updateHeight(x);

        return x;
    }

    AVLNode* rotateLeft(AVLNode* x) {
        AVLNode* y = x->right;
        AVLNode* T2 = y->left;

        y->left = x;
        x->right = T2;

        updateHeight(x);
        updateHeight(y);

        return y;
    }

    AVLNode* insert(AVLNode* node, int key, const std::string& value) {
        if (node == nullptr) {
            return new AVLNode(key, value);
        }

        if (key < node->key) {
            node->left = insert(node->left, key, value);
        } else if (key > node->key) {
            node->right = insert(node->right, key, value);
        } else {
            // Duplicate keys not allowed in this example
            return node;
        }

        updateHeight(node);

        int balance = getBalanceFactor(node);

        if (balance > 1) {
            if (key < node->left->key) {
                return rotateRight(node);
            } else {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }

        if (balance < -1) {
            if (key > node->right->key) {
                return rotateLeft(node);
            } else {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

    AVLNode* findMinNode(AVLNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }

    AVLNode* erase(AVLNode* node, int key) {
        if (node == nullptr) {
            return node;
        }

        if (key < node->key) {
            node->left = erase(node->left, key);
        } else if (key > node->key) {
            node->right = erase(node->right, key);
        } else {
            if (node->left == nullptr || node->right == nullptr) {
                AVLNode* temp = (node->left != nullptr) ? node->left : node->right;

                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }

                delete temp;
            } else {
                AVLNode* temp = findMinNode(node->right);
                node->key = temp->key;
                node->value = temp->value;
                node->right = erase(node->right, temp->key);
            }
        }

        if (node == nullptr) {
            return node;
        }

        updateHeight(node);

        int balance = getBalanceFactor(node);

        if (balance > 1) {
            if (getBalanceFactor(node->left) >= 0) {
                return rotateRight(node);
            } else {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }

        if (balance < -1) {
            if (getBalanceFactor(node->right) <= 0) {
                return rotateLeft(node);
            } else {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

    void inOrderTraversal(AVLNode* node) {
        if (node != nullptr) {
            inOrderTraversal(node->left);
            std::cout << "Key: " << node->key << ", Value: " << node->value << ", Height: " << node->height << "\n";
            inOrderTraversal(node->right);
        }
    }

public:
    AVLTree() : root(nullptr) {}

    void insert(int key, const std::string& value) {
        root = insert(root, key, value);
    }

    void erase(int key) {
        root = erase(root, key);
    }

    std::string find(int key) {
        AVLNode* current = root;
        while (current != nullptr) {
            if (key < current->key) {
                current = current->left;
            } else if (key > current->key) {
                current = current->right;
            } else {
                return current->value;
            }
        }
        return "Key not found";
    }

    void printTree() {
        inOrderTraversal(root);
    }
};

int main() {
    AVLTree avlTree;

    avlTree.insert(10, "Alice");
    avlTree.insert(20, "Bob");
    avlTree.insert(4, "Charlie");
    avlTree.insert(8, "David");
    avlTree.insert(15, "Eve");

    avlTree.erase(8);
    avlTree.erase(10);

    std::cout << "Searching for keys and their values:\n";
    std::cout << "Key 15: " << avlTree.find(15) << "\n";
    std::cout << "Key 30: " << avlTree.find(30) << "\n";
    std::cout << "Key 8: " << avlTree.find(8) << "\n";

    std::cout << "\nAVL Tree (Key, Value, Height):\n";
    avlTree.printTree();

    return 0;
}


