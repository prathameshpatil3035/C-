#include <iostream>

using namespace std;

int main() {
    class Base {
    public:
        virtual ~Base() {}
    };

    class Derived : public Base {
    public:
        void show() {
            cout << "Derived class" << endl;
        }
    };

    Base* basePtr = new Derived();
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);

    if (derivedPtr) {
        derivedPtr->show(); // Output: Derived class
    } else {
        cout << "Invalid cast" << endl;
    }

    delete basePtr;
    return 0;
}
