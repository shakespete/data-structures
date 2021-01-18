#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Node {
    const char* val;
    Node* next;
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    bool empty() const;
    Node* front() const;
    void add(const char* e);
    void remove();
private:
    Node* head;
};

LinkedList::LinkedList() : head(NULL) {}
LinkedList::~LinkedList() { while (!empty()) remove(); }
bool LinkedList::empty() const { return head == NULL; }
Node* LinkedList::front() const { return empty() ? NULL : head; }
void LinkedList::add(const char* e) {
    Node* v = new Node;
    v->val = e;
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
    LinkedList* LL = new LinkedList();
    LL->add("friend");
    LL->add("old");
    LL->add("my");
    LL->add("darkness");
    LL->add("Hello");
    
    while (!LL->empty()) {
        printf("%s ", LL->front()->val);
        LL->remove();
    }
    printf("\nFIN\n");
    
    return 0;
}
