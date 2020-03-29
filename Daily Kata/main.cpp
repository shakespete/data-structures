#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

class DynamicArray {
	enum { DEF_CAP = 7 };
public:
	DynamicArray(int cap = DEF_CAP);
	~DynamicArray();
	int size() const;
	bool empty() const;
	int find(const int e) const;
	void push(const int e);
	int pop();
private:
	int* A;
	int capacity;
	int n;
};

DynamicArray::DynamicArray(int cap) : A(new int[cap]), n(0), capacity(cap) { }
DynamicArray::~DynamicArray() { while (!empty()) pop(); }
int DynamicArray::size() const { return n; }
bool DynamicArray::empty() const { return n == 0; }
int DynamicArray::find(const int e) const {
	if (empty()) return -1;
	for (int i = 0; i < n; ++i) {
		if (A[i] == e) return i;
	}
		
	return -1;
}
void DynamicArray::push(const int e) {
	if (size() == capacity) {
		int* B = new int[capacity];
		for (int i = 0; i < capacity; ++i) B[i] = A[i];
		A = B;
		capacity *= 2;
	}
	A[n++] = e;
}
int DynamicArray::pop() { return A[--n]; }

int main() {
	DynamicArray* da = new DynamicArray();
	da->push(0);
	da->push(1);
	da->push(2);
	da->push(3);
	da->push(4);
	da->push(5);
	da->push(6);
	da->push(7);
	da->push(8);
	da->push(9);

	printf("Size: %d\n", da->size());
	printf("Find 9: %d\n", da->find(9));
	printf("Top: %d\n", da->pop());
	printf("Find 9: %d\n", da->find(9));
	printf("Find 8: %d\n", da->find(8));
	return 0;
}