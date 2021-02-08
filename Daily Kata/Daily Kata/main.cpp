#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Node {
    const char* val;
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
    void add(const char* e, Node* v);
    void addFront(const char* e);
    void addBack(const char* e);
    void remove(Node* v);
    void removeFront();
    void removeBack();
private:
    Node* head;
    Node* tail;
};

DLL::DLL() {
    head = new Node;
    tail = new Node;
    head->val = NULL;
    tail->val = NULL;
    head->next = tail;
    tail->prev = head;
}
DLL::~DLL() { while (!empty()) removeBack(); }
bool DLL::empty() const { return head->next == tail; }
Node* DLL::front() const { return empty() ? NULL : head->next;}
Node* DLL::back() const { return empty() ? NULL : tail->prev; }
void DLL::add(const char* e, Node* v) {
    Node* u = new Node;
    u->val = e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}
void DLL::addFront(const char* e) { add(e, head->next); }
void DLL::addBack(const char* e) { add(e, tail); }
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


int main() {
    DLL* DList = new DLL();
    DList->addBack("A");
    DList->addBack("stick,");
    DList->addBack("a");
    DList->addBack("stone,");
    DList->addBack("it's");
    DList->addBack("the");
    DList->addBack("end");
    DList->addBack("of");
    DList->addBack("the");
    DList->addBack("road");
    
    while (!DList->empty()) {
        printf("%s ", DList->front()->val);
        DList->removeFront();
    }
    printf("\nFIN\n");
    return 0;
}
