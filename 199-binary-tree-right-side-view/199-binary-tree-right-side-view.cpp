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
        if(root == NULL) return {};
        vector<int>res;
        queue<TreeNode*>q; q.push(root);
        while(q.size()){
            int siz = q.size();
            for(int i=0;i<siz;i++){
                TreeNode* f = q.front(); q.pop();
                if(f->left!=NULL) q.push(f->left);
                if(f->right!=NULL) q.push(f->right);
                if(i==siz-1) res.push_back(f->val);
            }
        }
        return res;
    }
};