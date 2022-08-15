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
    bool dfs(TreeNode* root, TreeNode* temp){
        if(root==nullptr) return false;
        if(root==temp) return true;
        return dfs(root->left,temp) or dfs(root->right,temp);
    }
    
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr) return nullptr;
        if(root==p or root==q) return root;
        TreeNode* l = lca(root->left,p,q);
        TreeNode* r = lca(root->right,p,q);
        if(l and r) return root;
        if(l) return l;
        return r;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!dfs(root,p) or !dfs(root,q)) return nullptr;
        return lca(root,p,q);
    }
};