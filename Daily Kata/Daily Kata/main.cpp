#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct TrieNode {
    bool isEnd;
    string word;
    unordered_map<char, TrieNode*> children;
    TrieNode() {
        isEnd = false;
        word = "*";
    }
};

class Trie {
public:
    Trie();
    TrieNode* root;
    bool query(string s);
    void insert(string s);
};

Trie::Trie() { root = new TrieNode(); }
bool Trie::query(string s) {
    TrieNode* crawler = root;
    
    for (auto& c : s) {
        if (!crawler->children[c]) return false;
        crawler = crawler->children[c];
    }
    return crawler->isEnd;
}
void Trie::insert(string s) {
    TrieNode* crawler = root;
    
    for (auto& c : s) {
        if (!crawler->children[c]) {
            crawler->children[c] = new TrieNode();
        }
        crawler = crawler->children[c];
    }
    
    crawler->isEnd = true;
    crawler->word = s;
}

int main() {
    Trie* t = new Trie();
    t->insert("Though she");
    t->insert("be but");
    t->insert("little,");
    t->insert("she is");
    t->insert("fierce!");
    
    cout << t->query("Though she") << "\n";
    cout << t->query("Though he") << "\n";
    cout << t->query("be but") << "\n";
    cout << t->query("little,") << "\n";
    cout << t->query("she is") << "\n";
    cout << t->query("fierce!") << "\n";
    
    std::cout << "\nFIN\n";
    return 0;
}
