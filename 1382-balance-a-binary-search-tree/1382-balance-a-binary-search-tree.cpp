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
    TreeNode* dfs(vector<int>& v, int i, int j){
        if(i>j) return nullptr;
        int m = i+(j-i)/2;
        TreeNode* root = new TreeNode(v[m]);
        root->left = dfs(v,i,m-1);
        root->right = dfs(v,m+1,j);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>v;
        queue<TreeNode*>q;
        q.push(root);
        while(q.size()){
            TreeNode* f = q.front(); q.pop();
            v.push_back(f->val);
            if(f->left) q.push(f->left);
            if(f->right) q.push(f->right);
        }
        sort(v.begin(),v.end());
        int n=v.size();
        return dfs(v,0,n-1);
    }
};