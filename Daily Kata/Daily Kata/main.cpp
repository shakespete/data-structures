#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    Node* next;
    string val;
    Node(string s) { val = s; }
};

class LL {
public:
    LL();
    ~LL();
    bool empty() const;
    Node* front() const;
    void add(string s);
    void remove();
private:
    Node* head;
};

LL::LL() : head(nullptr) { }
LL::~LL() { while (!empty()) remove(); }
bool LL::empty() const { return head == nullptr; }
Node* LL::front() const { return empty() ? nullptr : head; }
void LL::add(string s) {
    Node* u = new Node(s);
    u->next = head;
    head = u;
}
void LL::remove() {
    if (!empty()) {
        Node* old = head;
        head = old->next;
        delete old;
    }
}


int main() {
    LL* ll = new LL();
    
    ll->add("the road");
    ll->add("it's the end of");
    ll->add("a stone,");
    ll->add("A stick,");
    
    while (!ll->empty()) {
        cout << ll->front()->val << " ";
        ll->remove();
    }
    
    printf("\nFIN\n");
    return 0;
}
