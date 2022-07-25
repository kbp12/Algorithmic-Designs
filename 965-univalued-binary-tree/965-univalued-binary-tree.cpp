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
    int val = -1;
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;
        if(val==-1) val = root->val;
        else if(root->val!=val) return false;
        return isUnivalTree(root->left) & isUnivalTree(root->right);
    }
};