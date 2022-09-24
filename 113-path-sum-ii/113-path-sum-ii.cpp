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
    vector<vector<int>>ans;
    void dfs(TreeNode* root,vector<int>& temp, int sum, int s){
        if(!root) return;
        if(!root->left and !root->right and s+root->val==sum){
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        if(root->left){
            temp.push_back(root->val);
            dfs(root->left,temp,sum,s+root->val);
            temp.pop_back();
        }
        if(root->right){
            temp.push_back(root->val);
            dfs(root->right,temp,sum,s+root->val);
            temp.pop_back();
        }
        return;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int>temp;
        dfs(root,temp,sum,0);
        return ans;
    }
};