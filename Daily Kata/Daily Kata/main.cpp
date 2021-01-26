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
    void add(Node* v, const char* e);
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
DLL::~DLL() { while (!empty()) removeFront(); }
bool DLL::empty() const { return head->next == tail; }
Node* DLL::front() const { return empty() ? NULL : head->next; }
Node* DLL::back() const { return empty() ? NULL : tail->prev; }
void DLL::add(Node* v, const char* e) {
    Node* u = new Node;
    u->val = e;
    u->prev = v->prev;
    u->next = v;
    v->prev->next = u;
    v->prev = u;
    
}
void DLL::addFront(const char* e) { add(head->next, e); }
void DLL::addBack(const char* e) { add(tail, e); }
void DLL::remove(Node* v) {
    if (!empty()) {
        Node* u = v->prev;
        Node* w = v->next;
        u->next = w;
        w->prev = u;
        delete v;
    }
}
void DLL::removeFront() { remove(head->next); }
void DLL::removeBack() {remove(tail->prev); }

int main() {
    DLL* dList = new DLL();
    dList->addBack("Do");
    dList->addBack("not");
    dList->addBack("go");
    dList->addBack("gentle");
    dList->addBack("into");
    dList->addBack("that");
    dList->addBack("good");
    dList->addBack("night");

    Node* node = dList->front();
    while (node->val) {
        printf("%s ", node->val);
        node = node->next;
    }
    printf("\nFIN\n");

    return 0;
}
