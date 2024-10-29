#include <iostream>
using namespace std;

// Node structure for Queue
struct Node {
    int data;
    Node* next;
};

// Queue class
class Queue {
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    Queue() {
        front = rear = nullptr;
    }

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Enqueued " << value << " to queue." << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        front = front->next;

        // If the queue is now empty
        if (front == nullptr) {
            rear = nullptr;
        }

        cout << "Dequeued " << temp->data << " from queue." << endl;
        delete temp;
    }

    // Peek operation
    int peek() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return -1; // Return -1 or handle appropriately for empty queue
        }
        return front->data;
    }

    // Display the queue
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    // Destructor to free memory
    ~Queue() {
        while (front != nullptr) {
            dequeue();
        }
    }
};

int main() {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    cout << "Queue contents: ";
    queue.display();

    cout << "Front element is: " << queue.peek() << endl;

    queue.dequeue();
    cout << "Queue after dequeue: ";
    queue.display();

    return 0;
}
