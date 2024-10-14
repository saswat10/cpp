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

int inorderPredecessor(TreeNode *root, int key)
{
    int predecessor = -1;

    while (root != nullptr)
    {
        if (key > root->data)
        {
            predecessor = root->data;
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }

    return predecessor;
}

int inorderSuccessor(TreeNode *root, int key)
{
    int successor = -1;

    while (root != nullptr)
    {
        if (key >= root->data)
        {
            root = root->right;
        }
        else
        {
            successor = root->data;
            root = root->left;
        }
    }

    return successor;
}

pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{

    // Write your code here.
    int pre = inorderPredecessor(root, key);
    int su = inorderSuccessor(root, key);

    return {pre, su};
}
