#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "PriorityHeapQueue.h"  
#include <algorithm>

using namespace std;
using namespace chrono;

vector<int> readDataFromFile(const string& filename) {
    vector<int> data;
    ifstream file(filename);
    int value;
    while (file >> value) {
        data.push_back(value);
    }
    return data;
}

int main() {
    
    std::cout << "Author: Noah Rainbow" << std::endl; 
    vector<int> smallData = readDataFromFile("small1k.txt");

    HeapPriorityQueue<int,MinComparator<int>> pq;

    auto start = high_resolution_clock::now();

    for (int value : smallData) {
        pq.insert(value);
    }

    vector<int> sortedSmallData;
    while (!pq.empty()) {
        sortedSmallData.push_back(pq.min());
        pq.removeMin();
    }

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    std::cout << "First Five Data: "; 
    for (int i = 0; i < 5; i++) {
        cout << sortedSmallData[i] << " ";
    }

    std::cout << std::endl; 

    cout << "Last Five Data: ";
    for (int i = sortedSmallData.size() - 1; i >= sortedSmallData.size() - 5; i--) {
        cout << sortedSmallData[i] << " ";
    }
    
    std::cout << std::endl; 

    cout << "\nRuntime for small1k.txt: " << duration.count() << " ms" << endl;

    vector<int> largeData = readDataFromFile("large100k.txt");

    HeapPriorityQueue<int, MaxComparator<int>> pqLarge;

    start = high_resolution_clock::now();

    for (int value : largeData) {
        pqLarge.insert(value);
    }

    vector<int> sortedLargeData;
    while (!pqLarge.empty()) {
        sortedLargeData.push_back(pqLarge.min());
        pqLarge.removeMin();
    }

    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    
    std::cout << std::endl;

    std::cout << std::endl;
    std::cout << "First Five Data (Descending): ";
vector<int> firstFive(sortedLargeData.end() - 5, sortedLargeData.end());
std::sort(firstFive.rbegin(), firstFive.rend()); // Sort in descending order

for (int value : firstFive) {
    std::cout << value << " ";
}
std::cout << std::endl; 

std::cout << "Last Five Data (Descending): "; 
vector<int> lastFive(sortedLargeData.begin(), sortedLargeData.begin() + 5);
std::sort(lastFive.rbegin(), lastFive.rend()); // Sort in descending order

for (int value : lastFive) {
    std::cout << value << " ";
}
std::cout << std::endl;

    

    cout << "\nRuntime for large100k.txt: " << duration.count() << " ms" << endl;

    return 0;
}
