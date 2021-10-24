//
//  main.cpp
//  Binary Search Tree (CLRS)
//
//  Created by Jose Mari Syjuco on 24/10/21.
//

#include <stdio.h>

class BST {
public:
    int key;
    BST *left;
    BST *right;
    BST *p;
    BST(int k);
    void insert(BST *root, int k);              // O(h) where h = height of tree
    void remove(BST *root, int k);              // O(h)
    void transplant(BST *root, BST *u, BST *v); // O(1)
    void inorderTreeWalk(BST *root);            // O(n)
    BST *treeSearch(BST *x, int k);             // O(h)
    BST *iterativeTreeSearch(BST *x, int k);    // "Unrolling" the recursion
    BST *treeMin(BST *x);                       // O(h)
    BST *treeMax(BST *x);                       // O(h)
    BST *treeSuccessor(BST *x);                 // O(h)
};

BST::BST(int k) {
    key = k;
    left = nullptr;
    right = nullptr;
    p = nullptr;
}
void BST::insert(BST *root, int k) {
    BST *x = root;
    BST *y = nullptr;
    BST *z = new BST(k);
    
    while (x) {
        y = x;          // trailing pointer
        if (z->key < x->key) x = x->left;
        else x = x->right;
    }
    
    z->p = y;           // assign parent
    if (!y) root = z;   // tree is empty
    else if (z->key < y->key) y->left = z;
    else y->right = z;
}
void BST::remove(BST *root, int k) {
    BST *z = treeSearch(root, k);
    
    if (!z->left) transplant(root, z, z->right);
    else if (!z->right) transplant(root, z, z->left);
    else {
        BST *y = treeMin(z->right);
        
        if (y->p != z) {
            transplant(root, y, y->right);
            y->right = z->right;
            y->right->p = y;
        }
        
        transplant(root, z, y);
        y->left = z->left;
        y->left->p = y;
    }
}
void BST::transplant(BST *root, BST *u, BST *v) {
    if (!u->p) root = v;
    else if (u == u->p->left) u->p->left = v;
    else u->p->right = v;
    
    if (v) v->p = u->p;
}
void BST::inorderTreeWalk(BST *x) {
    if (x) {
        inorderTreeWalk(x->left);
        printf("%d\n", x->key);
        inorderTreeWalk(x->right);
    }
}
BST *BST::treeSearch(BST *x, int k) {
    if (!x || k == x->key) return x;
    if (k < x->key) return treeSearch(x->left, k);
    else return treeSearch(x->right, k);
}
BST *BST::iterativeTreeSearch(BST *x, int k) {
    while (x && k != x->key) {
        if (k < x->key) x = x->left;
        else x = x->right;
    }
    return x;
}
BST *BST::treeMin(BST *x) {
    while (x->left) x = x->left;
    return x;
}
BST *BST::treeMax(BST *x) {
    while (x->right) x = x->right;
    return x;
}
BST *BST::treeSuccessor(BST *x) {
    if (x->right) return treeMin(x->right);
    
    BST *y = x->p;
    while (y && x == y->right) {
        x = y;
        y = y->p;
    }
    return y;
    
}

int main() {
    BST* root = new BST(12);
    root->insert(root, 5);
    root->insert(root, 18);
    root->insert(root, 2);
    root->insert(root, 9);
    root->insert(root, 15);
    root->insert(root, 19);
    root->insert(root, 13);
    root->insert(root, 17);
    
//    root->remove(root, 13);
//    root->inorderTreeWalk(root);
//    root->insert(root, 18);
//    root->inorderTreeWalk(root);
//    root->remove(root, 18);
//    root->inorderTreeWalk(root);
//    root->insert(root, 11);
    root->inorderTreeWalk(root);
    return 0;
}
