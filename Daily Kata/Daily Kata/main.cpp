#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

class DStack {
    enum { DEF_CAP = 2 };
public:
    DStack(int cap = DEF_CAP);
    ~DStack();
    int size() const;
    bool empty() const;
    int top() const;
    void push(int e);
    int pop();
private:
    int* S;
    int t;
    int capacity;
};

DStack::DStack(int cap) : S(new int[cap]), capacity(cap), t(-1) {};
DStack::~DStack() { while (!empty()) pop(); }
int DStack::size() const { return t + 1; }
bool DStack::empty() const { return size() == 0; }
int DStack::top() const { return empty() ? -1 : S[t];}
void DStack::push(int e) {
    if (size() == capacity) {
        int* B = new int[capacity * 2];
        for (int i = 0; i < capacity; ++i) B[i] = S[i];
        S = B;
    }
    S[++t] = e;
}
int DStack::pop() {
    if (!empty()) {
        return S[t--];
    }
    return -1;
}

int main() {
    DStack* ds = new DStack();
    ds->push(9);
    ds->push(8);
    ds->push(7);
    ds->push(6);
    ds->push(5);
    ds->push(4);
    ds->push(3);
    ds->push(2);
    ds->push(1);
    
    while (!ds->empty()) {
        printf("%d ", ds->pop());
    }
    printf("\nFIN\n");
    return 0;
}
