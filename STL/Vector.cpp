// Constructor/Destructor:

// vector(): Constructs an empty vector.
// vector(size_type count, const T& value): Constructs the vector with count copies of elements with value value.
// ~vector(): Destructor.
// Element Access:

// operator[]: Accesses the element at index.
// at(): Accesses the element at index with bounds checking.
// front(): Accesses the first element.
// back(): Accesses the last element.
// data(): Returns a pointer to the underlying array.
// Modifiers:

// push_back(): Adds an element to the end.
// pop_back(): Removes the last element.
// insert(): Inserts elements at a specified position.
// erase(): Removes elements from a specified position or range. not inclusive last iterator (before last iterator)
// clear(): Removes all elements.
// emplace(): Constructs and inserts elements at a specified position.
// emplace_back(): Constructs and adds an element to the end.
// resize(): Changes the size of the vector.
// Capacity:

// size(): Returns the number of elements.
// empty(): Checks if the vector is empty.
// reserve(): Requests that the vector capacity be at least enough to contain n elements.
// capacity(): Returns the number of elements that can be held in the currently allocated storage.
// Iterators:

// begin(): Returns an iterator to the beginning.
// end(): Returns an iterator to the end (point to the next position after last element in vector).
// rbegin(): Returns a reverse iterator to the beginning.
// rend(): Returns a reverse iterator to the end. (point to the previous position before first element in vector).

// Comparison:
// ==, !=, <, <=, >, >=: Comparison operators for vectors.

// swap(): swap 2 vectors

// algorithms:

