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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        vector<double>ans;
        while(!q.empty()){
            int sz = q.size();
            double s = 0;
            for(int i=0;i<sz;i++){
                TreeNode* f = q.front(); q.pop();
                s+=f->val;
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            s = s/sz;
            ans.push_back(s);
        }
        return ans;
    }
};