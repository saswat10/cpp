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

/*
    Program to print the tree node
    boundary wise in anticlockwise direction....
*/

bool isLeaf(TreeNode* node){
    return (node->left == nullptr && node->right == nullptr);
}

void addLeftBoundary(TreeNode* root, vector<int> &res){
    TreeNode* curr = root->left;
    while(curr){
        if(!isLeaf(curr)) res.push_back(curr->val);
        if(curr->left) curr = curr->left;
        else curr = curr->right;
    }
}

void addRightBoundary(TreeNode* root, vector<int> &res){
    TreeNode* curr = root->right;
    vector<int> tmp;
    while(curr){
        if(!isLeaf(curr)) tmp.push_back(curr->val);
        if(curr->right) curr = curr->right;
        else  curr = curr->left;
    }

    for(int i = tmp.size()-1; i>=0; i-- ){
        res.push_back(tmp[i]);
    }
}

void addLeaves(TreeNode* root, vector<int> &res){
    if(isLeaf(root)){
        res.push_back(root->val);
        return;
    }
    if(root->left) addLeaves(root->left, res);
    if(root->right) addLeaves(root->right, res);
}

vector<int> printBoundary(TreeNode* node){
    vector<int> res;
    if(!node) return res;
    if(!isLeaf(node)) res.push_back(node->val);
    addLeftBoundary(node, res);
    addLeaves(node, res);
    addRightBoundary(node, res);
    return res;
}