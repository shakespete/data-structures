#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef int E;

struct Node {
	E val;
	E count = 0;
	Node* left = NULL;
	Node* right = NULL;
};

class BST {
public:
	BST();
	int size() const;
	bool empty() const;
	Node* root() const;
	bool search(E& e);
	void add(const E& e);
	void traverse(Node* v);
private:
	int n;
	Node* rootNode;
};


BST::BST() {
	n = 0;
	rootNode = NULL;
}
int BST::size() const { return n; }
bool BST::empty() const { return n == 0; }
Node* BST::root() const { return empty() ? NULL : rootNode; }
bool BST::search(E& e) {
	Node* curr = rootNode;
	while (curr != NULL) {
		if (e > curr->val) curr = curr->right;
		else if (e < curr->val) curr = curr->left;
		else return true;
	}
	return false;
}
void BST::add(const E& e) {
	if (rootNode != NULL) {
		Node* curr = rootNode;
		while (true) {
			if (e > curr->val) {
				if (curr->right == NULL) {
					curr->right = new Node;
					curr->right->val = e;
					curr->right->count++;
					break;
				}
				else {
					curr = curr->right;
				}
			}
			else if (e < curr->val) {
				if (curr->left == NULL) {
					curr->left = new Node;
					curr->left->val = e;
					curr->left->count++;
					break;
				}
				else {
					curr = curr->left;
				}
			}
			else {
				curr->count++;
				break;
			}
		}
	}
	else {
		rootNode = new Node;
		rootNode->val = e;
		rootNode->count++;
	}
	n++;
}
void BST::traverse(Node* v) {
	if (v != NULL) {
		traverse(v->left);
		for (int i = 0; i < v->count; ++i) {
			printf(" %d", v->val ? v->val : -1);
		}
		traverse(v->right);
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	int TC, N, val;
	scanf("%d", &TC);
	for (int test_case = 1; test_case <= TC; ++test_case) {
		printf("Case #%d:", test_case);
		BST* bst = new BST();
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) {
			scanf("%d", &val);
			bst->add(val);
		}
		bst->traverse(bst->root());
		delete bst;
		printf("\n");
	}
	return 0;
}
