#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Node {
	const char* val;
	Node* next;
};

class LL {
public:
	LL();
	~LL();
	bool empty() const;
	Node* front() const;
	void add(const char* e);
	void remove();
private:
	Node* head;
};
LL::LL() : head(NULL) { }
LL::~LL() { while (!empty()) remove(); }
bool LL::empty() const { return head == NULL; }
Node* LL::front() const { return empty() ? NULL : head; }
void LL::add(const char* e) {
	Node* node = new Node;
	node->val = e;
	node->next = head;
	head = node;
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
	list->add("friend");
	list->add("old");
	list->add("my");
	list->add("darkness");
	list->add("hello");

	while (!list->empty()) {
		printf("%s ", list->front()->val);
		list->remove();
	}
	return 0;
}