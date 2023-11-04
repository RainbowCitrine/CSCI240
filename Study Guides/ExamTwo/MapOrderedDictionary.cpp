#include <iostream>
#include <map>
#include <vector>

class OrderedDictionary {
public:
    // Constructor: Initialize an empty ordered dictionary
    OrderedDictionary() {}

    // Insert a key-value pair
    void Insert(const std::string& key, const std::string& value) {
        ordered_dict.insert({key, value});
    }

    // Delete a specific key-value pair
    void Delete(const std::string& key, const std::string& value) {
        // Find all key-value pairs with the given key
        auto range = ordered_dict.equal_range(key);

        // Iterate through the range and remove the specified key-value pair
        for (auto it = range.first; it != range.second; ++it) {
            if (it->second == value) {
                ordered_dict.erase(it);
                break;  // Remove only one entry with the given key-value pair
            }
        }
    }

    // Search for all values associated with a key
    std::vector<std::string> Search(const std::string& key) {
        std::vector<std::string> result;
        // Find all key-value pairs with the given key
        auto range = ordered_dict.equal_range(key);

        // Iterate through the range and collect the values
        for (auto it = range.first; it != range.second; ++it) {
            result.push_back(it->second);
        }
        return result;
    }

    // Search for key-value pairs within a key range
    std::vector<std::pair<std::string, std::string>> SearchRange(const std::string& key1, const std::string& key2) {
        std::vector<std::pair<std::string, std::string>> result;
        // Find the lower and upper bounds for the specified key range
        auto lower = ordered_dict.lower_bound(key1);
        auto upper = ordered_dict.upper_bound(key2);

        // Iterate through the range and collect the key-value pairs
        for (auto it = lower; it != upper; ++it) {
            result.push_back(*it);
        }
        return result;
    }

    // Find and return the smallest (leftmost) key
    std::string MinKey() {
        return ordered_dict.begin()->first;
    }

    // Find and return the largest (rightmost) key
    std::string MaxKey() {
        return std::prev(ordered_dict.end())->first;
    }

    // Find and return the key-value pairs immediately before the given key
    std::vector<std::pair<std::string, std::string>> Predecessor(const std::string& key) {
        std::vector<std::pair<std::string, std::string>> result;
        // Find the lower bound for the specified key
        auto it = ordered_dict.lower_bound(key);

        // Check if the lower bound is not the beginning of the dictionary
        if (it != ordered_dict.begin()) {
            --it; // Move to the previous element
            // While the key is the same, keep moving to the previous element
            while (it->first == key) {
                --it;
            }
            ++it; // Move back to the correct element
        }

        // Find all key-value pairs before the specified key and collect them
        auto range = ordered_dict.equal_range(it->first);
        for (auto rit = range.first; rit != it; ++rit) {
            result.push_back(*rit);
        }
        return result;
    }

    // Find and return the key-value pairs immediately after the given key
    std::vector<std::pair<std::string, std::string>> Successor(const std::string& key) {
        std::vector<std::pair<std::string, std::string>> result;
        // Find the upper bound for the specified key
        auto it = ordered_dict.upper_bound(key);

        // Find all key-value pairs after the specified key and collect them
        auto range = ordered_dict.equal_range(key);
        for (auto rit = it; rit != range.second; ++rit) {
            result.push_back(*rit);
        }
        return result;
    }

    // Return the number of key-value pairs in the ordered dictionary
    size_t Size() {
        return ordered_dict.size();
    }

private:
    std::multimap<std::string, std::string> ordered_dict;
};

int main() {
    OrderedDictionary od;

    // Insert some key-value pairs
    od.Insert("apple", "red");
    od.Insert("banana", "yellow");
    od.Insert("apple", "green");  // Insert another entry with the same key

    // Search for all values associated with 'apple'
    std::cout << "Search 'apple': ";
    std::vector<std::string> apple_values = od.Search("apple");
    for (const std::string& value : apple_values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;

    // Search for key-value pairs within a key range ['aardvark', 'banana']
    std::cout << "Search Range ['aardvark', 'banana']: ";
    std::vector<std::pair<std::string, std::string>> range_result = od.SearchRange("aardvark", "banana");
    for (const auto& kvp : range_result) {
        std::cout << "(" << kvp.first << ", " << kvp.second << ") ";
    }
    std::cout << std::endl;

    // Get the size of the ordered dictionary
    std::cout << "Size of Ordered Dictionary: " << od.Size() << std::endl;

    return 0;
}
