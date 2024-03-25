#include <iostream>
#include <list>

using namespace std;

int main() {
    // Constructor(s)
    list<int> mylist1; // Empty list
    list<int> mylist2(5); // List with 5 default-initialized elements
    list<int> mylist3(3, 7); // List with 3 elements with value 7
    list<int> mylist4(mylist3); // Copy constructor
    list<int> mylist5(mylist3.begin(), mylist3.end()); // List constructed from another list's iterators

    // Outputting constructor(s) results
    cout << "mylist1: "; // Output: mylist1:
    for (int i : mylist1) {
        cout << i << " ";
    }
    cout << endl; // Output: <nothing>

    cout << "mylist2: "; // Output: mylist2: 0 0 0 0 0
    for (int i : mylist2) {
        cout << i << " ";
    }
    cout << endl; // Output: 0 0 0 0 0

    cout << "mylist3: "; // Output: mylist3: 7 7 7
    for (int i : mylist3) {
        cout << i << " ";
    }
    cout << endl; // Output: 7 7 7

    cout << "mylist4: "; // Output: mylist4: 7 7 7
    for (int i : mylist4) {
        cout << i << " ";
    }
    cout << endl; // Output: 7 7 7

    cout << "mylist5: "; // Output: mylist5: 7 7 7
    for (int i : mylist5) {
        cout << i << " ";
    }
    cout << endl; // Output: 7 7 7

    // Iterators
    cout << "mylist5: "; // Output: mylist5: 7 7 7
    for (auto it = mylist5.begin(); it != mylist5.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl; // Output: 7 7 7

    // Capacity
    cout << "mylist3 empty(): " << mylist3.empty() << endl; // Output: mylist3 empty(): 0
    cout << "mylist3 size(): " << mylist3.size() << endl; // Output: mylist3 size(): 3

    // Element Access
    cout << "mylist3 front(): " << mylist3.front() << endl; // Output: mylist3 front(): 7
    cout << "mylist3 back(): " << mylist3.back() << endl; // Output: mylist3 back(): 7

    // Modifiers
    mylist3.push_back(8); // Adding 8 to the end of the list
    mylist3.pop_back(); // Removing the last element from the list
    mylist3.push_front(6); // Adding 6 to the beginning of the list
    mylist3.pop_front(); // Removing the first element from the list

    cout << "mylist3 after modifications: ";
    for (int i : mylist3) {
        cout << i << " ";
    }
    cout << endl; // Output: mylist3 after modifications: 7 7 8

    // Operations
    mylist3.merge(mylist5); // Merging mylist5 into mylist3
    cout << "mylist3 after merge: ";
    for (int i : mylist3) {
        cout << i << " ";
    }
    cout << endl; // Output: mylist3 after merge: 7 7 8 7 7 7

    return 0;
}
