#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

class DynamicStack {
    enum { DEF_CAP = 5 };
public:
    DynamicStack(int cap = DEF_CAP);
    ~DynamicStack();
    int size() const;
    bool empty() const;
    int front() const;
    void push(const int e);
    int pop();
private:
    int* S;
    int t;
    int capacity;
};

DynamicStack::DynamicStack(int cap) : S(new int[cap]), t(-1), capacity(cap) { }
DynamicStack::~DynamicStack() { while(!empty()) pop(); }
int DynamicStack::size() const { return t + 1; }
bool DynamicStack::empty() const { return size() == 0; }
int DynamicStack::front() const { return empty() ? -1 : S[t]; }
void DynamicStack::push(const int e) {
    if (size() == capacity) {
        int* B = new int[capacity * 2];
        for (int i = 0; i < capacity; ++i) B[i] = S[i];
        S = B;
        capacity *= 2;
    }
    S[++t] = e;
}
int DynamicStack::pop() { return S[t--]; }

int main() {
    DynamicStack* ds = new DynamicStack();
    ds->push(1);
    ds->push(2);
    ds->push(3);
    ds->push(4);
    ds->push(5);
    ds->push(6);
    ds->push(7);
    ds->push(8);
    ds->push(9);
    ds->push(10);
    ds->push(11);
    ds->push(12);
    ds->push(13);
    ds->push(14);
    ds->push(15);
    
    while (!ds->empty()) { printf("%d ", ds->pop()); }
    printf("\nFIN\n");
    return 0;
}
