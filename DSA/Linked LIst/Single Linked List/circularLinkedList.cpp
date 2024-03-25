#include <iostream>
using namespace std;

// Definition for singly-linked list node
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class CircularLinkedList {
private:
    ListNode* head;

public:
    CircularLinkedList() : head(nullptr) {}

    // Method to insert a new node at the end of the list
    void insertEnd(int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            head->next = head; // Point to itself to make it circular
        } else {
            ListNode* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // Make the new node point to the head to maintain circularity
        }
    }

    // Method to delete a node from the list by value
    void deleteNode(int val) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }

        ListNode* prev = nullptr;
        ListNode* current = head;
        do {
            if (current->val == val) {
                if (current == head) {
                    if (head->next == head) { // Only one node in the list
                        delete head;
                        head = nullptr;
                    } else {
                        ListNode* temp = head;
                        while (temp->next != head) {
                            temp = temp->next;
                        }
                        temp->next = head->next;
                        delete head;
                        head = temp->next;
                    }
                    return;
                } else {
                    prev->next = current->next;
                    delete current;
                    return;
                }
            }
            prev = current;
            current = current->next;
        } while (current != head);

        cout << "Node with value " << val << " not found in the list." << endl;
    }

      void insertEnd(int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            head->next = head; // Point to itself to make it circular
        } else {
            ListNode* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head; // Make the new node point to the head to maintain circularity
        }
    }

    // Method to insert a new node at the beginning of the list
    void insertFront(int val) {
        ListNode* newNode = new ListNode(val);
        if (!head) {
            head = newNode;
            head->next = head; // Point to itself to make it circular
        } else {
            ListNode* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
            head = newNode; // Update head to point to the new node
        }
    }

    // Method to insert a new node at a specified position in the list
    void insertAt(int val, int pos) {
        if (pos <= 0) {
            cout << "Invalid position." << endl;
            return;
        }
        if (pos == 1) {
            insertFront(val);
            return;
        }
        ListNode* newNode = new ListNode(val);
        ListNode* current = head;
        int count = 1;
        while (current && count < pos - 1) {
            current = current->next;
            count++;
        }
        if (!current) {
            cout << "Position out of range." << endl;
            delete newNode;
            return;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    // Method to delete the first node of the list
    void deleteFirst() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        ListNode* temp = head;
        ListNode* lastNode = head;
        while (lastNode->next != head) {
            lastNode = lastNode->next;
        }
        if (head->next == head) { // Only one node in the list
            delete head;
            head = nullptr;
        } else {
            head = head->next;
            lastNode->next = head;
            delete temp;
        }
    }

    // Method to delete the last node of the list
    void deleteLast() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        ListNode* temp = head;
        ListNode* prev = nullptr;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        if (prev) {
            prev->next = head;
        } else { // Only one node in the list
            delete head;
            head = nullptr;
            return;
        }
        delete temp;
    }

    // Method to delete a node from the list by value
    void deleteNode(int val) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        ListNode* temp = head;
        ListNode* prev = nullptr;
        do {
            if (temp->val == val) {
                if (temp == head) {
                    deleteFirst();
                    return;
                }
                prev->next = temp->next;
                delete temp;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);
        cout << "Node with value " << val << " not found in the list." << endl;
    }

    // Method to clear the entire list
    void clear() {
        while (head) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            if (head == temp) // Avoid infinite loop if head->next was not updated correctly
                head = nullptr;
        }
    }


    // Method to display the list
    void display() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        ListNode* current = head;
        do {
            cout << current->val << " ";
            current = current->next;
        } while (current != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList cll;

    // Inserting elements at the end
    cll.insertEnd(1);
    cll.insertEnd(2);
    cll.insertEnd(3);

    cout << "Circular linked list:" << endl;
    cll.display(); // Output: 1 2 3

    // Deleting a node
    cll.deleteNode(2);
    cout << "List after deleting node with value 2:" << endl;
    cll.display(); // Output: 1 3

    // Deleting a node
    cll.deleteNode(1);
    cout << "List after deleting node with value 1:" << endl;
    cll.display(); // Output: 3

    // Deleting the only node
    cll.deleteNode(3);
    cout << "List after deleting node with value 3:" << endl;
    cll.display(); // Output: List is empty.

     // Inserting elements at the end
    cll.insertEnd(1);
    cll.insertEnd(2);
    cll.insertEnd(3);

    cout << "Circular linked list:" << endl;
    cll.display(); // Output: 1 2 3

    // Inserting elements at the front
    cll.insertFront(0);
    cll.insertFront(-1);

    cout << "Circular linked list after inserting at front:" << endl;
    cll.display(); // Output: -1 0 1 2 3

    // Inserting at specified position
    cll.insertAt(4, 4);
    cout << "List after inserting 4 at position 4:" << endl;
    cll.display(); // Output: -1 0 1 4 2 3

    // Deleting first and last node
    cll.deleteFirst();
    cll.deleteLast();
    cout << "List after deleting first and last node:" << endl;
    cll.display(); // Output: 0 1 4 2

    // Deleting a node
    cll.deleteNode(1);
    cout << "List after deleting node with value 1:" << endl;
    cll.display(); // Output: 0 4 2

    // Clearing the list
    cll.clear();
    cout << "List after clearing:" << endl;
    cll.display(); // Output: List is empty.

    return 0;
}
