#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

class Stack {
    enum { DEF_CAP = 3 };
public:
    Stack(int cap = DEF_CAP);
    ~Stack();
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

Stack::Stack(int cap) : S(new int[cap]), t(-1), capacity(cap) { };
Stack::~Stack() { while (!empty()) pop(); }
int Stack::size() const { return t + 1; }
bool Stack::empty() const { return t == -1; }
int Stack::top() const { return empty() ? -1 : S[t]; }
void Stack::push(int e) {
    if (size() == capacity) {
        int* T = new int[capacity * 2];
        for (int i = 0; i < capacity; ++i) T[i] = S[i];
        S = T;
    }
    S[++t] = e;
}
int Stack::pop() {
    if (!empty()) return S[t--];
    return -1;
}

int main() {
    Stack* st = new Stack();
    st->push(0);
    st->push(1);
    st->push(2);
    st->push(3);
    st->push(4);
    st->push(5);
    st->push(6);
    st->push(7);
    st->push(8);
    st->push(9);
    st->push(10);
    st->push(11);
    
    while(!st->empty()) {
        printf("%d ", st->pop());
    }
    
    printf("\nFIN\n");
    return 0;
}
