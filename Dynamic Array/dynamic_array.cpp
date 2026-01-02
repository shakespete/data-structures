#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdexcept>

class Stack {
    enum { DEF_CAP = 100 };
public:
    Stack(int cap = DEF_CAP);
    ~Stack();
    int size() const;
    bool empty() const;
    bool find(int e) const;
    int top() const;
    void push(int e);
    int pop();
private:
    int* A;
    int capacity;
    int n;
};
Stack::Stack(int cap): capacity(cap), A(new int[cap]), n(0) { }
Stack::~Stack() { delete[] A; }
int Stack::size() const { return n; }
bool Stack::empty() const { return n == 0; }
bool Stack::find(int e) const {
    for (int i = 0; i < n; ++i) {
        if (A[i] == e) return true;
    }
    return false;
}
int Stack::top() const {
    if (empty()) throw std::runtime_error("Stack is empty");
    return A[n - 1];
}
void Stack::push(int e) {
    if (size() == capacity) {
        int* B = new int[capacity * 2];
        for (int i = 0; i < capacity; ++i) B[i] = A[i];
        delete[] A;
        A = B;
        capacity *= 2;
    }
    A[n++] = e;
}
int Stack::pop() {
    if (empty()) throw std::runtime_error("Stack is empty");
    return A[--n];
}

int main() {
    Stack st(5);
    st.push(0);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.push(7);
    st.push(8);
    st.push(9);

    printf("Size: %d\n", st.size());
    printf("Find 9: %d\n", st.find(9));
    printf("Top: %d\n", st.top());
    printf("Pop: %d\n", st.pop());
    printf("Find 9: %d\n", st.find(9));
    printf("Top: %d\n", st.top());

    printf("\nFIN\n");
    return 0;
}
