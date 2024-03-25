#include <iostream>
#include <stack>
using namespace std;

class Stack {
private:
    stack<int> st;

public:
    // Method to push a new element onto the stack
    void push(int val) {
        st.push(val);
    }

    // Method to pop the top element from the stack
    void pop() {
        if (!st.empty())
            st.pop();
        else
            cout << "Stack is empty. Cannot pop." << endl;
    }

    // Method to return the top element of the stack
    int peek() {
        if (!st.empty())
            return st.top();
        else {
            cout << "Stack is empty. Cannot peek." << endl;
            return -1; // Assuming -1 represents an empty stack
        }
    }

    // Method to check if the stack is empty
    bool isEmpty() {
        return st.empty();
    }

    // Method to get the size of the stack
    int size() {
        return st.size();
    }

    // Method to print the elements of the stack
    void print() {
        if (st.empty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        stack<int> temp = st;
        cout << "Stack elements (top to bottom): ";
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }

    // Method to clear the stack
    void clear() {
        while (!st.empty())
            st.pop();
    }

    // Method to reverse the stack
    void reverse() {
        stack<int> auxStack;
        while (!st.empty()) {
            auxStack.push(st.top());
            st.pop();
        }
        st = auxStack;
    }

    //swap
    void Swap(){
    stack<int> st1, st2;
    st1.swap(st2);
    }
};

int main() {
    Stack s;

    // Pushing elements onto the stack
    s.push(1);
    s.push(2);
    s.push(3);

    // Printing stack elements
    s.print(); // Output: Stack elements (top to bottom): 3 2 1

    // Popping elements from the stack
    s.pop();

    // Printing the top element of the stack
    cout << "Top element of the stack: " << s.peek() << endl; // Output: 2

    // Checking if the stack is empty
    cout << "Is the stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl; // Output: No

    // Getting the size of the stack
    cout << "Size of the stack: " << s.size() << endl; // Output: 2

    // Clearing the stack
    s.clear();
    s.print(); // Output: Stack is empty.

    // Reversing the stack
    s.reverse();

    // Printing reversed stack elements
    s.print(); // Output: Stack elements (top to bottom): 1 2 3
    return 0;
}
