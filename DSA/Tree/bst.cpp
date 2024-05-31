#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <stdexcept>

using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insertRecursive(Node* root, int value) {
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

    Node* searchRecursive(Node* root, int value) {
        if (root == nullptr || root->data == value) {
            return root;
        }

        if (value < root->data) {
            return searchRecursive(root->left, value);
        } else {
            return searchRecursive(root->right, value);
        }
    }

    Node* deleteRecursive(Node* root, int value) {
        if (root == nullptr) {
            return nullptr;
        }

        if (value < root->data) {
            root->left = deleteRecursive(root->left, value);
        } else if (value > root->data) {
            root->right = deleteRecursive(root->right, value);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteRecursive(root->right, temp->data);
        }
        return root;
    }

    Node* findMin(Node* root) {
        while (root && root->left != nullptr) {
            root = root->left;
        }
        return root;
    }

    Node* findMax(Node* root) {
        while (root && root->right != nullptr) {
            root = root->right;
        }
        return root;
    }

    int heightRecursive(Node* root) {
        if (root == nullptr) {
            return -1;
        }
        int leftHeight = heightRecursive(root->left);
        int rightHeight = heightRecursive(root->right);
        return max(leftHeight, rightHeight) + 1;
    }

    void inOrderRecursive(Node* root, vector<int>& result) {
        if (root != nullptr) {
            inOrderRecursive(root->left, result);
            result.push_back(root->data);
            inOrderRecursive(root->right, result);
        }
    }

    void preOrderRecursive(Node* root, vector<int>& result) {
        if (root != nullptr) {
            result.push_back(root->data);
            preOrderRecursive(root->left, result);
            preOrderRecursive(root->right, result);
        }
    }

    void postOrderRecursive(Node* root, vector<int>& result) {
        if (root != nullptr) {
            postOrderRecursive(root->left, result);
            postOrderRecursive(root->right, result);
            result.push_back(root->data);
        }
    }

    bool isBSTUtil(Node* root, int min, int max) {
        if (root == nullptr) {
            return true;
        }

        if (root->data < min || root->data > max) {
            return false;
        }

        return isBSTUtil(root->left, min, root->data - 1) &&
               isBSTUtil(root->right, root->data + 1, max);
    }

public:
    BST() {
        root = nullptr;
    }

    void insert(int value) {
        root = insertRecursive(root, value);
    }

    bool search(int value) {
        return searchRecursive(root, value) != nullptr;
    }

    void remove(int value) {
        root = deleteRecursive(root, value);
    }

    int findMin() {
        Node* minNode = findMin(root);
        if (minNode != nullptr) {
            return minNode->data;
        }
        throw runtime_error("Tree is empty");
    }

    int findMax() {
        Node* maxNode = findMax(root);
        if (maxNode != nullptr) {
            return maxNode->data;
        }
        throw runtime_error("Tree is empty");
    }

    int height() {
        return heightRecursive(root);
    }

    vector<int> levelOrder() {
        vector<int> result;
        if (root == nullptr) {
            return result;
        }

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            result.push_back(current->data);
            if (current->left != nullptr) {
                q.push(current->left);
            }
            if (current->right != nullptr) {
                q.push(current->right);
            }
        }
        return result;
    }

    vector<int> inOrder() {
        vector<int> result;
        inOrderRecursive(root, result);
        return result;
    }

    vector<int> preOrder() {
        vector<int> result;
        preOrderRecursive(root, result);
        return result;
    }

    vector<int> postOrder() {
        vector<int> result;
        postOrderRecursive(root, result);
        return result;
    }

    bool isBST() {
        return isBSTUtil(root, numeric_limits<int>::min(), numeric_limits<int>::max());
    }

    Node* successor(int value) {
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
};

// Usage
int main() {
    BST tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    // Searching for a value
    int searchValue = 60;
    bool isFound = tree.search(searchValue);
    cout << "Search for " << searchValue << ": " << (isFound ? "Node found" : "Node not found") << endl;

    vector<int> levelOrder = tree.levelOrder();
    cout << "Level Order Traversal: ";
    for (int val : levelOrder) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> inOrder = tree.inOrder();
    cout << "Inorder Traversal: ";
    for (int val : inOrder) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> preOrder = tree.preOrder();
    cout << "Preorder Traversal: ";
    for (int val : preOrder) {
        cout << val << " ";
    }
    cout << endl;

    vector<int> postOrder = tree.postOrder();
    cout << "Postorder Traversal: ";
    for (int val : postOrder) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Height of the tree: " << tree.height() << endl;
    cout << "Minimum value: " << tree.findMin() << endl;
    cout << "Maximum value: " << tree.findMax() << endl;
    cout << "Is BST: " << (tree.isBST() ? "Yes" : "No") << endl;

    int value = 30;
    Node* successor = tree.successor(value);
    cout << "Successor of " << value << ": " << (successor ? to_string(successor->data) : "No successor found") << endl;

    // Deleting a node
    tree.remove(20);
    inOrder = tree.inOrder();
    cout << "Inorder Traversal after deleting 20: ";
    for (int val : inOrder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
