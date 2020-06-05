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
	head = new Node();
	tail = new Node();
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

bool is_equal(const char* a, const char* b) {
	while (*a == *b) {
		if (*a == '\0') return true;
		++a;
		++b;
	}
	return false;
}

class HashMap {
	enum { DEF_CAP = 100 };
public:
	HashMap(int cap = DEF_CAP);
	int hash(const char* e);
	void insert(const char* e);
	void remove(const char* e);
	Node* retrieve(const char* e);
private:
	DLL* HM;
	int capacity;
};

HashMap::HashMap(int cap) : HM(new DLL[cap]), capacity(cap) { }
int HashMap::hash(const char* e) {
	int hash = 31;
	int c;
	while (c = *e++) {
		hash = (((hash << 5) + hash) + c) % capacity;
	}
	return hash % capacity;
}
void HashMap::insert(const char* e) {
	int hashVal = hash(e);
	HM[hashVal].addBack(e);
}
void HashMap::remove(const char* e) {
	int hashVal = hash(e);
	if (HM[hashVal].empty()) return;

	Node* node = retrieve(e);
	if (node != NULL) HM[hashVal].remove(node);
	return;
}
Node* HashMap::retrieve(const char* e) {
	int hashVal = hash(e);
	if (HM[hashVal].empty()) return NULL;

	Node* node = HM[hashVal].front();
	while (node->val != NULL) {
		if (is_equal(e, node->val)) return node;
		node = node->next;
	}
	return NULL;
}

int main() {
	HashMap* hm = new HashMap();
	hm->insert("is");
	hm->insert("misfortune");
	hm->insert("school");
	hm->insert("The");
	hm->insert("good");
	hm->insert("of");
	hm->insert("school");
	hm->insert("a");

	printf("%s ", hm->retrieve("The")->val);
	printf("%s ", hm->retrieve("school")->val);
	printf("%s ", hm->retrieve("of")->val);
	printf("%s ", hm->retrieve("misfortune")->val);
	printf("%s ", hm->retrieve("is")->val);
	printf("%s ", hm->retrieve("a")->val);
	printf("%s ", hm->retrieve("good")->val);
	printf("%s ", hm->retrieve("school")->val);
	printf("\nFIN\n");
	return 0;
}