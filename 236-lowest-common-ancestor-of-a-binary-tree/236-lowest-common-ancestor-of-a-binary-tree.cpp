/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;
        
        if(root->val==p->val || root->val==q->val) return root;
        
        TreeNode *left=NULL, *right=NULL;
        
        if(root->left!=NULL){
            left=lowestCommonAncestor(root->left, p, q);
        }
        if(root->right!=NULL){
            right=lowestCommonAncestor(root->right, p, q);
        }
        
        if(left!=NULL && right!=NULL) return root;
        
        if(left==NULL){
            return right;
        }else{
            return left;
        }
        return NULL;
    }
};