#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class AVLNode {
public:
    int key;
    std::string data;
    int height;
    AVLNode* left;
    AVLNode* right;

    AVLNode(int k, const std::string& d) : key(k), data(d), height(1), left(nullptr), right(nullptr) {}
};

class BetterPopMap {
private:
    AVLNode* root;

    int getHeight(AVLNode* node) {
        if (!node) return 0;
        return node->height;
    }

    int getBalanceFactor(AVLNode* node) {
        if (!node) return 0;
        return getHeight(node->left) - getHeight(node->right);
    }

    AVLNode* rotateLeft(AVLNode* node) {
        AVLNode* newRoot = node->right;
        node->right = newRoot->left;
        newRoot->left = node;

        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        newRoot->height = 1 + std::max(getHeight(newRoot->left), getHeight(newRoot->right));

        return newRoot;
    }

    AVLNode* rotateRight(AVLNode* node) {
        AVLNode* newRoot = node->left;
        node->left = newRoot->right;
        newRoot->right = node;

        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
        newRoot->height = 1 + std::max(getHeight(newRoot->left), getHeight(newRoot->right));

        return newRoot;
    }

    AVLNode* insert(AVLNode* node, int key, const std::string& data) {
        if (!node) return new AVLNode(key, data);

        if (key < node->key) {
            node->left = insert(node->left, key, data);
        }
        else if (key > node->key) {
            node->right = insert(node->right, key, data);
        }
        else {
            // Key already exists, update data
            node->data = data;
            return node;
        }

        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

        int balance = getBalanceFactor(node);

        if (balance > 1) {
            if (key < node->left->key) {
                return rotateRight(node);
            }
            else {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }

        if (balance < -1) {
            if (key > node->right->key) {
                return rotateLeft(node);
            }
            else {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

    AVLNode* findMinValueNode(AVLNode* node) {
        AVLNode* current = node;
        while (current->left) {
            current = current->left;
        }
        return current;
    }

    AVLNode* erase(AVLNode* node, int key) {
        if (!node) return node;

        if (key < node->key) {
            node->left = erase(node->left, key);
        }
        else if (key > node->key) {
            node->right = erase(node->right, key);
        }
        else {
            if (!node->left || !node->right) {
                AVLNode* temp = node->left ? node->left : node->right;
                if (!temp) {
                    temp = node;
                    node = nullptr;
                }
                else {
                    *node = *temp;
                }
                delete temp;
            }
            else {
                AVLNode* temp = findMinValueNode(node->right);
                node->key = temp->key;
                node->data = temp->data;
                node->right = erase(node->right, temp->key);
            }
        }

        if (!node) return node;

        node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));

        int balance = getBalanceFactor(node);

        if (balance > 1) {
            if (getBalanceFactor(node->left) >= 0) {
                return rotateRight(node);
            }
            else {
                node->left = rotateLeft(node->left);
                return rotateRight(node);
            }
        }

        if (balance < -1) {
            if (getBalanceFactor(node->right) <= 0) {
                return rotateLeft(node);
            }
            else {
                node->right = rotateRight(node->right);
                return rotateLeft(node);
            }
        }

        return node;
    }

    void printInOrder(AVLNode* node) {
        if (!node) return;
        printInOrder(node->left);
        std::cout << "Key: " << node->key << ", Data: " << node->data << ", Height: " << node->height << std::endl;
        printInOrder(node->right);
    }

public:
    BetterPopMap() : root(nullptr) {}

    void insert(int key, const std::string& data) {
        root = insert(root, key, data);
    }

    void erase(int key) {
        root = erase(root, key);
    }

    std::string find(int key) {
        AVLNode* node = root;
        while (node) {
            if (key < node->key) {
                node = node->left;
            }
            else if (key > node->key) {
                node = node->right;
            }
            else {
                return node->data;
            }
        }
        return "Not found";
    }

    void print() {
        printInOrder(root);
    }
};

int main() {
    BetterPopMap betterPopMap;

    std::ifstream inputFile("popSmall.txt");
    if (!inputFile) {
        std::cerr << "Error opening the input file." << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::istringstream iss(line);
        std::string token;
        int key;
        std::string data;

        if (std::getline(iss, token, ',')) {
            key = std::stoi(token);
        }

        if (std::getline(iss, data)) {
            size_t first = data.find_first_not_of(' ');
            size_t last = data.find_last_not_of(' ');
            data = data.substr(first, (last - first + 1));
        }

        betterPopMap.insert(key, data);
    }

    inputFile.close();

    std::cout << "List of all records:" << std::endl;
    betterPopMap.print();
    std::cout << std::endl;

    std::cout << "Search for key 6037: " << betterPopMap.find(6037) << std::endl;
    std::cout << "Search for key 6000: " << betterPopMap.find(6000) << std::endl;

    betterPopMap.insert(6066, "1, New County, CA");
    betterPopMap.insert(6065, "2000, Riverside, CA");

    std::cout << "Records after insertions:" << std::endl;
    betterPopMap.print();
    std::cout << std::endl;

    betterPopMap.erase(6999);
    betterPopMap.erase(6075);

    std::cout << "Records after deletions:" << std::endl;
    betterPopMap.print();

    return 0;
}



