#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEnd;
};

class Trie {
public:
    Trie();
    TrieNode* root;
    void insert(string s);
    bool query(string s);
};

Trie::Trie() { root = new TrieNode(); }
void Trie::insert(string s) {
    TrieNode* crawler = root;
    
    for (auto letter : s) {
        if (crawler->children.find(letter) == crawler->children.end()) {
            TrieNode* node = new TrieNode();
            crawler->children.insert({ letter, node });
        }
        crawler = crawler->children[letter];
    }
    crawler->isEnd = true;
}
bool Trie::query(string s) {
    TrieNode* crawler = root;
    
    for (auto letter : s) {
        if (crawler->children.find(letter) == crawler->children.end()) return false;
        crawler = crawler->children[letter];
    }
    return crawler->isEnd;
}


int main() {
    Trie* t = new Trie();
    t->insert("We know");
    t->insert("what we are,");
    t->insert("but know not");
    t->insert("what we may be.");
    
    cout << t->query("We know") << "\n";
    cout << t->query("what we are,") << "\n";
    cout << t->query("but know not") << "\n";
    cout << t->query("what we may be") << "\n";
    cout << t->query("what we may be.") << "\n";
    
    std::cout << "\nFIN\n";
    return 0;
}
