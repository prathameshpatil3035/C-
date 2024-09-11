// the ability of a function, object, or operator to take on multiple forms.It allows the same function or method to behave differently based on the object it is operating on.

#include <iostream>
#include <cmath>

// Abstract class
class Shape
{
public:
    virtual double area() const = 0;      // Pure virtual function
    virtual double perimeter() const = 0; // Pure virtual function
};

class Circle : public Shape
{
public:
    Circle(double radius) : radius(radius) {}

    double area() const override
    {
        return M_PI * radius * radius;
    }

    double perimeter() const override
    {
        return 2 * M_PI * radius;
    }

private:
    double radius;
};

class Rectangle : public Shape
{
public:
    Rectangle(double width, double height) : width(width), height(height) {}

    double area() const override
    {
        return width * height;
    }

    double perimeter() const override
    {
        return 2 * (width + height);
    }

private:
    double width;
    double height;
};

int main()
{
    Shape *shapes[2];
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);

    for (int i = 0; i < 2; ++i)
    {
        std::cout << "Shape " << i + 1 << " Area: " << shapes[i]->area() << std::endl;
        std::cout << "Shape " << i + 1 << " Perimeter: " << shapes[i]->perimeter() << std::endl;
    }

    // Clean up
    delete shapes[0];
    delete shapes[1];

    return 0;
}
