//
//  main.cpp
//  Binary Search Tree (Simple)
//
//  Created by Jose Mari Syjuco on 31/10/21.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

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
    Node *treeSearch(Node* x, int e) const; // O(h) where h = height of tree
    Node *treeMin(Node *x) const;           // O(h)
    void insert(int e);                     // O(h)
    void remove(int e);                     // O(h)
    void transplant(Node *u, Node *v);      // O(1)
    void inorderTreeWalk(Node *x) const;    // O(n) where n = number of nodes
};

BST::BST() : root(nullptr) { }
Node *BST::treeSearch(Node *x, int e) const {
    while (x && x->value != e) {
        if (e < x->value) x = x->left;
        else x = x->right;
    }
    return x;
}
Node *BST::treeMin(Node *x) const {
    while (x->left) x = x->left;
    return x;
}
void BST::insert(int e) {
    Node *x = root;
    Node *y = nullptr;  // trailing pointer
    Node *z = new Node(e);
    
    while (x) {         // traverse down the tree
        y = x;
        if (z->value < x->value) x = x->left;
        else x = x->right;
    }
    
    z->parent = y;                              // assign parent of z
    if (!y) root = z;                           // empty, assign z as root
    else if (z->value < y->value) y->left = z;  // assign z as left child
    else y->right = z;                          // assign z as right child
}
void BST::remove(int e) {
    Node *z = treeSearch(root, e);
    
    if (!z->left) transplant(z, z->right);
    else if (!z->right) transplant(z, z->left);
    else {
        Node *y = treeMin(z->right);
        
        // if z is not y's parent
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
    if (!u->parent) root = v;                            // assign as root
    else if (u == u->parent->left) u->parent->left = v;  // assign as left child
    else u->parent->right = v;                           // assign as right child
    
    if (v) v->parent = u->parent;                        // assign parent
}
void BST::inorderTreeWalk(Node *x) const {
   if (x) {
      inorderTreeWalk(x->left);
      printf("%d\n", x->value);
      inorderTreeWalk(x->right);
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
    
    bst->inorderTreeWalk(bst->root);
    printf("Remove 12\n");
    bst->remove(12);
    bst->inorderTreeWalk(bst->root);
    bst->remove(17);
    printf("Remove 17\n");
    bst->inorderTreeWalk(bst->root);
    return 0;
}


// Observe that the member functions treeSearch, treeMin, and inorderTreeWalk are all declared to be const,
// which informs the compiler that they do not alter the contents of the BST.

//          12
//        /    \
//      5       18
//     / \     /  \
//    2   9   15  19
//           /  \
//          13  17
