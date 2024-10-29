#include <iostream>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// BST class
class BinarySearchTree {
private:
    Node* root;

    // Helper function to insert a new node
    Node* insert(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }
        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        }
        return node;
    }

    // Helper function to find a node with a given value
    bool search(Node* node, int value) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == value) {
            return true;
        } else if (value < node->data) {
            return search(node->left, value);
        } else {
            return search(node->right, value);
        }
    }

    // Helper function for in-order traversal
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    // Helper function to delete a node
    Node* deleteNode(Node* node, int value) {
        if (node == nullptr) {
            return node;
        }
        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        } else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        } else {
            // Node with only one child or no child
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            // Node with two children: Get the inorder successor
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }
        return node;
    }

    // Helper function to find the minimum value node
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr) {
            current = current->left;
        }
        return current;
    }

public:
    // Constructor
    BinarySearchTree() {
        root = nullptr;
    }

    // Insert a new value
    void insert(int value) {
        root = insert(root, value);
    }

    // Search for a value
    bool search(int value) {
        return search(root, value);
    }

    // Delete a value
    void deleteValue(int value) {
        root = deleteNode(root, value);
    }

    // Display in-order traversal
    void displayInOrder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree bst;

    // Insert nodes
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "In-order traversal: ";
    bst.displayInOrder();

    // Search for a node
    int key = 40;
    if (bst.search(key)) {
        cout << key << " found in the tree." << endl;
    } else {
        cout << key << " not found in the tree." << endl;
    }

    // Delete a node
    bst.deleteValue(20);
    cout << "In-order traversal after deleting 20: ";
    bst.displayInOrder();

    return 0;
}
