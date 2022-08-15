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
    int count = 0;
    
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr) return nullptr;
        TreeNode* l = lca(root->left,p,q);
        TreeNode* r = lca(root->right,p,q);
        if(root==p or root==q){
            count++;
            return root;
        }
        if(l and r) return root;
        if(l) return l;
        return r;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = lca(root,p,q);
        if(count==2) return ans;
        return nullptr;
    }
};