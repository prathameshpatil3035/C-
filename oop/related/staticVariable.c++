// In C++, a static variable behaves differently depending on where it's declared — in a file (as a global variable), within a function, or as part of a class. Here's a detailed explanation with examples for each case:

// 1. Static Variable in a File(as Global Variable)
//     A static global variable declared in a file has internal linkage,
//     meaning it is only visible within the file it is defined in.This restricts its scope to that file, preventing it from being used in other files even if they include the file.

// file1.cpp
#include <iostream>

static int fileStaticVar = 10; // Global static variable

void display()
{
    std::cout << "Global static variable: " << fileStaticVar << std::endl;
}

// file2.cpp
// This file cannot access `fileStaticVar` from file1.cpp due to its internal linkage.

// 2. Static Variable in a Function
// A static variable inside a function retains its value between function calls. It is initialized only once, the first time the function is called, and then keeps its state for the lifetime of the program.

#include <iostream>

void staticFunction()
{
    static int count = 0; // Static local variable
    count++;
    std::cout << "Static variable count: " << count << std::endl;
}

int main()
{
    staticFunction(); // count = 1
    staticFunction(); // count = 2
    staticFunction(); // count = 3
    return 0;
}

// 3. Static Variable in a Class
//     When a static variable is declared inside a class,
//     it is shared by all instances of that class.A static member is common to all objects, meaning there is only one copy of the variable, regardless of how many objects are created.

#include <iostream>

class MyClass
{
public:
    static int classStaticVar; // Static class variable

    void increment()
    {
        classStaticVar++;
    }

    static void display()
    {
        std::cout << "Static variable in class: " << classStaticVar << std::endl;
    }
};

// Definition of the static variable outside the class
int MyClass::classStaticVar = 0;

int main()
{
    MyClass obj1, obj2;

    obj1.increment();
    MyClass::display(); // Outputs: Static variable in class: 1

    obj2.increment();
    MyClass::display(); // Outputs: Static variable in class: 2

    return 0;
}

// Summary :  File - level static variable : Limited to file scope(internal linkage).Function - level static variable : Retains value between function calls.Class - level static variable : Shared across all instances of the class.