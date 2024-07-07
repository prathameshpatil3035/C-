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
        std::cout << "Windows Button pressed" << std::endl;
    }
};

// Concrete Product: Windows TextBox
class WinTextBox : public TextBox {
public:
    void show() const override {
        std::cout << "Windows TextBox showing" << std::endl;
    }
};

// Concrete Product: Mac Button
class MacButton : public Button {
public:
    void press() const override {
        std::cout << "Mac Button pressed" << std::endl;
    }
};

// Concrete Product: Mac TextBox
class MacTextBox : public TextBox {
public:
    void show() const override {
        std::cout << "Mac TextBox showing" << std::endl;
    }
};

//Factory Interface
class IFactory{
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
    static IFactory* createFactory(const std::string& osType) {
        if (osType == "Windows") {
            return new WinFactory();
        } else if (osType == "Mac") {
            return new MacFactory();
        } else {
            return nullptr;
        }
    }
};

int main() {

    string osType;
    cout << "Enter OS type (Windows/Mac): ";
    cin >> osType;

    GUIFactory guiFactory;
    const IFactory* const ifactory = GUIFactory::createFactory(osType);

    const Button* button = ifactory->createButton();
    button->press();

    const TextBox* textBox = ifactory->createTextBox();
    textBox->show();

    return 0;
}
