#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class BST {
public:
    int val;
    BST* left;
    BST* right;
    BST(int e);
    BST* treeMin(BST* x);
    BST* treeSearch(int e);
    BST* insert(int e);
    BST* remove(int e, BST* parent);
    void inorderTraversal();
};

BST::BST(int e) {
    val = e;
    left = nullptr;
    right = nullptr;
}
BST* BST::treeMin(BST* x) {
    while (x->left) x = x->left;
    return x;
}
BST* BST::treeSearch(int e) {
    BST* x = this;
    while (x && x->val != e) {
        if (e < x->val) x = x->left;
        else x = x->right;
    }
    return x;
}
BST* BST::insert(int e) {
    BST* x = this;
    
    while (true) {
        if (e < x->val) {
            if (x->left) x = x->left;
            else {
                BST* node = new BST(e);
                x->left = node;
                break;
            }
        } else {
            if (x->right) x = x->right;
            else {
                BST* node = new BST(e);
                x->right = node;
                break;
            }
        }
    }
    return x;
}
BST* BST::remove(int e, BST* parent) {
    BST* x = this;
    
    while (x) {
        if (x->left && x->right) {
            BST* min = treeMin(x->right);
            x->val = min->val;
            x->right->remove(min->val, x);
        } else if (!parent) {
            if (x->left) {
                x->val = x->left->val;
                x->right = x->left->right;
                x->left = x->left->left;
            } else if (x->right) {
                x->val = x->right->val;
                x->left = x->right->left;
                x->right = x->right->right;
            } else {
                x = nullptr;
            }
        } else if (parent->left == x) {
            parent->left = x->left ? x->left : x->right;
        } else if (parent->right == x) {
            parent->right = x->left ? x->left : x->right;
        }
        break;
    }
    return x;
}

void BST::inorderTraversal() {
    stack<BST*> st;
    BST* x = this;
    
    while (x || !st.empty()) {
        while(x) {
            st.push(x);
            x = x->left;
        }
        
        x = st.top();
        st.pop();
        
        cout << x->val << " ";
        x = x->right;
    }
}

int main() {
    BST* root = new BST(10);
    root->insert(5);
    root->insert(2);
    root->insert(1);
    root->insert(5);
    root->insert(15);
    root->insert(13);
    root->insert(14);
    root->insert(22);
    
    cout << "Inorder: ";
    root->inorderTraversal();
    cout << "\n";
    
    printf("\nFIN\n");
    return 0;
}
