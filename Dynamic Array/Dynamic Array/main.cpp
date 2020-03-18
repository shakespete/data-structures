//
//  main.cpp
//  Dynamic Array
//
//  Created by Jose Mari Prim Syjuco on 2/27/20.
//  Copyright © 2020 Jose Mari Prim Syjuco. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

class Stack {
    enum { DEF_CAP = 100 };
public:
    Stack(int e = DEF_CAP);
    int size();
    bool empty();
    bool find(int e);
    void push(int e);
    int pop();
private:
    int* A;
    int capacity;
    int n;
};
Stack::Stack(int e) : capacity(e), A(new int[e]), n(0) { }
int Stack::size() { return n; }
bool Stack::empty() { return n == 0; }
bool Stack::find(int e) {
    if (empty()) return false;
    for (int i = 0; i < n; ++i)
        if (A[i] == e) return true;

    return false;
}
void Stack::push(int e) {
    if (size() == capacity) {
        int* B = new int[capacity * 2];
        for (int i = 0; i < capacity; ++i) B[i] = A[i];
        A = B;
        capacity *= 2;
    }
    A[n++] = e;
}
int Stack::pop() { return A[--n]; }


int main() {
    Stack* st = new Stack(5);
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
    
    printf("Size: %d\n", st->size());
    printf("Find 9: %d\n", st->find(9));
    printf("Top: %d\n", st->pop());
    printf("Find 9: %d\n", st->find(9));
    printf("Find 8: %d\n", st->find(8));

    return 0;
}
