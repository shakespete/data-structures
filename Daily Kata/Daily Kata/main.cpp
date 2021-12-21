#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    string val;
    Node* prev;
    Node* next;
    Node(string s) {
        val = s;
        prev = nullptr;
        next = nullptr;
    }
};

class DLL {
public:
    DLL() {
        head = new Node("*");
        tail = new Node("*");
        head->next = tail;
        tail->prev = head;
    }
    ~DLL() { while (!empty()) removeBack(); }
    bool empty() const { return head->next == tail; }
    Node* front() const { return empty() ? nullptr : head->next; }
    Node* back() const { return empty() ? nullptr : tail->prev; }
    void add(Node* v, string s) {
        Node* u = new Node(s);
        u->prev = v->prev;
        u->next = v;
        v->prev->next = u;
        v->prev = u;
    }
    void addFront(string s) { add(head->next, s); }
    void addBack(string s) { add(tail, s); }
    void remove(Node* v) {
        if (!empty()) {
            Node* u = v->prev;
            Node* w = v->next;
            u->next = w;
            w->prev = u;
            delete v;
        }
    }
    void removeFront() { if (!empty()) remove(head->next); }
    void removeBack() { if (!empty()) remove(tail->prev); }
private:
    Node* head;
    Node* tail;
};

class HashMap {
    enum { DEF_CAP = 100 };
public:
    HashMap(int cap = DEF_CAP) : HM(new DLL[cap]), capacity(cap) { }
    int hash(string s) {
        int hash = 5381;
        for (int i = 0; i < s.size(); ++i) {
            hash = (((hash << 5) + hash) + s[i]) % capacity;
        }
//        cout << s << ": " << hash << "\n";
        return hash;
    }
    void insert(string s) {
        int hashVal = hash(s);
        HM[hashVal].addBack(s);
    }
    Node* retrieve(string s) {
        int hashVal = hash(s);
        if (HM[hashVal].empty()) return nullptr;
        
        Node* node = HM[hashVal].front();
        while (node) {
            if (s.compare(node->val) == 0) return node;
            node = node->next;
        }
        return node;
    }
    void remove(string s) {
        int hashVal = hash(s);
        if (HM[hashVal].empty()) return;
        
        Node* node = retrieve(s);
        if (node) HM[hashVal].remove(node);
        return;
    }
private:
    DLL* HM;
    int capacity;
};

int main() {
    HashMap* hm = new HashMap();
       
    hm->insert("A stick,");
    hm->insert("a stone,");
    hm->insert("the end");
    hm->insert("of the road");
    hm->insert("The rest");
    hm->insert("of a stump,");
    hm->insert("a lonesome road");
    
    cout << hm->retrieve("A stick,")->val << " ";
    cout << hm->retrieve("a stone,")->val << " ";
    cout << hm->retrieve("the end")->val << " ";
    cout << hm->retrieve("of the road")->val << "\n";
    cout << hm->retrieve("The rest")->val << " ";
    cout << hm->retrieve("of a stump,")->val << " ";
    cout << hm->retrieve("a lonesome road")->val << "\n";
    
    hm->remove("the end");
    Node* node = hm->retrieve("the end");
    int val = node ? 1 : 0;
    cout << val;
    
    cout << "\nFIN\n";
    return 0;
}
