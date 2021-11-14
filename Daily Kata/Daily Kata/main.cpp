#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>

using namespace std;

class DynamicStack {
    enum { DEF_CAP = 3 };
public:
    DynamicStack(int cap = DEF_CAP);
    ~DynamicStack();
    int size() const;
    bool empty() const;
    int top() const;
    void push(int e);
    void pop();
private:
    int *S;
    int t;
    int capacity;
};

DynamicStack::DynamicStack(int cap) : S(new int[cap]), t(-1), capacity(cap) { };
DynamicStack::~DynamicStack() { while (!empty()) pop(); }
int DynamicStack::size() const { return t + 1; }
bool DynamicStack::empty() const { return size() == 0; }
int DynamicStack::top() const { return empty() ? -1 : S[t]; }
void DynamicStack::push(int e) {
    if (size() == capacity) {
        int *T = new int[capacity * 2];
        for (int i = 0; i < capacity; ++i) T[i] = S[i];
        S = T;
        capacity *= 2;
    }
    S[++t] = e;
}
void DynamicStack::pop() { if (!empty()) --t; }

int main() {
    DynamicStack *st = new DynamicStack();
    st->push(10);
    st->push(9);
    st->push(8);
    st->push(7);
    st->push(6);
    st->push(5);
    st->push(4);
    st->push(3);
    st->push(2);
    st->push(1);
    
    while (!st->empty()) {
        printf("%d ", st->top());
        st->pop();
    }
    printf("\nFIN\n");
    return 0;
}
