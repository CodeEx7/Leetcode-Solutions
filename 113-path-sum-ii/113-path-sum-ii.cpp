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
    void helper(TreeNode* root, int targetSum, vector<vector<int>> &res, vector<int> temp){
        if(root==NULL) return;
        
        targetSum-=root->val;
        temp.push_back(root->val);
        
        if(targetSum==0 && root->left==NULL && root->right==NULL){
            res.push_back(temp);
            return;
        }
        
        helper(root->left, targetSum, res, temp);
        helper(root->right, targetSum, res, temp);
        
    }
    //wejhfvwveefuklnwEFBK.JSHFF S kwdfbQWEM,F KJWFQ,qwf  SFBFmjff dwd wjddW.EKJF AEAFwefk wefhwEF/
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> temp;
        
        helper(root, targetSum, res, temp);
        
        return res;
    }
};