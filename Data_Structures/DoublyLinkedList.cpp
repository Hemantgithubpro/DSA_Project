#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// DoublyLinkedList class
class DoublyLinkedList {
private:
    Node* head;

public:
    // Constructor
    DoublyLinkedList() {
        head = nullptr;
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            newNode->prev = nullptr;
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        newNode->prev = nullptr;

        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
    }

    // Delete a node by value
    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;

        // If the head node is to be deleted
        if (temp->data == value) {
            head = temp->next;
            if (head != nullptr) {
                head->prev = nullptr;
            }
            delete temp;
            return;
        }

        // Traverse to find the node to delete
        while (temp != nullptr && temp->data != value) {
            temp = temp->next;
        }

        // If the node is found
        if (temp != nullptr) {
            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            }
            if (temp->prev != nullptr) {
                temp->prev->next = temp->next;
            }
            delete temp;
        } else {
            cout << "Value not found in the list." << endl;
        }
    }

    // Display the list from beginning to end
    void displayForward() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Display the list from end to beginning
    void displayBackward() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free memory
    ~DoublyLinkedList() {
        Node* temp = head;
        while (temp != nullptr) {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
    }
};

int main() {
    DoublyLinkedList dlist;

    // Insert nodes
    dlist.insertAtEnd(10);
    dlist.insertAtEnd(20);
    dlist.insertAtBeginning(5);
    dlist.insertAtEnd(30);

    // Display list forward and backward
    cout << "Doubly Linked List (Forward): ";
    dlist.displayForward();

    cout << "Doubly Linked List (Backward): ";
    dlist.displayBackward();

    // Delete node
    dlist.deleteByValue(20);
    cout << "After deleting 20 (Forward): ";
    dlist.displayForward();

    return 0;
}
