#include <bits/stdc++.h>
#include <iostream>
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
void removeSubtree(TreeNode *node, int val)

{
  if (node == nullptr)
    return;
  if (node->left != nullptr && node->left->val == val) {
    node->left = nullptr;
    return;
  }
  if (node->right != nullptr && node->right->val == val) {
    node->right = nullptr;
    return;
  }

  removeSubtree(node->left, val);
  removeSubtree(node->right, val);
}

int height(TreeNode *node) {
  if (node == nullptr)
    return 0;

  int lh = height(node->left);
  int rh = height(node->right);

  return 1 + max(lh, rh);
}

vector<int> treeQueries(TreeNode *root, vector<int> &queries) {
  vector<int> ans;
  for (int i = 0; i < queries.size(); i++) {
    TreeNode *dummy = root;
    removeSubtree(dummy, queries[i]);
    ans.push_back(height(dummy));
  }

  return ans;
}

int main() {

  cout << "Hello World";
  return 0;
}