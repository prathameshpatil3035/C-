// Constructor/Destructor:

// string(): Constructs an empty string.
// string(const char* s): Constructs a string from a C-style string.
// string(const string& str): Copy constructor.
// ~string(): Destructor.
// Assignment:

// operator=: Assigns a new value to the string.
// Concatenation:

// operator+: Concatenates two strings.
// append(): Appends a string to the end.
// +=: Appends a string to the end.
// Modifiers:

// clear(): Clears the contents of the string.
// erase(): Erases a portion of the string. not include last iterator in case of iterator. include last index in case of index
// insert(): Inserts characters into the string.
// empty(): Checks if the string is empty.
// replace(): Replaces a portion of the string with another string.
// Element Access:

// operator[]: Accesses the character at a specified position.
// at(): Accesses the character at a specified position with bounds checking.
// front(): Returns the first character.
// back(): Returns the last character.
// data(): Returns a pointer to the underlying character array.
// String Operations:

// length(): Returns the length of the string.
// size(): Returns the length of the string.
// substr(): Returns a substring. str.substr(index, length)
// find(): Searches for a substring.
// rfind(): Searches for a substring from the end.
// compare(): Compares two strings.
// Conversion:

// c_str(): Returns a C-style string.
// stoi(), stol(), stoll(): Converts a string to an integer, long, or long long, respectively.
// stof(), stod(), stold(): Converts a string to a float, double, or long double, respectively.
// Iterators:

// begin(): Returns an iterator to the beginning.
// end(): Returns an iterator to the end.
// rbegin(): Returns a reverse iterator to the beginning.
// rend(): Returns a reverse iterator to the end.
// Capacity:

// reserve(): Requests that the string capacity be at least enough to contain n characters.
// capacity(): Returns the capacity of the string.
// Comparison:

// ==, !=, <, <=, >, >=: Comparison operators for strings.
// Swap:

// swap(): Swaps the contents of two strings.

#include <iostream>
#include <string>

#include <algorithm> // for std::transform and std::all_of
#include <cctype>    // for std::tolower, std::toupper, std::isalnum, isupper, islower

using namespace std;

// 'a' - 'A' = 32
//  ASCII values :
//      0 = 48, 9 = 57
//      A = 65, Z = 90
//      a = 97, z = 122

int main()
{
    // Declare and initialize a string
    string myString = "Hello, World!";

    // Push back
    myString.push_back('!');
    std::cout << "After push_back: " << myString << std::endl; // Output: Hello, World!!

    // Pop back
    myString.pop_back();
    std::cout << "After pop_back: " << myString << std::endl; // Output: Hello, World!

    // clear(): Clears the contents of the string.
    myString.clear();
    cout << "After clear(): " << myString << endl; // Output: After clear():

    // Insert a string into another string
    myString = "Hello, World!";
    myString.insert(7, "Beautiful ");
    cout << "After insert(): " << myString << endl; // Output: After insert(): Hello, Beautiful World!

    // Erase a portion of the string
    myString.erase(5, 10);
    cout << "After erase(): " << myString << endl; // Output: After erase(): Hello

    // Replace a portion of the string with another string
    myString.replace(0, 5, "Hi");
    cout << "After replace(): " << myString << endl; // Output: After replace(): Hi

    // isupper and islower
    if (isupper('A'))
    {
        cout << 'A' << " is an uppercase letter.\n";
    }

    if (islower('a'))
    {
        cout << 'a' << " is a lowercase letter.\n";
    }

    // Element Access
    cout << "Character at index 0: " << myString[0] << endl;                          // Output: Character at index 0: H
    cout << "Character at index 0 (using at()): " << myString.at(0) << endl;          // Output: Character at index 0 (using at()): H
    cout << "First character: " << myString.front() << endl;                          // Output: First character: H
    cout << "Last character: " << myString.back() << endl;                            // Output: Last character: i
    cout << "Pointer to the underlying character array: " << myString.data() << endl; // Output: Pointer to the underlying character array: Hi

    // String Operations
    cout << "Length of the string: " << myString.length() << endl;            // Output: Length of the string: 2
    cout << "Size of the string: " << myString.size() << endl;                // Output: Size of the string: 2
    cout << "Substring: " << myString.substr(0, 1) << endl;                   // Output: Substring: H  myString.substr(2) = string from index 2 to right
    cout << "Find substring 'llo': " << myString.find("llo") << endl;         // Output: Find substring 'llo': -1 (not found)
    cout << "Reverse Find substring 'l': " << myString.rfind("l") << endl;    // Output: Reverse Find substring 'l': 1
    cout << "Comparison with 'Hello': " << myString.compare("Hello") << endl; // Output: Comparison with 'Hello': 1 (different)

    // Conversion
    const char *cstr = myString.c_str();
    cout << "C-style string: " << cstr << endl; // Output: C-style string: Hi
    int integer = stoi("123");
    cout << "String to integer: " << integer << endl; // Output: String to integer: 123
    float floating = stof("3.14");
    cout << "String to float: " << floating << endl; // Output: String to float: 3.14

    // Iterators
    cout << "Iterating through the string: ";
    for (auto it = myString.begin(); it != myString.end(); ++it)
    {
        cout << *it << " "; // Output: Iterating through the string: H i
    }
    cout << endl;

    cout << "Reversed Iterating through the string: ";
    for (auto it = myString.rbegin(); it != myString.rend(); ++it)
    {
        cout << *it << " "; // Output: Reversed Iterating through the string: i H
    }
    cout << endl;

    // Capacity
    cout << "Is the string empty? " << (myString.empty() ? "Yes" : "No") << endl; // Output: Is the string empty? No
    myString.reserve(10);
    cout << "Capacity of the string: " << myString.capacity() << endl; // Output: Capacity of the string: 10

    // Reverse
    reverse(myString.begin(), myString.end());

    // Swap
    string otherString = "Bye";
    myString.swap(otherString);
    cout << "After swap(): " << myString << " " << otherString << endl; // Output: After swap(): Bye Hi

    string s = "Hello World 123";
    char ch = s[0]; // First character of the string

    cout << "Original string: " << s << endl;
    cout << "Original character: " << ch << endl;

    // Convert character to lowercase and uppercase
    char lowerChar = tolower(static_cast<unsigned char>(ch));
    char upperChar = toupper(static_cast<unsigned char>(ch));
    cout << "Lowercase character: " << lowerChar << endl;
    cout << "Uppercase character: " << upperChar << endl;

    // Check if the character is alphanumeric
    bool isCharAlphanumeric = isalnum(static_cast<unsigned char>(ch));
    cout << "Is character alphanumeric: " << boolalpha << isCharAlphanumeric << endl;

    // Convert the string to lowercase and uppercase
    string lowerStr = s;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    cout << "Lowercase string: " << lowerStr << endl;

    string upperStr = s;
    transform(upperStr.begin(), upperStr.end(), upperStr.begin(), ::toupper);
    cout << "Uppercase string: " << upperStr << endl;

    // Check if the string is alphanumeric
    bool isStrAlphanumeric = !s.empty() && all_of(s.begin(), s.end(), ::isalnum);
    cout << "Is string alphanumeric: " << boolalpha << isStrAlphanumeric << endl;

    return 0;
}
