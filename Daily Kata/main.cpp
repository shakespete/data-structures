#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

class TrieNode {
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
	void insert(const char* str, const int k);
	int find(const char* str);
	void remove(const char* str);
private:
	TrieNode* root;
};

Trie::Trie() { root = new TrieNode(); }
void Trie::insert(const char* str, const int k) {
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
	crawler->key = k;
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

int uniq_id = 0;
int main() {
	Trie* trie = new Trie();
	trie->insert("hello", uniq_id);
	uniq_id++;
	trie->insert("darkness", uniq_id);
	uniq_id++;
	trie->insert("my", uniq_id);
	uniq_id++;
	trie->insert("old", uniq_id);
	uniq_id++;
	trie->insert("friend", uniq_id);
	uniq_id++;

	printf("%d\n", trie->find("hello"));
	printf("%d\n", trie->find("old"));
	printf("%d\n", trie->find("friend"));
	trie->remove("hello");
	trie->remove("old");
	trie->remove("friend");
	printf("%d\n", trie->find("hello"));
	printf("%d\n", trie->find("old"));
	printf("%d\n", trie->find("friend"));

	return 0;
}