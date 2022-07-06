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
	vector<int> ans;
    bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }
    void leftBoundary(TreeNode* root){
        if (!root || isLeaf(root)) return;
        ans.push_back(root->val);
        leftBoundary(root->left ? root->left: root->right);
    }
    void leaves(TreeNode* root){
        if(!root) return;
        leaves(root->left);
        if(isLeaf(root)) ans.push_back(root->val);
        leaves(root->right);
    }
    void rightBoundary(TreeNode* root){
        if (!root || isLeaf(root)) return;
        rightBoundary(root->right ? root->right: root->left);
        ans.push_back(root->val);
    }
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) return ans;
        ans.push_back(root->val);
        leftBoundary(root->left);
        if(!isLeaf(root)) leaves(root);
        rightBoundary(root->right);
        return ans;
    }
};