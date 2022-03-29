#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Stack {
    enum { DEF_CAP = 3 };
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

Stack::Stack(int cap) : S(new string[cap]), t(-1), capacity(cap) { }
Stack::~Stack() { while (!empty()) pop(); }
int Stack::size() const { return t + 1; }
bool Stack::empty() const { return size() == 0; }
string Stack::top() const { return empty() ? "Empty" : S[t]; }
void Stack::push(string s) {
    if (size() == capacity) {
        string* T = new string[capacity * 2];
        for (int i = 0; i < capacity; ++i) T[i] = S[i];
        S = T;
        capacity *= 2;
    }
    S[++t] = s;
}
void Stack::pop() { if (!empty()) --t; }

int main() {
    //
    Stack* st = new Stack();
    st->push("without deserving.");
    st->push("and lost");
    st->push("without merit,");
    st->push("oft got");
    st->push("false imposition;");
    st->push("and most");
    st->push("is an idle");
    st->push("Reputation");
    
    while (!st->empty()) {
        cout << st->top() << " ";
        st->pop();
    }
    
    cout << "\nFIN\n";
    return 0;
}
