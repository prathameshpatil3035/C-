#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    // Constructor
    unordered_map<int, string> myMap;

    // insert
    myMap.insert({1, "One"});
    myMap.insert({2, "Two"});
    myMap.insert({3, "Three"});

    // Output: Map elements after insert: {1: One}, {2: Two}, {3: Three}
    cout << "Map elements after insert: ";
    for (auto& entry : myMap) {
        cout << "{" << entry.first << ": " << entry.second << "}, ";
    }
    cout << endl;

    // empty
    cout << "Is map empty? " << (myMap.empty() ? "Yes" : "No") << endl; // Output: Is map empty? No

    // size
    cout << "Size of map: " << myMap.size() << endl; // Output: Size of map: 3

    // find
    auto it = myMap.find(2);
    if (it != myMap.end()) {
        cout << "Found key 2 in the map with value: " << it->second << endl; // Output: Found key 2 in the map with value: Two
    } else {
        cout << "Key 2 not found in the map" << endl;
    }

    // count
    cout << "Number of occurrences of key 3 in the map: " << myMap.count(3) << endl; // Output: Number of occurrences of key 3 in the map: 1

    // erase
    myMap.erase(1); // Remove key 1 from the map

    // Output: Map elements after erase: {2: Two}, {3: Three}
    cout << "Map elements after erase: ";
    for (auto& entry : myMap) {
        cout << "{" << entry.first << ": " << entry.second << "}, ";
    }
    cout << endl;

    // clear
    myMap.clear(); // Clear all elements from the map

    // Output: Is map empty after clear? Yes
    cout << "Is map empty after clear? " << (myMap.empty() ? "Yes" : "No") << endl;

    return 0;
}
