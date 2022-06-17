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
    int findBottomLeftValue(TreeNode* root){
        queue<TreeNode*>q; q.push(root);
        int res = -1;
        while(q.size()){
            int siz = q.size();
            for(int i=0;i<siz;i++){
                TreeNode* f = q.front(); q.pop();
                if(i==0) res = f->val;
                if(f->left) q.push(f->left);
                if(f->right) q.push(f->right);
            }
        }
        return res;
    }
};