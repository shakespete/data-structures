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
    Node* cursor;
};

LL::LL() : cursor(NULL) { };
LL::~LL() { while (!empty()) remove(); }
bool LL::empty() const { return cursor == NULL; }
Node* LL::front() const { return empty() ? NULL : cursor; }
void LL::add(const char* e) {
    Node* v = new Node;
    v->val = e;
    v->next = cursor;
    cursor = v;
}
void LL::remove() {
    if (!empty()) {
        Node* old = cursor;
        cursor = cursor->next;
        delete old;
    }
}

int main() {
    LL* list = new LL();
    list->add("the bone");
    list->add("and");
    list->add("the flesh");
    list->add("the ground,");
    list->add("The foot,");
    
    while (!list->empty()) {
        printf("%s ", list->front()->val);
        list->remove();
    }
    printf("\nFIN\n");
    
    return 0;
}
