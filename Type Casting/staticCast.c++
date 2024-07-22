#include <iostream>

using namespace std;

int main() {
    // Numeric conversion
    double numDouble = 9.99;
    int numInt = static_cast<int>(numDouble);
    cout << "Double to int: " << numInt << endl; // Output: Double to int: 9

    // Pointer conversion (upcasting)
    class Base {
    public:
        virtual void show() {
            cout << "Base class" << endl;
        }
    };

    class Derived : public Base {
    public:
        void show() override {
            cout << "Derived class" << endl;
        }
    };

    Derived derived;
    Base* basePtr = static_cast<Base*>(&derived);
    basePtr->show(); // Output: Derived class

    return 0;
}
