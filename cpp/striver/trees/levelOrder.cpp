#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

vector<vector<int>> levelOrder(TreeNode *root) {
  vector<vector<int>> ans;

  // nullity check for edge cases...
  if(root == nullptr) return ans;
  
  queue<TreeNode*> q;
  q.push(root);
  while(!q.empty()){
    int size = q.size();

    vector<int> level;
    for(int i = 0; i< size; i++){
      TreeNode* front = q.front();
      if(front->left) q.push(front->left);
      if(front->right) q.push(front->right);

      level.push_back(front->val);
      q.pop();
    }

    ans.push_back(level);
  }


  return ans;
}
