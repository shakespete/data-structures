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
    LinkedList* list = new LinkedList();
    
    list->add("don't see");
    list->add("The sentimental fool ");
    list->add("long ago\n");
    list->add("in her ");
    list->add("somewhere back ");
    list->add("He came from ");
    
    while (!list->empty()) {
        cout << list->front()->val;
        list->remove();
    }
    
    std::cout << "\nFIN\n";
    return 0;
}
