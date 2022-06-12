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
    
    int helper(TreeNode* root){
     if(root==NULL) return 0;
        int summ=0;
        if(root->val%2==0){
            if(root->left != NULL && root->left->left != NULL) summ += root->left->left->val;
            if(root->left != NULL && root->left->right != NULL) summ += root->left->right->val;
            if(root->right != NULL && root->right->left != NULL) summ += root->right->left->val;
            if(root->right != NULL && root->right->right != NULL) summ += root->right->right->val;
        }
        return summ + helper(root->left) + helper(root->right);
 }
    //main working function
    int sumEvenGrandparent(TreeNode* root) {
        int summ=0;
        if(root==NULL) return summ;
        return helper(root);

        return summ;
    }
};