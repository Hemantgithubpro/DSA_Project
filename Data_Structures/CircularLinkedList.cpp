#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// CircularLinkedList class
class CircularLinkedList {
private:
    Node* head;

public:
    // Constructor
    CircularLinkedList() {
        head = nullptr;
    }

    // Insert at the end
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;  // Points back to itself
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Insert at the beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;

        if (head == nullptr) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;  // Update head to the new beginning
        }
    }

    // Delete a node by value
    void deleteByValue(int value) {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        // If head node is the one to be deleted
        if (head->data == value) {
            while (temp->next != head) {
                temp = temp->next;
            }
            if (head->next == head) {  // Only one node
                delete head;
                head = nullptr;
            } else {
                temp->next = head->next;
                delete head;
                head = temp->next;
            }
            return;
        }

        // Find the node to delete
        do {
            prev = temp;
            temp = temp->next;
        } while (temp != head && temp->data != value);

        // If the node is found
        if (temp->data == value) {
            prev->next = temp->next;
            delete temp;
        } else {
            cout << "Value not found in the list." << endl;
        }
    }

    // Displaying the Doubly linked list
    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }

    // Destructor to free memory
    ~CircularLinkedList() {
        if (head == nullptr) return;

        Node* temp = head;
        do {
            Node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        } while (temp != head);
        head = nullptr;
    }
};

int main() {
    CircularLinkedList clist;

    // Insert nodes
    clist.insertAtEnd(10);
    clist.insertAtEnd(20);
    clist.insertAtBeginning(5);
    clist.insertAtEnd(30);

    // Display list
    cout << "Circular Linked List: ";
    clist.display();

    // Delete node
    clist.deleteByValue(20);
    cout << "After deleting 20: ";
    clist.display();

    return 0;
}
