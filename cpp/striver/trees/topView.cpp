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


vector<int> topView(TreeNode* root){
    vector<int> ans;
    if(root == NULL) return ans;
    map<int, int> mpp;
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while(!q.empty()){
        auto it = q.front();
        q.pop();

        TreeNode* node = it.first;
        int line = it.second;

        if(mpp.find(line) == mpp.end()) mpp[line] = node->val;

        if(node->left!=NULL){
            q.push({node->left, --line});
        }

        if(node->right!=NULL){
            q.push({node->right, ++line});
        }
    }

    for(auto it: mpp){
        ans.push_back(it.second);
    }

    return ans;
}


//  O{N} both TC and SC

// cannot implement the recursive mode