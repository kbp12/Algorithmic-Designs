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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return {};
        vector<int>adj[205];
        queue<pair<TreeNode*,int>>q;
        q.push({root,102});
        while(!q.empty()){
            int sz = q.size();
            for(int i=0;i<sz;i++){
                auto p = q.front(); q.pop();
                adj[p.second].push_back(p.first->val);
                if(p.first->left) q.push({p.first->left,p.second-1});
                if(p.first->right) q.push({p.first->right,p.second+1});
            }
        }
        vector<vector<int>>ans;
        for(int i=0;i<205;i++){
            if(adj[i].size()){
                ans.push_back(adj[i]);
            }
        }
        return ans;
    }
};