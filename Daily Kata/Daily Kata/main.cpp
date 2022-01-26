#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    string val;
    Node* next;
};

class CLL {
public:
    CLL();
    ~CLL();
    bool empty() const;
    Node* front() const;
    void advance();
    void add(string s);
    void remove();
private:
    Node* cursor;
};

CLL::CLL() : cursor(nullptr) { }
CLL::~CLL() { while (!empty()) remove(); }
bool CLL::empty() const { return cursor == nullptr; }
Node* CLL::front() const { return empty() ? nullptr : cursor->next; }
void CLL::advance() { if (!empty()) cursor = cursor->next; }
void CLL::add(string s) {
    Node* v = new Node();
    v->val = s;
    if (empty()) {
        v->next = v;
        cursor = v;
    } else {
        v->next = cursor->next;
        cursor->next = v;
    }
}
void CLL::remove() {
    if (!empty()) {
        Node* old = cursor->next;
        if (old == cursor) cursor = nullptr;
        else cursor->next = old->next;
        delete old;
    }
}

class Queue {
public:
    Queue();
    ~Queue();
    int size() const;
    bool empty() const;
    Node* front() const;
    void enq(string s);
    void deq();
private:
    CLL CL;
    int n;
};

Queue::Queue() : CL(), n(0) { }
Queue::~Queue() { while (!empty()) deq(); }
int Queue::size() const { return n; }
bool Queue::empty() const { return n == 0; }
Node* Queue::front() const { return empty() ? nullptr : CL.front(); }
void Queue::enq(string s) {
    CL.add(s);
    CL.advance();
    ++n;
}
void Queue::deq() {
    if (!empty()) {
        CL.remove();
        --n;
    }
}

int main() {
    Queue* q = new Queue();
    q->enq("We know");
    q->enq("what we are,");
    q->enq("but not");
    q->enq("what we");
    q->enq("may be.");
    
    while (!q->empty()) {
        cout << q->front()->val << " ";
        q->deq();
    }
    
    std::cout << "\nFIN\n";
    return 0;
}
