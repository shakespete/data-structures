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
	u->prev = v->prev;
	u->next = v;
	v->prev->next = u;
	v->prev = u;
}
void DLL::addFront(const E& e) { add(head->next, e); }
void DLL::addBack(const E& e) { add(tail, e); }
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

class HashMap {
	enum { DEF_CAP = 1000 };
public:
	HashMap(int cap = DEF_CAP);
	int hash(const E& e);
	void insert(const E& e);
	void remove(const E& e);
	Node* retrieve(const E& e);
private:
	DLL* HM;
	int capacity;
};

HashMap::HashMap(int cap) : HM(new DLL[cap]), capacity(cap) { }
int HashMap::hash(const E& e) {
	int hash = (e * 31) % capacity;
	if (hash < 0) hash += capacity;
	return hash;
}
void HashMap::insert(const E& e) {
	int hashVal = hash(e);
	HM[hashVal].addBack(e);
}
void HashMap::remove(const E& e) {
	int hashVal = hash(e);
	if (HM[hashVal].empty()) return;

	Node* node = this->retrieve(e);
	if (node != NULL) HM[hashVal].remove(node);
	return;
}
Node* HashMap::retrieve(const E& e) {
	int hashVal = hash(e);
	if (HM[hashVal].empty()) return NULL;

	Node* node = HM[hashVal].front();
	while (node->val) {
		if (node->val == e) return node;
		node = node->next;
	}
	return NULL;
}


int main() {
	HashMap* hm = new HashMap();

	hm->insert(13);
	hm->insert(25);
	hm->insert(17);
	hm->insert(3);
	hm->insert(90);
	hm->insert(39);
	hm->insert(12);
	hm->insert(5);
	printf("%d ", hm->retrieve(3)->val);
	printf("%d ", hm->retrieve(5)->val);
	printf("%d ", hm->retrieve(12)->val);
	printf("%d ", hm->retrieve(13)->val);
	printf("%d ", hm->retrieve(17)->val);
	printf("%d ", hm->retrieve(25)->val);
	printf("%d ", hm->retrieve(39)->val);
	printf("%d ", hm->retrieve(90)->val);
	printf("%d ", hm->retrieve(3)->val);

	hm->remove(12);
	hm->remove(3);
	hm->remove(100);

	printf("\nFIN\n");

	return 0;
}