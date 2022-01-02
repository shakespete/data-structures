#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    string val;
    Node* next;
    Node* prev;
    Node(string str) {
        val = str;
        prev = nullptr;
        next = nullptr;
    }
};

class DLL {
public:
    DLL();
    ~DLL();
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

DLL::DLL() {
    head = new Node("*");
    tail = new Node("*");
    head->next = tail;
    tail->prev = head;
}
DLL::~DLL() { while (!empty()) removeBack(); }
bool DLL::empty() const { return head->next == tail; }
Node* DLL::front() const { return empty() ? nullptr : head->next; }
Node* DLL::back() const { return empty() ? nullptr : tail->prev; }
void DLL::add(Node* v, string str) {
    Node* u = new Node(str);
    u->next = v;
    u->prev = v->prev;
    v->prev->next = u;
    v->prev = u;
}
void DLL::addFront(string str) { add(head->next, str); }
void DLL::addBack(string str) { add(tail, str); }
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
    int hash(string str);
    void insert(string str);
    void remove(string str);
    Node* retrieve(string str);
private:
    DLL* HM;
    int capacity;
};


HashMap::HashMap(int cap) : HM(new DLL[cap]), capacity(cap) { }
int HashMap::hash(string str) {
    int hash = 5381;
    for (int i = 0; i < str.size(); ++i) {
        hash = (((hash << 5) + hash) + str[i]) % capacity;
    }
    return hash;
}
void HashMap::insert(string str) {
    int hashVal = hash(str);
    HM[hashVal].addBack(str);
}
void HashMap::remove(string str) {
    int hashVal = hash(str);
    if (HM[hashVal].empty()) return;
    
    Node* node = retrieve(str);
    if (node) HM[hashVal].remove(node);
    return;
}
Node* HashMap::retrieve(string str) {
    int hashVal = hash(str);
    if (HM[hashVal].empty()) return nullptr;
    
    Node* node = HM[hashVal].front();
    while (node) {
        if (str.compare(node->val) == 0) return node;
        node = node->next;
    }
    return nullptr;
}

int main() {
//
    
    HashMap* hm = new HashMap();
    hm->insert("My tongue");
    hm->insert("will tell");
    hm->insert("the anger");
    hm->insert("of my heart,");
    hm->insert("or else");
    hm->insert("my heart concealing");
    hm->insert("it will break.");
    
    cout << hm->retrieve("My tongue")->val << " ";
    cout << hm->retrieve("will tell")->val << " ";
    cout << hm->retrieve("the anger")->val << " ";
    cout << hm->retrieve("of my heart,")->val << "\n";
    cout << hm->retrieve("or else")->val << " ";
    cout << hm->retrieve("my heart concealing")->val << " ";
    cout << hm->retrieve("it will break.")->val << "\n";
        
    std::cout << "FIN\n";
    return 0;
}
