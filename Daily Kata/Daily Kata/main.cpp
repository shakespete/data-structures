#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

struct Node {
    unordered_map<char, Node*> children;
    bool isEnd;
};

class Trie {
public:
    Node* root;
    Trie();
    void insert(string s);
    bool query(string s);
};


Trie::Trie() { root = new Node(); }
void Trie::insert(string s) {
    Node* crawler = root;
    
    for (auto letter : s) {
        if (crawler->children.find(letter) == crawler->children.end()) {
            Node* node = new Node();
            crawler->children.insert({ letter, node });
        }
        crawler = crawler->children[letter];
    }
    crawler->isEnd = true;
}
bool Trie::query(string s) {
    Node* crawler = root;
    
    for (auto letter : s) {
        if (crawler->children.find(letter) == crawler->children.end()) return false;
        crawler = crawler->children[letter];
    }
    return crawler->isEnd;
}

int main() {
    Trie* t = new Trie();
    
    t->insert("The devil");
    t->insert("can cite");
    t->insert("Scripture");
    t->insert("for his");
    t->insert("purpose");
    
    cout << t->query("The devil") << "\n";
    cout << t->query("can cite") << "\n";
    cout << t->query("Scripture") << "\n";
    cout << t->query("for his") << "\n";
    cout << t->query("purpose") << "\n";
    
    cout << t->query("scripture") << "\n";
    
    std::cout << "FIN\n";
    return 0;
}
