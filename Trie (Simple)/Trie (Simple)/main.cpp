//
//  main.cpp
//  Trie (Simple)
//
//  Created by Jose Mari Syjuco on 9/12/21.
//

#include <iostream>
#include <string>
#include <unordered_map>

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
    
    for (auto letter : str) {
        if (crawler->children.find(letter) == crawler->children.end()) {
            TrieNode* node = new TrieNode();
            crawler->children.insert({ letter, node });
        }
        crawler = crawler->children[letter];
    }
    crawler->isEnd = true;
}
bool Trie::query(string str) {
    TrieNode* crawler = root;
    for (auto letter : str) {
        if (crawler->children.find(letter) == crawler->children.end()) return false;
        crawler = crawler->children[letter];
    }
    return crawler->isEnd;
}

int main(int argc, const char * argv[]) {
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
    
    std::cout << "FIN\n";
    return 0;
}
