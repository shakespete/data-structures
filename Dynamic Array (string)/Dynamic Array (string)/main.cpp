//
//  main.cpp
//  Dynamic Array (string)
//
//  Created by Jose Mari Syjuco on 13/1/21.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

bool is_equal(const char* a, const char* b) {
    while (*a == *b) {
        if (*a == '\0') return true;
        ++a;
        ++b;
    }
    return false;
}

struct Node {
    const char* val;
};

class DArray {
    enum {DEF_CAP = 2};
public:
    DArray(int e = DEF_CAP);
    int size() const;
    bool empty() const;
    int find(const char* e);
    void push(const char* e);
    const char* pop();
private:
    Node** A;
    int capacity;
    int n;
};

DArray::DArray(int e) : capacity(e), A(new Node*[e]), n(0) { }
int DArray::size() const { return n; }
bool DArray::empty() const {return n == 0;};
int DArray::find(const char* e) {
    if (empty()) return -1;
    for (int i = 0; i < n; ++i) {
        if (is_equal(e, A[i]->val)) return i;
    }
    return false;
}
void DArray::push(const char* e) {
    if (size() == capacity) {
        Node** B = new Node*[capacity * 2];
        for (int i = 0; i < capacity; ++i) B[i] = A[i];
        A = B;
        capacity *= 2;
    }
    Node* v = new Node;
    v->val = e;
    A[n++] = v;
}
const char* DArray::pop() {
    Node* v = A[--n];
    return v->val;
}

int main() {
    DArray* arr = new DArray();
    arr->push("friend");
    arr->push("old");
    arr->push("my");
    arr->push("darkness");
    arr->push("Hello");
    
    printf("%d\n", arr->find("old"));
    printf("%d\n", arr->find("darkness"));
    
    while (!arr->empty()) {
        printf("%s ", arr->pop());
    }
    
    printf("\nFIN\n");
    
    return 0;
}
