#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
    string word;
    bool isEnd;
    unordered_map<char, Node*> children;
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
        if (!crawler->children[c]) {
            crawler->children[c] = new Node();
        }
        crawler = crawler->children[c];
    }
    
    crawler->isEnd = true;
    crawler->word = s;
}
bool Trie::query(string s) {
    Node* crawler = root;
    
    for (auto& c : s) {
        if (!crawler->children[c]) return false;
        crawler = crawler->children[c];
    }
    
    if (crawler->isEnd) return true;
    return false;
}

int main() {
    Trie* t = new Trie();
    t->insert("Stars,");
    t->insert("hide your fires;");
    t->insert("Let not light");
    t->insert("see my black");
    t->insert("and deep desires.");
    
    cout << t->query("Stars,") << "\n";
    cout << t->query("hide your fires;") << "\n";
    cout << t->query("Let not light") << "\n";
    cout << t->query("see my black") << "\n";
    cout << t->query("and deep desires.") << "\n";
    cout << t->query("and deep desires") << "\n";
    
    std::cout << "\nFIN\n";
    return 0;
}
