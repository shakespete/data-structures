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

class DLList {
public:
    DLList();
    ~DLList();
    bool empty() const;
    Node* front() const;
    Node* back() const;
    void add(Node* v, string str);
    void addFront(string str);
    void addBack(string str);
    void remove(Node* v);
    void removeFront();
    void removeBack();
private:
    Node* head;
    Node* tail;
};

DLList::DLList() {
    head = new Node();
    tail = new Node();
    head->next = tail;
    tail->prev = head;
    head->val = "*";
    tail->val = "*";
}
DLList::~DLList() { while (!empty()) removeBack(); }
bool DLList::empty() const { return head->next == tail; }
Node* DLList::front() const { return empty() ? nullptr : head->next; }
Node* DLList::back() const { return empty() ? nullptr : tail->prev; }
void DLList::add(Node* v, string str) {
    Node* u = new Node;
    u->val = str;
    
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}
void DLList::addFront(string str) { add(head->next, str); }
void DLList::addBack(string str) { add(tail, str); }
void DLList::remove(Node* v) {
    if (!empty()) {
        Node* u = v->prev;
        Node* w = v->next;
        u->next = w;
        w->prev = u;
        delete v;
    }
}
void DLList::removeFront() { if (!empty()) remove(head->next); }
void DLList::removeBack() { if (!empty()) remove(tail->prev); }

class HashMap {
    enum { DEF_CAP = 100 };
public:
    HashMap(int cap = DEF_CAP);
    int hash(string str);
    void insert(string str);
    Node* retrieve(string str);
    void remove(string str);
private:
    DLList* HM;
    int capacity;
};

HashMap::HashMap(int cap) : HM(new DLList[cap]), capacity(cap) { };
int HashMap::hash(string str) {
    int hash = 5381;
    for (int i = 0; i < (int)str.size(); ++i) {
        hash = (((hash << 5) + hash) + str[i]) % capacity;
    }
    return hash;
}
void HashMap::insert(string str) {
    int hashVal = hash(str);
    HM[hashVal].addBack(str);
}
Node* HashMap::retrieve(string str) {
    int hashVal = hash(str);
//    cout << hashVal << " ";
    if (HM[hashVal].empty()) return nullptr;
    
    Node* node = HM[hashVal].front();
    while (node) {
        if (str.compare(node->val) == 0) return node;
        node = node->next;
    }
    return nullptr;
}
void HashMap::remove(string str) {
    int hashVal = hash(str);
    if (HM[hashVal].empty()) return;
    
    Node* node = retrieve(str);
    if (node) HM[hashVal].remove(node);
    return;
}

int main() {
    HashMap* hm = new HashMap();
    hm->insert("Hell");
    hm->insert("is empty");
    hm->insert("and all");
    hm->insert("the devils");
    hm->insert("are here");
    
    cout << hm->retrieve("Hell")->val << " ";
    cout << hm->retrieve("is empty")->val << " ";
    cout << hm->retrieve("and all")->val << " ";
    cout << hm->retrieve("the devils")->val << " ";
    cout << hm->retrieve("are here")->val << " ";
    
    std::cout << "\nFIN\n";
    return 0;
}
