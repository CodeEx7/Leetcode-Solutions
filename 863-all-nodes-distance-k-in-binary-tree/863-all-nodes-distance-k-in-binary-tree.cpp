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
    //find parent
    void findParent(unordered_map<TreeNode*, TreeNode*> &parent, TreeNode *root){
        if(root==NULL) return;
        if(root->left) parent.insert({root->left, root});
        if(root->right) parent.insert({root->right, root});
        
        findParent(parent, root->left);
        findParent(parent, root->right);
    }
    //main working function
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        if(root==NULL) return res;
        
        unordered_map<TreeNode*, TreeNode*> parent; //parent map
        findParent(parent, root); //finding parent of each node
        
        
        queue<TreeNode*> q;
        TreeNode *curr=target;
        unordered_set<TreeNode*> vis;
        q.push(curr);
        
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode *temp=q.front();
                q.pop();
                vis.insert(temp);
                if(k==0) res.push_back(temp->val);
                if(temp->left && vis.find(temp->left)==vis.end()) q.push(temp->left);
                if(temp->right && vis.find(temp->right)==vis.end()) q.push(temp->right);
                if(parent.find(temp)!=parent.end() && vis.find(parent[temp])==vis.end()) q.push(parent[temp]);
            }
            k--;
            if(k<0) break;
        }
        return res;
    }
};