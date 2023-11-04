#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

unsigned long long polynomialHash(const std::string& str, int a) {
    unsigned long long hash = 0;
    for (char c : str) {
        hash = hash * a + c;
    }
    return hash;
}

int main() {
    std::vector<int> aValues = {0, 37, 40, 41};

    for (int a : aValues) {
        std::ifstream inputFile("usdeclarPC.txt");
        if (!inputFile.is_open()) {
            std::cerr << "Error: Cannot open input file." << std::endl;
            return 1;
        }

        std::unordered_set<std::string> uniqueWords;
        std::unordered_map<unsigned long long, int> hashCounts;

        std::string word;
        while (inputFile >> word) {
            if (uniqueWords.count(word) == 0) {
                uniqueWords.insert(word);
                unsigned long long hash = polynomialHash(word, a);
                hashCounts[hash]++;
            }
        }

        inputFile.close();

        std::cout << "For 'a' = " << a << ":" << std::endl;
        std::cout << "Total unique words in file: " << uniqueWords.size() << std::endl;
        std::cout << "Total unique hash codes: " << hashCounts.size() << std::endl;
        std::cout << "Number of collisions: " << (uniqueWords.size() - hashCounts.size()) << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
