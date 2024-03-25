#include <iostream>
using namespace std;

// Definition for doubly-linked list node
struct ListNode {
    int val;
    ListNode* prev;
    ListNode* next;
    ListNode(int x) : val(x), prev(nullptr), next(nullptr) {}
};

class DoublyLinkedList {
private:
    ListNode* head;
    ListNode* tail;

public:
    DoublyLinkedList() : head(nullptr), tail(nullptr) {}

    // Method to insert a new node at the end of the list
    void insertEnd(int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Method to insert a new node at the beginning of the list
    void insertFront(int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Method to delete a node from the list by value
    void deleteNode(int val) {
        ListNode* current = head;
        while (current) {
            if (current->val == val) {
                if (current == head && current == tail) {
                    head = tail = nullptr;
                } else if (current == head) {
                    head = head->next;
                    head->prev = nullptr;
                } else if (current == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Node with value " << val << " not found in the list." << endl;
    }

    // Method to display the list in forward direction
    void displayForward() {
        ListNode* current = head;
        while (current) {
            cout << current->val << " ";
            current = current->next;
        }
        cout << endl;
    }

    // Method to display the list in backward direction
    void displayBackward() {
        ListNode* current = tail;
        while (current) {
            cout << current->val << " ";
            current = current->prev;
        }
        cout << endl;
    }

    void deleteLast() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        ListNode* temp = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete temp;
    }

    // Method to delete the first node of the list
    void deleteFirst() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        ListNode* temp = head;
        head = head->next;
        head->prev = nullptr;
        delete temp;
    }

    // Method to delete a node from the list by value
    void deleteNode(int val) {
        ListNode* current = head;
        while (current) {
            if (current->val == val) {
                if (current == head) {
                    deleteFirst();
                    return;
                }
                if (current == tail) {
                    deleteLast();
                    return;
                }
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                return;
            }
            current = current->next;
        }
        cout << "Node with value " << val << " not found in the list." << endl;
    }

    // Method to clear the entire list
    void clear() {
        while (head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};


int main() {
    DoublyLinkedList dll;

    // Inserting elements at the end
    dll.insertEnd(1);
    dll.insertEnd(2);
    dll.insertEnd(3);

    // Inserting elements at the front
    dll.insertFront(0);
    dll.insertFront(-1);

    cout << "Forward traversal:" << endl;
    dll.displayForward(); // Output: -1 0 1 2 3

    cout << "Backward traversal:" << endl;
    dll.displayBackward(); // Output: 3 2 1 0 -1

    // Deleting a node
    dll.deleteNode(1);
    cout << "List after deleting 1:" << endl;
    dll.displayForward(); // Output: -1 0 2 3

    // Deleting last node
    dll.deleteLast();
    cout << "List after deleting last node:" << endl;
    dll.displayForward(); // Output: -1 0 1 4 2

    // Deleting first node
    dll.deleteFirst();
    cout << "List after deleting first node:" << endl;
    dll.displayForward(); // Output: 0 1 4 2

    // Deleting a node
    dll.deleteNode(1);
    cout << "List after deleting node with value 1:" << endl;
    dll.displayForward(); // Output: 0 4 2

    // Clearing the list
    dll.clear();
    cout << "List after clearing:" << endl;
    dll.displayForward();

    return 0;
}
