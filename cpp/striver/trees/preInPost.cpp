#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    struct TreeNode
    {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    vector<int> preInPostOrderTraversal(TreeNode *root)
    {
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});
        vector<int> pre, in, post;
        if(root == nullptr) return;
        while(!st.empty()){
            auto it = st.top();
            st.pop();


            // this is a part of pre
            // increment 1 to 2
            // push the left side of the tree
            if(it.second == 1){
                pre.push_back(it.first -> val);
                it.second++;
                st.push(it);

                if(it.first->left != nullptr){
                    st.push({it.first->left, 1});
                }
            }

            // this is the part of in
            // increment 2 to 3
            // push to right
            else if(it.second == 2){
                in.push_back(it.first->val);
                it.second++;
                st.push(it);

                if(it.first-> right!=NULL){
                    st.push({it.first->right, 1});
                }
            }

            // don't push it back again
            else{
                post.push_back(it.first->val);
            }

        }
    }
};