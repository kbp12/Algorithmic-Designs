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
    vector<int> bfs(TreeNode* root){
        if(root==NULL) return {0,0,2000};
        vector<int>l = bfs(root->left);
        vector<int>r = bfs(root->right);
        int l12 = min(l[1],l[2]);
        int r12 = min(r[1],r[2]);
        int a1 = l[1]+r[1];
        int a2 = min(l[2]+r12,r[2]+l12);
        int a3 = 1+min(l[0],l12)+min(r[0],r12);
        return {a1,a2,a3};
    }
    
    int minCameraCover(TreeNode* root) {
        vector<int>ans = bfs(root);
        return min(ans[1],ans[2]);
    }
};