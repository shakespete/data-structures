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

class DLList {
public:
    DLList();
    ~DLList();
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

DLList::DLList() {
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
    head->val = "*";
    tail->val = "*";
}
bool DLList::empty() const { return head->next == tail; }
Node* DLList::front() const { return empty() ? nullptr : head->next; }
Node* DLList::back() const { return empty() ? nullptr : tail->prev; }
void DLList::add(Node* v, string str) {
    Node* u = new Node;
    u->val = str;
    
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}
void DLList::addFront(string str) { add(head->next, str); }
void DLList::addBack(string str) { add(tail, str); }
void DLList::remove(Node* v) {
    if (!empty()) {
        Node* u = v->prev;
        Node* w = v->next;
        u->next = w;
        w->prev = u;
        delete v;
    }
}
void DLList::removeFront() { if (!empty()) remove(head->next); }
void DLList::removeBack() { if (!empty()) remove(tail->prev); }

int main() {
    DLList* dlist = new DLList();
    dlist->addBack("We are");
    dlist->addBack("such stuff");
    dlist->addBack("as dreams");
    dlist->addBack("are made on,");
    dlist->addBack("and our");
    dlist->addBack("little life");
    dlist->addBack("is rounded");
    dlist->addBack("with a sleep.");
    
    while (!dlist->empty()) {
        cout << dlist->front()->val << " ";
        dlist->removeFront();
    }
    std::cout << "\nFIN\n";
    return 0;
}