// swap(): Swaps the contents of two vectors.
// reverse
// reverse_copy
// lower_bound
// upper_bound
// max_element
// min_element
// minmax_element
// find
// count
// all_of, any_of, none_of
// copy - back_inserter
// transform
// unique (with erase)- array should be sorted and erase used to remove duplicates from end
// replace - replace specific elements with provided one
// remove (with erase)- used with erase and removed specific element
// accumulate

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{

    // Constructs an empty vector
    vector<int> myVector;
    // Constructs the vector with 5 copies of elements with value 10
    vector<int> myVector2(5, 10);

    // Create a vector
    vector<int> myVector = {10, 20, 30, 40, 50};

    // Access the element at index using operator[]
    int elementAtIndex0 = myVector[0];
    cout << "Element at index 0: " << elementAtIndex0 << endl; // Output: Element at index 0: 10

    // Access the element at index with bounds checking using at()
    try
    {
        int elementAtIndex3 = myVector.at(3);
        cout << "Element at index 3: " << elementAtIndex3 << endl; // Output: Element at index 3: 40
    }
    catch (const out_of_range &e)
    {
        cout << "Index out of range" << endl;
    }

    // Access the first element using front()
    int firstElement = myVector.front();
    cout << "First element: " << firstElement << endl; // Output: First element: 10

    // Access the last element using back()
    int lastElement = myVector.back();
    cout << "Last element: " << lastElement << endl; // Output: Last element: 50

    // Returns a pointer to the underlying array using data()
    int *dataArray = myVector.data();
    cout << "Data pointer: " << dataArray << endl; // Output: Data pointer: 0x...

    vector<int> myVector;

    // push_back(): Adds an element to the end
    myVector.push_back(10);
    myVector.push_back(20);
    myVector.push_back(30);

    // Output after push_back()
    cout << "After push_back(): ";
    for (int num : myVector)
    {
        cout << num << " "; // Output: After push_back(): 10 20 30
    }
    cout << endl;

    // pop_back(): Removes the last element
    myVector.pop_back();

    // Output after pop_back()
    cout << "After pop_back(): ";
    for (int num : myVector)
    {
        cout << num << " "; // Output: After pop_back(): 10 20
    }
    cout << endl;

    // insert(): Inserts elements at a specified position
    myVector.insert(myVector.begin() + 1, 15);           // Insert 15 at position 1
    myVector.insert(myVector.begin() + 2, {16, 17, 18}); // Insert more than one elements

    // Output after insert()
    cout << "After insert(): ";
    for (int num : myVector)
    {
        cout << num << " "; // Output: After insert(): 10 15 20
    }
    cout << endl;

    // erase(): Removes elements from a specified position or range
    myVector.erase(myVector.begin() + 1);                       // Erase element at position 1
    myVector.erase(myVector.begin() + 1, myVector.begin() + 3); // Erase more than one elements not inclusive last iterator (before last iterator)

    // Output after erase()
    cout << "After erase(): ";
    for (int num : myVector)
    {
        cout << num << " "; // Output: After erase(): 10 20
    }
    cout << endl;

    // clear(): Removes all elements
    myVector.clear();

    // Output after clear()
    cout << "After clear(): ";
    for (int num : myVector)
    {
        cout << num << " "; // Output: After clear():
    }
    cout << endl;

    // emplace(): Constructs and inserts elements at a specified position
    myVector.emplace(myVector.begin(), 5); // Insert 5 at the beginning

    vector<pair<int, int>> vec;
    vec.emplace(vec.begin(), 1, 2); // Constructs a pair<int, int>(1, 2) at the beginning of the vector

    // Output after emplace()
    cout << "After emplace(): ";
    for (int num : myVector)
    {
        cout << num << " "; // Output: After emplace(): 5
    }
    cout << endl;

    // emplace_back(): Constructs and adds an element to the end
    myVector.emplace_back(25); // Add 25 to the end

    // Output after emplace_back()
    cout << "After emplace_back(): ";
    for (int num : myVector)
    {
        cout << num << " "; // Output: After emplace_back(): 5 25
    }
    cout << endl;

    // resize(): Changes the size of the vector
    myVector.resize(3); // Resize to 3 elements with default value 0 for not initialized numbers (expect previous numbers)

    // Output after resize()
    cout << "After resize(): ";
    for (int num : myVector)
    {
        cout << num << " "; // Output: After resize(): 5 25 0
    }
    cout << endl;

    vector<int> myVector = {1, 2, 3, 4, 5};

    // size(): Returns the number of elements
    int vectorSize = myVector.size();
    cout << "Vector size: " << vectorSize << endl; // Output: Vector size: 5

    // empty(): Checks if the vector is empty
    bool isEmpty = myVector.empty();
    cout << "Is vector empty? " << (isEmpty ? "Yes" : "No") << endl; // Output: Is vector empty? No

    // reserve(): Requests that the vector capacity be at least enough to contain n elements
    myVector.reserve(10); // Reserve space for at least 10 elements

    // capacity(): Returns the number of elements that can be held in the currently allocated storage
    int vectorCapacity = myVector.capacity();
    cout << "Vector capacity: " << vectorCapacity << endl; // Output: Vector capacity: 10

    // Iterators
    // begin(): Returns an iterator to the beginning
    auto itBegin = myVector.begin();
    // end(): Returns an iterator to the end (point to the next position after last element in vector).
    auto itEnd = myVector.end();
    // rbegin(): Returns a reverse iterator to the beginning
    auto ritBegin = myVector.rbegin();
    // rend(): Returns a reverse iterator to the endrend(): Returns a reverse iterator to the end. (point to the previous position before first element in vector).
    auto ritEnd = myVector.rend();

    // swap indexes : takes elements as arguments
    //              [1,2,3,4,5,6,7,8]
    // after swap - [1,2,3,7,5,6,4,8]
    swap(myVector[3], myVector[6]); // swap indexe elements 3 and 6

    // reverse vector : : takes iterators as arguments
    reverse(vec.begin(), vec.end()); // include algorithm file
    reverse(vec.begin() + 3, vec.end() + 5);

    vector<int> vec = {1, 2, 3, 4, 5};
    vector<int> reversed_vec(vec.size());

    // Reverse the vector into a new vector
    reverse_copy(vec.begin(), vec.end(), reversed_vec.begin());

    // Output the elements using iterators
    cout << "Elements using iterators: ";
    for (auto it = itBegin; it != itEnd; ++it)
    {
        cout << *it << " ";
    }
    cout << endl; // Output: Elements using iterators: 1 2 3 4 5

    // Output the elements using reverse iterators
    cout << "Elements using reverse iterators: ";
    for (auto rit = ritBegin; rit != ritEnd; ++rit)
    {
        cout << *rit << " ";
    }
    cout << endl; // Output: Elements using reverse iterators: 5 4 3 2 1

    vector<int> firstVector = {1, 2, 3};
    vector<int> secondVector = {4, 5, 6};

    // Swapping the contents of the vectors
    firstVector.swap(secondVector);

    // First Vector: 1 2 3
    // Second Vector: 4 5 6
    // After Swap:
    // First Vector: 4 5 6
    // Second Vector: 1 2 3

    vector<int> nums = {1, 2, 4, 4, 4, 5, 6, 7}; // Must be sorted for binary search to work
    int target = 4;

    // Find the lower bound
    auto lower = lower_bound(nums.begin(), nums.end(), target);
    // Find the upper bound
    auto upper = upper_bound(nums.begin(), nums.end(), target);

    // Print results
    if (lower != nums.end())
        cout << "Lower bound of " << target << " is at index: " << (lower - nums.begin()) << endl;
    else
        cout << "Lower bound not found.\n";

    if (upper != nums.end())
       cout << "Upper bound of " << target << " is at index: " << (upper - nums.begin()) << endl;
    else
       cout << "Upper bound not found.\n";

    return 0;
}
