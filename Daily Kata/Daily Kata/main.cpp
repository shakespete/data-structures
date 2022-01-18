#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>

using namespace std;

class DStack {
    enum { DEF_CAP = 3 };
public:
    DStack(int cap = DEF_CAP);
    ~DStack();
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

DStack::DStack(int cap) : S(new int[cap]), t(-1), capacity(cap) {}
DStack::~DStack() { while (!empty()) pop(); }
int DStack::size() const { return t + 1; }
bool DStack::empty() const { return size() == 0; }
int DStack::top() const { return empty() ? -1 : S[t]; }
void DStack::push(int e) {
    if (size() == capacity) {
        int* T = new int[capacity * 2];
        for (int i = 0; i < capacity; ++i) T[i] = S[i];
        S = T;
        capacity = capacity * 2;
    }
    S[++t] = e;
}
void DStack::pop() { if (!empty()) --t; }

int main() {
    DStack* stack = new DStack();
    stack->push(10);
    stack->push(9);
    stack->push(8);
    stack->push(7);
    stack->push(6);
    stack->push(5);
    stack->push(4);
    stack->push(3);
    stack->push(2);
    stack->push(1);
    
    while (!stack->empty()) {
        cout << stack->top() << " ";
        stack->pop();
    }
    
    std::cout << "\nFIN\n";
    return 0;
}
