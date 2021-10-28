#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int parent(int i) { return i / 2; }
int left(int i) { return 2 * i; }
int right(int i) { return 2 * i + 1; }

// O(log(n)) || O(h) where h = height of node
void maxHeapify(int *A, int i, int heapSize) {
    int l = left(i);
    int r = right(i);

    int largest;
    if (l <= heapSize && A[l] > A[i]) largest = l;
    else largest = i;

    if (r <= heapSize && A[r] > A[largest]) largest = r;

    if (largest != i) {
        swap(&A[i], &A[largest]);
        maxHeapify(A, largest, heapSize);
    }
}

// O(n)
void buildMaxHeap(int *A, int N) {
    int heapSize = N;
    for (int i = N / 2; i >= 1; --i) {
        maxHeapify(A, i, heapSize);
    }
}

// O(nlog(n))
void heapSort(int *A, int N) {
    buildMaxHeap(A, N);
    int heapSize = N;
    for (int i = N; i >= 2; --i) {
        swap(&A[1], &A[i]);
        heapSize--;
        maxHeapify(A, 1, heapSize);
    }
}

int main() {
    int num[] = { 0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7 };
    int N = sizeof(num) / sizeof(num[0]);
    printf("%d\n", N);

    for (int i = 1; i < N; ++i) printf("%d ", num[i]);
    printf("\n");

    buildMaxHeap(num, N);
    for (int i = 1; i < N; ++i) printf("%d ", num[i]);
    printf("\n");
    
    heapSort(num, N);
    for (int i = 2; i <= N; ++i) printf("%d ", num[i]);
    printf("\n");
    return 0;
}
