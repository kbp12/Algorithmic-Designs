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
    int ans = 0, covered = 0, notcovered = 1, hascamera = 2;
    
    int dfs(TreeNode* root){
        if(root==NULL) return covered;
        int l = dfs(root->left), r = dfs(root->right);
        if(l==notcovered || r==notcovered){
            ans++;
            return hascamera;
        }
        if(l==covered && r==covered){
            return notcovered;
        }
        return covered;
    }
    
    int minCameraCover(TreeNode* root) {
        if(dfs(root)==notcovered) return ans+1;
        return ans;
    }
};