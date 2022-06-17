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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL) return {};
        vector<int>res;
        queue<TreeNode*>q; q.push(root); 
        while(q.size()){
            int siz = q.size();
            int ans = INT_MIN;
            for(int i=0;i<siz;i++){
                TreeNode* f = q.front(); q.pop();
                ans = max(ans,f->val);
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            res.push_back(ans);
        }
        return res;
    }
};