#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int parent(int i) {	return i / 2; }
int left(int i) { return 2 * i; }
int right(int i) { return 2 * i + 1; }

void maxHeapify(int* A, int i, int heapSize) {
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

void buildMaxHeap(int* A, int N) {
	int heapSize = N;
	for (int i = N / 2; i >= 1; --i) {
		maxHeapify(A, i, heapSize);
	}
}

int main() {
	int num[] = { 0,2,8,1,14,7,9,3,4,10,16 };
	int N = sizeof(num) / sizeof(num[0]);
	printf("%d\n", N);

	for (int i = 1; i <= N; ++i)printf("%d ", num[i]);
	printf("\n");

	buildMaxHeap(num, N);
	for (int i = 1; i <= N; ++i)printf("%d ", num[i]);
	printf("\n");
	return 0;
}