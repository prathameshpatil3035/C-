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

// Intermediate derived class from Person
class Manager : public Person {
public:
    void manage() {
        std::cout << "Managing..." << std::endl;
    }
};

// Derived class from both Employee and Manager (Multiple inheritance)
class TeamLead : public Employee, public Manager {
public:
    void lead() {
        std::cout << "Leading..." << std::endl;
    }
};

int main() {
    TeamLead teamLead;
    teamLead.speak();  // Inherited from Person through Manager
    teamLead.work();   // Inherited from Employee
    teamLead.manage(); // Inherited from Manager
    teamLead.lead();   // Defined in TeamLead

    return 0;
}
