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
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int>u;
        queue<TreeNode*>q; q.push(root);
        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                TreeNode* f = q.front(); q.pop();
                if(u.find(k-f->val)!=u.end()) return true;
                u.insert(f->val);
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
        }
        return false;
    }
};