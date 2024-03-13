#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    // I/O
    cout << "\nI/O:" << endl;
    string input;
    cout << "Enter a string: ";
    getline(cin, input);
    cout << "You entered: " << input << endl;

    // String Concatenation
    cout << "\nString Concatenation:" << endl;
    string concat = "Hello";
    concat += ", World!";
    cout << "Concatenated string: " << concat << endl;

    // String Length
    cout << "\nString Length:" << endl;
    string str_length = "Hello, world!";
    cout << "Length of the string: " << str_length.length() << endl;

    // String Comparison
    cout << "\nString Comparison:" << endl;
    const char* str_cmp1 = "Hello";
    const char* str_cmp2 = "Hello";
    int comparison_result = strcmp(str_cmp1, str_cmp2);
    cout << "Comparison result of 'Hello' and 'Hello': " << comparison_result << endl;

    // Constructor/Destructor
    string str1;                             // Default constructor
    string str2("Hello");                    // Constructor with C string
    string str3(str2);                       // Copy constructor
    string str4(5, 'x');                     // Constructor with repetition
    cout << "str1: " << str1 << endl;        // str1: 
    cout << "str2: " << str2 << endl;        // str2: Hello
    cout << "str3: " << str3 << endl;        // str3: Hello
    cout << "str4: " << str4 << endl;        // str4: xxxxx

    // Assignment Operator
    string str5 = "World";                   // Assignment operator
    str1 = str5;                              // Assigning one string to another
    cout << "str1 after assignment: " << str1 << endl;   // str1 after assignment: World

    // Modifiers
    // append()
    string str1 = "Hello";
    string str2 = "World";
    cout << "Before append: " << str1 << endl;
    str1.append(" ");
    str1.append(str2);
    cout << "After append: " << str1 << endl;

    // push_back()
    string str3 = "Hello";
    cout << "Before push_back: " << str3 << endl;
    str3.push_back(' ');
    str3.push_back('W');
    str3.push_back('o');
    str3.push_back('r');
    str3.push_back('l');
    str3.push_back('d');
    cout << "After push_back: " << str3 << endl;

    // assign()
    string str4;
    cout << "Before assign: " << str4 << endl;
    str4.assign("Hello");
    cout << "After assign: " << str4 << endl;

    // insert()
    string str5 = "Hello";
    cout << "Before insert: " << str5 << endl;
    str5.insert(5, ", world");
    cout << "After insert: " << str5 << endl;

    // erase()
    string str6 = "Hello, world!";
    cout << "Before erase: " << str6 << endl;
    str6.erase(5, 7);
    cout << "After erase: " << str6 << endl;

    // replace()
    string str7 = "Hello, world!";
    cout << "Before replace: " << str7 << endl;
    str7.replace(7, 6, "universe");
    cout << "After replace: " << str7 << endl;

    // swap()
    string str8 = "Hello";
    string str9 = "World";
    cout << "Before swap: str8 = " << str8 << ", str9 = " << str9 << endl;
    str8.swap(str9);
    cout << "After swap: str8 = " << str8 << ", str9 = " << str9 << endl;

    // clear()
    string str10 = "Hello, world!";
    cout << "Before clear: " << str10 << endl;
    str10.clear();
    cout << "After clear: " << str10 << endl;

    string str = "Hello, world!";
    // Element Access
    cout << "Element Access:" << endl;
    char ch1 = str[0];
    char ch2 = str.at(1);
    char ch3 = str.front();
    char ch4 = str.back();
    const char* cstr = str.data();
    cout << "Using operator[]: " << ch1 << endl;    // Using operator[]: H
    cout << "Using at(): " << ch2 << endl;         // Using at(): e
    cout << "Using front(): " << ch3 << endl;      // Using front(): H
    cout << "Using back(): " << ch4 << endl;       // Using back(): !
    cout << "Using data(): " << cstr << endl;      // Using data(): Hello, world!

    // Capacity
    cout << "\nCapacity:" << endl;
    bool empty = str.empty();
    size_t size = str.size();    // Same as str.length();
    size_t max_size = str.max_size();
    size_t capacity = str.capacity();
    str.reserve(50);
    size_t new_capacity = str.capacity();
    str.shrink_to_fit();
    size_t after_shrink_capacity = str.capacity();
    cout << "Is empty? " << (empty ? "Yes" : "No") << endl;     // Is empty? No
    cout << "Size of the string: " << size << endl;            // Size of the string: 13
    cout << "Max size of the string: " << max_size << endl;    // Max size of the string: some_large_value
    cout << "Capacity of the string: " << capacity << endl;    // Capacity of the string: 13
    cout << "Capacity after reserve: " << new_capacity << endl; // Capacity after reserve: 50
    cout << "Capacity after shrink: " << after_shrink_capacity << endl; // Capacity after shrink: 13

    // String Operations
    cout << "\nString Operations:" << endl;
    const char* c_string = str.c_str();
    string copied_string = str;
    string substr = str.substr(7, 5);
    size_t find_result = str.find("world");
    size_t rfind_result = str.rfind("o");
    size_t find_first_of_result = str.find_first_of("o");
    size_t find_last_of_result = str.find_last_of("o");
    size_t find_first_not_of_result = str.find_first_not_of("Hello,");
    size_t find_last_not_of_result = str.find_last_not_of("!");
    int compare_result = str.compare("Hello, world!");
    cout << "C-style string: " << c_string << endl;                 // C-style string: Hello, world!
    cout << "Copied string: " << copied_string << endl;             // Copied string: Hello, world!
    cout << "Substring: " << substr << endl;                        // Substring: world
    cout << "Find 'world': " << find_result << endl;                // Find 'world': 7
    cout << "Reverse Find 'o': " << rfind_result << endl;           // Reverse Find 'o': 8
    cout << "Find first of 'o': " << find_first_of_result << endl;  // Find first of 'o': 4
    cout << "Find last of 'o': " << find_last_of_result << endl;    // Find last of 'o': 8
    cout << "Find first not of 'Hello,': " << find_first_not_of_result << endl;  // Find first not of 'Hello,': 7
    cout << "Find last not of '!': " << find_last_not_of_result << endl;         // Find last not of '!': 12
    cout << "Compare with 'Hello, world!': " << compare_result << endl;           // Compare with 'Hello, world!': 0

    // Iterators
    cout << "\nIterators:" << endl;
    for (auto it = str.begin(); it != str.end(); ++it) {
        cout << *it;
    }
    cout << endl;

    for (auto rit = str.rbegin(); rit != str.rend(); ++rit) {
        cout << *rit;
    }
    cout << endl;

    // cstring functions
    // strcpy
    char destination[20];
    const char* source = "Hello, world!";
    strcpy(destination, source);
    cout << "strcpy: " << destination << endl; // Output: strcpy: Hello, world!

    // strncpy
    char dest2[20];
    const char* src2 = "Hello, universe!";
    strncpy(dest2, src2, 5);
    dest2[5] = '\0'; // Null-terminate the string
    cout << "strncpy: " << dest2 << endl; // Output: strncpy: Hello

    // strcat
    char string1[20] = "Hello, ";
    const char* string2 = "world!";
    strcat(string1, string2);
    cout << "strcat: " << string1 << endl; // Output: strcat: Hello, world!

    // strncat
    char string3[20] = "Hello, ";
    const char* string4 = "universe!";
    strncat(string3, string4, 5);
    cout << "strncat: " << string3 << endl; // Output: strncat: Hello, unive

    // strcmp
    const char* string5 = "Hello";
    const char* string6 = "World";
    int comparison = strcmp(string5, string6);
    cout << "strcmp: " << comparison << endl; // Output: strcmp: -15

    // strncmp
    const char* string7 = "Hello";
    const char* string8 = "Hell";
    int comparison2 = strncmp(string7, string8, 4);
    cout << "strncmp: " << comparison2 << endl; // Output: strncmp: 0

    // strlen
    const char* string9 = "Hello, world!";
    cout << "strlen: " << strlen(string9) << endl; // Output: strlen: 13

    // strchr
    const char* string10 = "Hello, world!";
    char* pointer = strchr(string10, 'o');
    if (pointer != nullptr) {
        cout << "strchr: " << pointer - string10 << endl; // Output: strchr: 4
    } else {
        cout << "Character not found." << endl;
    }

    // strrchr
    const char* string11 = "Hello, world!";
    char* pointer2 = strrchr(string11, 'o');
    if (pointer2 != nullptr) {
        cout << "strrchr: " << pointer2 - string11 << endl; // Output: strrchr: 8
    } else {
        cout << "Character not found." << endl;
    }

    // strstr
    const char* string12 = "Hello, world!";
    const char* substring = "world";
    char* pointer3 = strstr(string12, substring);
    if (pointer3 != nullptr) {
        cout << "strstr: " << pointer3 - string12 << endl; // Output: strstr: 7
    } else {
        cout << "Substring not found." << endl;
    }

    // strpbrk
    const char* string13 = "Hello, world!";
    const char* accept = "wxy";
    char* pointer4 = strpbrk(string13, accept);
    if (pointer4 != nullptr) {
        cout << "strpbrk: " << pointer4 - string13 << endl; // Output: strpbrk: 7
    } else {
        cout << "No characters found." << endl;
    }

    // strspn
    const char* string14 = "Hello, world!";
    const char* accept2 = "Helo,";
    size_t length = strspn(string14, accept2);
    cout << "strspn: " << length << endl; // Output: strspn: 9

    // strcspn
    const char* string15 = "Hello, world!";
    const char* reject = " ,!";
    size_t length2 = strcspn(string15, reject);
    cout << "strcspn: " << length2 << endl; // Output: strcspn: 5

    // memset
    char string16[20] = "Hello, world!";
    memset(string16, '*', 5);
    cout << "memset: " << string16 << endl; // Output: memset: ***** world!

    // memcpy
    char string17[20] = "Hello, world!";
    char buffer[20];
    memcpy(buffer, string17, 5);
    buffer[5] = '\0'; // Null-terminate the string
    cout << "memcpy: " << buffer << endl; // Output: memcpy: Hello

    // memmove
    char string18[20] = "Hello, world!";
    memmove(string18 + 7, string18 + 2, 5);
    cout << "memmove: " << string18 << endl; // Output: memmove: Hello, llo world!

    // memcmp
    const char* string19 = "Hello";
    const char* string20 = "Hel";
    int comparison3 = memcmp(string19, string20, 3);
    cout << "memcmp: " << comparison3 << endl; // Output: memcmp: 0

    // memchr
    const char* string21 = "Hello, world!";
    char* pointer5 = (char*)memchr(string21, 'o', 13);
    if (pointer5 != nullptr) {
        cout << "memchr: " << pointer5 - string21 << endl; // Output: memchr: 4
    } else {
        cout << "Character not found." << endl;
    }

    return 0;
}
