
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

#include "binary_heap.hh"

using namespace std;

// Function to simulate the heap property verification using public methods
bool verifyHeapProperty(BinaryHeap heap) {  // Use a copy of the heap to not modify the original
    std::vector<std::pair<float, int>> elements;
    while (!heap.empty()) {
        elements.push_back(heap.top());
        heap.pop();
    }

    // Check if the elements are in non-decreasing order (min-heap property)
    for (size_t i = 1; i < elements.size(); i++) {
        if (elements[i - 1].first > elements[i].first) {
            return false;
        }
    }
    return true;
}

int main() {
    const int NUM_VERTICES = 10000;  // Assuming the known number of vertices
    BinaryHeap heap(NUM_VERTICES);

    // Insertion test
    cout << "Insertion test progress: ";
    for (int i = 0; i < NUM_VERTICES; i++) {
        heap.push(make_pair(NUM_VERTICES - i, i));
        assert(verifyHeapProperty(heap));
        if (i % (NUM_VERTICES / 10) == 0) {
            cout << (i * 100) / NUM_VERTICES << "%.. ";
            cout.flush();
        }
    }
    cout << "100%\n";

    // Top and pop test
    cout << "Top and pop test progress: ";
    for (int i = 0; i < NUM_VERTICES; i++) {
        assert(heap.top().first == i + 1);
        heap.pop();
        assert(verifyHeapProperty(heap));
        if (i % (NUM_VERTICES / 10) == 0) {
            cout << (i * 100) / NUM_VERTICES << "%.. ";
            cout.flush();
        }
    }
    cout << "100%\n";

    // Insertion and decreaseKey test
    cout << "Insertion and decreaseKey test progress: ";
    for (int i = 0; i < NUM_VERTICES; i++) {
        heap.push(make_pair(NUM_VERTICES - i, i));
        if (i % (NUM_VERTICES / 10) == 0) {
            cout << (i * 50) / NUM_VERTICES << "%.. ";
            cout.flush();
        }
    }
    for (int i = 0; i < NUM_VERTICES; i++) {
        heap.decreaseKey(i, NUM_VERTICES - i - 1);  // Decrease the key by 1 to ensure it's always smaller
        assert(verifyHeapProperty(heap));
        if (i % (NUM_VERTICES / 10) == 0) {
            cout << 50 + (i * 50) / NUM_VERTICES << "%.. ";
            cout.flush();
        }
    }
    cout << "100%\n";

    // Stress test: Random operations
    // Reset the heap
    heap = BinaryHeap(NUM_VERTICES);
    cout << "Stress test progress: ";
    vector<int> randomValues(NUM_VERTICES);
    for (int i = 0; i < NUM_VERTICES; i++) {
        randomValues[i] = NUM_VERTICES - i;
    }
    random_shuffle(randomValues.begin(), randomValues.end());
    for (int i : randomValues) {
        heap.push(make_pair(i, i));
        if (i % (NUM_VERTICES / 10) == 0) {
            cout << (i * 50) / NUM_VERTICES << "%.. ";
            cout.flush();
        }
    }
    for (int i : randomValues) {
        heap.decreaseKey(i, i / 2);
        assert(verifyHeapProperty(heap));
        if (i % (NUM_VERTICES / 10) == 0) {
            cout << 50 + (i * 50) / NUM_VERTICES << "%.. ";
            cout.flush();
        }
    }
    cout << "100%\n";

    cout << "All tests passed!" << endl;

    return 0;
}
