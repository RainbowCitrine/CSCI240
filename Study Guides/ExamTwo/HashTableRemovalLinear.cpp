/*
Describe how to perform a removal from a hash table that uses linear
probing to resolve collisions where we do not use a special marker to
represent deleted elements. That is, we must rearrange the contents so that
it appears that the removed entry was never inserted in the first place.
*/

#include <iostream>
#include <vector>

class HashTable {
private:
    int size;
    std::vector<std::pair<int, int>> table;

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int tableSize) : size(tableSize), table(tableSize, std::make_pair(-1, -1)) {}

    void insert(int key, int value) {
        int index = hashFunction(key);
        while (table[index].first != -1) {
            index = (index + 1) % size;
        }
        table[index] = std::make_pair(key, value);
    }

    void remove(int key) {
        int index = hashFunction(key);
        while (table[index].first != -1) {
            if (table[index].first == key) {
                // Remove the element and rearrange the table
                table[index] = std::make_pair(-1, -1);
                int nextIndex = (index + 1) % size;

                while (table[nextIndex].first != -1) {
                    int newIndex = hashFunction(table[nextIndex].first);
                    if (newIndex <= index) {
                        table[index] = table[nextIndex];
                        table[nextIndex] = std::make_pair(-1, -1);
                        index = nextIndex;
                    }
                    nextIndex = (nextIndex + 1) % size;
                }
                return; // Element removed
            }
            index = (index + 1) % size;
        }
    }

    int search(int key) {
        int index = hashFunction(key);
        while (table[index].first != -1) {
            if (table[index].first == key) {
                return table[index].second;
            }
            index = (index + 1) % size;
        }
        return -1; // Element not found
    }
};

int main() {
    HashTable hashTable(10);

    hashTable.insert(3, 10);
    hashTable.insert(11, 20);
    hashTable.insert(17, 30);
    hashTable.insert(25, 40);
    hashTable.insert(39, 50);
    hashTable.insert(8, 60);
    hashTable.insert(9, 70);

    std::cout << "Initial Hash Table:" << std::endl;
    for (auto pair : hashTable.table) {
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    std::cout << std::endl;

    // Remove an element
    hashTable.remove(17);

    std::cout << "\nHash Table after removing 17:" << std::endl;
    for (auto pair : hashTable.table) {
        std::cout << "(" << pair.first << ", " << pair.second << ") ";
    }
    std::cout << std::endl;

    return 0;
}
