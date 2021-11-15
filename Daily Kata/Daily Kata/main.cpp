#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

class MaxHeap {
public:
    MaxHeap(vector<int> &arr);
    vector<int> heap;
    vector<int> buildMaxHeap(vector<int> &arr);
    void maxHeapify(int i, int heapSize, vector<int> &arr);
    void insert(int val);
    int extractMax();
};

MaxHeap::MaxHeap(vector<int> &arr) { heap = buildMaxHeap(arr); }
vector<int> MaxHeap::buildMaxHeap(vector<int> &arr) {
    int heapSize = (int)arr.size();
    int parentIdx = heapSize / 2 - 1;
    for (int i = parentIdx; i >= 0; --i) maxHeapify(i, heapSize, arr);
    return arr;
}
void MaxHeap::maxHeapify(int i, int heapSize, vector<int> &arr) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    int largest;
    if (l < heapSize && arr[l] > arr[i]) largest = l;
    else largest = i;
    
    if (r < heapSize && arr[r] > arr[largest]) largest = r;
    
    if (largest != i) {
        swap(arr[i], arr[largest]);
        maxHeapify(largest, heapSize, arr);
    }
}
void MaxHeap::insert(int val) {
    heap.push_back(val);
    int heapSize = (int)heap.size();
    int current = heapSize - 1;
    int parent = heapSize / 2 - 1;
    
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
    maxHeapify(0, heapSize, heap);
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
    
    printf("\nFIN\n");
    return 0;
}
