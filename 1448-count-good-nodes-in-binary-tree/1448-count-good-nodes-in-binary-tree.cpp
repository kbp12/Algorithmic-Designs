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
    int dfs(TreeNode* root, int v){
        if(!root) return 0;
        int c = 0;
        if(root->val>=v){
            c++;
        }
        c+=dfs(root->left,max(root->val,v));
        c+=dfs(root->right,max(root->val,v));
        return c;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,INT_MIN);
    }
};