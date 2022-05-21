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
    Node* u = new Node();
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
    Node* retrieve(string s);
    void remove(string s);
private:
    DLL* HM;
    int capacity;
};

HashMap::HashMap(int cap) : HM(new DLL[cap]), capacity(cap) { }
int HashMap::hash(string s) {
    int hash = 5381;
    for (int i = 0; i < (int)s.size(); ++i) {
        hash = (((hash << 5) + hash) + s[i]) % capacity;
    }
    return hash;
}
void HashMap::insert(string s) {
    int hashVal = hash(s);
    HM[hashVal].addBack(s);
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
void HashMap::remove(string s) {
    int hashVal = hash(s);
    if (HM[hashVal].empty()) return;
    
    Node* node = retrieve(s);
    if (node) HM[hashVal].remove(node);
    return;
}

int main() {
    HashMap* hm = new HashMap();
    
    hm->insert("basically what you are.");
    hm->insert("is of course");
    hm->insert("the continuum in which");
    hm->insert("At any rate");
    hm->insert("everything occurs,");
    
    cout << hm->retrieve("At any rate")->val << " ";
    cout << hm->retrieve("the continuum in which")->val << " ";
    cout << hm->retrieve("everything occurs,")->val << " ";
    cout << hm->retrieve("is of course")->val << " ";
    cout << hm->retrieve("basically what you are.")->val << "\n";
    
    hm->remove("the continuum in which");
    Node* node = hm->retrieve("the continuum in which");
    if (!node) cout << "Removed: the continuum in which\n";
    
    std::cout << "\nFIN\n";
    return 0;
}
