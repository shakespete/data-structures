#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class BST {
public:
    BST(int e);
    int val;
    BST* left;
    BST* right;
    BST* treeMin(BST* x);
    BST* treeSearch(int e);
    BST* insert(int e);
    BST* remove(int e, BST* parent);
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
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
        else if (e > x->val) x = x->right;
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
            };
        }
    }
    return x;
}
BST* BST::remove(int e, BST* parent = nullptr) {
    BST* x = this;
    while (x) {
        if (e < x->val) {
            parent = x;
            x = x->left;
        } else if (e > x->val) {
            parent = x;
            x = x->right;
        } else {
            if (x->left && x->right) {
                BST* min = treeMin(x);
                x->val = min->val;
                x->right->remove(min->val, x);
            } else if (!parent) {
                if (x->left) {
                    x->val = x->left->val;
                    x->right = x->left->right;
                    x->left = x->left->left;
                } else if (x->right) {
                    x->val = x->left->val;
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
    stack<BST*> st;
    BST* x = this;
    
    while (x || !st.empty()) {
        while (x) {
            st.push(x);
            x = x->left;
        }
        x = st.top();
        st.pop();
        
        cout << x->val << " ";
        x = x->right;
    }
}
void BST::preorderTraversal() {
    stack<BST*> st;
    BST* x = this;
    
    st.push(x);
    while (!st.empty()) {
        x = st.top();
        st.pop();
        
        cout << x->val << " ";
        if (x->right) st.push(x->right);
        if (x->left) st.push(x->left);
    }
}
void BST::postorderTraversal() {
    stack<BST*> s1, s2;
    BST* x = this;
    
    s1.push(x);
    
    while (!s1.empty()) {
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
    
    
    root->insert(12);
    root->inorderTraversal();
    cout << "\n";
    
    root->remove(1);
    root->remove(14);
    root->remove(12);
    root->inorderTraversal();
    cout << "\n";
    std::cout << "FIN\n";
    return 0;
}
