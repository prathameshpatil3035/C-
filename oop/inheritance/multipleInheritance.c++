#include <iostream>

// Base class 1
class Person {
public:
    void speak() {
        std::cout << "Speaking..." << std::endl;
    }
};

// Base class 2
class Employee {
public:
    void work() {
        std::cout << "Working..." << std::endl;
    }
};

// Derived class
class Manager : public Person, public Employee {
public:
    void manage() {
        std::cout << "Managing..." << std::endl;
    }
};

int main() {
    Manager manager;
    manager.speak();  // Inherited from Person
    manager.work();   // Inherited from Employee
    manager.manage(); // Defined in Manager

    return 0;
}
