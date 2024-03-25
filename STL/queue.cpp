#include <iostream>
#include <queue>

using namespace std;

int main() {
    // Constructor
    queue<int> myQueue;

    // push
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    // Output: Queue elements after push: 10 20 30
    cout << "Queue elements after push: ";
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << endl;

    // front and back
    myQueue.push(40);
    myQueue.push(50);

    // Output: Front element: 40
    cout << "Front element: " << myQueue.front() << endl; // Output: Front element: 40

    // Output: Back element: 50
    cout << "Back element: " << myQueue.back() << endl; // Output: Back element: 50

    // pop
    myQueue.pop(); // Removes the front element

    // Output: Queue elements after pop: 50
    cout << "Queue elements after pop: ";
    while (!myQueue.empty()) {
        cout << myQueue.front() << " ";
        myQueue.pop();
    }
    cout << endl; // Output: Queue elements after pop: 50

    // empty
    cout << "Is queue empty? " << (myQueue.empty() ? "Yes" : "No") << endl; // Output: Is queue empty? Yes

    // size
    cout << "Size of queue: " << myQueue.size() << endl; // Output: Size of queue: 0

    return 0;
}
