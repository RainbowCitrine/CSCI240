#include <map>
#include <iostream>
#include <string>
#include <chrono>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <algorithm>
#include "HashMap.h" // Include your HashMap header file

class HashMapSTL {
    std::map<int, std::string> m;

public:
    int MapSize() {
        return m.size();
    }
    bool isEmpty() {
        return MapSize() == 0;
    }
    void insertCases() {
        m.insert({13, "31"});
        m.insert({21, "12"});
        m.insert({5, "5"});
        m.insert({37, "73"});
        m.insert({15, "51"});
    }
    void findCases() {
        if (m.find(10) != m.end())
            std::cout << "Element Found: " << m[10] << std::endl;
        else
            std::cout << "Element not Found" << std::endl;

        if (m.find(21) != m.end())
            std::cout << "Element Found: 21 " << m[21] << std::endl;

        else
            std::cout << "Element not Found: " << m[21] << std::endl;
    }
    void removeCases() {
        if (m.find(20) != m.end())
            m.erase(20);
        else
            std::cout << "Element not Found cannot remove" << std::endl;

        if (m.find(37) != m.end()) {
            std::cout << "Element erased: 37 " << m[37] << std::endl;
            m.erase(37);
        }
        else
            std::cout << "Element not found cannot remove" << std::endl;

        if (m.find(37) != m.end())
            std::cout << "Element Found";
        else
            std::cout << "Element 37 cannot be found" << std::endl;
    }

    void testSmallDataInsertion() {
        HashMap<int, std::string, std::hash<int>> SecondMap;

        std::ifstream smallData("small1k.txt");
        std::string line;

        auto start = std::chrono::high_resolution_clock::now();
        int inserted = 0;
        while (std::getline(smallData, line)) {
            try {
                int val = std::stoi(line);
                std::string reversed = std::to_string(val);
                std::reverse(reversed.begin(), reversed.end());

                SecondMap.put(val, reversed);
                inserted++;
            }
            catch (const std::invalid_argument& e) {
                std::cout << "Error: " << e.what() << std::endl;
            }
        }
        smallData.close();

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = end - start;
        std::cout << "Time Taken to insert 1000 pairs into the hash map: " << elapsed.count() << std::endl;

        std::cout << "HashMap size: " << inserted << std::endl;
    }
};

int main(int argc, char const* argv[]) {
    HashMapSTL HM;

    HM.insertCases();
    HM.findCases();
    HM.removeCases();
    HM.testSmallDataInsertion();

    HashMap<int, std::string, std::hash<int>> ThirdMap;

    std::ifstream LargeData("large100k.txt");
    std::string lineTwo;

    auto startSecond = std::chrono::high_resolution_clock::now();
    while (std::getline(LargeData, lineTwo)) {
        int value = std::stoi(lineTwo);
        std::string reversed = std::to_string(value);
        std::reverse(reversed.begin(), reversed.end());

        ThirdMap.put(value, reversed);
    }
    LargeData.close();

    auto endSecond = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsedTwo = endSecond - startSecond;

    std::cout << "Elapsed time taken to insert 100k pairs into the hash map: " << elapsedTwo.count() << std::endl;
    std::cout << "HashMap size: " << ThirdMap.size() << std::endl;
    return 0;
}
