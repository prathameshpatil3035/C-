#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root;

    // Private helper methods
    Node* insertRecursive(Node* root, int value);
    Node* deleteRecursive(Node* root, int value);
    Node* findMin(Node* root);
    Node* findMax(Node* root);
    bool isBSTUtil(Node* root, int min, int max);
    void inOrderRecursive(Node* root);
    void preOrderRecursive(Node* root);
    void postOrderRecursive(Node* root);

public:
    BST() : root(nullptr) {}

    // Public methods
    void insert(int value);
    void remove(int value);
    int height();
    void levelOrder();
    void inOrder();
    void preOrder();
    void postOrder();
    int minValue();
    int maxValue();
    bool isBST();
    Node* successor(int value);
};

// Insertion
Node* BST::insertRecursive(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insertRecursive(root->left, value);
    } else if (value > root->data) {
        root->right = insertRecursive(root->right, value);
    }

    return root;
}

void BST::insert(int value) {
    root = insertRecursive(root, value);
}

// Deletion
Node* BST::deleteRecursive(Node* root, int value) {
    if (root == nullptr) {
        return nullptr;
    }

    if (value < root->data) {
        root->left = deleteRecursive(root->left, value);
    } else if (value > root->data) {
        root->right = deleteRecursive(root->right, value);
    } else {
        // Case 1: No child or only one child
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // Case 2: Two children
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteRecursive(root->right, temp->data);
    }
    return root;
}

void BST::remove(int value) {
    root = deleteRecursive(root, value);
}

// Helper function to find minimum value node in a subtree
Node* BST::findMin(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

// Helper function to find maximum value node in a subtree
Node* BST::findMax(Node* root) {
    if (root == nullptr) {
        return nullptr;
    }
    while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}

// Height of tree
int max(int a, int b) {
    return (a > b) ? a : b;
}

int BST::height() {
    if (root == nullptr) {
        return 0;
    }
    queue<Node*> q;
    q.push(root);
    int height = 0;

    while (!q.empty()) {
        int nodeCount = q.size();
        height++;

        while (nodeCount > 0) {
            Node* current = q.front();
            q.pop();
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
            nodeCount--;
        }
    }
    return height;
}

// Traversal - Level order
void BST::levelOrder() {
    if (root == nullptr) {
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
    cout << endl;
}

// Traversal - Inorder (DFS)
void BST::inOrderRecursive(Node* root) {
    if (root != nullptr) {
        inOrderRecursive(root->left);
        cout << root->data << " ";
        inOrderRecursive(root->right);
    }
}

void BST::inOrder() {
    inOrderRecursive(root);
    cout << endl;
}

// Traversal - Preorder (DFS)
void BST::preOrderRecursive(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";
        preOrderRecursive(root->left);
        preOrderRecursive(root->right);
    }
}

void BST::preOrder() {
    preOrderRecursive(root);
    cout << endl;
}

// Traversal - Postorder (DFS)
void BST::postOrderRecursive(Node* root) {
    if (root != nullptr) {
        postOrderRecursive(root->left);
        postOrderRecursive(root->right);
        cout << root->data << " ";
    }
}

void BST::postOrder() {
    postOrderRecursive(root);
    cout << endl;
}

// Minimum and Maximum value
int BST::minValue() {
    Node* minNode = findMin(root);
    if (minNode != nullptr) {
        return minNode->data;
    }
    throw runtime_error("Tree is empty");
}

int BST::maxValue() {
    Node* maxNode = findMax(root);
    if (maxNode != nullptr) {
        return maxNode->data;
    }
    throw runtime_error("Tree is empty");
}

// Check if BST
bool BST::isBSTUtil(Node* root, int min, int max) {
    if (root == nullptr) {
        return true;
    }

    if (root->data < min || root->data > max) {
        return false;
    }

    return (isBSTUtil(root->left, min, root->data - 1) &&
            isBSTUtil(root->right, root->data + 1, max));
}

bool BST::isBST() {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

// Successor in BST
Node* BST::successor(int value) {
    Node* current = root;
    Node* successor = nullptr;

    while (current != nullptr) {
        if (current->data > value) {
            successor = current;
            current = current->left;
        } else {
            current = current->right;
        }
    }
    return successor;
}

int main() {
    BST tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    cout << "Level Order Traversal: ";
    tree.levelOrder();

    cout << "Inorder Traversal: ";
    tree.inOrder();

    cout << "Preorder Traversal: ";
    tree.preOrder();

    cout << "Postorder Traversal: ";
    tree.postOrder();

    cout << "Height of the tree: " << tree.height() << endl;

    cout << "Minimum value: " << tree.minValue() << endl;
    cout << "Maximum value: " << tree.maxValue() << endl;

    cout << "Is BST: " << (tree.isBST() ? "Yes" : "No") << endl;

    int value = 30;
    Node* successor = tree.successor(value);
    if (successor != nullptr) {
        cout << "Successor of " << value << ": " << successor->data << endl;
    } else {
        cout << "No successor found for " << value << endl;
    }

    // Deleting a node
    tree.remove(20);
    cout << "Inorder Traversal after deleting 20: ";
    tree.inOrder();

    return 0;
}
