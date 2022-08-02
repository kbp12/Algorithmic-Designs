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
    pair<int,int> robnow(TreeNode* root){
        if(!root) return {0,0};
        pair<int,int>p1 = robnow(root->left);
        pair<int,int>p2 = robnow(root->right);
        int f = max(p1.first+p2.first,root->val+p1.second+p2.second);
        int s = max({p1.first+p2.first,p1.first+p2.second,p2.first+p1.second});
        return {f,s};
    }
    
    int rob(TreeNode* root) {
        pair<int,int>p = robnow(root);
        return max(p.first,p.second);
    }
};