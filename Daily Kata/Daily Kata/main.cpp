#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Node {
    const char* val;
    Node* next;
};

class LL {
public:
    LL();
    ~LL();
    bool empty() const;
    Node* front() const;
    void add(const char* e);
    void remove();
private:
    Node* head;
};


LL::LL() : head(NULL) { }
LL::~LL() { while (!empty()) remove(); }
bool LL::empty() const { return head == NULL;}
Node* LL::front() const { return empty() ? NULL : head; }
void LL::add(const char* e) {
    Node* node = new Node;
    node->val = e;
    node->next = head;
    head = node;
}
void LL::remove() {
    if (!empty()) {
        Node* old = head;
        head = old->next;
        delete old;
    }
}

int main() {
    LL* l = new LL();
    
    l->add("of the road,");
    l->add("it's the end");
    l->add("a stone,");
    l->add("A stick,");
    
    while (!l->empty()) {
        printf("%s ", l->front()->val);
        l->remove();
    }
    printf("\nFIN\n");
    
    return 0;
}
