#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>

using namespace std;

class TrieNode {
public:
    int key;
    bool isEnd;
    bool isDeleted;
    TrieNode **children;
    TrieNode() {
        key = 0;
        isEnd = false;
        isDeleted = false;
        children = new TrieNode *[26];
        for (int i = 0; i < 26; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    Trie();
    int find(string word);
    void insert(string word, int k);
    void remove(string word);
    TrieNode *root;
};

Trie::Trie() { root = new TrieNode(); }
int Trie::find(string word) {
    TrieNode *crawler = root;
    
    int idx = 0;
    for (auto c : word) {
        idx = c - 'a'; // case sensitive
        if (crawler->children[idx] == nullptr) return -1;
        
        crawler = crawler->children[idx];
    }
    
    if (crawler->isEnd && !crawler->isDeleted) return crawler->key;
    return -1;
}
void Trie::insert(string word, int k) {
    TrieNode *crawler = root;
    
    int idx = 0;
    for (auto c : word) {
        idx = c - 'a'; // case sensitive
        if (crawler->children[idx] == nullptr)
            crawler->children[idx] = new TrieNode();
        
        crawler = crawler->children[idx];
    }
    
    crawler->isEnd = true;
    crawler->key = k;
}
void Trie::remove(string word) {
    TrieNode *crawler = root;
    
    int idx = 0;
    for (auto c : word) {
        idx = c - 'a'; // case sensitive
        if (crawler->children[idx] == nullptr) return;
        crawler = crawler->children[idx];
    }
    
    if (crawler->isEnd) crawler->isDeleted = true;
}

int main() {
    int uniqId = 0;
    
    Trie* t = new Trie();
    t->insert("sing", ++uniqId);
    t->insert("sip", ++uniqId);
    t->insert("ask", ++uniqId);
    
    printf("%d\n", t->find("sing"));
    printf("%d\n", t->find("sip"));
    printf("%d\n", t->find("ask"));
    printf("%d\n", t->find("sin"));
    printf("%d\n", t->find("as"));
    t->remove("sing");
    printf("%d\n", t->find("sing"));
    return 0;
}
