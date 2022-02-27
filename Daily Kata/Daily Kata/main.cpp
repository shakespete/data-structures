#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    string val;
    Node* prev;
    Node* next;
};

class DLL {
public:
    DLL();
    ~DLL();
    bool empty() const;
    Node* front() const;
    Node* back() const;
    void add(Node* v, string s);
    void addFront(string s);
    void addBack(string s);
    void remove(Node* v);
    void removeFront();
    void removeBack();
private:
    Node* head;
    Node* tail;
};

DLL::DLL() {
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
    head->val = "*";
    tail->val = "*";
}
DLL::~DLL() { while (!empty()) removeFront(); }
bool DLL::empty() const { return head->next == tail; }
Node* DLL::front() const { return empty() ? nullptr : head->next; }
Node* DLL::back() const { return empty() ? nullptr : tail->prev; }
void DLL::add(Node* v, string s) {
    Node* u = new Node();
    u->val = s;
    
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}
void DLL::addFront(string s) { add(head->next, s); }
void DLL::addBack(string s) { add(tail, s); }
void DLL::remove(Node* v) {
    if (!empty()) {
        Node* u = v->prev;
        Node* w = v->next;
        u->next = w;
        w->prev = u;
        delete v;
    }
}
void DLL::removeFront() { if (!empty()) remove(head->next); }
void DLL::removeBack() { if (!empty()) remove(tail->prev); }

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
    DLL dlist;
    int n;
};

Queue::Queue() : dlist(), n(0) { }
Queue::~Queue() { while (!empty()) deq(); };
int Queue::size() const { return n; }
bool Queue::empty() const { return n == 0;}
Node* Queue::front() const { return empty() ? nullptr : dlist.front(); }
void Queue::enq(string s) {
    dlist.addBack(s);
    n++;
}
void Queue::deq() {
    if (!empty()) {
        dlist.removeFront();
        n--;
    }
}

int main() {
    Queue* q = new Queue();
    q->enq("Cry “havoc!”");
    q->enq("and let slip");
    q->enq("the dogs");
    q->enq("of war!");

    
    while (!q->empty()) {
        cout << q->front()->val << " ";
        q->deq();
    }
    
    std::cout << "\nFIN\n";
    return 0;
}
