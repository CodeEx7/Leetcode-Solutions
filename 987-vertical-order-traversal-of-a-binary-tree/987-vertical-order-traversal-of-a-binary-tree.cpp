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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL) return {};
        map<int, map<int, multiset<int>>> mapp;
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});
        
        while(!q.empty()){
            int x=q.front().second.first;
            int y=q.front().second.second;
            auto temp_node=q.front().first;
            q.pop();
            mapp[x][y].insert(temp_node->val);
            if(temp_node->left) q.push({temp_node->left,{x-1,y+1}});
            if(temp_node->right) q.push({temp_node->right,{x+1,y+1}});
        }
        
        vector<vector<int>> ans;
        for (auto p : mapp) {
            vector<int> col;
            for (auto q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};