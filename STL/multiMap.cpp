#include <iostream>
#include <map>

using namespace std;

int main() {
    // Constructor
    multimap<int, string> myMultimap;

    // insert
    myMultimap.insert({30, "Thirty"});
    myMultimap.insert({10, "Ten"});
    myMultimap.insert({20, "Twenty"});
    myMultimap.insert({30, "Another Thirty"}); // Inserting duplicate key

    // Output: Multimap elements after insert: (10, Ten) (20, Twenty) (30, Thirty) (30, Another Thirty)
    cout << "Multimap elements after insert: ";
    for (auto elem : myMultimap) {
        cout << "(" << elem.first << ", " << elem.second << ") ";
    }
    cout << endl;

    // empty
    cout << "Is multimap empty? " << (myMultimap.empty() ? "Yes" : "No") << endl; // Output: Is multimap empty? No

    // size
    cout << "Size of multimap: " << myMultimap.size() << endl; // Output: Size of multimap: 4

    // find
    auto it = myMultimap.find(30);
    if (it != myMultimap.end()) {
        cout << "Found key 30 in the multimap" << endl; // Output: Found key 30 in the multimap
    } else {
        cout << "Key 30 not found in the multimap" << endl;
    }

    // equal_range
    auto range = myMultimap.equal_range(30);
    cout << "Range of elements with key 30:" << endl;
    for (auto itr = range.first; itr != range.second; ++itr) {
        cout << "(" << itr->first << ", " << itr->second << ") ";
    }
    cout << endl;

    // erase
    myMultimap.erase(30); // Remove all elements with key 30 from the multimap

    // Output: Multimap elements after erase: (10, Ten) (20, Twenty)
    cout << "Multimap elements after erase: ";
    for (auto elem : myMultimap) {
        cout << "(" << elem.first << ", " << elem.second << ") ";
    }
    cout << endl;

    // clear
    myMultimap.clear(); // Clear all elements from the multimap

    // Output: Is multimap empty after clear? Yes
    cout << "Is multimap empty after clear? " << (myMultimap.empty() ? "Yes" : "No") << endl;

    return 0;
}
