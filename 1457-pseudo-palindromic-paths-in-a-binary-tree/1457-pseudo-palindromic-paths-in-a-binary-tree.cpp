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
    set<int>s;
    int ans = 0;
    
    void dfs(TreeNode* root){
        if(!root) return;
        bool erased = false;
        if(s.find(root->val)!=s.end()){
            erased = true;
            s.erase(root->val);
            if(s.size()<2 and !root->left and !root->right)  ans++;
        }else{
            s.insert(root->val);
            if(s.size()<2 and !root->left and !root->right) ans++; 
        }
        dfs(root->left);
        dfs(root->right);
        if(erased) s.insert(root->val);
        else s.erase(root->val);
        return;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return ans;
    }
};