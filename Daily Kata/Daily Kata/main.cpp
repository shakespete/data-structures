#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    string val;
    bool isWord;
    vector<Node*> children{ vector<Node *>(26, nullptr) };
};

class Trie {
public:
    Trie();
    void insert(string s);
    bool query(string s);
private:
    Node* root;
};

Trie::Trie() { root = new Node(); }
void Trie::insert(string s) {
    Node* crawler = root;
    
    for (auto& c : s) {
        cout << c - 'a' << ": " << c << "\n";
        if (!crawler->children[c - 'a']) {
            crawler->children[c - 'a'] = new Node();
        }
        crawler = crawler->children[c - 'a'];
    }
    crawler->isWord = true;
}
bool Trie::query(string s) {
    Node* crawler = root;
    
    for (auto& c : s) {
        if (!crawler->children[c - 'a']) return false;
        crawler = crawler->children[c - 'a'];
    }
    return crawler->isWord;
}

int main() {
    Trie* trie = new Trie();
         
    
    trie->insert("all");
    trie->insert("that");
    trie->insert("glisters");
    trie->insert("is");
    trie->insert("not");
    trie->insert("gold");
    
    cout << trie->query("all") << "\n";
    cout << trie->query("that") << "\n";
    cout << trie->query("glitters") << "\n";
    cout << trie->query("is") << "\n";
    cout << trie->query("not") << "\n";
    cout << trie->query("gold") << "\n";
    
    std::cout << "\nFIN\n";
    return 0;
}
