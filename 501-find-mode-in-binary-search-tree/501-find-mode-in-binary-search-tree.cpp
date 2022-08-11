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
    int helper(TreeNode *root,unordered_map<int,int> &mapp){
        if(root==NULL) return 0;
        
            mapp[root->val]++;
        
        return max(mapp[root->val], max(helper(root->left, mapp), helper(root->right, mapp)));
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res;
        unordered_map<int,int> mapp;
        int cnt= helper(root, mapp);
        for(auto it:mapp){
            if(it.second==cnt){
                res.push_back(it.first);
            }
        }
        return res;
    }
};