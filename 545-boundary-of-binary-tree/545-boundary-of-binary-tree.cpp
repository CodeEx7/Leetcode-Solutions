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
class Solution
{
    public:
        void leftside(vector<int> &ans, TreeNode *root)
        {
            if (root == NULL)
                return;
            if (root->left)
            {
                ans.push_back(root->val);
                leftside(ans, root->left);
            }
            else if (root->right)
            {
                ans.push_back(root->val);
                leftside(ans, root->right);
            }
        }
    void rightside(vector<int> &ans, TreeNode *root)
    {
        if (root == NULL)
            return;
        if (root->right)
        {
            rightside(ans, root->right);
            ans.push_back(root->val);
        }
        else if (root->left)
        {
            rightside(ans, root->left);
            ans.push_back(root->val);
        }
    }
    void leafTreeNode(vector<int> &ans, TreeNode *root)
    {
        if (root == NULL)
            return;
        else if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->val);
            return;
        }
        else
        {
            leafTreeNode(ans, root->left);
            leafTreeNode(ans, root->right);
        }
    }

    vector<int> boundaryOfBinaryTree(TreeNode *root)
    {
        vector<int> ans;
        if (root == NULL)
            return ans;
        ans.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
            return ans;
        leftside(ans, root->left);
        leafTreeNode(ans, root);
        rightside(ans, root->right);
        return ans;
    }
};