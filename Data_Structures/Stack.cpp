#include <iostream>
using namespace std;

// Node structure for Stack
struct Node {
    int data;
    Node* next;
};

// Stack class
class Stack {
private:
    Node* top;

public:
    // Constructor
    Stack() {
        top = nullptr;
    }

    // Push operation
    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        cout << "Pushed " << value << " onto stack." << endl;
    }

    // Pop operation
    void pop() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        cout << "Popped " << temp->data << " from stack." << endl;
        delete temp;
    }

    // Peek operation
    int peek() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return -1; // Return -1 or handle appropriately for empty stack
        }
        return top->data;
    }

    // Display the stack
    void display() {
        if (top == nullptr) {
            cout << "Stack is empty." << endl;
            return;
        }
        Node* temp = top;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free memory
    ~Stack() {
        while (top != nullptr) {
            pop();
        }
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Stack contents: ";
    stack.display();

    cout << "Top element is: " << stack.peek() << endl;

    stack.pop();
    cout << "Stack after pop: ";
    stack.display();

    return 0;
}
