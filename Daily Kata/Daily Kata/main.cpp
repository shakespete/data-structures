#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stack {
    enum { DEF_CAP = 2 };
public:
    Stack(int cap = DEF_CAP);
    ~Stack();
    int size() const;
    bool empty() const;
    string top() const;
    void push(string s);
    void pop();
private:
    string* S;
    int t;
    int capacity;
};

Stack::Stack(int cap) : S(new string[cap]), capacity(cap), t(-1) { }
Stack::~Stack() { while (!empty()) pop(); }
int Stack::size() const { return t + 1; }
bool Stack::empty() const { return size() == 0; }
string Stack::top() const { return empty() ? "--" : S[t]; }
void Stack::push(string s) {
    if (capacity == size()) {
        string* T = new string[capacity * 2];
        for (int i = 0; i < capacity; ++i) T[i] = S[i];
        S = T;
        capacity *= 2;
    }
    S[++t] = s;
}
void Stack::pop() { if (!empty()) --t; }

int main() {
    Stack* st = new Stack();
    st->push("bedfellows");
    st->push("with strange");
    st->push("a man");
    st->push("acquaints");
    st->push("Misery");
    
    while (!st->empty()) {
        cout << st->top() << " ";
        st->pop();
    }
    
    std::cout << "\nFIN\n";
    return 0;
}
