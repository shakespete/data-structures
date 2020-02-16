#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void str_copy(char* des, char* src) {
	while (*src != '\0') * des++ = *src++;
	*des = '\0';
}

// Trie Node
class TrieNode {
public:
	TrieNode();
	~TrieNode();
	char* val;
	bool isEndOfWord;
	bool hasChildren;
	TrieNode** children;
};
TrieNode::TrieNode() {
	isEndOfWord = false;
	hasChildren = false;
	val = new char[10];

	children = new TrieNode * [26];
	for (int i = 0; i < 26; ++i) children[i] = NULL;
}
TrieNode::~TrieNode() {
	if (hasChildren) {
		for (int i = 0; i < 26; ++i) {
			if (children[i] != NULL) delete children[i];
		}
	}
	delete[] children;
}

// Trie
class Trie {
public:
	Trie();
	~Trie();
	void insert(char str[]);
	void traverse(TrieNode* v);
	TrieNode* root;
};

Trie::Trie() { root = new TrieNode(); }
Trie::~Trie() { delete root; }

void Trie::insert(char str[]) {
	TrieNode* crawler = root;

	int ctr = 0;
	int indx;
	while (str[ctr] != '\0') {
		indx = str[ctr] - 'a'; //depends on the case

		if (crawler->children[indx] == NULL) {
			crawler->hasChildren = true;
			crawler->children[indx] = new TrieNode();
		}

		crawler = crawler->children[indx];
		ctr++;
	}
	crawler->val = str;
	crawler->isEndOfWord = true;
	crawler->hasChildren = false;
}

// Inorder Traversal
void Trie::traverse(TrieNode * v) {
	if (v != NULL && v->hasChildren) {
		for (int i = 0; i < 26; ++i) {
			if (v->children[i] != NULL) {
				if (v->children[i]->isEndOfWord && !v->hasChildren) {
					printf(" %s", v->children[i]->val);
				}
				else if (v->children[i]->isEndOfWord) {
					printf(" %s", v->children[i]->val);
					traverse(v->children[i]);
				}
				else traverse(v->children[i]);
			}
		}
	}
}


int main() {
	freopen("input.txt", "r", stdin);

	int TC, C, command;
	scanf("%d", &TC);
	for (int test_case = 1; test_case <= TC; ++test_case) {
		printf("Case #%d:", test_case);

		Trie* t = new Trie();

		scanf("%d", &C);
		for (int i = 0; i < C; ++i) {
			scanf("%d", &command);
			if (command == 0) {
				char* src = new char[10];
				scanf("%s", src);
				t->insert(src);
			}
			else {
				t->traverse(t->root);
			}
		}
		delete t;
		printf("\n");
	}
	return 0;
}
