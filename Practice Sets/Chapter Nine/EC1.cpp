#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <set>

// Function to calculate the cyclic shift hash code
unsigned long long cyclicShiftHash(const std::string& word, int shift) {
    unsigned long long hash = 0;
    for (char c : word) {
        hash = (hash << shift) | c;
    }
    return hash;
}

int main() {
    std::ifstream file("usdeclarPC.txt");
    if (!file.is_open()) {
        std::cerr << "File not found!" << std::endl;
        return 1;
    }

    std::set<std::string> uniqueWords; // Using a set to store unique words
    std::unordered_map<unsigned long long, int> hashCodes;

    std::string word;
    while (file >> word) {
        for (int shift : {0, 1, 5, 13}) {
            unsigned long long hash = cyclicShiftHash(word, shift);

            if (uniqueWords.find(word) == uniqueWords.end()) {
                if (hashCodes.find(hash) != hashCodes.end()) {
                    hashCodes[hash]++;
                } else {
                    hashCodes[hash] = 1;
                }
                uniqueWords.insert(word); // Insert the word into the set
            }
        }
    }

    for (int shift : {0, 1, 5, 13}) {
        int collisions = 0;
        for (const auto& entry : hashCodes) {
            if (entry.second > 1) {
                collisions += (entry.second - 1);
            }
        }
        std::cout << "Shift Value: " << shift << ", Words: " << uniqueWords.size() << ", Collisions: " << collisions << std::endl;
    }

    return 0;
}
