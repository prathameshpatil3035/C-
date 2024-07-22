#include <iostream>

using namespace std;

void print(int* ptr) {
    cout << "Value: " << *ptr << endl;
}

int main() {
    const int val = 42;
    // Removing constness
    print(const_cast<int*>(&val)); // Output: Value: 42

    int nonConstVal = 100;
    const int* constPtr = &nonConstVal;
    // Adding constness
    int* modifiablePtr = const_cast<int*>(constPtr);
    *modifiablePtr = 200;
    cout << "Modified value: " << nonConstVal << endl; // Output: Modified value: 200

    return 0;
}
