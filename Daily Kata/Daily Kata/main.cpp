#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MaxHeap {
public:
    MaxHeap(vector<int>& vec);
    vector<int> heap;
    vector<int> buildMaxHeap(vector<int>& vec);
    void maxHeapify(int i, vector<int>& vec, int heapSize);
    void insert(int e);
    int extractMax();
};

MaxHeap::MaxHeap(vector<int>& vec) { heap = buildMaxHeap(vec); }
vector<int> MaxHeap::buildMaxHeap(vector<int>& vec) {
    int heapSize = (int)vec.size();
    int parent = heapSize / 2 - 1;
    for (int i = parent; i >= 0; --i) maxHeapify(i, vec, heapSize);
    return vec;
}
void MaxHeap::maxHeapify(int i, vector<int>& vec, int heapSize) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    int largest = i;
    if (l < heapSize && vec[l] > vec[largest]) largest = l;
    if (r < heapSize && vec[r] > vec[largest]) largest = r;
    
    if (largest != i) {
        swap(vec[largest], vec[i]);
        maxHeapify(largest, vec, heapSize);
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
    std::cout << "FIN\n";
    return 0;
}
