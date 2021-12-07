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
    head->val = "";
    tail->val = "";
}
DLL::~DLL() { while (!empty()) removeBack(); }
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


bool strComp(string a, string b) {
    int i = 0;
    while (a[i] == b[i]) {
        if (a[i] == '\0') return true;
        ++i;
    }
    return false;
}


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
    int hash = 5381;
    for (int i = 0; i < s.size(); ++i) {
        hash = (((hash << 5) + hash) + s[i]) % capacity;
    }
    return hash;
}
void HashMap::insert(string s) {
    int hashVal = hash(s);
    cout << s << ": " << hashVal << "\n";
    HM[hashVal].addBack(s);
}
void HashMap::remove(string s) {
    int hashVal = hash(s);
    if (HM[hashVal].empty()) return;
    
    Node* node = retrieve(s);
    if (node) HM[hashVal].remove(node);
}
Node* HashMap::retrieve(string s) {
    int hashVal = hash(s);
    if (HM[hashVal].empty()) return nullptr;
    
    Node* node = HM[hashVal].front();
    while (node) {
        if (strComp(node->val, s)) return node;
        node = node->next;
    }
    return nullptr;
}

int main() {
    
    HashMap* hm = new HashMap();
    hm->insert("is");
    hm->insert("misfortune");
    hm->insert("school");
    hm->insert("The");
    hm->insert("good");
    hm->insert("of");
    hm->insert("school");
    hm->insert("a");
    
    hm->insert("A stick,");
    hm->insert("It's the rest");
    hm->insert("of a stump,");
    hm->insert("it's a little alone");
    hm->insert("of the road");
    hm->insert("it's the end");
    hm->insert("a stone,");

    cout << hm->retrieve("The")->val << " ";
    cout << hm->retrieve("school")->val << " ";
    cout << hm->retrieve("of")->val << " ";
    cout << hm->retrieve("misfortune")->val << " ";
    cout << hm->retrieve("is")->val << " ";
    cout << hm->retrieve("a")->val << " ";
    cout << hm->retrieve("good")->val << " ";
    cout << hm->retrieve("school")->val << "\n";
    
    cout << hm->retrieve("A stick,")->val << " ";
    cout << hm->retrieve("a stone,")->val << " ";
    cout << hm->retrieve("it's the end")->val << " ";
    cout << hm->retrieve("of the road")->val << "\n";
    cout << hm->retrieve("It's the rest")->val << " ";
    cout << hm->retrieve("of a stump,")->val << " ";
    cout << hm->retrieve("it's a little alone")->val << " ";
    
    printf("\nFIN\n");
    return 0;
}
