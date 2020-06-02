#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Node {
	const char* val;
	Node* next;
};

class CLL {
public:
	CLL();
	~CLL();
	bool empty() const;
	Node* front();
	Node* back();
	void add(const char* e);
	void advance();
	void remove();
private:
	Node* cursor;
};

CLL::CLL() : cursor(NULL) { }
CLL::~CLL() { while (!empty()) remove(); }
bool CLL::empty() const { return cursor == NULL; }
Node* CLL::front() { return empty() ? NULL : cursor->next; }
Node* CLL::back() { return empty() ? NULL : cursor; }
void CLL::add(const char* e) {
	Node* v = new Node();
	v->val = e;

	if (empty()) {
		v->next = v;
		cursor = v;
	}
	else {
		v->next = cursor->next;
		cursor->next = v;
	}
}
void CLL::advance() { if (!empty()) cursor = cursor->next; }
void CLL::remove() {
	if (!empty()) {
		Node* old = cursor->next;
		if (old == cursor) cursor = NULL;
		else cursor->next = old->next;
		delete old;
	}
}

class Queue {
public:
	Queue();
	~Queue();
	int size();
	bool empty();
	Node* front();
	void enq(const char* e);
	void deq();
private:
	CLL CL;
	int n;
};

Queue::Queue() : CL(), n(0) { }
Queue::~Queue() { while (!empty()) deq(); }
int Queue::size() { return n; }
bool Queue::empty() { return n == 0; }
Node* Queue::front() { return empty() ? NULL : CL.front(); }
void Queue::enq(const char* e) {
	CL.add(e);
	CL.advance();
	++n;
}
void Queue::deq() {
	CL.remove();
	--n;
}

int main() {
	Queue* q = new Queue();
	q->enq("Hello");
	q->enq("darkness");
	q->enq("my");
	q->enq("old");
	q->enq("friend");

	while (!q->empty()) {
		printf("%s ", q->front()->val);
		q->deq();
	}
	return 0;
}