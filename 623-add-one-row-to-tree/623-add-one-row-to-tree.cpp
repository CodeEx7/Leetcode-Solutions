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
    TreeNode* addOneRow(TreeNode* head, int val, int depth) {
        TreeNode* root=head;
        if(root==NULL) return NULL;
        depth--;
        
        if(depth==0){
            TreeNode* temp_head=root;
            
            TreeNode* head_node= new TreeNode(val);
            
            head_node->left=temp_head;
            head_node->right=NULL;
                        
            return head_node;
        }else if(depth==1){
            TreeNode* temp_left=root->left;
            TreeNode* temp_right=root->right;
            
            TreeNode* left_node= new TreeNode(val);
            TreeNode* right_node= new TreeNode(val);
            
            root->left=left_node;
            root->right=right_node;
            
            left_node->left=temp_left;
            right_node->right=temp_right;
        }
        
        
        TreeNode* t1=addOneRow(root->left, val, depth);
        TreeNode* t2=addOneRow(root->right, val, depth);
        
        return head;
    }
};