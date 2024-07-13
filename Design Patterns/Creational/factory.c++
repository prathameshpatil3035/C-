// The Factory Design Pattern is a creational design pattern that provides an interface for creating objects in a superclass, but allows subclasses to alter the type of objects that will be created. It deals with the problem of creating objects without specifying the exact class of object that will be created.

// Explanation
// The Factory Pattern typically involves the following components:

// Product: The interface or abstract class that defines the object type to be created.
// ConcreteProduct: Classes that implement the Product interface.
// Creator: The factory class that declares the factory method, which returns a Product object. It may also define a default implementation of the factory method.
// ConcreteCreator: Subclasses that override the factory method to return instances of ConcreteProduct.


#include <iostream>
using namespace std;

// Product interface
class Shape {
public:
    virtual void draw() const = 0;
    virtual ~Shape() {}
};

// Concrete Product: Circle
class Circle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a Circle" << endl;
    }
};

// Concrete Product: Square
class Square : public Shape {
public:
    void draw() const override {
        cout << "Drawing a Square" << endl;
    }
};

// Concrete Product: Triangle
class Triangle : public Shape {
public:
    void draw() const override {
        cout << "Drawing a Triangle" << endl;
    }
};

// Factory Class /  Creator class (also acts as ConcreteCreator here)
class ShapeFactory {
public:
    enum ShapeType {
        CIRCLE,
        SQUARE,
        TRIANGLE
    };

    Shape* createShape(ShapeType type) const {
        switch (type) {
            case CIRCLE:
                return new Circle();
            case SQUARE:
                return new Square();
            case TRIANGLE:
                return new Triangle();
            default:
                return nullptr;
        }
    }
};

// Creator class
// class AnimalFactory {
// public:
//     virtual Animal* createAnimal() const = 0;
//     virtual ~AnimalFactory() = default;
// };

// ConcreteCreator for Dog
// class DogFactory : public AnimalFactory {
// public:
//     Animal* createAnimal() const override {
//         return new Dog();
//     }
// };

// ConcreteCreator for Cat
// class CatFactory : public AnimalFactory {
// public:
//     Animal* createAnimal() const override {
//         return new Cat();
//     }
// };

int main() {

    ShapeFactory factory;

    // Create shapes
    Shape* circle = factory.createShape(ShapeFactory::CIRCLE);
    Shape* square = factory.createShape(ShapeFactory::SQUARE);
    Shape* triangle = factory.createShape(ShapeFactory::TRIANGLE);

    // Use shapes
    if (circle) circle->draw(); // Outputs: Drawing a Circle
    if (square) square->draw(); // Outputs: Drawing a Square
    if (triangle) triangle->draw(); // Outputs: Drawing a Triangle

    // Clean up
    delete circle;
    delete square;
    delete triangle;

    return 0;
}
