//
//  main.cpp
//  Binary Search Tree (CLRS) - Tree class
//
//  Created by Jose Mari Syjuco on 25/10/21.
//

#include <stdio.h>

class Node {
public:
    int key;
    Node* left;
    Node* right;
    Node* p;
    Node(int k) {
        key = k;
        left = nullptr;
        right = nullptr;
        p = nullptr;
    }
};

class BST {
public:
    BST();
    Node *getRoot();
    void insert(int k);                         // O(h) where h = height of tree
    void remove(int k);                         // O(h)
    void transplant(Node *u, Node *v);          // O(1)
    void inorderTreeWalk(Node *x);              // O(n)
    Node *treeSearch(Node *x, int k);           // O(h)
    Node *iterativeTreeSearch(Node *x, int k);  // "Unrolling" the recursion
    Node *treeMin(Node *x);                     // O(h)
    Node *treeMax(Node *x);                     // O(h)
    Node *treeSuccessor(Node *x);               // O(h)
private:
    Node* root;
};

BST::BST() : root(nullptr) { }
Node *BST::getRoot() { return root; }
void BST::insert(int k) {
    Node *x = root;
    Node *y = nullptr;
    Node *z = new Node(k);
    
    while (x) {
        y = x;          // trailing pointer
        if (z->key < x->key) x = x->left;
        else x = x->right;
    }
    
    z->p = y;           // assign parent
    if (!y) root = z;   // tree is empty, assign root
    else if (z->key < y->key) y->left = z;
    else y->right = z;
}
void BST::remove(int k) {
    Node *z = treeSearch(root, k);
    
    if (!z->left) transplant(z, z->right);
    else if (!z->right) transplant(z, z->left);
    else {
        Node *y = treeMin(z->right);
        
        if (y->p != z) {
            transplant(y, y->right);
            y->right = z->right;
            y->right->p = y;
        }
        
        transplant(z, y);
        y->left = z->left;
        y->left->p = y;
    }
}
void BST::transplant(Node *u, Node *v) {
    if (!u->p) root = v;
    else if (u == u->p->left) u->p->left = v;
    else u->p->right = v;
    
    if (v) v->p = u->p;
}
void BST::inorderTreeWalk(Node *x) {
    if (x) {
        inorderTreeWalk(x->left);
        printf("%d\n", x->key);
        inorderTreeWalk(x->right);
    }
}
Node *BST::treeSearch(Node *x, int k) {
    if (!x || k == x->key) return x;
    if (k < x->key) return treeSearch(x->left, k);
    else return treeSearch(x->right, k);
}
Node *BST::iterativeTreeSearch(Node *x, int k) {
    while (x && k != x->key) {
        if (k < x->key) x = x->left;
        else x = x->right;
    }
    return x;
}
Node *BST::treeMin(Node *x) {
    while (x->left) x = x->left;
    return x;
}
Node *BST::treeMax(Node *x) {
    while (x->right) x = x->right;
    return x;
}
Node *BST::treeSuccessor(Node *x) {
    if (x->right) return treeMin(x->right);
    
    Node *y = x->p;
    while (y && x == y->right) {
        x = y;
        y = y->p;
    }
    return y;
}

int main() {
    BST* bst = new BST();
    bst->insert(12);
    bst->insert(5);
    bst->insert(18);
    bst->insert(19);
    bst->insert(15);
    bst->insert(9);
    bst->insert(2);
    bst->insert(13);
    bst->insert(17);
    
    Node* n = bst->treeSearch(bst->getRoot(), 13);
    printf("Found: %d\n", n->key);
    Node* n1 = bst->treeSearch(bst->getRoot(), 8);
    if (!n1) printf("NIL\n");
    Node* n2 = bst->treeSearch(bst->getRoot(), 18);
    printf("Found: %d\n", n2->key);
    Node* n3 = bst->treeSearch(bst->getRoot(), 12);
    printf("Found: %d\n", n3->key);
    
    Node* min = bst->treeMin(bst->getRoot());
    printf("Min: %d\n", min->key);
    Node* max = bst->treeMax(bst->getRoot());
    printf("Max: %d\n", max->key);
    
    bst->inorderTreeWalk(bst->getRoot());
    bst->remove(12);
    bst->inorderTreeWalk(bst->getRoot());
    return 0;
}
