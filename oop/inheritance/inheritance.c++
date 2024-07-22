// Types of Inheritance:-
// Single Inheritance: A derived class inherits from only one base class.
// Multiple Inheritance: A derived class inherits from more than one base class.
// Multilevel Inheritance: A class is derived from another derived class.
// Hierarchical Inheritance: Multiple classes are derived from a single base class.
// Hybrid Inheritance: A combination of two or more types of inheritance.

//example of inheritance:-
#include <iostream>
#include <string>

// Base class
class Vehicle {
public:
    Vehicle(std::string brand) : brand(brand) {}

    void honk() {
        std::cout << brand << " goes beep beep!" << std::endl;
    }

protected:
    std::string brand;
};

// Derived class inheriting from Vehicle
class Car : public Vehicle {
public:
    Car(std::string brand, std::string model) : Vehicle(brand), model(model) {}

    void display() {
        std::cout << "Brand: " << brand << ", Model: " << model << std::endl;
    }

private:
    std::string model;
};

int main() {
    Car car("Toyota", "Corolla");
    car.honk();
    car.display();

    return 0;
}
