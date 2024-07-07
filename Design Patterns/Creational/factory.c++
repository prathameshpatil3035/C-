#include <iostream>

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
        std::cout << "Drawing a Circle" << std::endl;
    }
};

// Concrete Product: Square
class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Square" << std::endl;
    }
};

// Concrete Product: Triangle
class Triangle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a Triangle" << std::endl;
    }
};

// Factory Class
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

int main() {
    using namespace std; // Use the standard namespace

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
