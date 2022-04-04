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
    Node* cursor = root;
    
    for (auto letter : s) {
        if (cursor->children.find(letter) == cursor->children.end()) {
            Node* node = new Node();
            cursor->children[letter] = node;
        }
        cursor = cursor->children[letter];
    }
    cursor->isEnd = true;
}
bool Trie::query(string s) {
    Node* cursor = root;
    
    for (auto letter : s) {
        if (cursor->children.find(letter) == cursor->children.end()) return false;
        cursor = cursor->children[letter];
    }
    if (cursor->isEnd) return true;
    return false;
}

int main() {
    Trie* t = new Trie();
    t->insert("Brevity");
    t->insert("is");
    t->insert("the");
    t->insert("soul");
    t->insert("of");
    t->insert("wit");
    
    cout << t->query("Brevity") << "\n";
    cout << t->query("is") << "\n";
    cout << t->query("the") << "\n";
    cout << t->query("soul") << "\n";
    cout << t->query("of") << "\n";
    cout << t->query("wit") << "\n";
    cout << t->query("souls") << "\n";
    
    
    std::cout << "FIN\n";
    
    return 0;
}
