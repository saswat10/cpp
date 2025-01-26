#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {

public:
  vector<int> getInorder(TreeNode *root) {

    vector<int> inorder;
    TreeNode *curr = root;

    while (curr != nullptr) {
      if (curr->left == nullptr) {
        inorder.push_back(curr->val);
        curr = curr->right;
      } else {

        TreeNode *prev = curr->left;
        while (prev->right && prev->right != curr) {
          prev = prev->right;
        }

        if (prev->right == nullptr) {
          prev->right = curr;
          curr = curr->left;
        } else {
          prev->right = nullptr;
          inorder.push_back(curr->val);
          curr = curr->right;
        }
      }
    }

    return inorder;
  }
};