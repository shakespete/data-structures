#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Node {
    const char* val;
    Node* prev;
    Node* next;
};

class DLL {
public:
    DLL();
    ~DLL();
    bool empty() const;
    Node* front() const;
    Node* back() const;
    void add(const char* e, Node* v);
    void addFront(const char* e);
    void addBack(const char* e);
    void remove(Node* v);
    void removeFront();
    void removeBack();
private:
    Node* head;
    Node* tail;
};

DLL::DLL() {
    head = new Node;
    tail = new Node;
    head->val = NULL;
    tail->val = NULL;
    head->next = tail;
    tail->prev = head;
}
DLL::~DLL() { while (!empty()) removeBack(); }
bool DLL::empty() const { return head->next == tail; }
Node* DLL::front() const { return empty() ? NULL : head->next;}
Node* DLL::back() const { return empty() ? NULL : tail->prev; }
void DLL::add(const char* e, Node* v) {
    Node* u = new Node;
    u->val = e;
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}
void DLL::addFront(const char* e) { add(e, head->next); }
void DLL::addBack(const char* e) { add(e, tail); }
void DLL::remove(Node* v) {
    if (!empty()) {
        Node* u = v->prev;
        Node* w = v->next;
        u->next = w;
        w->prev = u;
        delete v;
    }
}
void DLL::removeFront() { if (!empty()) remove(head->next); }
void DLL::removeBack() { if (!empty()) remove(tail->prev); }

bool is_equal(const char* a, const char* b) {
    while (*a == *b) {
        if (*a == '\0') return true;
        ++a;
        ++b;
    }
    return false;
}

class HashMap {
    enum { DEF_CAP = 100 };
public:
    HashMap(int cap = DEF_CAP);
    int hash(const char* e);
    void insert(const char* e);
    void remove(const char* e);
    Node* retrieve(const char* e);
private:
    DLL* HM;
    int capacity;
};

HashMap::HashMap(int cap) : HM(new DLL[cap]), capacity(cap) { }
int HashMap::hash(const char* e) {
    int hash = 31;
    int c;
    while (c = *e++) {
        hash = (((hash << 5) + hash) + c) % capacity;
    }
    return hash % capacity;
}
void HashMap::insert(const char* e) {
    int hashVal = hash(e);
    HM[hashVal].addBack(e);
}
void HashMap::remove(const char* e) {
    int hashVal = hash(e);
    if (HM[hashVal].empty()) return;
    
    Node* node = retrieve(e);
    if (node != NULL) HM[hashVal].remove(node);
    return;
}
Node* HashMap::retrieve(const char* e) {
    Node* u = new Node;
    u->val = "-";
    int hashVal = hash(e);
    if (HM[hashVal].empty()) return u;
    
    Node* node = HM[hashVal].front();
    while (node->val != NULL) {
        if(is_equal(e, node->val)) return node;
        node = node->next;
    }
    return u;
}

int main() {
    HashMap* hm = new HashMap();
    hm->insert("end");
    hm->insert("stick,");
    hm->insert("a");
    hm->insert("stone,");
    hm->insert("road");
    hm->insert("it's");
    hm->insert("the");
    hm->insert("A");
    hm->insert("of");
    hm->insert("the");
    
    
    printf("%s ", hm->retrieve("A")->val);
    printf("%s ", hm->retrieve("stick,")->val);
    printf("%s ", hm->retrieve("a")->val);
    printf("%s ", hm->retrieve("stone,")->val);
    printf("%s ", hm->retrieve("it's")->val);
    printf("%s ", hm->retrieve("the")->val);
    printf("%s ", hm->retrieve("end")->val);
    printf("%s ", hm->retrieve("of")->val);
    printf("%s ", hm->retrieve("the")->val);
    printf("%s\n", hm->retrieve("road")->val);
    
    hm->remove("A");
    hm->remove("stone,");
    hm->remove("end");
    hm->remove("road");
    printf("%s ", hm->retrieve("A")->val);
    printf("%s ", hm->retrieve("stick,")->val);
    printf("%s ", hm->retrieve("a")->val);
    printf("%s ", hm->retrieve("stone,")->val);
    printf("%s ", hm->retrieve("it's")->val);
    printf("%s ", hm->retrieve("the")->val);
    printf("%s ", hm->retrieve("end")->val);
    printf("%s ", hm->retrieve("of")->val);
    printf("%s ", hm->retrieve("the")->val);
    printf("%s ", hm->retrieve("road")->val);
    
    printf("\nFIN\n");
    return 0;
}
