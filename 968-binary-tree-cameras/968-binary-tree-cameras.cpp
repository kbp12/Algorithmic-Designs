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
    unordered_set<TreeNode*>uset;
    void dfs(TreeNode* root, TreeNode* parent){
        if(root==NULL) return;
        dfs(root->left,root);
        dfs(root->right,root);
        if((parent==NULL && uset.find(root)==uset.end()) || uset.find(root->left)==uset.end() || uset.find(root->right)==uset.end()){
            ans++;
            uset.insert(root);
            uset.insert(parent);
            uset.insert(root->left);
            uset.insert(root->right);
        }
        return;
    }
    
    
    int minCameraCover(TreeNode* root) {
        uset.insert(NULL);
        dfs(root,NULL);
        return ans;
    }
};