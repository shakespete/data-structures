#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef int E;

class Node {
public:
	E val;
	Node* next;
};

class CLL {
public:
	CLL();
	~CLL();
	bool empty() const;
	Node* front() const;
	Node* back() const;
	void advance();
	void add(const E& e);
	void remove();
private:
	Node* cursor;
};

CLL::CLL() : cursor(NULL) { }
CLL::~CLL() { while (!empty()) remove(); }
bool CLL::empty() const { return cursor == NULL; }
Node* CLL::front() const { return empty() ? NULL : cursor->next; }
Node* CLL::back() const { return empty() ? NULL : cursor; }
void CLL::advance() { if (!empty()) cursor = cursor->next; }
void CLL::add(const E& e) {
	Node* v = new Node;
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
void CLL::remove() {
	if (!empty()) {
		Node* old = cursor->next;
		if (old == cursor) cursor = NULL;
		else cursor->next = old->next;
		delete old;
	}
}


int main() {
	CLL* clist = new CLL();
	clist->add(5);
	clist->add(4);
	clist->add(3);
	clist->add(2);
	clist->add(1);

	clist->advance();

	Node* node = clist->front();
	while (node) {
		printf("%d ", node->val);
		clist->remove();
		node = clist->front();
	}

	return 0;
}