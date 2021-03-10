#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Node {
    const char* val;
    Node* next;
};

class CLL {
public:
    CLL();
    ~CLL();
    bool empty() const;
    Node* front() const;
    Node* back() const;
    void add(const char* e);
    void advance();
    void remove();
private:
    Node* cursor;
};

CLL::CLL() : cursor(NULL) { }
CLL::~CLL() { while (!empty()) remove(); }
bool CLL::empty() const { return cursor == NULL; }
Node* CLL::front() const { return empty() ? NULL : cursor->next; }
Node* CLL::back() const { return empty() ? NULL : cursor;}
void CLL::add(const char* e) {
    Node* v = new Node;
    v->val = e;
    if (empty()) {
        v->next = v;
        cursor = v;
    } else {
        v->next = cursor->next;
        cursor->next = v;
    }
}
void CLL::advance() {
    if (!empty()) cursor = cursor->next;
}
void CLL::remove() {
    if (!empty()) {
        Node* old = cursor->next;
        if (cursor == old) cursor = NULL;
        else cursor->next = old->next;
        delete old;
    }
}

int main() {
    CLL* clist = new CLL();
    clist->add("in the brush");
    clist->add("a fox");
    clist->add("when it blooms,");
    clist->add("The oak");
    Node* node = clist->front();
    while (!clist->empty()) {
        printf("%s ", node->val);
        node = node->next;
        clist->remove();
    }
    printf("\nFIN\n");
    return 0;
}
