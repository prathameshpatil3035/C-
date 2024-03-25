#include <iostream>
#include <set>

using namespace std;

int main() {
    // Constructor
    multiset<int> ms;

    // insert
    ms.insert(30);
    ms.insert(10);
    ms.insert(50);
    ms.insert(30); // Inserting a duplicate value

    // Output: Multiset elements after insert: 10 30 30 50
    cout << "Multiset elements after insert: ";
    for (int elem : ms) {
        cout << elem << " ";
    }
    cout << endl;

    // empty
    cout << "Is multiset empty? " << (ms.empty() ? "Yes" : "No") << endl; // Output: Is multiset empty? No

    // size
    cout << "Size of multiset: " << ms.size() << endl; // Output: Size of multiset: 4

    // count
    cout << "Number of occurrences of 30 in the multiset: " << ms.count(30) << endl; // Output: Number of occurrences of 30 in the multiset: 2

    // erase
    ms.erase(30); // Remove all occurrences of value 30 from the multiset
    ms.erase(ms.find(30)); //only single 30 erase (firstoccurance)
    ms.erase(ms.lower_bound(30), next(ms.lower_bound(30), 2)); // Erase two occurrences of value 30 from the multiset
    // ms.erase(ms.find(30), ms.find(30) + 2); //erase all 30 within given renge

    // Output: Multiset elements after erase: 10 50
    cout << "Multiset elements after erase: ";
    for (int elem : ms) {
        cout << elem << " ";
    }
    cout << endl;

    // clear
    ms.clear(); // Clear all elements from the multiset

    // Output: Is multiset empty after clear? Yes
    cout << "Is multiset empty after clear? " << (ms.empty() ? "Yes" : "No") << endl;

    return 0;
}
