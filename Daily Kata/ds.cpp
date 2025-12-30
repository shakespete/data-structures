#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef int E;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
};

class DLL {
public:
    DLL();
    ~DLL();
    bool empty() const;
    Node* front() const;
    Node* back() const;
    void add(Node* v, const E& e);
    void addFront(const E& e);
    void addBack(const E& e);
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
};
DLL::~DLL() {
    while (!empty()) {
        removeBack();
    }
    head->next = NULL;
    tail->prev = NULL;
    delete head;
    delete tail;
};
bool DLL::empty() const {
    return head->next == tail;
};
Node* DLL::front() const {
    if (!empty()) return head->next;
    return head;
};
Node* DLL::back() const {
    if (!empty()) return tail->prev;
    return tail;
};
void DLL::add(Node* v, const E& e) {
    Node* u = new Node();
    u->val = e;

    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
};
void DLL::addFront(const E& e) {
    add(head->next, e);
}
void DLL::addBack(const E& e) {
    add(tail, e);
}
void DLL::remove(Node* v) {
    if (!empty()) {
        v->prev->next = v->next;
        v->next->prev = v->prev;
        delete v;
    }
}
void DLL::removeFront() {
    if (!empty()) remove(head->next);
}
void DLL::removeBack() {
    if (!empty()) remove(tail->prev);
}

int main() {
    DLL* dll = new DLL();
    dll->addFront(5);
    dll->addBack(6);
    dll->addFront(4);
    dll->addBack(7);
    dll->addFront(3);
    dll->addBack(8);
    dll->addFront(2);
    dll->addBack(9);
    dll->addFront(1);
    dll->addBack(10); 

    while(!dll->empty()) {
        printf("%d ", dll->front()->val);
        dll->removeFront();
    }
    
    delete dll;
    printf("\nFIN\n");
}