#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* right, TreeNode* left): val(x), left(left), right(right) {}
};


bool isSymmetricHelp(TreeNode* left, TreeNode* right){
    if(left == NULL || right == NULL) return left == right;

    if(left->val!= right->val) return false;

    return isSymmetricHelp(left->left, right->right)
        && 
            isSymmetricHelp(left->right, right->left);
}

bool isSymmetric(TreeNode* root){
    return root == NULL || isSymmetricHelp(root->left, root->right);
}