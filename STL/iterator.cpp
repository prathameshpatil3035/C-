#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
    // Example vector
    vector<int> vec = {1, 2, 3, 4, 5};

    // Using std::advance
    auto it = vec.begin();
    advance(it, 2); // Advance iterator by 2 positions using std::advance
    cout << "Value at position 2 (using advance): " << *it << endl; // Output: Value at position 2 (using advance): 3

    // Using std::next
    auto nextIt = next(vec.begin(), 2); // Advance iterator by 2 positions using std::next
    cout << "Value at position 2 (using next): " << *nextIt << endl; // Output: Value at position 2 (using next): 3

    // Output vector elements using iterators
    cout << "Vector elements: ";
    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    // Using std::advance
    auto it = vec.begin();
    advance(it, 2); // Advance iterator by 2 positions using std::advance
    cout << "Value at position 2 (using advance): " << *it << endl; // Output: Value at position 2 (using advance): 3

    // Using std::next
    auto nextIt = next(vec.begin(), 2); // Advance iterator by 2 positions using std::next
    cout << "Value at position 2 (using next): " << *nextIt << endl; // Output: Value at position 2 (using next): 3

    // Output vector elements using iterators
    cout << "Vector elements: ";
    for (auto iter = vec.begin(); iter != vec.end(); ++iter) {
        cout << *iter << " ";
    }
    cout << endl;

    return 0;
}
