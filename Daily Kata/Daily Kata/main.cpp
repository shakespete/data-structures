#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    string val;
};

class Stack {
    enum { DEF_CAP = 2 };
public:
    Stack(int cap = DEF_CAP);
    ~Stack();
    int size() const;
    bool empty() const;
    Node* top() const;
    void push(string s);
    void pop();
private:
    Node** S;
    int t;
    int capacity;
};

Stack::Stack(int cap) : S(new Node*[cap]), t(-1), capacity(cap) { }
Stack::~Stack() { while (!empty()) pop(); }
int Stack::size() const { return t + 1; }
bool Stack::empty() const { return t == -1; }
Node* Stack::top() const { return empty() ? nullptr : S[t]; }
void Stack::push(string s) {
    if (size() == capacity) {
        Node** T = new Node*[capacity * 2];
        for (int i = 0; i < capacity; ++i) T[i] = S[i];
        S = T;
        capacity *= 2;
    }
    Node* node = new Node();
    node->val = s;
    S[++t] = node;
}
void Stack::pop() {
    if (!empty()) {
        delete S[t];
        --t;
    }
}

int main() {
    Stack* st = new Stack();
    st->push("wit");
    st->push("foolish");
    st->push("than a");
    st->push("fool");
    st->push("a witty");
    st->push("Better");
    
    while (!st->empty()) {
        cout << st->top()->val << " ";
        st->pop();
    }
    
    std::cout << "\nFIN\n";
    return 0;
}
