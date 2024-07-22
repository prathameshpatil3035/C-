#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // Constructor
    Person(std::string name, int age) : name(name), age(age) {}

    // Getter for name
    std::string getName() {
        return name;
    }

    // Setter for name
    void setName(std::string name) {
        this->name = name;
    }

    // Getter for age
    int getAge() {
        return age;
    }

    // Setter for age
    void setAge(int age) {
        if (age > 0) {
            this->age = age;
        }
    }

    // Method to display person's details
    void display() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    Person person("John", 30);
    person.display();

    person.setName("Jane");
    person.setAge(25);
    person.display();

    return 0;
}
