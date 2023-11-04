#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include "PriorityQueue.h"  
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

    PriorityQueue<int,MinC<int>> pq;

    auto start = high_resolution_clock::now();

    for (int value : smallData) {
        pq.insert(value);
    }

    vector<int> sortedSmallData;
    while (!pq.isEmpty()) {
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

    cout << "\nRuntime for small1k.txt: " << duration.count() << " ms" << endl;

    vector<int> largeData = readDataFromFile("large100k.txt");

    PriorityQueue<int, MaxC<int>> pqLarge;

    start = high_resolution_clock::now();

    for (int value : largeData) {
        pqLarge.insert(value);
    }

    vector<int> sortedLargeData;
    while (!pqLarge.isEmpty()) {
        sortedLargeData.push_back(pqLarge.min());
        pqLarge.removeMin();
    }

    stop = high_resolution_clock::now();
    duration = duration_cast<milliseconds>(stop - start);
    
    std::cout << std::endl; 
    cout << "First Five Data: ";
    vector<int> firstFive(sortedLargeData.end() - 5, sortedLargeData.end());
    sort(firstFive.begin(), firstFive.end()); // Sort in ascending order

    for (int value : firstFive) {
        cout << value << " ";
    }
    std::cout << std::endl; 
    std::cout << "Last Five Data: "; 
    for (int i = 0; i < 5; i++) {
        cout << sortedLargeData[i] << " ";
    }

    cout << "\nRuntime for large100k.txt: " << duration.count() << " ms" << endl;

    return 0;
}
