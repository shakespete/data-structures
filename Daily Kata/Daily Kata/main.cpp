#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

struct Node {
    const char *val;
    Node *prev;
    Node *next;
};

class DLL {
public:
    DLL();
    ~DLL();
    bool empty() const;
    Node *front() const;
    Node *back() const;
    void add(Node *v, const char *e);
    void addFront(const char *e);
    void addBack(const char *e);
    void remove(Node *v);
    void removeFront();
    void removeBack();
private:
    Node *head;
    Node *tail;
};

DLL::DLL() {
    head = new Node;
    tail = new Node;
    head->next = tail;
    tail->prev = head;
    head->val = nullptr;
    tail->val = nullptr;
    
}
DLL::~DLL() { while (!empty()) removeFront(); }
bool DLL::empty() const { return head->next == tail; }
Node *DLL::front() const { return empty() ? nullptr : head->next; }
Node *DLL::back() const { return empty() ? nullptr : tail->prev; }
void DLL::add(Node *v, const char *e) {
    Node *u = new Node;
    u->val = e;
    
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}
void DLL::addFront(const char *e) { add(head->next, e); }
void DLL::addBack(const char *e) { add(tail, e); }
void DLL::remove(Node *v) {
    if (!empty()) {
        Node *u = v->prev;
        Node *w = v->next;
        u->next = w;
        w->prev = u;
        delete v;
    }
}
void DLL::removeFront() { remove(head->next); }
void DLL::removeBack() { remove(tail->prev); }

bool is_equal(const char *a, const char *b) {
    while (*a == *b) {
        if (*a == '\0') return true;
        ++a;
        ++b;
    }
    return false;
}

class HashMap {
    enum { DEF_CAP = 50 };
public:
    HashMap(int cap = DEF_CAP);
    int hash(const char *e);
    void insert(const char *e);
    void remove(const char *e);
    Node *retrieve(const char *e);
private:
    DLL *HM;
    int capacity;
};

HashMap::HashMap(int cap) : HM(new DLL[cap]), capacity(cap) { }
int HashMap::hash(const char *e) {
    int hash = 33;
    int c;
    while (c = *e++) {
        hash = (((hash << 5) + hash) + c) % capacity;
    }
    return hash % capacity;
}
void HashMap::insert(const char *e) {
    int hashVal = hash(e);
    HM[hashVal].addBack(e);
}
void HashMap::remove(const char *e) {
    int hashVal = hash(e);
    if (HM[hashVal].empty()) return;
    
    Node *node = retrieve(e);
    if (node) HM[hashVal].remove(node);
    return;
}
Node *HashMap::retrieve(const char *e) {
    int hashVal = hash(e);
    if (HM[hashVal].empty()) return nullptr;
    
    Node *node = HM[hashVal].front();
    while (node) {
        if (is_equal(node->val, e)) return node;
        node = node->next;
    }
    return nullptr;
}

int main() {
    HashMap *hm = new HashMap();
    
    hm->insert("You know");
    hm->insert("to love\n");
    hm->insert("We're no");
    hm->insert("strangers");
    hm->insert("and so do I");
    hm->insert("the rules");
    
    printf("%s ", hm->retrieve("We're no")->val);
    printf("%s ", hm->retrieve("strangers")->val);
    printf("%s", hm->retrieve("to love\n")->val);
    printf("%s ", hm->retrieve("You know")->val);
    printf("%s ", hm->retrieve("the rules")->val);
    printf("%s ", hm->retrieve("and so do I")->val);
    
    printf("\nFIN\n");
    return 0;
}
