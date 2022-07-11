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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        if(root) q.push(root);
        vector<int>ans;
        while(!q.empty()){
            int siz = q.size();
            int v;
            for(int i=0;i<siz;i++){
                TreeNode* f = q.front(); q.pop();
                v = f->val;
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};