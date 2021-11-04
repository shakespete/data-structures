#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

struct Node {
    const char *val;
    Node *prev;
    Node *next;
};

class DLL{
public:
    DLL();
    ~DLL();
    bool empty() const;
    Node *front() const;
    Node *back() const;
    void add(Node *v, const char *e);
    void addFront(const char *e);
    void addBack(const char *e);
    void remove(Node *v);
    void removeFront();
    void removeBack();
private:
    Node *head;
    Node *tail;
};

DLL::DLL() {
    head = new Node();
    tail = new Node();
    head->val = nullptr;
    tail->val = nullptr;
    head->next = tail;
    tail->prev = head;
}
DLL::~DLL() { while (!empty()) removeFront(); }
bool DLL::empty() const { return head->next == tail; }
Node *DLL::front() const { return empty() ? nullptr : head->next; }
Node *DLL::back() const { return empty() ? nullptr : tail->prev; }
void DLL::add(Node *v, const char *e) {
    Node *u = new Node();
    u->val = e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}
void DLL::addFront(const char *e) { add(head->next, e); }
void DLL::addBack(const char *e) { add(tail, e); }
void DLL::remove(Node *v) {
    if (!empty()) {
        Node *u = v->prev;
        Node *w = v->next;
        u->next = w;
        w->prev = u;
        delete v;
    }
}
void DLL::removeFront() { if (!empty()) remove(head->next); }
void DLL::removeBack() { if (!empty()) remove(tail->prev); }

int main() {
    DLL *dlist = new DLL();
    dlist->addBack("no");
    dlist->addBack("strangers");
    dlist->addBack("to");
    dlist->addBack("love");
    dlist->addFront("We're");
    
    while (!dlist->empty()) {
        printf("%s ", dlist->front()->val);
        dlist->removeFront();
    }
    
    printf("\nFIN\n");
    return 0;
}
