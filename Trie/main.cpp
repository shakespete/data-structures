#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// Trie Node
class TrieNode {
public:
	TrieNode();
	int key;
	bool isEndOfWord;
	bool isDeleted;
	TrieNode** children;
};
TrieNode::TrieNode() {
	key = 0;
	isEndOfWord = false;
	isDeleted = false;

	children = new TrieNode * [26];
	for (int i = 0; i < 26; ++i) {
		children[i] = NULL;
	}
}


// Trie
class Trie {
public:
	Trie();
	void insert(char str[], int k);
	int find(char str[]);
	void remove(char str[]);
	TrieNode* root;
};

Trie::Trie() { root = new TrieNode(); }
void Trie::insert(char str[], int k) {
	TrieNode* crawler = root;

	int ctr = 0;
	int indx;
	while (str[ctr] != '\0') {
		indx = str[ctr] - 'a'; // depends on the case

		if (crawler->children[indx] == NULL)
			crawler->children[indx] = new TrieNode();

		crawler = crawler->children[indx];
		ctr++;
	}

	crawler->isEndOfWord = true;
	crawler->key = k;
}

int Trie::find(char str[]) {
	TrieNode* crawler = root;
	int ctr = 0;
	int indx;
	while (str[ctr] != '\0') {
		indx = str[ctr] - 'a'; // depends on the case

		if (crawler->children[indx] == NULL)
			return -1;

		crawler = crawler->children[indx];
		ctr++;
	}

	if (crawler->isEndOfWord && !crawler->isDeleted)
		return crawler->key;
	return -1;
}

void Trie::remove(char str[]) {
	TrieNode* crawler = root;
	int ctr = 0;
	int indx;
	while (str[ctr] != '\0') {
		indx = str[ctr] - 'a'; //depends on the case

		if (crawler->children[indx] == NULL) return;

		crawler = crawler->children[indx];
		ctr++;
	}

	if (crawler->isEndOfWord)
		crawler->isDeleted = true;
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