#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Stack {
private:
    ListNode* top;

public:
    Stack() : top(nullptr) {}

    // Method to push a new element onto the stack
    void push(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = top;
        top = newNode;
    }

    // Method to pop the top element from the stack
    void pop() {
        if (!top) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        ListNode* temp = top;
        top = top->next;
        delete temp;
    }

    // Method to return the top element of the stack
    int peek() {
        if (!top) {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1; // Assuming -1 represents an empty stack
        }
        return top->val;
    }

    // Method to check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Method to reverse the stack
    void reverse() {
        Stack auxStack;
        while (!isEmpty()) {
            auxStack.push(peek());
            pop();
        }
        while (!auxStack.isEmpty()) {
            push(auxStack.peek());
            auxStack.pop();
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

    // Reversing the stack
    stack.reverse();

    // Popping and printing elements from the stack
    while (!stack.isEmpty()) {
        cout << stack.peek() << " ";
        stack.pop();
    }
    cout << endl; // Output: 1 2 3

    return 0;
}
