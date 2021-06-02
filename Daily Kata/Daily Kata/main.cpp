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
    Node* back() const;
    void add(const char* e);
    void remove();
private:
    Node* head;
};

LL::LL() : head(NULL) { };
LL::~LL() { while (!empty()) remove(); };
bool LL::empty() const { return head == NULL; }
Node* LL::front() const { return empty() ? NULL : head; }
void LL::add(const char* e) {
    Node* v = new Node;
    v->val = e;
    v->next = head;
    head = v;
}
void LL::remove() {
    if (!empty()) {
        Node* old = head;
        head = old->next;
        delete old;
    }
}

int main() {
    LL* list = new LL();
    
    list->add("a bite,");
    list->add("a bee,");
    list->add("a grain,");
    list->add("A point,");
    
    while (!list->empty()) {
        printf("%s ", list->front()->val);
        list->remove();
    }
    printf("\nFIN\n");
    return 0;
}
