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

CLL::CLL() : cursor(NULL) { }
CLL::~CLL() { while (!empty()) remove(); }
bool CLL::empty() const { return cursor == NULL; }
Node* CLL::front() const { return empty() ? NULL : cursor->next;}
Node* CLL::back() const { return empty() ? NULL : cursor; }
void CLL::advance() {
    if (!empty()) cursor = cursor->next;
}
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
void CLL::remove() {
    if (!empty()) {
        Node* old = cursor->next;
        if (old == cursor) cursor = NULL;
        else cursor->next = old->next;
        delete old;
    }
    
}

int main () {
    CLL* CL = new CLL();
    CL->add("Hello");
    CL->add("darkness");
    CL->add("my");
    CL->add("old");
    CL->add("friend");
    
    while (!CL->empty()) {
        printf("%s ", CL->front()->val);
        CL->remove();
    }
    printf("\nFIN\n");
    return 0;
}
