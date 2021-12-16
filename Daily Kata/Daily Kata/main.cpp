#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd;
};

class Trie {
public:
    TrieNode* root;
    Trie();
    void insert(string str);
    bool query(string str);
};

Trie::Trie() { root = new TrieNode(); }
void Trie::insert(string str) {
    TrieNode* crawler = root;
    
    for (char c : str) {
        if (crawler->children.find(c) == crawler->children.end()) {
            TrieNode* node = new TrieNode();
            crawler->children.insert({ c, node });
        }
        crawler = crawler->children[c];
    }
    crawler->isEnd = true;
}
bool Trie::query(string str) {
    TrieNode* crawler = root;
    
    for (char c : str) {
        if (crawler->children.find(c) == crawler->children.end()) return false;
        crawler = crawler->children[c];
    }
    if (crawler->isEnd) return true;
    return false;
}

int main() {
    Trie* t = new Trie();
    
    t->insert("I'm used");
    t->insert("to it");
    t->insert("by now");
    t->insert("Another day");
    t->insert("just believe");
    t->insert("Just breathe");
    
    cout << t->query("I'm used") << "\n";
    cout << t->query("hello") << "\n";
    cout << t->query("to it") << "\n";
    cout << t->query("by now") << "\n";
    cout << t->query("Another day") << "\n";
    cout << t->query("just believe") << "\n";
    cout << t->query("Just breathe") << "\n";
    cout << t->query("just") << "\n";
    cout << "\nFIN\n";
    return 0;
}
