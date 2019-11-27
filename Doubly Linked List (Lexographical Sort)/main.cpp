#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int str_compare(const char* a, const char* b) {
	while (*a != '\0' || *b != '\0') {
		if (*a < *b) return 0;
		else if (*a > * b) return 1;
		else {
			++a;
			++b;
		}
	}
	return 0;
}

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
	void insertion_sort(const char* e);
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
DLL::~DLL() {
	while (!empty()) removeFront();
	delete head;
	delete tail;
}
bool DLL::empty() const { return head->next == tail; }
Node* DLL::front() const { return empty() ? NULL : head->next; }
Node* DLL::back() const { return empty() ? NULL : tail->prev; }
void DLL::insertion_sort(const char* e) {
	if (empty()) addBack(e);
	else {
		Node* node = front();
		while (node->val) {
			if (str_compare(e, node->val) == 0) {
				add(node, e);
				return;
			}
			node = node->next;
		}
		addBack(e);
	}
}
void DLL::add(Node* v, const char* e) {
	Node* u = new Node;
	u->val = e;
	u->prev = v->prev;
	u->next = v;
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
	DLL* sortedList = new DLL();
	sortedList->insertion_sort("Since");
	sortedList->insertion_sort("childhood's");
	sortedList->insertion_sort("hour");
	sortedList->insertion_sort("I");
	sortedList->insertion_sort("have");
	sortedList->insertion_sort("not");
	sortedList->insertion_sort("been");
	sortedList->insertion_sort("as");
	sortedList->insertion_sort("others");
	sortedList->insertion_sort("were");

	Node* node = sortedList->front();
	while (node->val) {
		printf("%s\n", node->val);
		node = node->next;
	}
	return 0;
}