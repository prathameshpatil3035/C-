#include <iostream>

// Base class
class Animal {
public:
    void eat() {
        std::cout << "Eating..." << std::endl;
    }
};

// Derived class
class Mammal : public Animal {
public:
    void breathe() {
        std::cout << "Breathing..." << std::endl;
    }
};

// Further derived class
class Dog : public Mammal {
public:
    void bark() {
        std::cout << "Barking..." << std::endl;
    }
};

int main() {
    Dog dog;
    dog.eat();     // Inherited from Animal
    dog.breathe(); // Inherited from Mammal
    dog.bark();    // Defined in Dog

    return 0;
}
