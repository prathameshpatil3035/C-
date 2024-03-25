#include <iostream>
using namespace std;

class Stack {
private:
    static const int MAX_SIZE = 1000; // Maximum size of the stack
    int arr[MAX_SIZE];
    int top; // Index of the top element

public:
    Stack() : top(-1) {}

    // Method to push a new element onto the stack
    void push(int val) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack overflow. Cannot push." << endl;
            return;
        }
        arr[++top] = val;
    }

    // Method to pop the top element from the stack
    void pop() {
        if (top < 0) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        top--;
    }

    // Method to return the top element of the stack
    int peek() {
        if (top < 0) {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1; // Assuming -1 represents an empty stack
        }
        return arr[top];
    }

    // Method to check if the stack is empty
    bool isEmpty() {
        return top < 0;
    }

    // Method to reverse the elements in the stack
    void reverse() {
        if (isEmpty())
            return;
        int temp[MAX_SIZE];
        int index = 0;
        while (!isEmpty()) {
            temp[index++] = peek();
            pop();
        }
        for (int i = 0; i < index; i++) {
            push(temp[i]);
        }
    }
};

int main() {
    Stack stack;

    // Pushing elements onto the stack
    stack.push(1);
    stack.push(2);
    stack.push(3);

    // Peeking at the top element
    cout << "Top element of the stack: " << stack.peek() << endl; // Output: 3

    // Popping elements from the stack
    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop(); // Trying to pop from an empty stack

    // Checking if the stack is empty
    cout << "Is the stack empty? " << (stack.isEmpty() ? "Yes" : "No") << endl; // Output: Yes

    // Reversing the elements in the stack
    stack.reverse();

    // Peeking at the top element after reversal
    cout << "Top element of the stack after reversal: " << stack.peek() << endl; // Output: 1


    return 0;
}
