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
    void helper(TreeNode* root, vector<int> &res, vector<bool> &levels, int level){
        if(root==NULL) return;
        if(levels[level]==false){
            levels[level]=true;
            res.push_back(root->val);
        }
        helper(root->right, res, levels, level+1);
        helper(root->left, res, levels, level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        vector<bool> levels(101, false);
        helper(root, res, levels, 0);
        return res;
    }
};