#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Insertion Operations
void insertAtBeginning(Node* &head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(Node* &head, int val) {
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

void insertAfter(Node* prevNode, int val) {
    if (prevNode == nullptr) {
        cout << "Previous node cannot be null." << endl;
        return;
    }
    Node* newNode = new Node(val);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

// Deletion Operations
void deleteAtBeginning(Node* &head) {
    if (head == nullptr) {
        cout << "List is empty. Nothing to delete." << endl;
        return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
}

void deleteByKey(Node* &head, int key) {
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

// Traversal Operation
void display(Node* head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// Searching Operation
Node* search(Node* head, int key) {
    while (head != nullptr) {
        if (head->data == key) {
            return head;
        }
        head = head->next;
    }
    return nullptr;
}

// Length Operation
int length(Node* head) {
    int count = 0;
    while (head != nullptr) {
        count++;
        head = head->next;
    }
    return count;
}

// Reverse Operation
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* nextNode = nullptr;
    while (current != nullptr) {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }
    return prev;
}

int main() {
    Node* head = nullptr;
    
    // Insertion
    insertAtBeginning(head, 10);
    insertAtEnd(head, 20);
    insertAfter(head->next, 15);
    
    // Displaying the linked list
    cout << "Linked List: ";
    display(head); // Output: 10 15 20
    
    // Deletion
    deleteAtBeginning(head);
    deleteByKey(head, 20);
    
    // Displaying the linked list after deletion
    cout << "Linked List after deletion: ";
    display(head); // Output: 15
    
    // Searching
    Node* foundNode = search(head, 15);
    if (foundNode != nullptr) {
        cout << "Node with value 15 found." << endl;
    } else {
        cout << "Node with value 15 not found." << endl;
    }
    
    // Length
    cout << "Length of the linked list: " << length(head) << endl; // Output: 1
    
    // Reverse
    head = reverse(head);
    
    // Displaying the reversed linked list
    cout << "Reversed Linked List: ";
    display(head); // Output: 15
    
    return 0;
}
