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
    void helper(TreeNode* root, int prev_max, int &cnt){
        if(root==NULL) 
            return;
        if(root->val >= prev_max){
            cnt++;
            prev_max=root->val;
        }
        helper(root->left, prev_max, cnt);
        helper(root->right, prev_max, cnt);
    }
    //main working function
    int goodNodes(TreeNode* root) {
        int prev_max=INT_MIN;
        int cnt=0;
        //if(root==NULL) return cnt;
        helper(root, prev_max, cnt);
        return cnt;
    }
};