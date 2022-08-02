#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    string val;
    Node* next;
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    bool empty() const;
    Node* front() const;
    void add(string s);
    void remove();
private:
    Node* head;
};

LinkedList::LinkedList() : head(nullptr) { }
LinkedList::~LinkedList() { while (!empty()) remove(); }
bool LinkedList::empty() const { return head == nullptr; }
Node* LinkedList::front() const { return empty() ? nullptr : head; }
void LinkedList::add(string s) {
    Node* v = new Node();
    v->val = s;
    v->next = head;
    head = v;
}
void LinkedList::remove() {
    if (!empty()) {
        Node* old = head;
        head = old->next;
        delete old;
    }
}

int main() {
    LinkedList* ll = new LinkedList();
//
//
    ll->add("you've borrowed");
    ll->add("With the words");
    ll->add("my sorrows\n");
    ll->add("you fill");
    ll->add("So why do");
    
    while (!ll->empty()) {
        cout << ll->front()->val << " ";
        ll->remove();
    }
    std::cout << "\nFIN\n";
    return 0;
}
