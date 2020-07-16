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
    children = new TrieNode*[26];
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
    Trie* t = new Trie();
    t->insert("hello", uniq_id);
    uniq_id++;
    t->insert("darkness", uniq_id);
    uniq_id++;
    t->insert("my", uniq_id);
    uniq_id++;
    t->insert("old", uniq_id);
    uniq_id++;
    t->insert("friend", uniq_id);
    
    printf("%d ", t->find("hello"));
    printf("%d ", t->find("darkness"));
    printf("%d ", t->find("my"));
    printf("%d ", t->find("old"));
    printf("%d ", t->find("friend"));
    t->remove("darkness");
    t->remove("old");
    t->remove("friend");
    printf("%d ", t->find("darkness"));
    printf("%d ", t->find("old"));
    printf("%d ", t->find("friend"));
    
    return 0;
}
