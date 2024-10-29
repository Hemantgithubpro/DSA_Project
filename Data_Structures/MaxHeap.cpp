#include <iostream>
#include <vector>
using namespace std;

class MaxHeap {
private:
    vector<int> heap;

    // Get the parent index
    int parent(int i) { return (i - 1) / 2; }

    // Get the left child index
    int leftChild(int i) { return (2 * i + 1); }

    // Get the right child index
    int rightChild(int i) { return (2 * i + 2); }

    // Heapify down to maintain max-heap property
    void heapifyDown(int i) {
        int largest = i;
        int left = leftChild(i);
        int right = rightChild(i);

        // If left child is larger
        if (left < heap.size() && heap[left] > heap[largest]) {
            largest = left;
        }

        // If right child is larger
        if (right < heap.size() && heap[right] > heap[largest]) {
            largest = right;
        }

        // If the largest is not the current node
        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    // Heapify up to maintain max-heap property
    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] < heap[i]) {
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

    // Remove and return the maximum element (root) from the heap
    int extractMax() {
        if (heap.size() == 0) {
            throw out_of_range("Heap is empty");
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return root;
    }

    // Get the maximum element from the heap
    int getMax() {
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
    MaxHeap maxHeap;

    maxHeap.insert(10);
    maxHeap.insert(20);
    maxHeap.insert(5);
    maxHeap.insert(15);
    maxHeap.insert(30);

    cout << "Max Heap elements: ";
    maxHeap.display();

    cout << "Maximum element: " << maxHeap.getMax() << endl;

    cout << "Extracting maximum element: " << maxHeap.extractMax() << endl;

    cout << "Max Heap after extraction: ";
    maxHeap.display();

    return 0;
}
