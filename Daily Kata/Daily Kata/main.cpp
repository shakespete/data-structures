#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    string val;
    Node* prev;
    Node* next;
    Node(string s) {
        val = s;
        prev = nullptr;
        next = nullptr;
    }
};

class DLL {
public:
    DLL();
    ~DLL();
    bool empty() const;
    Node* front() const;
    Node* back() const;
    void add(Node* v, string str);
    void addFront(string str);
    void addBack(string str);
    void remove(Node* v);
    void removeFront();
    void removeBack();
private:
    Node* head;
    Node* tail;
};

DLL::DLL() {
    head = new Node("");
    tail = new Node("");
    head->next = tail;
    tail->prev = head;
}
DLL::~DLL() { while (!empty()) removeFront(); }
bool DLL::empty() const { return head->next == tail; }
Node* DLL::front() const { return empty() ? nullptr : head->next; }
Node* DLL::back() const { return empty() ? nullptr : tail->prev; }
void DLL::add(Node* v, string str) {
    Node* u = new Node(str);
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}
void DLL::addFront(string str) { add(head->next, str); }
void DLL::addBack(string str) { add(tail, str); }
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
    void enq(string str);
    void deq();
private:
    DLL list;
    int n;
};

Queue::Queue() : list(), n(0) { }
Queue::~Queue() { while (!empty()) deq(); }
int Queue::size() const { return n; }
bool Queue::empty() const { return n == 0; }
Node* Queue::front() const { return empty() ? nullptr : list.front(); }
void Queue::enq(string str) {
    list.addBack(str);
    n++;
}
void Queue::deq() {
    if (!empty()) list.removeFront();
    n--;
}

int main() {
    Queue* q = new Queue();
    
    q->enq("A mile, ");
    q->enq("a must, ");
    q->enq("a thrust, ");
    q->enq("a bump,\n");
    q->enq("It's a girl, ");
    q->enq("it's a rhyme, ");
    q->enq("it's a cold, ");
    q->enq("it's the mumps\n");
    
    while (!q->empty()) {
        cout << q->front()->val;
        q->deq();
    }
    cout << "FIN\n";
    return 0;
}
