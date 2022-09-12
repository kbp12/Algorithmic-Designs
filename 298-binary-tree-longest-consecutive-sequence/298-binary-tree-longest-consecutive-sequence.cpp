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
    int ans;
    void dfs(TreeNode* root, int len, int prev){
        ans = max(ans,len);
        if(!root) return;
        if(root->val==prev+1){
            len++; prev++;
        }else{
            len = 1; prev = root->val;
        }
        dfs(root->left,len,prev);
        dfs(root->right,len,prev);
        return;
    }
    
    int longestConsecutive(TreeNode* root) {
        ans = 0;
        dfs(root,1,root->val);
        return ans;
    }
};