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


void recursion(TreeNode* root, int level, vector<int> &res){
    if(root == NULL) return;
    if(res.size() == level) res.push_back(root->val);
    recursion(root->right, level+1, res);
    recursion(root->left, level+1, res);
}