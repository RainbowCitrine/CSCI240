#include <iostream>
#include <map>

// Define a custom structure for entries with key-value pairs
struct Entry {
    int key;
    int value;
};

// Create a map using the custom comparator
std::map<int, Entry> orderedMap;

// Define the ADT functions as before
std::map<int, Entry>::iterator FirstEntry(int k) {
    auto it = orderedMap.lower_bound(k);
    return it;
}

std::map<int, Entry>::iterator LastEntry(int k) {
    auto it = orderedMap.lower_bound(k);
    if (it != orderedMap.begin()) {
        --it;
    }
    return it;
}

std::map<int, Entry>::iterator CeilingEntry(int k) {
    auto it = orderedMap.lower_bound(k);
    return it;
}

std::map<int, Entry>::iterator FloorEntry(int k) {
    auto it = orderedMap.lower_bound(k);
    if (it->first > k && it != orderedMap.begin()) {
        --it;
    }
    return it;
}

std::map<int, Entry>::iterator LowerEntry(int k) {
    auto it = orderedMap.lower_bound(k);
    if (it != orderedMap.begin()) {
        --it;
    }
    return it;
}

std::map<int, Entry>::iterator HigherEntry(int k) {
    auto it = orderedMap.upper_bound(k);
    return it;
}

int main() {
    // Insert some entries into the ordered map
    Entry entry1 = {1, 10};
    Entry entry2 = {3, 30};
    Entry entry3 = {5, 50};
    Entry entry4 = {7, 70};

    orderedMap[1] = entry1;
    orderedMap[3] = entry2;
    orderedMap[5] = entry3;
    orderedMap[7] = entry4;

    // Use the ADT functions
    std::map<int, Entry>::iterator it;

    it = FirstEntry(2);
    std::cout << "First Entry with key <= 2: " << it->second.key << " " << it->second.value << std::endl;

    it = LastEntry(6);
    std::cout << "Last Entry with key <= 6: " << it->second.key << " " << it->second.value << std::endl;

    it = CeilingEntry(4);
    std::cout << "Ceiling Entry for key 4: " << it->second.key << " " << it->second.value << std::endl;

    it = FloorEntry(4);
    std::cout << "Floor Entry for key 4: " << it->second.key << " " << it->second.value << std::endl;

    it = LowerEntry(4);
    std::cout << "Lower Entry for key 4: " << it->second.key << " " << it->second.value << std::endl;

    it = HigherEntry(4);
    std::cout << "Higher Entry for key 4: " << it->second.key << " " << it->second.value << std::endl;

    return 0;
}
