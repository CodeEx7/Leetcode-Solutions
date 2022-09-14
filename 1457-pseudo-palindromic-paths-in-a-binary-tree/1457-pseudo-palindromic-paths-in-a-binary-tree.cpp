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
    // bool isPalindrome(unordered_map<int,int> mapp){
    //     int flag=0;
    //     for(auto it:mapp){
    //         if(it.second%2!=0){
    //             flag++;
    //         }
    //         if(flag>1) return false;
    //     }
    //     return true;
    // }
    unordered_map<int,int> mapp;
    int res=0;
    //--------------------------------------------------------------
    void helper(TreeNode *root){
        if(root==NULL) return;
        
        mapp[root->val]++;
            
        if(root->left==NULL && root->right==NULL){
            int flag=0;
            for(auto it:mapp){
                if(it.second%2!=0){
                    flag++;
                }
                if(flag>1) break;
            }
            if(flag<=1) res++;
        }
        
        helper(root->left);
        helper(root->right);
        mapp[root->val]--;
    }
    //-------------------------------------------
    int pseudoPalindromicPaths (TreeNode* root) {
        //int res=0;
        //unordered_map<int,int> mapp;
        helper(root);
        return res;
    }
};