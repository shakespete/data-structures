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
    void advance();
    void add(const char* e);
    void remove();
private:
    Node* cursor;
};

CLL::CLL() : cursor(nullptr) { }
CLL::~CLL() { while (!empty()) remove(); }
bool CLL::empty() const { return cursor == nullptr; }
Node* CLL::front() const { return empty() ? nullptr : cursor->next; }
Node* CLL::back() const { return empty() ? nullptr : cursor; }
void CLL::advance() { if (empty()) cursor = cursor->next; }
void CLL::add(const char* e) {
    Node* u = new Node();
    u->val = e;
    if (cursor == NULL) {
        u->next = u;
        cursor = u;
    } else {
        u->next = cursor->next;
        cursor->next = u;
    }
}
void CLL::remove() {
    Node* old = cursor->next;
    if (old == cursor) cursor = nullptr;
    else cursor->next = old->next;
    delete old;
}

int main() {
    CLL* clist = new CLL();
    clist->add("ya");
    clist->add("take");
    clist->add("wanna");
    clist->add("I");
    clist->add("oooh");
    clist->add("Jamaica");
    clist->add("Aruba");
    
    while (!clist->empty()) {
        printf("%s ", clist->front()->val);
        clist->remove();
    }
    
    printf("\nFIN\n");
    return 0;
}
