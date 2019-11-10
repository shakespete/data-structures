#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Node {
	int id;
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
	void add(Node* v, const char* e, int id);
	void addFront(const char* e, int id);
	void addBack(const char* e, int id);
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
	head->val = NULL;
}
DLL::~DLL() { while (!empty()) removeFront(); }
bool DLL::empty() const { return head->next == tail; }
Node* DLL::front() const { return empty() ? NULL : head->next; }
Node* DLL::back() const { return empty() ? NULL : tail->prev; }
void DLL::add(Node* v, const char* e, int id) {
	Node* u = new Node;
	u->id = id;
	u->val = e;
	u->prev = v->prev;
	u->next = v;
	v->prev->next = u;
	v->prev = u;
}
void DLL::addFront(const char* e, int id) { add(head->next, e, id); }
void DLL::addBack(const char* e, int id) { add(tail, e, id); }
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

int uniq_id = 0;
class HashMap {
	enum { DEF_CAP = 5381 };
public:
	HashMap(int cap);
	int hash(const char* e);
	int insert(const char* e);
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
int HashMap::insert(const char* e) {
	int hashVal = hash(e);
	if (HM[hashVal].empty()) {
		++uniq_id;
		HM[hashVal].addBack(e, uniq_id);
		return uniq_id;
	}
	else {
		Node* node = this->retrieve(e);
		if (node != NULL) return node->id;
		else {
			++uniq_id;
			HM[hashVal].addBack(e, uniq_id);
			return uniq_id;
		}
	}
}
void HashMap::remove(const char* e) {
	int hashVal = hash(e);
	if (HM[hashVal].empty()) return;

	Node* node = HM[hashVal].front();
	while (node->val != NULL) {
		if (is_equal(node->val, e)) {
			HM[hashVal].remove(node);
			break;
		}
		node = node->next;
	}
	return;
}
Node* HashMap::retrieve(const char* e) {
	int hashVal = hash(e);
	if (HM[hashVal].empty()) return NULL;

	Node* node = HM[hashVal].front();
	while (node->val != NULL) {
		if (is_equal(node->val, e)) return node;
		node = node->next;
	}
	return NULL;
}

int main() {
	return 0;
}
