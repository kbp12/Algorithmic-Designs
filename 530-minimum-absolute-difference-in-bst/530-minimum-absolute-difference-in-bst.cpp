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
    int prev=INT_MIN, ans = INT_MAX;
    void calcdiff(TreeNode* root){
        if(!root) return;
        calcdiff(root->left);
        if(prev != INT_MIN)
        {
            int t = root->val - prev;
            ans = min(ans,t);
        }
        prev = root->val;
        calcdiff(root->right);
        return;   
    }
    
    int getMinimumDifference(TreeNode* root) {
        calcdiff(root);
        return ans;
    }
};