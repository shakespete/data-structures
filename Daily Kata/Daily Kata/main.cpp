#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
public:
    MaxHeap(vector<int>& arr);
    vector<int> heap;
    vector<int> buildMaxHeap(vector<int>& arr);
    void maxHeapify(int i, vector<int>& arr, int heapSize);
    void insert(int e);
    int extractMax();
};

MaxHeap::MaxHeap(vector<int>& arr) { heap = buildMaxHeap(arr); }
vector<int> MaxHeap::buildMaxHeap(vector<int>& arr) {
    int heapSize = (int)arr.size();
    int parent = heapSize / 2 - 1;
    for (int i = parent; i >= 0; --i) maxHeapify(i, arr, heapSize);
    return arr;
}
void MaxHeap::maxHeapify(int i, vector<int>& arr, int heapSize) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    int largest = i;
    if (l < heapSize && arr[l] > arr[largest]) largest = l;
    if (r < heapSize && arr[r] > arr[largest]) largest = r;
    
    if (largest != i) {
        swap(arr[largest], arr[i]);
        maxHeapify(largest, arr, heapSize);
    }
}
void MaxHeap::insert(int e) {
    heap.push_back(e);
    int heapSize = (int)heap.size();
    int parent = heapSize / 2 - 1;
    int current = heapSize - 1;
    
    while (current > 0 && heap[current] > heap[parent]) {
        swap(heap[current], heap[parent]);
        current = parent;
        parent = (current - 1) / 2;
    }
}
int MaxHeap::extractMax() {
    int heapSize = (int)heap.size();
    if (heapSize == 0) return -1;
    
    int max = heap[0];
    heap[0] = heap[heapSize - 1];
    heap.pop_back();
    maxHeapify(0, heap, heapSize - 1);
    
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
    for (int i : maxHeap.heap) printf("%d ", i);
    std::cout << "\nFIN\n";
    return 0;
}
