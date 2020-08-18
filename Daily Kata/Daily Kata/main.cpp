#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Node {
    const char* val;
};

class Stack {
    enum { DEF_CAP = 5 };
public:
    Stack(int cap = DEF_CAP);
    ~Stack();
    int size() const;
    bool empty() const;
    Node* top() const;
    void push(const char* e);
    void pop();
private:
    Node** S;
    int t;
    int capacity;
};

Stack::Stack(int cap) : S(new Node*[cap]), t(-1), capacity(cap) { }
Stack::~Stack() { while (!empty()) pop(); }
int Stack::size() const { return t + 1;}
bool Stack::empty() const { return size() == 0; }
Node* Stack::top() const { return empty() ? NULL : S[t]; }
void Stack::push(const char* e) {
    Node* v = new Node;
    v->val = e;
    if (size() == capacity) {
        Node** B = new Node*[capacity * 2];
        for (int i = 0; i < capacity; ++i) B[i] = S[i];
        S = B;
        capacity *= 2;
    }
    ++t;
    S[t] = v;
}
void Stack::pop() {
    if (!empty()) delete S[t];
    --t;
}

int main() {
    Stack* st = new Stack();
    st->push("silence");
    st->push("in");
    st->push("be");
    st->push("may");
    st->push("there");
    st->push("peace");
    st->push("what");
    st->push("remember");
    st->push("and");
    st->push("haste");
    st->push("and");
    st->push("noise");
    st->push("the");
    st->push("amid");
    st->push("placidly");
    st->push("Go");
    
    while (!st->empty()) {
        printf("%s ", st->top()->val);
        st->pop();
    }
    printf("\n");
    return 0;
}
