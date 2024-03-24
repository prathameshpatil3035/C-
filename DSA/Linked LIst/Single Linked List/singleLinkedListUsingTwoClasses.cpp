#include <iostream>
using namespace std;

// Node class
class Node {
public:
    int data;
    Node* next;
    
    // Constructor
    Node(int val) : data(val), next(nullptr) {}
};

// LinkedList class
class LinkedList {
private:
    Node* head; // Head pointer of the linked list

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Insertion at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insertion at the end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Displaying the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Deletion from the beginning
    void deleteAtBeginning() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete." << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Deletion by key
    void deleteByKey(int key) {
        Node* temp = head;
        Node* prev = nullptr;
        if (temp != nullptr && temp->data == key) {
            head = temp->next;
            delete temp;
            return;
        }
        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Key not found in the list." << endl;
            return;
        }
        prev->next = temp->next;
        delete temp;
    }

    // Searching for a key
    Node* search(int key) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->data == key) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }

    // Length of the linked list
    int length() {
        int count = 0;
        Node* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    // Reverse the linked list
    void reverse() {
        Node* prev = nullptr;
        Node* current = head;
        Node* nextNode = nullptr;
        while (current != nullptr) {
            nextNode = current->next;
            current->next = prev;
            prev = current;
            current = nextNode;
        }
        head = prev;
    }
};

int main() {
    LinkedList myList;
    
    // Insertion
    myList.insertAtBeginning(10);
    myList.insertAtEnd(20);
    myList.insertAtEnd(30);

    // Displaying the linked list
    cout << "Linked List: ";
    myList.display(); // Output: 10 20 30

    // Deletion
    myList.deleteAtBeginning();
    myList.deleteByKey(20);

    // Displaying the linked list after deletion
    cout << "Linked List after deletion: ";
    myList.display(); // Output: 30

    // Searching
    Node* foundNode = myList.search(30);
    if (foundNode != nullptr) {
        cout << "Node with value 30 found." << endl;
    } else {
        cout << "Node with value 30 not found." << endl;
    }

    // Length
    cout << "Length of the linked list: " << myList.length() << endl; // Output: 1

    // Reverse
    myList.reverse();

    // Displaying the reversed linked list
    cout << "Reversed Linked List: ";
    myList.display(); // Output: 30

    return 0;
}
