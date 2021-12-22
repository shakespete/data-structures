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
    void preorderTraversal();
    void postorderTraversal();
private:
    BST* root;
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
    while (x && e != x->val) {
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
        if (e < x->val) {
            x = x->left;
            parent = x;
        } else if (e > x->val) {
            x = x->right;
            parent = x;
        } else {
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
    }
    return x;
}
void BST::inorderTraversal() {
    BST* x = this;
    stack<BST*> s;
    
    while (x || !s.empty()) {
        while (x) {
            s.push(x);
            x = x->left;
        }
        
        x = s.top();
        s.pop();
        
        cout << x->val << " ";
        x = x->right;
    }
}
void BST::preorderTraversal() {
    BST* x = this;
    stack<BST*> s;
    
    s.push(x);
    while (!s.empty()) {
        x = s.top();
        s.pop();
        
        cout << x->val << " ";
        
        if (x->right) s.push(x->right);
        if (x->left) s.push(x->left);
    }
}
void BST::postorderTraversal() {
    BST* x = this;
    stack<BST*> s1, s2;
    
    s1.push(x);
    while(!s1.empty()) {
        x = s1.top();
        s1.pop();
        s2.push(x);
        
        if (x->left) s1.push(x->left);
        if (x->right) s1.push(x->right);
    }
    
    while (!s2.empty()) {
        x = s2.top();
        s2.pop();
        
        cout << x->val << " ";
    }
}

int main() {
    BST *root = new BST(10);
    root->left = new BST(5);
    root->left->left = new BST(2);
    root->left->left->left = new BST(1);
    root->left->right = new BST(5);
    root->right = new BST(15);
    root->right->left = new BST(13);
    root->right->left->right = new BST(14);
    root->right->right = new BST(22);
    
    cout << "Inorder: ";
    root->inorderTraversal();
    cout << "\n";
    
    cout << "Preorder: ";
    root->preorderTraversal();
    cout << "\n";
    
    cout << "Postorder: ";
    root->postorderTraversal();
    cout << "\n";
    
    cout << "\nFIN\n";
    return 0;
}
