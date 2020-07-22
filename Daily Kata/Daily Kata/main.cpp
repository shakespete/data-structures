#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

class Stack {
    enum { DEF_CAP = 5 };
public:
    Stack(int cap = DEF_CAP);
    ~Stack();
    int size() const;
    bool empty() const;
    int top() const;
    void push(const int e);
    void pop();
private:
    int* S;
    int t;
    int capacity;
};

Stack::Stack(int cap) : S(new int[cap]), t(-1), capacity(cap) { }
Stack::~Stack() { while (!empty()) pop(); }
int Stack::size() const { return t + 1;}
bool Stack::empty() const { return size() == 0; }
int Stack::top() const { return empty() ? -1 : S[t]; }
void Stack::push(const int e) {
    if (size() == capacity) {
        int* B = new int[capacity * 2];
        for (int i = 0; i < capacity; ++i) B[i] = S[i];
        S = B;
        delete[] B;
    }
    ++t;
    S[t] = e;
}
void Stack::pop() { if (!empty()) --t; }

int main() {
    Stack* st = new Stack();
    st->push(15);
    st->push(14);
    st->push(13);
    st->push(12);
    st->push(11);
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
    printf("\n");
    
    return 0;
}
