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
    void helper(TreeNode *root, int &k, int &small){
        if(root!=NULL){
            helper(root->left, k, small);
            if(--k==0) small=root->val;
            helper(root->right, k, small);
        }
    }
    int kthSmallest(TreeNode* root, int k) {
         int small=0;
        
        helper(root, k, small);
        
        return small;
    }
};