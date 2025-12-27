#include <stdio.h>

typedef int E;

class Node {
    public:
        E val;
        Node* next;
};

class LL {
    public:
        LL();
        ~LL();
        bool empty();
        Node* front();
        void add(const E& e);
        void remove();
    private:
        Node* head;
};

LL::LL(): head(NULL) {};
LL::~LL() { while(!empty()) remove(); };
bool LL::empty() { return head == NULL; };
Node* LL::front() { return empty() ? NULL : head; };
void LL::add(const E& e) {
    Node* v = new Node();
    v->val = e;
    v->next = head;
    head = v;
}
void LL::remove() {
    if (!empty()) {
        Node* old = head;
        head = old->next;
        delete old;
    } 
}

int main() {
    LL* ll = new LL();
    ll->add(5);
    ll->add(4);
    ll->add(3);
    ll->add(2);
    ll->add(1);

    while (!ll->empty()) {
        printf("%d ", ll->front()->val);
        ll->remove();
    }
    delete ll;
    printf("\nFIN\n");
}