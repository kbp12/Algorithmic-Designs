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
    priority_queue<pair<double,int>,vector<pair<double,int>>, greater<pair<double,int>>>pq;
    void dfs(TreeNode* root, double target){
        if(!root) return;
        double diff = root->val;
        diff = abs(diff-target);
        pq.push({diff,root->val});
        dfs(root->left,target);
        dfs(root->right,target);
        return;
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        dfs(root,target);
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second); pq.pop();
        }
        return ans;
    }
};