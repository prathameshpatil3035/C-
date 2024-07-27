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

    // Copy constructor
    Stack(const Stack& other) : top(nullptr) {
        if (other.top == nullptr) {
            return;
        }
        
        // Copy the list into a stack
        ListNode* current = other.top;
        ListNode* newNode = new ListNode(current->val);
        top = newNode;
        ListNode* thisCurrent = top;

        while (current->next != nullptr) {
            current = current->next;
            newNode = new ListNode(current->val);
            thisCurrent->next = newNode;
            thisCurrent = newNode;
        }
    }

    // Destructor
    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Method to push a new element onto the stack
    void push(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = top;
        top = newNode;
    }

    // Method to pop the top element from the stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        ListNode* temp = top;
        top = top->next;
        delete temp;
    }

    // Method to return the top element of the stack
    int peek() const {
        if (isEmpty()) {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1; // Assuming -1 represents an empty stack
        }
        return top->val;
    }

    // Method to check if the stack is empty
    bool isEmpty() const {
        return top == nullptr;
    }

    // Method to reverse the stack
    void reverse() {
        ListNode* prev = nullptr;
        ListNode* curr = top;
        ListNode* next = nullptr;
        
        while (curr != nullptr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        top = prev;
    }

    // Method to print the stack
    void print() const {
        Stack copyStack(*this); // Create a copy of the stack for printing

        while (!copyStack.isEmpty()) {
            cout << copyStack.peek() << " ";
            copyStack.pop();
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    // Pushing elements onto the stack
    stack.push(1);
    stack.push(2);
    stack.push(3);
    
    stack.print(); // Output should be 3 2 1
    
    stack.reverse();
    stack.print(); // Output should be 1 2 3

    return 0;
}
