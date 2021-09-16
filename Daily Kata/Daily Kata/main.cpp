#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

class Stack {
    enum { DEF_CAP = 10 };
public:
    Stack(int cap = DEF_CAP);
    ~Stack();
    bool empty();
    void push(int e);
    int pop();
private:
    int* S;
    int top;
    int capacity;
};

Stack::Stack(int cap) : S(new int[cap]), top(0), capacity(cap) { };
Stack::~Stack() { while (!empty()) pop(); }
bool Stack::empty() { return top == 0; }
void Stack::push(int e) {
    if (top != capacity) {
        S[++top] = e;
    }
}
int Stack::pop() {
    if (!empty()) {
        return S[top--];
    }
    return -1;
}

int main() {
    Stack* st = new Stack();
    st->push(1);
    st->push(2);
    st->push(3);
    st->push(4);
    st->push(5);
    st->push(6);
    st->push(7);
    st->push(8);
    while (!st->empty()) {
        printf("%d\n", st->pop());
    }
    printf("FIN\n");
    return 0;
}
