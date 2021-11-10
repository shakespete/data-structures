#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

class MaxHeap {
public:
    MaxHeap(vector<int> &vector);
    vector<int> heap;
    vector<int> buildMaxHeap(vector<int> &vector);
    void maxHeapify(int i, vector<int> &vector, int heapSize);
    void insert(int e);
    int extractMax();
};


MaxHeap::MaxHeap(vector<int> &vector) { heap = buildMaxHeap(vector); }
vector<int> MaxHeap::buildMaxHeap(vector<int> &vector) {
    int heapSize = (int)vector.size();
    int parentIdx = heapSize / 2 - 1;
    for (int i = parentIdx; i >= 0; --i) maxHeapify(i, vector, heapSize);
    return vector;
}
void MaxHeap::maxHeapify(int i, vector<int> &vector, int heapSize) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    int largest = i;
    if (l < heapSize && vector[l] > vector[i]) largest = l;
    if (r < heapSize && vector[r] > vector[largest]) largest = r;
    
    if (largest != i) {
        swap(vector[largest], vector[i]);
        maxHeapify(largest, vector, heapSize);
    }
}
void MaxHeap::insert(int e) {
    heap.push_back(e);
    int heapSize = (int)heap.size();
    int current = heapSize - 1;
    int parent = heapSize / 2 - 1;
    
    while (current >= 0 && heap[current] > heap[parent]) {
        swap(heap[current], heap[parent]);
        current = parent;
        parent = (current - 1) / 2;
    }
}
int MaxHeap::extractMax() {
    int heapSize = (int)heap.size();
    if (heapSize == 0) return -1;
    
    int max = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    maxHeapify(0, heap, heapSize);
    return max;
}

int main() {
    vector<int> arr = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
    MaxHeap maxHeap(arr);
    for (int i : maxHeap.heap) printf("%d ", i);
    
    printf("\nInsert: 22\n");
    maxHeap.insert(22);
    for (int i : maxHeap.heap) printf("%d ", i);
    
    printf("\nExtract Max: %d\n", maxHeap.extractMax());
    for (int i : maxHeap.heap) printf("%d ", i);
    
    printf("\nExtract Max: %d\n", maxHeap.extractMax());
    for (int i : maxHeap.heap) printf("%d ", i);
    
    printf("\nInsert: 18\n");
    maxHeap.insert(18);
    for (int i : maxHeap.heap) printf("%d ", i);
    
    printf("\nExtract Max: %d\n", maxHeap.extractMax());
    for (int i : maxHeap.heap) printf("%d ", i);
    
    printf("\nExtract Max: %d\n", maxHeap.extractMax());
    for (int i : maxHeap.heap) printf("%d ", i);    printf("\nFIN\n");
    return 0;
}
