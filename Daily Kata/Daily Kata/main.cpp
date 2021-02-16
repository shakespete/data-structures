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
    void push(const int e);
    int pop();
private:
    int* S;
    int t;
    int capacity;
};

DStack::DStack(int cap) : S(new int[cap]), t(-1), capacity(cap) { }
DStack::~DStack() { while (!empty()) pop(); }
int DStack::size() const { return t + 1; }
bool DStack::empty() const { return size() == 0; }
int DStack::top() const { return empty() ? -1 : S[t]; }
void DStack::push(const int e) {
    if (size() == capacity) {
        int* B = new int[capacity * 2];
        for (int i = 0; i < capacity; ++i) B[i] = S[i];
        S = B;
        capacity *= 2;
    }
    S[++t] = e;
}
int DStack::pop() {
    if (!empty()) { return S[t--]; }
    return -1;
}

int main () {
    DStack* st = new DStack();
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
        printf("T: %d -> ", st->top());
        printf("%d\n", st->pop());
    }
    printf("\nFIN\n");
    
    return 0;
}
