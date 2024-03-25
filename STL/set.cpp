#include <iostream>
#include <set>

using namespace std;

int main() {
    // Constructor
    set<int> mySet;

    // insert
    mySet.insert(30);
    mySet.insert(10);
    mySet.insert(50);

    // Output: Set elements after insert: 10 30 50
    cout << "Set elements after insert: ";
    for (int elem : mySet) {
        cout << elem << " ";
    }
    cout << endl;

    // empty
    cout << "Is set empty? " << (mySet.empty() ? "Yes" : "No") << endl; // Output: Is set empty? No

    // size
    cout << "Size of set: " << mySet.size() << endl; // Output: Size of set: 3

    // find
    auto it = mySet.find(30);

    // {1, 2, 3, 4}
    auto it = mySet.find(5);    // it = mySet.end() as 5 is not present

    if (it != mySet.end()) {
        cout << "Found element 30 in the set" << endl; // Output: Found element 30 in the set
    } else {
        cout << "Element 30 not found in the set" << endl;
    }

    // count
    cout << "Number of occurrences of 30 in the set: " << mySet.count(30) << endl; // Output: Number of occurrences of 30 in the set: 1

    // erase
    mySet.erase(30); // Remove element 30 from the set

    // Output: Set elements after erase: 10 50
    cout << "Set elements after erase: ";
    for (int elem : mySet) {
        cout << elem << " ";
    }
    cout << endl;

    // clear
    mySet.clear(); // Clear all elements from the set

    // Output: Is set empty after clear? Yes
    cout << "Is set empty after clear? " << (mySet.empty() ? "Yes" : "No") << endl;

    return 0;
}
