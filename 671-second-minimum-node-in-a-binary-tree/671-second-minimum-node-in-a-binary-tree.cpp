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
    long long min1, min2 = LONG_MAX;
    void dfs(TreeNode* root){
        if(!root) return;
        if(min1<root->val && root->val<min2){
            min2 = root->val;
        }else if(min1 == root->val){
            dfs(root->left);
            dfs(root->right);
        }
        return;
    }
    
    int findSecondMinimumValue(TreeNode* root) {
        min1 = root->val;
        dfs(root);
        return min2!=LONG_MAX ? min2:-1;
    }
};