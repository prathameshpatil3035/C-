#include <iostream>

using namespace std;

// Function to get the value of a specific bit
bool getBit(int num, int pos) {
    return (num & (1 << pos)) != 0;
}

// Function to set a specific bit to 1
int setBit(int num, int pos) {
    return num | (1 << pos);
}

// Function to clear a specific bit (set it to 0)
int clearBit(int num, int pos) {
    int mask = ~(1 << pos);
    return num & mask;
}

// Function to update a specific bit to a given value (0 or 1)
int updateBit(int num, int pos, bool bitValue) {
    int value = bitValue ? 1 : 0;
    int mask = ~(1 << pos);
    return (num & mask) | (value << pos);
}

// Check if a number is a power of two
bool isPowerOfTwo(int num) {
    return (num & (num - 1)) == 0 && num != 0;
}

// Count the number of set bits (1s) in the binary representation of a number
int countSetBits(int num) {
    int count = 0;
    while (num) {
        num &= (num - 1);
        count++;
    }
    return count;
}

// Generate all possible subsets of a set represented by an array
void generateSubsets(int arr[], int n) {
    // Total subsets will be 2^n
    int totalSubsets = 1 << n;
    
    // Iterate through all subsets
    for (int i = 0; i < totalSubsets; i++) {
        cout << "{ ";
        // Print elements of the subset
        for (int j = 0; j < n; j++) {
            // Check if j-th bit of i is set
            if (i & (1 << j)) {
                cout << arr[j] << " ";
            }
        }
        cout << "}" << endl;
    }
}

int main() {
    int num = 15; // Binary representation: 1111

    // Get value of bit at position 2
    cout << "Bit at position 2: " << getBit(num, 2) << endl;

    // Set bit at position 1 to 1
    num = setBit(num, 1); // Binary representation after setting: 1111 -> 1111
    cout << "After setting bit at position 1: " << num << endl;

    // Clear bit at position 3
    num = clearBit(num, 3); // Binary representation after clearing: 1111 -> 1011
    cout << "After clearing bit at position 3: " << num << endl;

    // Update bit at position 0 to 0
    num = updateBit(num, 0, false); // Binary representation after updating: 1011 -> 1010
    cout << "After updating bit at position 0 to 0: " << num << endl;

     // Test isPowerOfTwo function
    int num1 = 8; // 8 is a power of two
    cout << num1 << " is " << (isPowerOfTwo(num1) ? "a" : "not a") << " power of two." << endl;

    int num2 = 10; // 10 is not a power of two
    cout << num2 << " is " << (isPowerOfTwo(num2) ? "a" : "not a") << " power of two." << endl;

    // Test countSetBits function
    int num3 = 15; // Binary representation: 1111 (4 set bits)
    cout << "Number of set bits in " << num3 << " is " << countSetBits(num3) << endl;

    // Generate subsets
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Subsets of {1, 2, 3}:" << endl;
    generateSubsets(arr, n);

    return 0;
}
