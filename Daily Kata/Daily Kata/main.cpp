#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

class DStack {
    enum { DEF_CAP = 2 };
public:
    DStack(int cap = DEF_CAP);
    ~DStack();
    int size() const;
    bool empty() const;
    int find(int e) const;
    void push(int e);
    int pop();
private:
    int* A;
    int capacity;
    int n;
};

DStack::DStack(int cap) : A(new int[cap]), capacity(cap), n(-1) { }
DStack::~DStack() { while (!empty()) pop(); }
int DStack::size() const { return n + 1; }
bool DStack::empty() const { return size() == 0; }
int DStack::find(int e) const {
    if (!empty()) {
        for (int i = 0; i < capacity; ++i) {
            if (A[i] == e) return i;
        }
    }
    return -1;
}
void DStack::push(int e) {
    if (size() == capacity) {
        int* B = new int[capacity * 2];
        for (int i = 0; i < capacity; ++i) B[i] = A[i];
        A = B;
        capacity *= 2;
    }
    A[++n] = e;
}
int DStack::pop() {
    if (!empty()) {
        return A[n--];
    }
    return -1;
}

int main() {
    DStack* ds = new DStack();
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
    
    printf("%d\n", ds->pop());
    printf("%d\n", ds->pop());
    printf("%d\n", ds->pop());
    printf("%d\n", ds->pop());
    printf("%d\n", ds->pop());
    
    printf("%d\n", ds->find(5));
    printf("%d\n", ds->find(4));
    printf("%d\n", ds->find(3));
    
    printf("%d\n", ds->find(6));
    return 0;
}
