#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

struct Node {
    string val;
    Node *next;
};

class CLL {
public:
    CLL();
    ~CLL();
    bool empty() const;
    Node *front() const;
    void advance();
    void add(string s);
    void remove();
private:
    Node *cursor;
};

CLL::CLL() : cursor(NULL) {}
CLL::~CLL() { while (!empty()) remove(); }
bool CLL::empty() const { return cursor == NULL; }
Node *CLL::front() const { return empty() ? nullptr : cursor->next; }
void CLL::advance() { if (!empty()) cursor = cursor->next; }
void CLL::add(string s) {
    Node *u = new Node();
    u->val = s;
    if (empty()) {
        u->next = u;
        cursor = u;
    } else {
        u->next = cursor->next;
        cursor->next = u;
    }
}
void CLL::remove() {
    if (!empty()) {
        Node *old = cursor->next;
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
    Node *front() const;
    void push(string s);
    void pop();
private:
    CLL CL;
    int n;
};

Queue::Queue() : CL(), n(0) {}
Queue::~Queue() { while (!empty()) pop(); }
int Queue::size() const { return n; }
bool Queue::empty() const { return n == 0; }
Node *Queue::front() const { return empty() ? nullptr : CL.front(); }
void Queue::push(string s) {
    CL.add(s);
    CL.advance();
    n++;
}
void Queue::pop() {
    if (!empty()) {
        CL.remove();
        n--;
    }
}

int main() {
    Queue *q = new Queue();
    q->push("Bermuda,");
    q->push("Bahama,");
    q->push("come on");
    q->push("pretty mama");
    q->push("\nKey Largo,");
    q->push("Montego,");
    q->push("baby why don't we go,");
    q->push("Jamaica");
    
    while (!q->empty()) {
        cout << q->front()->val << " ";
        q->pop();
    }
    printf("\nFIN\n");
    return 0;
}
