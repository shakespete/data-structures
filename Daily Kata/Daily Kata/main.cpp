#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

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
    int* S;
    int t;
    int capacity;
};

DynamicStack::DynamicStack(int cap) : S(new int[cap]), t(-1), capacity(cap) { }
DynamicStack::~DynamicStack() { while (!empty()) pop(); }
int DynamicStack::size() const { return t + 1; }
bool DynamicStack::empty() const { return size() == 0; }
int DynamicStack::top() const { return empty() ? -1 : S[t]; }
void DynamicStack::push(int e) {
    if (size() == capacity) {
        int* T = new int[capacity * 2];
        for (int i = 0; i < capacity; ++i) T[i] = S[i];
        capacity *= 2;
        S = T;
        delete[] T;
    }
    S[++t] = e;
}
void DynamicStack::pop() { if (!empty()) --t; }

int main() {
    DynamicStack* s = new DynamicStack();
    
    s->push(15);
    s->push(14);
    s->push(13);
    s->push(12);
    s->push(11);
    s->push(10);
    s->push(9);
    s->push(8);
    s->push(7);
    s->push(6);
    s->push(5);
    s->push(4);
    s->push(3);
    s->push(2);
    s->push(1);
    
    while (!s->empty()) {
        cout << s->top() << " ";
        s->pop();
    }
    cout << "\nFIN\n";
    return 0;
}
