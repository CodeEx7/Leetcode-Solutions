/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //helper function
    bool helper(TreeNode *root, TreeNode* &prev){
        if(root==NULL) return true;
        if(helper(root->left, prev)==false) return false;
        if(prev!=NULL && prev->val>=root->val) return false;
        prev=root;
        if(helper(root->right, prev)==false) return false;
        
        return true;
    }
    //main working function
    bool isValidBST(TreeNode* root) {
        TreeNode *prev=NULL;
        return helper(root, prev);
    }
};