// The Builder Design Pattern is a creational design pattern that allows for the construction of complex objects step-by-step. It separates the construction of a complex object from its representation, so the same construction process can create different representations.

// Explanation
// In the Builder Pattern, there are four main components:

// Builder: This is an abstract interface that defines all the steps required to create the product.
// Concrete Builder: This implements the Builder interface and provides specific implementations of the steps to construct the product.
// Product: This is the complex object that is being constructed.
// Director: This is responsible for managing the construction process. It uses a Builder object to construct a Product.

#include <iostream>
#include <string>

using namespace std;

// Product class
class Car {
public:
    string body;
    string engine;
    string wheels;

    void show() {
        cout << "Car with Body: " << body << ", Engine: " << engine << ", Wheels: " << wheels << endl;
    }
};

// Builder interface
class CarBuilder {
public:
    virtual void buildBody() = 0;
    virtual void buildEngine() = 0;
    virtual void buildWheels() = 0;
    virtual Car* getCar() = 0;
    virtual ~CarBuilder() = default;
};

// Concrete Builder for Sports Car
class SportsCarBuilder : public CarBuilder {
private:
    Car* car;
public:
    SportsCarBuilder() { car = new Car(); }

    void buildBody() override {
        car->body = "Sporty Body";
    }

    void buildEngine() override {
        car->engine = "V8 Engine";
    }

    void buildWheels() override {
        car->wheels = "Sport Wheels";
    }

    Car* getCar() override {
        return car;
    }
};

// Concrete Builder for Sedan Car
class SedanCarBuilder : public CarBuilder {
private:
    Car* car;
public:
    SedanCarBuilder() { car = new Car(); }

    void buildBody() override {
        car->body = "Sedan Body";
    }

    void buildEngine() override {
        car->engine = "I4 Engine";
    }

    void buildWheels() override {
        car->wheels = "Regular Wheels";
    }

    Car* getCar() override {
        return car;
    }
};

// Director
class Director {
private:
    CarBuilder* builder;
public:
    void setBuilder(CarBuilder* b) {
        builder = b;
    }

    Car* constructCar() {
        builder->buildBody();
        builder->buildEngine();
        builder->buildWheels();
        return builder->getCar();
    }
};

int main() {
    Director director;
    
    // Create Sports Car
    SportsCarBuilder sportsCarBuilder;
    director.setBuilder(&sportsCarBuilder);
    Car* sportsCar = director.constructCar();
    sportsCar->show();
    delete sportsCar;

    // Create Sedan Car
    SedanCarBuilder sedanCarBuilder;
    director.setBuilder(&sedanCarBuilder);
    Car* sedanCar = director.constructCar();
    sedanCar->show();
    delete sedanCar;

    return 0;
}
