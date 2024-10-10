#include<bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


vector<vector<int>> zigzagLevelOrder(TreeNode* root){
    vector<vector<int>> result;
    if(root == NULL){
        return result;
    }
    
    queue<TreeNode* > nodeQueue;
    nodeQueue.push(root);
    bool leftToRight = true;

    while(!nodeQueue.empty()){
        int size =  nodeQueue.size();
        vector<int> row(size);
        for(int i = 0; i< size; i++){   
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();

            // find position to fill nodes value
            int index = leftToRight ? i : size-1-i;

            row[index] = node->val;
            if(node-> left){
                nodeQueue.push(node->left);
            }
            if(node-> right){
                nodeQueue.push(node->right);
            }
        }

        // after this level
        leftToRight = !leftToRight;
        result.push_back(row);
    }
    return result;
}