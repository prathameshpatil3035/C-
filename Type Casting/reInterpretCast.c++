#include <iostream>

using namespace std;

int main() {
    int num = 65;
    // Reinterpret int as char
    char* charPtr = reinterpret_cast<char*>(&num);
    cout << "Reinterpreted value: " << *charPtr << endl; // Output: Reinterpreted value: A

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
    Base* basePtr = &derived;

    // Reinterpret Base pointer as Derived pointer
    Derived* derivedPtr = reinterpret_cast<Derived*>(basePtr);
    derivedPtr->show(); // Output: Derived class

    return 0;
}
