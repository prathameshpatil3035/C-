#include <iostream>

// Base class
class Animal {
public:
    void eat() {
        std::cout << "Eating..." << std::endl;
    }
};

// Derived class 1
class Dog : public Animal {
public:
    void bark() {
        std::cout << "Barking..." << std::endl;
    }
};

// Derived class 2
class Cat : public Animal {
public:
    void meow() {
        std::cout << "Meowing..." << std::endl;
    }
};

int main() {
    Dog dog;
    Cat cat;
    dog.eat();  // Inherited from Animal
    dog.bark(); // Defined in Dog

    cat.eat();  // Inherited from Animal
    cat.meow(); // Defined in Cat

    return 0;
}
