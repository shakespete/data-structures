#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Node {
	const char* val;
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
	void add(Node* v, const char* e);
	void addFront(const char* e);
	void addBack(const char* e);
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
void DLL::add(Node* v, const char* e) {
	Node* u = new Node;
	u->val = e;

	u->next = v;
	u->prev = v->prev;
	v->prev->next = u;
	v->prev = u;
}
void DLL::addFront(const char* e) { add(head->next, e); }
void DLL::addBack(const char* e) { add(tail, e); }
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


int main() {
	DLL* dList = new DLL();
	dList->addBack("hello");
	dList->addBack("darkness");
	dList->addBack("my");
	dList->addBack("old");
	dList->addBack("friend");

	while (!dList->empty()) {
		printf("%s ", dList->front()->val);
		dList->removeFront();
	}
	printf("\n");

	return 0;
}