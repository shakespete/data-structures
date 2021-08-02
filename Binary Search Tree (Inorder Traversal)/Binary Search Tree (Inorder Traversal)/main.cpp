#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct Node {
    int value;
    Node* left;
    Node* right;
};

class BinarySearchTree {
public:
    Node* insert(Node* u, int val);
    void inOrder(Node* u);
    void postOrder(Node* u);
};
Node* BinarySearchTree::insert(Node* u, int val) {
    if (u == NULL) {
        Node* node = new Node;
        node->left = NULL;
        node->right = NULL;
        node->value = val;
        return node;
    }
    Node* curr;
    if (val <= u->value) {
        curr = insert(u->left, val);
        u->left = curr;
    } else {
        curr = insert(u->right, val);
        u->right = curr;
    }
    return u;
}
void BinarySearchTree::inOrder(Node* u) {
    if (u != NULL) {
        inOrder(u->left);
        printf("%d ", u->value);
        inOrder(u->right);
    }
}
void BinarySearchTree::postOrder(Node* u) {
    if (u != NULL) {
        postOrder(u->left);
        postOrder(u->right);
        printf("%d ", u->value);
    }
}

int main() {
    Node* root = NULL;
    BinarySearchTree* tree = new BinarySearchTree();
    
    int arr[] = {1, 2, 5, 3, 6, 4};
    for (int i = 0; i < 6; ++i)
        root = tree->insert(root, arr[i]);
    
//    tree->inOrder(root);
    tree->postOrder(root);
    printf("\nFIN\n");
    return 0;
}
// Inorder: 1 2 3 4 5 6
// Postorder: 4 3 6 5 2 1

//    1
//     \
//      2
//       \
//        5
//       / \
//      3   6
//       \
//        4
