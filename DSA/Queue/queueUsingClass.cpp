#include <iostream>

using namespace std;

template<typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& d) : data(d), next(nullptr) {}
    };

    Node* frontPtr;
    Node* rearPtr;
    size_t size;

public:
    Queue() : frontPtr(nullptr), rearPtr(nullptr), size(0) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(const T& item) {
        Node* newNode = new Node(item);
        if (isEmpty()) {
            frontPtr = newNode;
            rearPtr = newNode;
        } else {
            rearPtr->next = newNode;
            rearPtr = newNode;
        }
        size++;
    }

    void dequeue() {
        if (!isEmpty()) {
            Node* temp = frontPtr;
            frontPtr = frontPtr->next;
            delete temp;
            size--;
        }
    }

    T front() const {
        if (!isEmpty()) {
            return frontPtr->data;
        }
        throw out_of_range("Queue is empty");
    }

    bool isEmpty() const {
        return size == 0;
    }

    size_t getSize() const {
        return size;
    }
};

int main() {
    Queue<int> q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    cout << "Queue Front: " << q.front() << endl;
    cout << "Queue Size: " << q.getSize() << endl;

    q.dequeue();

    cout << "Queue Front after dequeue: " << q.front() << endl;
    cout << "Queue Size after dequeue: " << q.getSize() << endl;

    return 0;
}
