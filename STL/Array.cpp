#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

// This STL ARRAY is fixed size always at compile time.

int main()
{
    // Declare an array of integers with size 5
    array<int, 5> myArray;

    // Fill the array
    myArray.fill(10);

    // Output: Elements of the array: 10 10 10 10 10
    cout << "Elements of the array: ";
    for (int i = 0; i < myArray.size(); ++i)
    {
        cout << myArray[i] << " ";
    }
    cout << endl;

    // Access elements using array syntax
    // Output: Using array syntax: 10 10 10 10 10
    cout << "Using array syntax: ";
    for (int i = 0; i < myArray.size(); ++i)
    {
        cout << myArray[i] << " ";
    }
    cout << endl;

    // Access elements using at() function
    // Output: Using at() function: 10 10 10 10 10
    cout << "Using at() function: ";
    for (int i = 0; i < myArray.size(); ++i)
    {
        cout << myArray.at(i) << " ";
    }
    cout << endl;

    // Accessing first and last element
    // Output: First element: 10
    cout << "First element: " << myArray.front() << endl;
    // Output: Last element: 10
    cout << "Last element: " << myArray.back() << endl;

    // Output: The array is not empty
    if (!myArray.empty())
    {
        cout << "The array is not empty" << endl;
    }
    else
    {
        cout << "The array is empty" << endl;
    }

    // Output: Size of the array: 5
    cout << "Size of the array: " << myArray.size() << endl;

    // Output: Maximum size of the array: 5
    cout << "Maximum size of the array: " << myArray.max_size() << endl;

    // Output: Address of the first element: 0x7ffee47a5a80
    cout << "Address of the first element: " << myArray.data() << endl;


    array<int, 5> arr = {1, 2, 3, 4, 5};

    // Display the output of begin(), end(), rbegin(), rend() methods
    cout << "Output of begin(): " << *arr.begin() << endl;   // Output of begin(): 1
    cout << "Output of end(): " << *(arr.end() - 1) << endl; // Output of end(): 5
    cout << "Output of rbegin(): " << *arr.rbegin() << endl; // Output of rbegin(): 5
    cout << "Output of rend(): " << *(arr.rend() - 1) << endl; // Output of rend(): 1

    cout << "Output of begin(): " << arr.begin()[0] << endl;   // Output of begin(): 1
    cout << "Output of end(): " << (arr.end() - 1)[0] << endl; // Output of end(): 5
    cout << "Output of rbegin(): " << arr.rbegin()[0] << endl; // Output of rbegin(): 5
    cout << "Output of rend(): " << (arr.rend() - 1)[0] << endl; // Output of rend(): 1


    // Create another array for swapping
    array<int, 5> anotherArray = {1, 2, 3, 4, 5};

    // Swap contents of arrays
    myArray.swap(anotherArray);

    // Output: After swapping:
    //         myArray: 1 2 3 4 5
    //         anotherArray: 10 10 10 10 10
    cout << "After swapping:" << endl;
    cout << "myArray: ";
    for (const auto &elem : myArray)
    {
        cout << elem << " ";
    }
    cout << endl;
    cout << "anotherArray: ";
    for (const auto &elem : anotherArray)
    {
        cout << elem << " ";
    }
    cout << endl;

    // Declare an array of integers with size 5
    array<int, 5> myArray = {1, 2, 3, 4, 5};

    // Reverse iterators
    cout << "Reverse Iterators: ";
    for (auto it = myArray.rbegin(); it != myArray.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    // Output: Reverse Iterators: 5 4 3 2 1

    // Output: The first element is: 1
    cout << "The first element is: " << *myArray.begin() << endl;

    // Output: The last element is: 5
    cout << "The last element is: " << *prev(myArray.end()) << endl;

    // Output: Address of the first element: 0x7ffee47a5a80
    cout << "Address of the first element: " << myArray.data() << endl;

    // Output: Is myArray empty? No
    cout << "Is myArray empty? " << (myArray.empty() ? "Yes" : "No") << endl;

    // Output: The array is not empty
    if (!myArray.empty())
    {
        cout << "The array is not empty" << endl;
    }
    else
    {
        cout << "The array is empty" << endl;
    }

    // #include <algorithm>
    //  Declare an array of integers with size 5
    array<int, 5> myArray = {5, 2, 8, 1, 9};

    // Sorting the array
    sort(myArray.begin(), myArray.end());

    // Declare an array of integers with size 5
    array<int, 5> myArray = {1, 2, 3, 4, 5};

    // Access elements using iterators
    cout << "Elements of the array using iterators: ";
    for (auto it = myArray.begin(); it != myArray.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Reverse access using reverse iterators
    cout << "Elements of the array in reverse using reverse iterators: ";
    for (auto it = myArray.rbegin(); it != myArray.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    // Access elements using range-based for loop
    cout << "Elements of the array using range-based for loop: ";
    for (const auto &elem : myArray)
    {
        cout << elem << " ";
    }
    cout << endl;

    return 0;
}
