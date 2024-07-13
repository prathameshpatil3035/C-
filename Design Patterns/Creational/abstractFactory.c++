// The Abstract Factory Design Pattern is a creational design pattern that provides an interface for creating families of related or dependent objects without specifying their concrete classes. This pattern allows you to produce different types of products using a single interface, promoting consistency among products of the same family and supporting the creation of families of related objects.

// Explanation
// The Abstract Factory Pattern typically involves the following components:

// AbstractFactory: An interface for creating abstract product families.
// ConcreteFactory: Classes that implement the AbstractFactory interface to create specific product families.
// AbstractProduct: An interface for a type of product.
// ConcreteProduct: Classes that implement the AbstractProduct interface.
// Client: Uses the AbstractFactory to create objects and interact with them through their interfaces.


#include <iostream>
#include <string>

using namespace std;

// Abstract Product: Button
class Button {
public:
    virtual void press() const = 0;
    virtual ~Button() = default;
};

// Abstract Product: TextBox
class TextBox {
public:
    virtual void show() const = 0;
    virtual ~TextBox() = default;
};

// Concrete Product: Windows Button
class WinButton : public Button {
public:
    void press() const override {
        cout << "Windows Button pressed" << endl;
    }
};

// Concrete Product: Windows TextBox
class WinTextBox : public TextBox {
public:
    void show() const override {
        cout << "Windows TextBox showing" << endl;
    }
};

// Concrete Product: Mac Button
class MacButton : public Button {
public:
    void press() const override {
        cout << "Mac Button pressed" << endl;
    }
};

// Concrete Product: Mac TextBox
class MacTextBox : public TextBox {
public:
    void show() const override {
        cout << "Mac TextBox showing" << endl;
    }
};

// Abstract Factory Interface
class IFactory {
public:
    virtual Button* createButton() const = 0;
    virtual TextBox* createTextBox() const = 0;
    virtual ~IFactory() = default;
};

// Concrete Factory: Windows Factory
class WinFactory : public IFactory {
public:
    Button* createButton() const override {
        return new WinButton();
    }
    TextBox* createTextBox() const override {
        return new WinTextBox();
    }
};

// Concrete Factory: Mac Factory
class MacFactory : public IFactory {
public:
    Button* createButton() const override {
        return new MacButton();
    }
    TextBox* createTextBox() const override {
        return new MacTextBox();
    }
};

// Abstract Factory
class GUIFactory {
public:
    // Static method to create the appropriate factory
    static IFactory* createFactory(const string& osType) {
        if (osType == "Windows") {
            return new WinFactory();
        } else if (osType == "Mac") {
            return new MacFactory();
        } else {
            return nullptr;
        }
    }
};

// Client Code
void clientCode(const IFactory& factory) {
    Button* button = factory.createButton();
    TextBox* textBox = factory.createTextBox();

    button->press();
    textBox->show();

    delete button;
    delete textBox;
}

int main() {
    string osType;
    cout << "Enter OS type (Windows/Mac): ";
    cin >> osType;

    IFactory* factory = GUIFactory::createFactory(osType);
    if (factory) {
        clientCode(*factory);
        delete factory;
    } else {
        cout << "Unknown OS type" << endl;
    }

    return 0;
}
