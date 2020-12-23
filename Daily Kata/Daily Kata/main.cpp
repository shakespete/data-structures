#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Node {
    int val;
};

class Stack {
    enum { DEF_CAP = 100 };
public:
    Stack(int cap = DEF_CAP);
    ~Stack();
    int size() const;
    bool empty() const;
    Node* top() const;
    void push(const int& e);
    void pop();
private:
    Node** S;
    int t;
    int capacity;
};

Stack::Stack(int cap) : S(new Node*[cap]), t(-1), capacity(cap) { }
Stack::~Stack() { while (!empty()) pop(); }
int Stack::size() const { return t + 1; }
bool Stack::empty() const { return size() == 0; }
Node* Stack::top() const { return empty() ? NULL : S[t]; }
void Stack::push(const int& e) {
    if (size() != capacity) {
        Node* v = new Node;
        v->val = e;
        ++t;
        S[t] = v;
    }
}
void Stack::pop() {
    if (!empty()) {
        delete S[t];
        --t;
    }
}

int main() {
    Stack* st = new Stack();
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
        printf("%d ", st->top()->val);
        st->pop();
    }
    printf("\nFIN\n");
    return 0;
}
