#define _CRT_SECURE_NO_WARNINGS
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
	bool empty() const;
	Node* front() const;
	void add(const E& e);
	void remove();
private:
	Node* head;
};

LL::LL() : head(NULL) { }
LL::~LL() { while (!empty()) remove(); }
bool LL::empty() const { return head == NULL; }
Node* LL::front() const { return empty() ? NULL : head; }
void LL::add(const E& e) {
	Node* v = new Node;
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
	LL* list = new LL();
	list->add(9);
	list->add(8);
	list->add(7);
	list->add(6);
	list->add(5);
	list->add(4);
	list->add(3);
	list->add(2);
	list->add(1);
	list->add(0);

	while (!list->empty()) {
		printf("%d ", list->front()->val);
		list->remove();
	}
	printf("\nFIN\n");

	return 0;
}