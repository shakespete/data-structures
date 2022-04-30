#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    string val;
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
    void add(Node* v, string s);
    void addFront(string s);
    void addBack(string s);
    void remove(Node* v);
    void removeFront();
    void removeBack();
private:
    Node* head;
    Node* tail;
};

DLL::DLL() {
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
    head->val = "*";
    tail->val = "*";
}
DLL::~DLL() { while (!empty()) removeFront(); }
bool DLL::empty() const { return head->next == tail; }
Node* DLL::front() const { return empty() ? nullptr : head->next; }
Node* DLL::back() const { return empty() ? nullptr : tail->prev; }
void DLL::add(Node* v, string s) {
    Node* u = new Node;
    u->val = s;
    
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}
void DLL::addFront(string s) { add(head->next, s); }
void DLL::addBack(string s) { add(tail, s); }
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

class HashMap {
    enum { DEF_CAP = 100 };
public:
    HashMap(int cap = DEF_CAP);
    int hash(string s);
    void insert(string s);
    void remove(string s);
    Node* retrieve(string s);
private:
    DLL* HM;
    int capacity;
};

HashMap::HashMap(int cap) : HM(new DLL[cap]), capacity(cap) { }
int HashMap::hash(string s) {
    int hash = 5386;
    for (int i = 0; i < (int)s.size(); ++i) {
        hash = (((hash << 5) + hash) + s[i]) % capacity;
    }
    return hash;
}
void HashMap::insert(string s) {
    int hashVal = hash(s);
    HM[hashVal].addBack(s);
}
void HashMap::remove(string s) {
    int hashVal = hash(s);
    if (HM[hashVal].empty()) return;
    
    Node* node = retrieve(s);
    if (node) HM[hashVal].remove(node);
    return;
}
Node* HashMap::retrieve(string s) {
    int hashVal = hash(s);
    if (HM[hashVal].empty()) return nullptr;
    
    Node* node = HM[hashVal].front();
    while (node) {
        if (s.compare(node->val) == 0) return node;
        node = node->next;
    }
    
    return nullptr;
}

int main() {
    HashMap* hm = new HashMap();
    
    hm->insert("to say");
    hm->insert("keep little company");
    hm->insert("the truth,");
    hm->insert("reason and love");
    hm->insert("together nowadays.");
    hm->insert("And yet,");
    
    
    cout << hm->retrieve("And yet,")->val << " ";
    cout << hm->retrieve("to say")->val << " ";
    cout << hm->retrieve("the truth,")->val << " ";
    cout << hm->retrieve("reason and love")->val << " ";
    cout << hm->retrieve("keep little company")->val << " ";
    cout << hm->retrieve("together nowadays.")->val << " ";
    
    std::cout << "\nFIN\n";
    return 0;
}
