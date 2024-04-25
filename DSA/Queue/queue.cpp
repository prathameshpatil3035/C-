#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};

class Queue {
private:
    Node* frontPtr;
    Node* rearPtr;

public:
    Queue() : frontPtr(nullptr), rearPtr(nullptr) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(int item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            frontPtr = newNode;
            rearPtr = newNode;
        } else {
            rearPtr->next = newNode;
            rearPtr = newNode;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            Node* temp = frontPtr;
            frontPtr = frontPtr->next;
            delete temp;
            if (frontPtr == nullptr) {
                rearPtr = nullptr;
            }
        }
    }

    int front() {
        if (!isEmpty()) {
            return frontPtr->data;
        }
        throw out_of_range("Queue is empty");
    }

    bool isEmpty() {
        return frontPtr == nullptr;
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl;

    q.dequeue();

    cout << "Front element after dequeue: " << q.front() << endl;

    return 0;
}
