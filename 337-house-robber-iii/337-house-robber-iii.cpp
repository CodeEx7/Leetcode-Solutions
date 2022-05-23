class Solution {
public:
    
    unordered_map<TreeNode*,int> mp;
    
    int giveAns(TreeNode *root){
        if(!root) return 0;
        if(mp.find(root)!=mp.end()) return mp[root];
        if(root->left){
            if(root->right){
                int x=root->val+giveAns(root->left->left)+giveAns(root->left->right)+giveAns(root->right->left)+giveAns(root->right->right);
                int y=giveAns(root->left)+giveAns(root->right);
                return mp[root]=max(x,y);
            }
            int x=root->val+giveAns(root->left->left)+giveAns(root->left->right);
            int y=giveAns(root->left)+giveAns(root->right);
            return mp[root]=max(x,y);
        }
        if(root->right){
            int x=root->val+giveAns(root->right->left)+giveAns(root->right->right);
            int y=giveAns(root->left)+giveAns(root->right);
            return mp[root]=max(x,y);
        }
        return mp[root]=root->val;
    }
    //main working function
    int rob(TreeNode* root) {
        return giveAns(root);
    }
};