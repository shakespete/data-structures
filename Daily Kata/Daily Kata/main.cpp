#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Node {
    int val;
};

class Heap {
    enum { DEF_CAP = 100 };
public:
    Heap(int cap = DEF_CAP);
    ~Heap();
    int size() const;
    bool empty() const;
    Node* root() const;
    void push(const int e);
    void pop();
private:
    Node** H;
    int n;
    int capacity;
};

Heap::Heap(int cap) : H(new Node*[cap]), n(0), capacity(cap) { }
Heap::~Heap() { while (!empty()) pop(); }
int Heap::size() const { return n; }
bool Heap::empty() const { return n == 0; }
Node* Heap::root() const { return empty() ? NULL : H[1]; }
void Heap::push(const int e) {
    if (size() != capacity) {
        Node* v = new Node;
        v->val = e;
        ++n;
        H[n] = v;
        
        int current = n;
        while (current > 1 && H[current]->val < H[current / 2]->val) {
            int parent = current / 2;
            
            Node* temp = H[parent];
            H[parent] = H[current];
            H[current] = temp;
            current = parent;
        }
    }
}
void Heap::pop() {
    if (!empty()) {
        delete H[1];
        H[1] = H[n];
        --n;
        
        int current = 1;
        while (current * 2 <= n) {
            int child;
            int left = current * 2;
            int right = current * 2 + 1;
            
            if (left == n) child = left;
            else child = H[left]->val < H[right]->val ? left : right;
            
            if (H[child]->val > H[current]->val) break;
            
            Node* temp = H[child];
            H[child] = H[current];
            H[current] = temp;
            current = child;
        }
    }
}

int main() {
    Heap* hp = new Heap();
    hp->push(6);
    hp->push(5);
    hp->push(4);
    hp->push(7);
    hp->push(9);
    hp->push(1);
    hp->push(8);
    hp->push(2);
    hp->push(3);
    
    while (!hp->empty()) {
        printf("%d ", hp->root()->val);
        hp->pop();
    }
    printf("\n");
    
    return 0;
}
