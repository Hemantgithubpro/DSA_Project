#include <iostream>
#include <vector>
using namespace std;

class MinHeap {
private:
    vector<int> heap;

    // Get the parent index
    int parent(int i) { return (i - 1) / 2; }

    // Get the left child index
    int leftChild(int i) { return (2 * i + 1); }

    // Get the right child index
    int rightChild(int i) { return (2 * i + 2); }

    // Heapify down to maintain min-heap property
    void heapifyDown(int i) {
        int smallest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        // If left child is smaller
        if (left < heap.size() && heap[left] < heap[smallest]) {
            smallest = left;
        }

        // If right child is smaller
        if (right < heap.size() && heap[right] < heap[smallest]) {
            smallest = right;
        }

        // If the smallest is not the current node
        if (smallest != i) {
            swap(heap[i], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    // Heapify up to maintain min-heap property
    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] > heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

public:
    // Insert a new element into the heap
    void insert(int key) {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    // Remove and return the minimum element (root) from the heap
    int extractMin() {
        if (heap.size() == 0) {
            throw out_of_range("Heap is empty");
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return root;
    }

    // Get the minimum element from the heap
    int getMin() {
        if (heap.size() == 0) {
            throw out_of_range("Heap is empty");
        }
        return heap[0];
    }

    // Display the elements of the heap
    void display() {
        for (int i : heap) {
            cout << i << " ";
        }
        cout << endl;
    }
};

int main() {
    MinHeap minHeap;

    minHeap.insert(10);
    minHeap.insert(20);
    minHeap.insert(5);
    minHeap.insert(15);
    minHeap.insert(30);

    cout << "Min Heap elements: ";
    minHeap.display();

    cout << "Minimum element: " << minHeap.getMin() << endl;

    cout << "Extracting minimum element: " << minHeap.extractMin() << endl;

    cout << "Min Heap after extraction: ";
    minHeap.display();

    return 0;
}
