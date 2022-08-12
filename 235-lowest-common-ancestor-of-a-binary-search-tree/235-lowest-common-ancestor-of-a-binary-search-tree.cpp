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
        if(!root) return NULL;
        TreeNode* l=NULL,*r=NULL;
        if(root==p || root==q) return root;
        if(p->val < root->val || q->val < root->val)
            l = lowestCommonAncestor(root->left,p,q);
        if(p->val > root->val || q->val > root->val)
            r = lowestCommonAncestor(root->right,p,q);
        
        if(l && r) return root;
        if(l) return l;
        if(r) return r;
        return NULL;
    }
};