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
    //helper function
    int helper(TreeNode* root, vector<int> &temp){
        if(root==NULL) return 0;
        int left=helper(root->left, temp);
        int right=helper(root->right, temp);
        
        if(root->left==NULL && root->right==NULL){
            temp.push_back(root->val);
            return 1;
        }
        if(left == 1){
            root->left=NULL;
        }
        if(right==1){
            root->right=NULL;
        }                                    
        return 0;
    }
    //main working function
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        if(root==NULL) 
            return res;
        while(root!=NULL){
            vector<int> temp;
            if(helper(root, temp)==1){
                res.push_back(temp);
                break;
            }
            res.push_back(temp);
        }      
      return res;  
    }
};