#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>

using namespace std;

class Node {
public:
    int value;
    Node *left;
    Node *right;
    Node *parent;
    Node(int e) {
        value = e;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
    }
};

class BST {
public:
    BST();
    Node *root;
    Node *treeSearch(Node *x, int e);
    Node *treeMin(Node *x);
    void insert(int e);
    void remove(int e);
    void transplant(Node *u, Node *v);
    void inorderTraversal(Node *x);
};

BST::BST() : root(nullptr) { }
Node *BST::treeSearch(Node *x, int e) {
    while (x && x->value != e) {
        if (e < x->value) x = x->left;
        else x = x->right;
    }
    return x;
}
Node *BST::treeMin(Node *x) {
    while (x->left) x = x->left;
    return x;
}
void BST::insert(int e) {
    Node *x = root;
    Node *y = nullptr;
    Node *z = new Node(e);
    
    while (x) {
        y = x;
        if (e < x->value) x = x->left;
        else x = x->right;
    }
    
    z->parent = y;
    if (!y) root = z;
    else if (e < y->value) y->left = z;
    else y->right = z;
}
void BST::remove(int e) {
    Node *z = treeSearch(root, e);
    
    if (!z->left) transplant(z, z->right);
    else if (!z->right) transplant(z, z->left);
    else {
        Node *y = treeMin(z->right);
        
        if (y->parent != z) {
            transplant(y, y->right);
            y->right = z->right;
            y->right->parent = y;
        }
        
        transplant(z, y);
        y->left = z->left;
        y->left->parent = y;
    }
}
void BST::transplant(Node *u, Node *v) {
    if (!u->parent) root = v;
    else if (u == u->parent->left) u->parent->left = v;
    else u->parent->right = v;
    
    if (v) v->parent = u->parent;
}
void BST::inorderTraversal(Node *x) {
    if (x) {
        inorderTraversal(x->left);
        printf("%d ", x->value);
        inorderTraversal(x->right);
    }
}

int main() {
    BST *bst = new BST();
    bst->insert(12);
    bst->insert(5);
    bst->insert(18);
    bst->insert(2);
    bst->insert(9);
    bst->insert(15);
    bst->insert(19);
    bst->insert(13);
    bst->insert(17);
    
    bst->inorderTraversal(bst->root);
    printf("\nRemove 12\n");
    bst->remove(12);
    bst->inorderTraversal(bst->root);
    bst->remove(17);
    printf("\nRemove 17\n");
    bst->inorderTraversal(bst->root);
    
    printf("\nFIN\n");
    return 0;
}
