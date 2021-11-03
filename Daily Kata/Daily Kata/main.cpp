#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

class MaxHeap {
public:
    MaxHeap(vector<int> &array);
    vector<int> heap;
    vector<int> buildMaxHeap(vector<int> &array);
    void maxHeapify(int i, vector<int> &array);
    void insert(int val);
    int extractMax();
};

MaxHeap::MaxHeap(vector<int> &array) { heap = buildMaxHeap(array); }
vector<int> MaxHeap::buildMaxHeap(vector<int> &array) {
    int parentIdx = (int)array.size() / 2 - 1;
    for (int i = parentIdx; i >= 0; --i) maxHeapify(i, array);
    return array;
}
void MaxHeap::maxHeapify(int i, vector<int> &array) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    
    int largest;
    if (l < array.size() && array[l] > array[i]) largest = l;
    else largest = i;
    
    if (r < array.size() && array[r] > array[largest]) largest = r;
    
    if (largest != i) {
        swap(array[i], array[largest]);
        maxHeapify(largest, array);
    }
}
void MaxHeap::insert(int val) {
    heap.push_back(val);
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
    if (heap.size() == 0) return -1;
    
    int max = heap[0];
    heap[0] = heap[heap.size() - 1];
    heap.pop_back();
    maxHeapify(0, heap);
    return max;
}

int main() {
    vector<int> arr = { 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
    MaxHeap maxHeap(arr);
    for (int i : maxHeap.heap) printf("%d ", i);
    
    printf("\nInsert: 22\n");
    maxHeap.insert(22);
    for (int i : maxHeap.heap) printf("%d ", i);
    return 0;
}
