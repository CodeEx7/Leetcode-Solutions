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
        if(root==NULL) return;
            helper(root->left, k, small);
            k--;
            if(k==0){
                small=root->val;
                return;
            } 
            helper(root->right, k, small);
    }
    
    
    int kthSmallest(TreeNode* root, int k) {
         int small;
        
        helper(root, k, small);
        
        return small;
    }
};