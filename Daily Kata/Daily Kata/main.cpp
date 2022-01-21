#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

struct Node {
    bool isEnd;
    string word;
    unordered_map<char, Node*> children;
    Node() {
        isEnd = false;
        word = "";
    }
};
class Trie {
public:
    Trie();
    void insert(string str);
    bool query(string str);
private:
    Node* root;
};

Trie::Trie() { root = new Node(); }
void Trie::insert(string str) {
    Node* crawler = root;
    for (auto& c : str) {
        if (crawler->children.find(c) == crawler->children.end()) {
            Node* node = new Node();
            crawler->children.insert({c, node});
        }
        crawler = crawler->children[c];
    }
    crawler->isEnd = true;
    crawler->word = str;
}
bool Trie::query(string str) {
    Node* crawler = root;
    for (auto& c : str) {
        if (crawler->children.find(c) == crawler->children.end()) return false;
        crawler = crawler->children[c];
    }
    if (crawler->isEnd) return true;
    return false;
}

int main() {
    Trie* t = new Trie();
    t->insert("Lord,");
    t->insert("what");
    t->insert("fools");
    t->insert("these");
    t->insert("mortals");
    t->insert("be!");
    
    cout << t->query("Lord,") << "\n";
    cout << t->query("what") << "\n";
    cout << t->query("fools") << "\n";
    cout << t->query("these") << "\n";
    cout << t->query("mortals") << "\n";
    cout << t->query("be.") << "\n";
    
    std::cout << "\nFIN\n";
    return 0;
}
