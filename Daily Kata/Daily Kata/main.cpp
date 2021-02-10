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
    key = 0;
    isEnd = false;
    isDel = false;
    
    children = new TrieNode*[26];
    for (int i = 0; i <= 26; ++i) {
        children[i] = NULL;
    }
}

class Trie {
public:
    Trie();
    void insert(const char* e, int k);
    int find(const char* e);
    void remove(const char* e);
private:
    TrieNode* root;
};

Trie::Trie() { root = new TrieNode(); }
void Trie::insert(const char* e, int k) {
    TrieNode* crawler = root;
    
    int ctr = 0;
    int idx;
    while (e[ctr] != '\0') {
        idx = e[ctr] - 'a';
        if (crawler->children[idx] == NULL)
            crawler->children[idx] = new TrieNode();
        
        crawler = crawler->children[idx];
        ctr++;
    }
    crawler->isEnd = true;
    crawler->key = k;
}
int Trie::find(const char* e) {
    TrieNode* crawler = root;
    
    int ctr = 0;
    int idx;
    while (e[ctr] != '\0') {
        idx = e[ctr] - 'a';
        if (crawler->children[idx] == NULL) return -1;
        
        crawler = crawler->children[idx];
        ctr++;
    }
    if (crawler->isEnd && !crawler->isDel) return crawler->key;
    return -1;
}
void Trie::remove(const char* e) {
    TrieNode* crawler = root;
    
    int ctr = 0;
    int idx;
    while (e[ctr] != '\0') {
        idx = e[ctr] - 'a';
        if (crawler->children[idx] == NULL) return;
        
        crawler = crawler->children[idx];
        ctr++;
    }
    if (crawler->isEnd) crawler->isDel = true;
    return;
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
    
    printf("\nFIN\n");
    return 0;
}
