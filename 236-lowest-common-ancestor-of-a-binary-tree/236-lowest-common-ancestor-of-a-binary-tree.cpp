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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    stack<TreeNode*> path_p, path_q;
    get_path_to_node(root, p, path_p);
    get_path_to_node(root, q, path_q);
    
    return lca_from_paths(path_p, path_q);
  }
  
private:
  bool get_path_to_node(TreeNode* root, TreeNode* node, 
      stack<TreeNode*>& path) {
    if (!root) {
      return false;
    }
    
    if (root == node || 
        get_path_to_node(root->left, node, path) ||
        get_path_to_node(root->right, node, path)) {
      path.push(root);
      return true;
    }
    
    return false;
  }
  
  TreeNode* lca_from_paths(stack<TreeNode*>& path1,
      stack<TreeNode*>& path2) {    
    TreeNode* lca = NULL;
    while (!path1.empty() && !path2.empty()) {
      if (path1.top() != path2.top()) {
        break;
      }
      
      lca = path1.top();
      path1.pop(), path2.pop();
    }
    
    return lca;
  }
};