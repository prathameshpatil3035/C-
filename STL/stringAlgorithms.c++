#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <sstream>
#include <regex>
#include <vector>

using namespace std;

int main() {
    // 1. Substring Search

    // find(): Finds the first occurrence of a substring.
    {
        string str = "Hello, welcome to the world of C++!";
        size_t pos = str.find("world");
        cout << "find(): 'world' found at position: " << pos << endl; // Output: find(): 'world' found at position: 24
    }

    // rfind(): Finds the last occurrence of a substring.
    {
        string str = "Find the last occurrence of the word 'word' in this word.";
        size_t pos = str.rfind("word");
        cout << "rfind(): Last occurrence of 'word' at position: " << pos << endl; // Output: rfind(): Last occurrence of 'word' at position: 38
    }

    // find_first_of(): Finds the first occurrence of any character in a given set.
    {
        string str = "abcdef";
        size_t pos = str.find_first_of("de");
        cout << "find_first_of(): First occurrence of any character in 'de' is at position: " << pos << endl; // Output: find_first_of(): First occurrence of any character in 'de' is at position: 3
    }

    // find_last_of(): Finds the last occurrence of any character in a given set.
    {
        string str = "abcdef";
        size_t pos = str.find_last_of("de");
        cout << "find_last_of(): Last occurrence of any character in 'de' is at position: " << pos << endl; // Output: find_last_of(): Last occurrence of any character in 'de' is at position: 4
    }

    // 2. Substring Extraction

    // substr(): Extracts a substring.
    {
        string str = "Hello, world!";
        string sub = str.substr(7, 5); // Extract "world"
        cout << "substr(): Extracted substring: " << sub << endl; // Output: substr(): Extracted substring: world
    }

    // 3. String Comparison

    // compare(): Compares two strings.
    {
        string str1 = "Hello";
        string str2 = "Hello";
        string str3 = "World";

        int result1 = str1.compare(str2);
        int result2 = str1.compare(str3);

        if (result1 == 0) {
            cout << "compare(): str1 and str2 are equal." << endl; // Output: compare(): str1 and str2 are equal.
        }
        if (result2 < 0) {
            cout << "compare(): str1 is less than str3." << endl; // Output: compare(): str1 is less than str3.
        }
    }

    // 4. String Manipulation

    // append(): Appends to the end of the string.
    {
        string str = "Hello";
        str.append(" World");
        cout << "append(): " << str << endl; // Output: append(): Hello World
    }

    // insert(): Inserts a substring at a specified position.
    {
        string str = "Hello World";
        str.insert(5, ",");
        cout << "insert(): " << str << endl; // Output: insert(): Hello, World
    }

    // erase(): Erases a portion of the string.
    {
        string str = "Hello, World!";
        str.erase(5, 2); // Erase ", "
        cout << "erase(): " << str << endl; // Output: erase(): HelloWorld!
    }

    // replace(): Replaces a portion of the string with another string.
    {
        string str = "Hello World!";
        str.replace(6, 5, "Universe"); // Replace "World" with "Universe"
        cout << "replace(): " << str << endl; // Output: replace(): Hello Universe!
    }

    // 5. String Conversion

    // stoi(): Converts a string to an integer.
    {
        string str = "123";
        int num = stoi(str);
        cout << "stoi(): " << num << endl; // Output: stoi(): 123
    }

    // stol(): Converts a string to a long.
    {
        string str = "123456789";
        long num = stol(str);
        cout << "stol(): " << num << endl; // Output: stol(): 123456789
    }

    // stoll(): Converts a string to a long long.
    {
        string str = "123456789012345";
        long long num = stoll(str);
        cout << "stoll(): " << num << endl; // Output: stoll(): 123456789012345
    }

    // stof(): Converts a string to a float.
    {
        string str = "123.45";
        float num = stof(str);
        cout << "stof(): " << num << endl; // Output: stof(): 123.45
    }

    // stod(): Converts a string to a double.
    {
        string str = "123.456";
        double num = stod(str);
        cout << "stod(): " << num << endl; // Output: stod(): 123.456
    }

    // to_string(): Converts various types to a string.
    {
        int num = 123;
        string str = to_string(num);
        cout << "to_string(): " << str << endl; // Output: to_string(): 123
    }

    // 6. String Traversal

    // Iterators: Use iterators to traverse the string.
    {
        string str = "Hello";
        cout << "Iterators: ";
        for (auto it = str.begin(); it != str.end(); ++it) {
            cout << *it;
        }
        cout << endl; // Output: Iterators: Hello
    }

    // Range-Based For Loop: A modern way to iterate over the characters.
    {
        string str = "World";
        cout << "Range-Based For Loop: ";
        for (char ch : str) {
            cout << ch;
        }
        cout << endl; // Output: Range-Based For Loop: World
    }

    // 7. String Tokenization

    // getline(): Reads a line of text into a string.
    {
        string str = "Tokenize this line";
        istringstream iss(str);
        string token;
        cout << "getline(): ";
        while (getline(iss, token, ' ')) {
            cout << token << " "; // Output: Tokenize this line
        }
        cout << endl;
    }

    // strtok(): Tokenizes a C-style string (from <cstring>).
    {
        char str[] = "Tokenize,this,line";
        char* token = strtok(str, ",");
        cout << "strtok(): ";
        while (token != nullptr) {
            cout << token << " ";
            token = strtok(nullptr, ",");
        }
        cout << endl; // Output: strtok(): Tokenize this line
    }

    // 8. String Transformation

    // transform(): Applies a function to each character.
    {
        string str = "hello world";
        transform(str.begin(), str.end(), str.begin(), ::toupper);
        cout << "transform() to uppercase: " << str << endl; // Output: transform() to uppercase: HELLO WORLD
    }

    // toupper() / tolower(): Converts characters to uppercase or lowercase.
    {
        char upper = toupper('a');
        char lower = tolower('A');
        cout << "toupper(): " << upper << endl; // Output: toupper(): A
        cout << "tolower(): " << lower << endl; // Output: tolower(): a
    }

    // 9. String Searching

    // regex_search(): Searches for a regex pattern in a string.
    {
        string str = "The quick brown fox jumps over the lazy dog.";
        regex pattern("\\bfox\\b");
        bool found = regex_search(str, pattern);
        if (found) {
            cout << "regex_search(): Pattern 'fox' found in the string." << endl; // Output: regex_search(): Pattern 'fox' found in the string.
        }
    }

    // regex_match(): Checks if the entire string matches a regex pattern.
    {
        string str = "The quick brown fox jumps over the lazy dog.";
        regex pattern("The quick brown fox jumps over the lazy dog\\.");
        bool match = regex_match(str, pattern);
        if (match) {
            cout << "regex_match(): The entire string matches the pattern." << endl; // Output: regex_match(): The entire string matches the pattern.
        } else {
            cout << "regex_match(): The entire string does not match the pattern." << endl; // Output: regex_match(): The entire string does not match the pattern.
        }
    }

    // 10. String Splitting

    // Custom Split Function: Splits a string based on a delimiter.
    {
        string str = "split,this,string";
        vector<string> tokens;
        istringstream tokenStream(str);
        string token;
        while (getline(tokenStream, token, ',')) {
            tokens.push_back(token);
        }
        cout << "split(): ";
        for (const auto& t : tokens) {
            cout << t << " "; // Output: split(): split this string
        }
        cout << endl;
    }

    // 11. Remove_if
    {
        string s = "asd, sfj, lei#, *ue";
        s.erase(remove_if(s.begin(), s.end(), [](char c) {
            return !isalnum(c); // Remove non-alphanumeric characters
        }), s.end());
    }
    
    return 0;
}
