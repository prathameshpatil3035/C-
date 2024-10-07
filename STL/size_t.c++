// size_t is an unsigned integral type defined in the C++ standard library, specifically in the header <cstddef>. It is commonly used to represent the size of objects in bytes and the result of the sizeof operator. Since it is unsigned, it cannot hold negative values, making it suitable for sizes and counts.

// When to Use size_t
// When declaring variables that represent sizes or counts, such as the size of arrays, the number of elements in a container, or indices in loops.
// When using STL containers like std::vector, std::string, etc., where methods return sizes or indices.
// To ensure compatibility across different platforms and avoid signed/unsigned mismatch issues.

#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Declare a vector and add some elements
    vector<int> numbers = {10, 20, 30, 40, 50};

    // Use size_t to get the size of the vector
    size_t size = numbers.size(); // size will hold the number of elements in the vector

    // Print the size
    cout << "The size of the vector is: " << size << endl; // Output: The size of the vector is: 5

    // Use size_t in a loop to iterate through the vector
    for (size_t i = 0; i < size; ++i) {
        cout << "Element at index " << i << " is: " << numbers[i] << endl; // Output: Element at index 0 is: 10, etc.
    }

    return 0;
}
