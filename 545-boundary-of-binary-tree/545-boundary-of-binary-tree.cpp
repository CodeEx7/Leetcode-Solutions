/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution {
public:
	
    void leftBoundary(TreeNode* root, vector<int> &ans){
        if (!root || (root->left == NULL && root->right == NULL)) return;
        ans.push_back(root->val);
        leftBoundary((root->left ? root->left: root->right), ans);
    }
    void leaves(TreeNode* root, vector<int> &ans){
        if(!root) return;
        leaves(root->left, ans);
        if((root->left == NULL && root->right == NULL)) ans.push_back(root->val);
        leaves(root->right, ans);
    }
    void rightBoundary(TreeNode* root, vector<int> &ans){
        if (!root || (root->left == NULL && root->right == NULL)) return;
        rightBoundary((root->right ? root->right: root->left), ans);
        ans.push_back(root->val);
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
        ans.push_back(root->val);
        leftBoundary(root->left, ans);
        if((root->left != NULL || root->right != NULL)) leaves(root, ans);
        rightBoundary(root->right, ans);
        return ans;
    }
};