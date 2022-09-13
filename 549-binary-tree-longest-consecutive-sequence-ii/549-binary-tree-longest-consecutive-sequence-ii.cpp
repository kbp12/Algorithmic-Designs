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
    int ans = 0;
    pair<int,int> dfs(TreeNode* root){
        if(!root) return {0,0};
        int inr = 1, dcr = 1;
        if(root->left){
            pair<int,int> l =  dfs(root->left);
            if(root->val == root->left->val+1){
                inr = l.first+1;
            }else if(root->val == root->left->val-1){
                dcr = l.second+1;
            }
        }
        if(root->right){
            pair<int,int> r = dfs(root->right);
            if(root->val == root->right->val +1){
                inr = max(inr,r.first+1);
            }else if(root->val == root->right->val-1){
                dcr = max(dcr,r.second+1);
            }
        }
        
        ans = max({ans,inr+dcr-1});
        return {inr,dcr};
    }
    
    int longestConsecutive(TreeNode* root) {
        dfs(root);
        return ans;
    }
};