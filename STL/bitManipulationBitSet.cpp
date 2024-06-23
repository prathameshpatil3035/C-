#include <iostream>
#include <bitset>
#include <map>

using namespace std;

int main() {
    unsigned int n = 42; // 00101010 in binary
    int count = __builtin_popcount(n);

    cout << "Number of set bits in " << n << " is: " << count << endl; // Output: 3

    // Initialize a bitset of size 8 with the binary representation of 42 (00101010)
    bitset<8> bits(42);

    // Create a bitset from a string
    bitset<8> fromString("1100");
    cout << "Bitset from string: " << fromString << endl; // Output: 00001100

    // Output the initial bitset
    cout << "Initial bitset: " << bits << endl; // Output: 00101010

    // Set all bits to 1
    bits.set();
    cout << "After set(): " << bits << endl; // Output: 11111111

    // Reset all bits to 0
    bits.reset();
    cout << "After reset(): " << bits << endl; // Output: 00000000

    // Set specific bit (set bit at position 2 to 1)
    bits.set(2);
    cout << "After set(2): " << bits << endl; // Output: 00000100

    // Reset specific bit (reset bit at position 2 to 0)
    bits.reset(2);
    cout << "After reset(2): " << bits << endl; // Output: 00000000

    // Flip all bits
    bits.flip();
    cout << "After flip(): " << bits << endl; // Output: 11111111

    // Flip a specific bit (flip bit at position 2)
    bits.flip(2);
    cout << "After flip(2): " << bits << endl; // Output: 11111011

    // Count the number of set bits (1s)
    cout << "Number of set bits: " << bits.count() << endl; // Output: 7

    // Check if any bit is set
    cout << "Any bit set? " << bits.any() << endl; // Output: 1 (true)

    // Check if no bits are set
    cout << "No bits set? " << bits.none() << endl; // Output: 0 (false)

    // Check if all bits are set
    cout << "All bits set? " << bits.all() << endl; // Output: 0 (false)

    // Access a specific bit (bit at position 2)
    cout << "Bit at position 2: " << bits[2] << endl; // Output: 0

    // Size of the bitset
    cout << "Size of the bitset: " << bits.size() << endl; // Output: 8

    // Convert bitset to unsigned long
    cout << "Bitset to unsigned long: " << bits.to_ulong() << endl; // Output: 251

    // Convert bitset to unsigned long long
    cout << "Bitset to unsigned long long: " << bits.to_ullong() << endl; // Output: 251

    // Convert bitset to string
    cout << "Bitset to string: " << bits.to_string() << endl; // Output: 11111011

    // Test if a specific bit is set (true if bit is 1)
    cout << "Is bit 3 set? " << bits.test(3) << endl; // Output: 1 (true)
    cout << "Is bit 4 set? " << bits.test(4) << endl; // Output: 0 (false)

    // Left shift
    bitset<8> shiftedLeft = bits << 2;
    cout << "After left shift by 2: " << shiftedLeft << endl; // Output: 10100000

    // Right shift
    bitset<8> shiftedRight = bits >> 2;
    cout << "After right shift by 2: " << shiftedRight << endl; // Output: 00001010

    // Bitwise AND
    bitset<8> other(15); // 00001111 in binary
    bitset<8> andResult = bits & other;
    cout << "Bitwise AND with 15: " << andResult << endl; // Output: 00001010

    // Bitwise OR
    bitset<8> orResult = bits | other;
    cout << "Bitwise OR with 15: " << orResult << endl; // Output: 00101111

    // Bitwise XOR
    bitset<8> xorResult = bits ^ other;
    cout << "Bitwise XOR with 15: " << xorResult << endl; // Output: 00100101

    // Find the first set bit (1)
    size_t firstSetBit = bits._Find_first();
    cout << "First set bit position: " << firstSetBit << endl; // Output: 1

    // Find the next set bit after a given position
    size_t nextSetBit = bits._Find_next(1);
    cout << "Next set bit after position 1: " << nextSetBit << endl; // Output: 3

    // Iterate over bits using a loop
    cout << "Iterating over bits: ";
    for (size_t i = 0; i < bits.size(); ++i) {
        cout << bits[i]; // Output each bit
    }
    cout << endl; // Output: 01010100

    // Iterate over bits using range-based for loop
    cout << "Using range-based for loop: ";
    for (auto bit : bits.to_string()) {
        cout << bit;
    }
    cout << endl; // Output: 00101010

    // Create a map with bitset keys
    map<bitset<4>, string> bitsetMap;

    // Insert elements into the map
    bitsetMap[bitset<4>("1010")] = "Ten";
    bitsetMap[bitset<4>("0101")] = "Five";

    // Iterate over the map and print its elements
    for (const auto& pair : bitsetMap) {
        cout << pair.first << ": " << pair.second << endl;
    }
    // Output:
    // 0101: Five
    // 1010: Ten

    return 0;
}
