//
//  main.cpp
//  Daily Kata
//
//  Created by Jose Mari Prim Syjuco on 3/22/20.
//  Copyright © 2020 Jose Mari Prim Syjuco. All rights reserved.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

struct Node {
    char* val;
};

class Stack {
    enum {DEF_CAP = 37};
public:
    Stack(int cap = DEF_CAP);
    ~Stack();
    int size() const;
    bool empty() const;
    Node* top() const;
    void push(char* e);
    void pop();
private:
    Node** S;
    int t;
    int capacity;
};
Stack::Stack(int cap) : S(new Node*[cap]), t(-1), capacity(cap) { };
Stack::~Stack() { while (!empty()) pop(); }
int Stack::size() const { return t+1;}
bool Stack::empty() const {return size() == 0;}
Node* Stack::top() const {return empty() ? NULL : S[t]; }
void Stack::push(char* e) {
    if (size()!= capacity) {
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
    st->push("friend");
    st->push("old");
    st->push("my");
    st->push("darkness");
    st->push("hello");

    while (!st->empty()) {
        printf("%s ", st->top()->val);
        st->pop();
    }
    return 0;
}
