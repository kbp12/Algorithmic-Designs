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
    TreeNode* ans;
    int maxdepth;
    int dfs(TreeNode* root, int depth){
        if(!root) return 0;
        int l = dfs(root->left , depth+1);
        int r = dfs(root->right, depth+1);
        maxdepth = max(maxdepth , depth);
        if(l == r and (l == maxdepth or depth == maxdepth)){
            ans = root;
        }
        if(l==0 and r==0) return depth;
        return max(l,r);
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        maxdepth = 0;
        ans = root;
        dfs(root , 1);
        return ans;
    }
};