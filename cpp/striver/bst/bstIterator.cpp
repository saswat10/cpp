#include <bits/stdc++.h>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

class BSTIterator
{
private:
    stack<TreeNode *> myStack;

public:
    BSTIterator(TreeNode *root)
    {
        pushAll(root);
    }

    /** @return the next smallest integer */
    int next()
    {
        TreeNode *tempNode = myStack.top();
        myStack.pop();
        pushAll(tempNode->right);
        return tempNode->data;
    }

    /** @return  whether we have a next smallest number */
    bool hasNext()
    {
        return !myStack.empty();
    }

private:
    void pushAll(TreeNode *root)
    {
        for (; root != NULL; myStack.push(root), root = root->left)
            ;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */