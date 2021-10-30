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
    Node *treePredecessor(Node* x);             // O(h)
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
    
    z->p = y;                              // assign y as parent of z
    if (!y) root = z;                      // tree is empty, assign z as root
    else if (z->key < y->key) y->left = z; // assign z as left child of y
    else y->right = z;                     // assign z as right child of y
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
/**
 *  We replace subtree rooted at u with subtree rooted at v:
 *  - node u's parent becomes node v's parent
 *  - u's parent will have v as appropriate child
 */
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
/**
 *  The successor of x:
 *  - is the minimum value in its right subtree OR
 *  - its lowest ancestor whose left child is also an ancestor of x
 */
    if (x->right) return treeMin(x->right);
    
    Node *y = x->p;
    while (y && x == y->right) {
        x = y;
        y = y->p;
    }
    return y;
}
Node *BST::treePredecessor(Node* x) {
/**
 *  The predecessor of x:
 *  - is the maximum value in its left subtree OR
 *  - its lowest ancestor whose right child is also an ancestor of x
 */
    if (x->left) return treeMax(x->left);
    
    Node *y = x->p;
    while (y && x == y->left) {
        x = y;
        y = y->p;
    }
    return y;
}

int main() {
    BST* bst = new BST();
    bst->insert(15);
    bst->insert(6);
    bst->insert(18);
    bst->insert(3);
    bst->insert(7);
    bst->insert(17);
    bst->insert(20);
    bst->insert(2);
    bst->insert(4);
    bst->insert(13);
    bst->insert(9);
    
    Node* r = bst->getRoot();
    printf("Root: %d\n", r->key);
    Node* n = bst->treeSearch(bst->getRoot(), 13);
    printf("Found: %d\n", n->key);
    Node* n1 = bst->treeSearch(bst->getRoot(), 8);
    if (!n1) printf("NIL: 8 not found\n");
    Node* n2 = bst->treeSearch(bst->getRoot(), 18);
    printf("Found: %d\n", n2->key);
    Node* n3 = bst->treeSearch(bst->getRoot(), 9);
    printf("Found: %d\n", n3->key);
    
    Node* min = bst->treeMin(bst->getRoot());
    printf("Min: %d\n", min->key);
    Node* max = bst->treeMax(bst->getRoot());
    printf("Max: %d\n", max->key);
    
    Node* s = bst->treeSearch(bst->getRoot(), 6);
    Node* successor6 = bst->treeSuccessor(s);
    printf("Successor of %d: %d\n", s->key, successor6->key);
    Node* s1 = bst->treeSearch(bst->getRoot(), 13);
    Node* successor13 = bst->treeSuccessor(s1);
    printf("Successor of %d (no right): %d\n", s1->key, successor13->key);
    
    Node* predecessor6 = bst->treePredecessor(s);
    printf("Predecessor of %d: %d\n", s->key, predecessor6->key);
    Node* s2 = bst->treeSearch(bst->getRoot(), 9);
    Node* predecessor7 = bst->treePredecessor(s2);
    printf("Predecessor of %d (no left): %d\n", s2->key, predecessor7->key);
    
    bst->inorderTreeWalk(bst->getRoot());
    printf("Removed root 15\n");
    bst->remove(15);
    bst->inorderTreeWalk(bst->getRoot());
    Node* nr = bst->getRoot();
    printf("New root: %d\n", nr->key);
    return 0;
}

//          15
//        /    \
//      6       18
//     / \     /  \
//    3   7   17  20
//   / \   \
//  2   4   13
//         /
//        9
