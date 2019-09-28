#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef int E;

class Node {
public:
	E val;
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
	void add(Node* v, const E& e);
	void addFront(const E& e);
	void addBack(const E& e);
	void remove(Node* v);
	void removeFront();
	void removeBack();
private:
	Node* head;
	Node* tail;
};

DLL::DLL() {
	head = new Node;
	tail = new Node;
	head->next = tail;
	tail->prev = head;
	head->val = NULL;
	tail->val = NULL;
}
DLL::~DLL() { while (!empty()) removeFront(); }
bool DLL::empty() const { return head->next == tail; }
Node* DLL::front() const { return empty() ? NULL : head->next; }
Node* DLL::back() const { return empty() ? NULL : tail->prev; }
void DLL::add(Node* v, const E& e) {
	Node* u = new Node;
	u->val = e;
	u->next = v;
	u->prev = v->prev;
	v->prev->next = u;
	v->prev = u;
}
void DLL::addFront(const E& e) { add(head->next, e); }
void DLL::addBack(const E& e) { add(tail, e); }
void DLL::remove(Node* v) {
	Node* u = v->prev;
	Node* w = v->next;
	u->next = w;
	w->prev = u;
	delete v;
}
void DLL::removeFront() { if (!empty()) remove(head->next); }
void DLL::removeBack() { if (!empty()) remove(tail->prev); }

int main() {
	DLL* dlist = new DLL();
	dlist->addFront(5);
	dlist->addBack(6);
	dlist->addFront(4);
	dlist->addBack(7);
	dlist->addFront(3);
	dlist->addBack(8);
	dlist->addFront(2);
	dlist->addBack(9);
	dlist->addFront(1);
	dlist->addBack(10);

	while (!dlist->empty()) {
		printf("%d\n", dlist->front()->val);
		dlist->removeFront();
	}
	printf("FIN\n");
	return 0;
}