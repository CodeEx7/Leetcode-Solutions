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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(root==NULL) return {};
        map<int, vector<int>> mapp;
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        
        while(!q.empty()){
            int temp_row=q.front().first;
            auto temp_node=q.front().second;
            q.pop();
            mapp[temp_row].push_back(temp_node->val);
            if(temp_node->left) q.push({temp_row-1, temp_node->left});
            if(temp_node->right) q.push({temp_row+1, temp_node->right});
        }
        
        vector<vector<int>> res;
        for(auto it:mapp){
            res.push_back(it.second);
        }
        return res;
    }
};