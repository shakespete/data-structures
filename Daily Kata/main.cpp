#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct TrieNode {
public:
	TrieNode();
	int key;
	bool isEnd;
	bool isDel;
	TrieNode** children;
};
TrieNode::TrieNode() {
	key = -1;
	isEnd = false;
	isDel = false;
	
	children = new TrieNode * [26];
	for (int i = 0; i < 26; ++i) {
		children[i] = NULL;
	}
}

class Trie {
public:
	Trie();
	void insert(const char* str, const int e);
	int find(const char* str);
	void remove(const char* str);
private:
	TrieNode* root;
};
Trie::Trie() { root = new TrieNode(); }
void Trie::insert(const char* str, const int e) {
	TrieNode* crawler = root;

	int ctr = 0;
	int idx;
	while (str[ctr] != '\0') {
		idx = str[ctr] - 'a';

		if (crawler->children[idx] == NULL)
			crawler->children[idx] = new TrieNode();

		crawler = crawler->children[idx];
		++ctr;
	}

	crawler->isEnd = true;
	crawler->key = e;
}
int Trie::find(const char* str) {
	TrieNode* crawler = root;

	int ctr = 0;
	int idx;
	while (str[ctr] != '\0') {
		idx = str[ctr] - 'a';

		if (crawler->children[idx] == NULL) return -1;

		crawler = crawler->children[idx];
		++ctr;
	}

	if (crawler->isEnd && !crawler->isDel) return crawler->key;
	return -1;
}
void Trie::remove(const char* str) {
	TrieNode* crawler = root;

	int ctr = 0;
	int idx;
	while (str[ctr] != '\0') {
		idx = str[ctr] - 'a';

		if (crawler->children[idx] == NULL) return;

		crawler = crawler->children[idx];
		++ctr;
	}

	if (crawler->isEnd && !crawler->isDel) crawler->isDel = true;
	return;
}

int uniqId = 0;
int main() {
	Trie* t = new Trie();
	t->insert("sing", ++uniqId);
	t->insert("sip", ++uniqId);
	t->insert("ask", ++uniqId);

	printf("%d\n", t->find("sing"));
	printf("%d\n", t->find("sip"));
	printf("%d\n", t->find("ask"));
	printf("%d\n", t->find("sin"));
	printf("%d\n", t->find("as"));
	return 0;
}