struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


int findCeil(TreeNode* root, int key){
    int ceil = -1;
    while(root){
        if(root->val == key){
            ceil = root->val;
            return ceil;
        }else if(root->val > key){
            ceil = root->val;
            root = root->left;
        }else{
            root = root->right;
        }
    }
    return ceil;
}


int findFloor(TreeNode* root, int key){
    int floor = -1;
    while(root){
        if(root->val == key){
            floor = root->val;
            return floor;
        }else if(root->val < key){
            floor = root->val;
            root = root->right;
        }else{
            root = root->left;
        }
    }
    return floor;
}