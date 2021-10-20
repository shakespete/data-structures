#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

class Queue {
    enum { DEF_CAP = 20 };
public:
    Queue(int cap = DEF_CAP);
    ~Queue();
    bool empty();
    void enq(int e);
    int deq();
private:
    int* Q;
    int capacity;
    int front;
    int rear;
};

Queue::Queue(int cap) : front(0), rear(0), capacity(cap), Q(new int[cap]) { };
Queue::~Queue() { while (!empty()) deq(); }
bool Queue::empty() { return front == rear; }
void Queue::enq(int e) { Q[rear++] = e; }
int Queue::deq() {
    if (!empty()) return Q[front++];
    return -1;
}

int main() {
    Queue* q = new Queue();
    q->enq(0);
    q->enq(1);
    q->enq(2);
    q->enq(3);
    q->enq(4);
    q->enq(5);
    q->enq(6);
    q->enq(7);
    q->enq(8);
    q->enq(9);
    q->enq(10);
    q->enq(11);
    
    while(!q->empty()) {
        printf("%d ", q->deq());
    }
    
    printf("\nFIN\n");
    return 0;
}
