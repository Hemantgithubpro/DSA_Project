#include <iostream>
using namespace std;

// Node structure for AVL Tree
struct Node {
    int data;
    Node* left;
    Node* right;
    int height;

    // Constructor
    Node(int value) {
        data = value;
        left = right = nullptr;
        height = 1;
    }
};

// AVL Tree class
class AVLTree {
private:
    Node* root;

    // Helper function to get height of the node
    int height(Node* node) {
        return node ? node->height : 0;
    }

    // Helper function to get the balance factor of the node
    int getBalance(Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    // Right rotation
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        // Return new root
        return x;
    }

    // Left rotation
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        // Return new root
        return y;
    }

    // Insert a node in the AVL Tree
    Node* insert(Node* node, int value) {
        // 1. Perform normal BST insertion
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        } else {
            return node;  // Duplicates not allowed
        }

        // 2. Update height of this ancestor node
        node->height = 1 + max(height(node->left), height(node->right));

        // 3. Get the balance factor to check if node is unbalanced
        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && value < node->left->data) {
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && value > node->right->data) {
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        // Return the (unchanged) node pointer
        return node;
    }

    // In-order traversal
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    // Helper function to find the node with minimum value
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

    // Delete a node from the AVL Tree
    Node* deleteNode(Node* node, int value) {
        // 1. Perform standard BST delete
        if (node == nullptr) {
            return node;
        }
        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            // Node with one child or no child
            if ((node->left == nullptr) || (node->right == nullptr)) {
                Node* temp = node->left ? node->left : node->right;
                if (temp == nullptr) {
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                // Node with two children
                Node* temp = minValueNode(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }

        // If the tree had only one node
        if (node == nullptr) {
            return node;
        }

        // 2. Update height of current node
        node->height = 1 + max(height(node->left), height(node->right));

        // 3. Get balance factor
        int balance = getBalance(node);

        // Left Left Case
        if (balance > 1 && getBalance(node->left) >= 0) {
            return rightRotate(node);
        }

        // Left Right Case
        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && getBalance(node->right) <= 0) {
            return leftRotate(node);
        }

        // Right Left Case
        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

public:
    // Constructor
    AVLTree() {
        root = nullptr;
    }

    // Public insert function
    void insert(int value) {
        root = insert(root, value);
    }

    // Public delete function
    void deleteValue(int value) {
        root = deleteNode(root, value);
    }

    // Public in-order display function
    void displayInOrder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    AVLTree avl;

    // Insert nodes
    avl.insert(10);
    avl.insert(20);
    avl.insert(30);
    avl.insert(40);
    avl.insert(50);
    avl.insert(25);

    cout << "In-order traversal of the AVL Tree: ";
    avl.displayInOrder();

    // Delete a node
    avl.deleteValue(40);
    cout << "In-order traversal after deleting 40: ";
    avl.displayInOrder();

    return 0;
}
