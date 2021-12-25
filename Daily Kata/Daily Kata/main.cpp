#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
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
    void insert(string str);
    bool query(string str);
};

Trie::Trie() { root = new TrieNode(); }
void Trie::insert(string str) {
    TrieNode* crawler = root;
    
    for (auto c : str) {
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
    
    for (auto c : str) {
        if (crawler->children.find(c) == crawler->children.end()) return false;
        crawler = crawler->children[c];
    }
    if (crawler->isEnd) return true;
    return false;
}

int main() {
         
    Trie* trie = new Trie();
    trie->insert("The fault,");
    trie->insert("dear Brutus,");
    trie->insert("is not in our stars.");
    trie->insert("But in ourselves,");
    trie->insert("that we");
    trie->insert("are underlings.");
    
    cout << trie->query("The fault,") << " ";
    cout << trie->query("dear Brutus,") << " ";
    cout << trie->query("is not in our stars.") << "\n";
    cout << trie->query("But in ourselves,") << " ";
    cout << trie->query("that we") << " ";
    cout << trie->query("are underlings.") << "\n";
    
    
    cout << "\nFIN\n";
    return 0;
}
