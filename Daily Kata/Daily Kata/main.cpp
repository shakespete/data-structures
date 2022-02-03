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
    void insert(string word);
    bool query(string word);
private:
    TrieNode* root;
};

Trie::Trie() { root = new TrieNode(); };
void Trie::insert(string word) {
    TrieNode* crawler = root;
    
    for (auto& c : word) {
        if (!crawler->children[c]) {
            TrieNode* node = new TrieNode();
            crawler->children[c] = node;
        }
        crawler = crawler->children[c];
    }
    crawler->isEnd = true;
    crawler->word = word;
}
bool Trie::query(string word) {
    TrieNode* crawler = root;
    
    for (auto& c : word) {
        if (!crawler->children[c]) return false;
        crawler = crawler->children[c];
    }
    return crawler->isEnd;
}


int main() {
    Trie* t = new Trie();
    t->insert("My tongue");
    t->insert("will tell");
    t->insert("the anger");
    t->insert("of my heart,");
    t->insert("or else");
    t->insert("my heart concealing it");
    t->insert("will break.");
    
    cout << t->query("My tongue") << "\n";
    cout << t->query("will tell") << "\n";
    cout << t->query("the anger") << "\n";
    cout << t->query("of your heart,") << "\n";
    cout << t->query("or else") << "\n";
    cout << t->query("my heart concealing it") << "\n";
    cout << t->query("will break.") << "\n";
    
    std::cout << "FIN\n";
    return 0;
}
