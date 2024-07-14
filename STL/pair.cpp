#include <iostream>
#include <utility> // For std::pair and std::make_pair
#include <string>

using namespace std;

int main() {
    // Creating an array of pairs
    pair<int, int> arr1[] = {{1, 2}, {3, 4}, {5, 6}, {7, 8}};
    cout << arr1[1].first << " " << arr1[1].second << endl; // Output: 3 4

    // Creating a pair of integers
    pair<int, int> p1 = {1, 3};
    cout << p1.first << " " << p1.second << endl; // Output: 1 3

    // Creating a pair where the second element is another pair
    pair<int, pair<int, int>> p2 = {1, {3, 4}};
    cout << p2.first << " " << p2.second.first << " " << p2.second.second << endl; // Output: 1 3 4

    // Create a pair using the constructor
    pair<int, string> myPair(1, "Hello");
    cout << "myPair: (" << myPair.first << ", " << myPair.second << ")" << endl; // Output: myPair: (1, Hello)

    // Create a pair using make_pair
    auto myPair2 = make_pair(2, "World");
    cout << "myPair2: (" << myPair2.first << ", " << myPair2.second << ")" << endl; // Output: myPair2: (2, World)

    // Access elements using first and second
    int number = myPair.first;
    string text = myPair.second;
    cout << "number: " << number << ", text: " << text << endl; // Output: number: 1, text: Hello

    // Modify elements
    myPair.first = 10;
    myPair.second = "Changed";
    cout << "Modified myPair: (" << myPair.first << ", " << myPair.second << ")" << endl; // Output: Modified myPair: (10, Changed)

    // Comparison operators
    pair<int, string> myPair3(10, "Changed");
    cout << boolalpha;
    // cout << "myPair == myPair3: " << (myPair == myPair3) << endl; // Output: myPair == myPair3: true
    // cout << "myPair != myPair2: " << (myPair != myPair2) << endl; // Output: myPair != myPair2: true
    // cout << "myPair < myPair2: " << (myPair < myPair2) << endl; // Output: myPair < myPair2: false
    // cout << "myPair <= myPair3: " << (myPair <= myPair3) << endl; // Output: myPair <= myPair3: true
    // cout << "myPair > myPair2: " << (myPair > myPair2) << endl; // Output: myPair > myPair2: true
    // cout << "myPair >= myPair3: " << (myPair >= myPair3) << endl; // Output: myPair >= myPair3: true

    // Swapping pairs
    pair<int, string> myPair4(20, "Swap");
    cout << "Before swap, myPair: (" << myPair.first << ", " << myPair.second << "), myPair4: (" << myPair4.first << ", " << myPair4.second << ")" << endl;
    // Output: Before swap, myPair: (10, Changed), myPair4: (20, Swap)

    myPair.swap(myPair4);
    cout << "After swap, myPair: (" << myPair.first << ", " << myPair.second << "), myPair4: (" << myPair4.first << ", " << myPair4.second << ")" << endl;
    // Output: After swap, myPair: (20, Swap), myPair4: (10, Changed)

    // Using pairs in STL containers
    pair<int, string> arr2[] = {make_pair(1, "one"), make_pair(2, "two"), make_pair(3, "three")};
    cout << "Pairs in array:" << endl;
    for (const auto& p : arr2) {
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
    // Output:
    // Pairs in array:
    // (1, one)
    // (2, two)
    // (3, three)

    return 0;
}
